/*! \file */ //Copyright 2011-2017 Tyler Gilbert; All Rights Reserved


#include "sys/File.hpp"
#include "sys/FileInfo.hpp"

namespace sys {

#if defined __link
FileInfo::FileInfo(link_transport_mdriver_t * d){
	m_driver = d;
	memset(&m_stat, 0, sizeof(m_stat));
}

#else
FileInfo::FileInfo() {
	memset(&m_stat, 0, sizeof(m_stat));
}
#endif

int FileInfo::get_info(const char * path){

#if defined __link
	return File::stat(path, &m_stat, m_driver);
#else
	return File::stat(path, &m_stat);
#endif
}


bool FileInfo::is_dir() const {
	return (m_stat.st_mode & LINK_S_IFMT) == LINK_S_IFDIR;
}

bool FileInfo::is_file() const {
	return (m_stat.st_mode & LINK_S_IFMT) == S_IFREG;
}

bool FileInfo::is_device() const {
	return is_block_device() || is_char_device();

}

bool FileInfo::is_block_device() const {
	return (m_stat.st_mode & (LINK_S_IFMT)) == LINK_S_IFBLK;
}

bool FileInfo::is_char_device() const {
	return (m_stat.st_mode & (LINK_S_IFMT)) == LINK_S_IFCHR;
}

u32 FileInfo::size() const {
	return m_stat.st_size;
}

bool FileInfo::is_executable() const {
	return false;
}

} /* namespace sys */