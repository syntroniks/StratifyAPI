/* Copyright 2016-2018 Tyler Gilbert ALl Rights Reserved */


/*! \file
 *
 */

#ifndef SAPI_SYS_LINK_HPP_
#define SAPI_SYS_LINK_HPP_

#include <mcu/types.h>
#include <sos/link.h>
#include "../var/String.hpp"
#include "../var/Vector.hpp"
#include "Appfs.hpp"
#include "Sys.hpp"
#include "ProgressCallback.hpp"
#include "Printer.hpp"

namespace sys {

class LinkInfo {
public:

	LinkInfo(){}
	LinkInfo(const var::ConstString & port,
				const sys::SysInfo & sys_info){
		set_port(port);
		set_info(sys_info);
	}

	void clear(){
		m_serial_number.clear();
		m_port.clear();
		m_sys_info.clear();
	}

	LinkInfo & set_port(const var::ConstString & port){
		m_port = port;
		return *this;
	}

	LinkInfo & set_info(const sys::SysInfo & sys_info){
		m_sys_info = sys_info;
		m_serial_number = sys_info.serial_number().to_string();
		return *this;
	}

	const var::String & port() const { return m_port; }
	const sys::SysInfo & sys_info() const { return m_sys_info; }
	const var::String & serial_number() const { return m_serial_number; }

private:
	var::String m_port;
	sys::SysInfo m_sys_info;
	var::String m_serial_number;

};

/*! \brief Link for Controlling Stratify OS remotely
 * \details This class is used to access devices
 * running Stratify OS from a remote platform (desktop/mobile/web).
 *
 * This class is a wrapper for the Stratify OS serialization protocol
 * which allows complete access to Stratify OS system calls
 * and filesystems.
 *
 * This class is not available on native Stratify OS applications.
 *
 *
 */
class Link {
public:
	Link();
	~Link();


	var::Vector<var::String> get_port_list();

	/*! \cond */
	typedef struct {
		var::String port;
		sys::SysInfo sys_info;
	} port_device_t;
	/*! \endcond */

	var::Vector<LinkInfo> get_info_list();

	/*! \details Gets the error message if an operation fails.
	  */
	const var::String & error_message() const { return m_error_message; }

	/*! \details Gets the current progress of an operation.  This allows
	  * multi-threaded applications to update a progress bar while copying files.
	  */
	int progress() const { return m_progress; }

	/*! \details Gets the maximum progress value of the current operation.
	  *
	  */
	int progress_max() const { return m_progress_max; }

	/*! \details Connects to the specified Stratify OS device. After calling this,
	  * other applications will not have access to the device.
	  *
	  * @param path The path to the serial device
	  * @param serial_number The serial number to connect to
	  * @param is_legacy True if connected to older devices
	  *
	  */
	int connect(
			const arg::SourceFilePath path,
			const arg::IsLegacy is_legacy = arg::IsLegacy(false)
			);

	/*! \details Reconnects to the last known path and serial number. */
	int reinit(){
		return connect(
					arg::SourceFilePath(path())
					);
	}

	int reconnect(
			const arg::RetryCount retries = arg::RetryCount(5),
			const arg::RetryDelay delay = arg::RetryDelay(chrono::Milliseconds(500))
			);

	/*! \details This disconnects from the device.  After calling this,
	  * other applications can access the device.
	  */
	int disconnect();

	/*! \details Sets the object to a disconnected state
	  * without interacting with the hardware.
	  *
	  * This can be called if the device was removed without
	  * being properly disconnected in software.
	  *
	  */
	void set_disconnected();


	/*! \details Returns true if the device is connected.
	  */
	bool is_connected() const;
	bool get_is_connected() const { return is_connected(); }

	//These are all the file transfer options over Stratify OS Link

	//Operations on the device
	/*! \details Creates a directory on the target device.
	  *
	  */
	int mkdir(
			const arg::DestinationDirectoryPath directory /*! The directory name */,
			const fs::Permissions permissions /*! The access permissions */
			);

	/*! \details Removes a directory on the target device.
	  *
	  */
	int rmdir(
			const arg::SourceDirectoryPath directory /*! The directory name (must be empty) */
			); //Directory must be empty

	/*! \details Deletes a file on the target device.
	  *
	  */
	int unlink(
			const arg::SourceFilePath filename /*! The filename to delete */
			);

	/*! \details Creates a symbolic link on the device.
	  * \note Stratify OS does not currently support symbolic links.  This function will
	  * always return an error.
	  *
	  * \note Symbolic links are not supported on all filesystems.
	  *
	  * \return Zero on sucess.
	  */
	int symlink(
			const arg::SourceFilePath old_path /*! The existing path */,
			const arg::DestinationFilePath new_path /*! The path to the new link */
			);

	/*! \details Loads the entries of a directory. */
	var::Vector<var::String> get_dir_list(
			const arg::SourceDirectoryPath directory
			);

	/*! \details Converts the permissions to a
	  * string of the format:
	  *
	  * -rwxrwxrwx
	  *
	  * The first character indicates:
	  * - - File
	  * - d Directory
	  * - c Character file
	  * - b Block file
	  *
	  * The order is other, group, user.  If the permission
	  * is not available, the character is replace by a "-".
	  *
	  */
	static var::String convert_permissions(link_mode_t mode);

	/*! \details Opens a directory such that it's contents can be
	  * read with readdir().
	  */
	int opendir(const arg::SourceDirectoryPath directory /*! The directory to open */);

	/*! \details Reads an entry from an open directory.
	  *
	  * \return The name of the next entry in the directory.
	  */
	int readdir_r(const arg::LinkDirp dirp /*! The directory to read (returned from opendir()) */,
					  struct link_dirent * entry /*! A pointer to the destination memory */,
					  struct link_dirent ** result /*! Assigned to \a entry on success or NULL on failure */
					  );

	/*! \details Closes an open directory.
	  *
	  */
	int closedir(const arg::LinkDirp dirp /*! The directory to close */);

	/*! \details This copies a file either from the device to the
	  * host or from the host to the device depending on the value of \a toDevice.
	  *
	  * \return Zero on success
	  */
	int copy(const arg::SourceFilePath src /*! The path to the source file */,
				const arg::DestinationFilePath dest /*! The path to the destination file */,
				const fs::Permissions & permissions /*! The access permissions if copying to the device */,
				const arg::IsCopyToDevice to_device = arg::IsCopyToDevice(true) /*! When true, copy is from host to device */,
				const ProgressCallback * progress_callback = 0);


	/*!
	  * \details Copies a file to the target device.
	  *
	  * \param src Path to the source file.
	  * \param dest Path to the destination file on the target device.
	  * \param mode Mode for file creation on target
	  * \param update Callback to execute as file is copied
	  * \param context Argument to pass to update callback
	  * \return Zero on success
	  */
	int copy_file_to_device(
			const arg::SourceFilePath src,
			const arg::DestinationFilePath dest,
			const fs::Permissions & permissions,
			const ProgressCallback * progress_callback = 0
			){
		return copy(
					src,
					dest,
					permissions,
					arg::IsCopyToDevice(true),
					progress_callback
					);
	}

	/*!
	  * \details Copes a file from the target device to the host.
	  *
	  * \param src Path to the source file on the target device
	  * \param dest Path to the destination file on the host
	  * \param mode Mode for file creation on host
	  * \param update Callback to execute as file is copied
	  * \param context Argument to pass to update callback
	  * \return Zero on success
	  */
	int copy_file_from_device(
			const arg::SourceFilePath src,
			const arg::DestinationFilePath dest,
			const fs::Permissions & permissions,
			const ProgressCallback * progress_callback = 0
			){
		return copy(
					src,
					dest,
					permissions,
					arg::IsCopyToDevice(false),
					progress_callback
					);
	}

	/*! \details Formats the filesystem on the device.
	  *
	  * \return Zero on success
	  */
	int format(
			const arg::SourceDirectoryPath path
			); //Format the drive

	/*! \details Funs an application on the target device.
	  *
	  * \return The PID of the new process or less than zero for an error
	  */
	int run_app(
			const arg::SourceFilePath path
			);


	/*! \details Opens a file (or device such as /dev/adc0) on the target device.
	  *
	  * \return The file descriptor on success or -1 on failure
	  *
	  * \note The target device has a limit on how many files can
	  * be open at a time. It is important that the host close any
	  * files that it opens.
	  *
	  * \note File access is more easily performed using fs::File
	  * rather than accessing files using this object.
	  *
	  * \code
	  * #include <sapi/sys.hpp>
	  *
	  * Link link;
	  * link.connect("path_to_serial_port", "serial_number");
	  *
	  * File file(link.driver());
	  *
	  * if( file.open("/home/hello.txt", File::READ_ONLY) < 0 ){
	  *   printf("Failed to open file on target device\n");
	  * } else {
	  *   file.close();
	  * }
	  *
	  * \endcode
	  *
	  *
	  */
	int open(const arg::FilePath file /*! The name of the file to open */,
				const fs::OpenFlags & flags /*! The access flags such as LINK_O_RDWR */,
				const fs::Permissions & permissions = fs::Permissions(0) /*! The access permissions when creating a new file */
			);

	/*! \details Reads an open file descriptor.
	  *
	  * \param fd File descriptor (returned from open)
	  * \param buf Pointer to the destination buffer for the read
	  * \param nbyte Number of bytes to read from the file
	  *
	  * \return Number of bytes read or less than zero on failure
	  */
	int read(
			const arg::FileDescriptor fd,
			const arg::DestinationBuffer buf,
			const arg::Size nbyte
			);

	/*! \details Writes an open file descriptor.
	  *
	  * \param fd File descriptor (returned from open)
	  * \param buf Pointer to the source buffer for the write
	  * \param nbyte Number of bytes to read from the file
	  *
	  * \return Number of bytes written or less than zero on failure
	  */
	int write(
			const arg::FileDescriptor fd,
			const arg::SourceBuffer buf,
			const arg::Size nbyte
			);

	/*! \details Checks to see if the target is in = mode.
	  *
	  * \return Non zero if = mode is active.
	  */
	bool is_bootloader() const { return m_is_bootloader; }

	bool is_connected_and_is_not_bootloader() const {
		return is_connected() && !is_bootloader();
	}

	bool is_legacy() const { return m_is_legacy; }


	/*! \details Performs an IO control operation on an open file descriptor.
	  *
	  *
	  * \param fd File descriptor (returned from open())
	  * \param request ioctl() request value
	  * \param ctl Pointer to 3rd argument
	  *
	  * \return Value returned based on request and fd
	  */
	int ioctl(
			const arg::FileDescriptor fd,
			const arg::IoRequest request,
			const arg::IoArgument arg = arg::IoArgument(NULL)
			);

	enum {
		SET /*! Whence value for lseek */ = LINK_SEEK_SET,
		CURRENT /*! Whence value for lseek */ = LINK_SEEK_CUR,
		END /*! Whence value for lseek */ = LINK_SEEK_END
	};

	/*! \details Performs an lseek \a fd.
	  *
	  * \param fd File descriptor from open()
	  * \param offset Offset for seek
	  * \param whence Type of seek
	  *
	  * \return Zero on success
	  */
	int lseek(
			const arg::FileDescriptor fd,
			const arg::Location offset,
			int whence);

	/*! \details Reads the file statistics on
	  * the specified target device file.
	  *
	  * \return Zero on success with \a st populated or less than zero on failure
	  */
	int stat(
			const arg::SourceFilePath path /*! The path to the target device file */,
			struct link_stat & st /*! A pointer to the destination structure */
			);

	/*!
	  * \details Closes an open file descriptor
	  * \param fd File descriptor to close
	  * \return Zero on success
	  */
	int close(const arg::FileDescriptor fd);

	/*! \details Sends a signal to the specified process.
	  *
	  * \param pid Process ID
	  * \param signo Signal number
	  *
	  * \return Zero on success or less than zero on error
	  */
	int kill_pid(int pid, int signo);

	/*! \details Gets the PID of the specified application name.
	  *
	  * @param name The name of the application to find the pid
	  * @return The PID or -1 if the application is not currently running
	  */
	int get_pid(
			const arg::Name & name
			){
		return get_is_executing(name);
	}

	/*! \details Resets the device (connection will be terminated).
	  *
	  * \return Zero on success or less than zero on error
	  */
	int reset();

	/*! \details Resets the device and invokes the bootloader.
	  *
	  * \return Zero on success or less than zero on error
	  *
	  * The connection to the device is terminated with this call.
	  *
	  */
	int reset_bootloader();

	int write_flash(int addr, const void * buf, int nbyte);
	int read_flash(int addr, void * buf, int nbyte);
	int get_bootloader_attr(bootloader_attr_t & attr);

	/*! \details Reads the time from
	  * the device.
	  *
	  * \return Zero on success
	  *
	  */
	int get_time(struct tm * gt);

	/*! \details This function sets the time on the device.
	  * \return Zero on success
	  */
	int set_time(struct tm * gt);

	/*! \details Renames a file.
	  *
	  * \param old_path Path to the old file (current path)
	  * \parm new_path New path where old_path will be
	  *
	  * \return Zero on success
	  */
	int rename(
			const arg::SourceFilePath old_path,
			const arg::DestinationFilePath new_path
			);

	/*! \details Changes the ownership of a file.
	  * \return Zero on success.
	  *
	  * \note Ownership is not supported on all filesystems.
	  *
	  */
	int chown(
			const arg::SourceFilePath path,
			const arg::OwnerId owner,
			const arg::GroupId group
			);

	/*! \details Changes the mode of a file.
	  * \return Zero on success.
	  *
	  * \note Ownership is not supported on all filesystems.
	  */
	int chmod(
			const arg::SourceFilePath path,
			const fs::Permissions & permissions
			);

	/*! \details Checks to see if a process called \a name is running.
	  *
	  * \param name Name of the application to check
	  *
	  * \return The pid of the running process or -1 if no processes match the name
	  */
	int get_is_executing(
			const arg::Name & name
			);

	/*!
	  * \details Updates the operating system.
	  *
	  * \param path Path to the new binary image on the host.
	  * \param verify true to read back the installation
	  * \param update Callback to execute as update is in progress
	  * \param context Argument to pass to the update callback
	  * \return Zero on success
	  *
	  * The host must be connected to the target bootloader
	  * before calling this method.
	  *
	  */
	int update_os(const arg::SourceFile image,
					  const arg::IsVerify is_verify,
					  const ProgressCallback * progress_callback = 0,
					  const arg::BootloaderRetryCount bootloader_retry_total = arg::BootloaderRetryCount(20)
			);

	int update_os(const arg::SourceFile image,
					  const arg::IsVerify is_verify,
					  arg::ProgressPrinter progress_printer,
					  const arg::BootloaderRetryCount bootloader_retry_total = arg::BootloaderRetryCount(20)
			);

	/*! \details Returns the driver needed by other API objects.
	  *
	  * Other objects need the link driver in order to operate correctly.
	  * If the driver is not provided, the program will crash.
	  *
	  * Consider the following example:
	  *
	  * \code
	  * #include <sapi/sys.hpp>
	  *
	  * Link link;
	  *
	  * link.connect("path_to_device", "serial_number");
	  *
	  * File file(link.driver()); //allows File to open a file on the target using this link driver
	  * File crash_file; //any operations use this will cause the program to crash
	  *
	  * \endcode
	  *
	  */
	link_transport_mdriver_t * driver() const { return m_driver; }

	/*! \details Assigns the driver options to the link driver.
	 *
	 */
	void set_driver_options(const void * options){
		if( m_driver ){
			m_driver->options = options;
		} else {
			m_error_message = "driver is null";
		}
	}

	/*! \details Sets the driver used by this object.
	  *
	  * If no driver is set, the default driver (serial port) is used.
	  *
	  */
	void set_driver(arg::ImplicitLinkDriver driver){
		m_driver = driver.argument();
	}

	void set_progress(int p){ m_progress = p; }
	void set_progress_max(int p){ m_progress_max = p; }


	/*! details Updates a binary app with the specified settings.
	  *
	  * @param file The binary image to modify
	  * @param attributes The attributes to apply
	  * @return Zero on success or -1 with error() set to an appropriate message
	  */
	int update_binary_install_options(arg::DestinationFile destination,
			const AppfsFileAttributes & attributes);

	/*! \details Installs a binary to the specified location.
	  *
	  * @param source The source of the binary file
	  * @param dest The location to install the file (directory)
	  * @param update A callback to update the caller on the progress of the install
	  * @param context First argument passed to \a update
	  * @return Zero on success or -1 with error() set to an appropriate message
	  *
	  * To install i nthe MCU RAM or flash, use /app as
	  * the \a dest value. The binary will be install in either /app/flash
	  * or /app/RAM depending on the binary installation flags.
	  *
	  * The application can be installed in an embedded filesystem such as
	  * /home but will then need to be installed by target device before
	  * it can be executed.
	  *
	  */
	int install_app(
			const arg::SourceFile source,
			const arg::DestinationDirectoryPath path,
			const arg::DestinationFileName name,
			const ProgressCallback * progress_callback = 0
			);

	/*! \details Returns the serial number of the last device
	  * that was connected (including the currently connected device)
	  * @return A string containing the serial number of the last connected (or currently connected) device
	  */
	const var::String & serial_number() const { return m_link_info.serial_number(); }
	const var::String & serial_no() const { return serial_number(); }

	/*! \details The path of the currently connected (or last connected) device */
	const var::String & path() const { return m_link_info.port(); }

	/*! \details The path of the currently connected (or last connected) notify device */
	const var::String & notify_path() const { return m_notify_path; }

	/*! \details Returns a copy of the system info for the
	  * connected device.
	  *
	  * Each time a device is connected, the system information
	  * is loaded. This object keeps a copy.
	  *
	  */
	const sys::SysInfo & sys_info() const { return m_link_info.sys_info(); }

	const LinkInfo & info() const { return m_link_info; }


private:
	var::String m_notify_path;
	var::String m_error_message;
	int m_stdout_fd;
	int m_stdin_fd;
	volatile int m_progress;
	volatile int m_progress_max;
	volatile int m_lock;
	bool m_is_bootloader;
	bool m_is_legacy;

	LinkInfo m_link_info;
	bootloader_attr_t m_bootloader_attributes;


	link_transport_mdriver_t m_driver_instance;
	link_transport_mdriver_t * m_driver;


	u32 validate_os_image_id_with_connected_bootloader(
			const arg::SourceFile image
			);

	int erase_os(
			arg::ProgressPrinter progress_printer,
			const arg::BootloaderRetryCount bootloader_retry_total = arg::BootloaderRetryCount(20)
			);

	int install_os(const arg::SourceFile image,
			const arg::IsVerify is_verify,
			const arg::HardwareId image_id,
			arg::ProgressPrinter progress_printer
			);

	int check_error(int err);
	void reset_progress();

};

}

#endif // SAPI_SYS_LINK_HPP_
