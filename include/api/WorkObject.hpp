#ifndef API_WORK_OBJECT_HPP
#define API_WORK_OBJECT_HPP

#include "ApiObject.hpp"


namespace api {

class Result {
public:
	Result(int return_value = 0, int error_number = 0){
		m_return_value = return_value;
		m_error_number = error_number;
	}

	/*! \details Returns true if the return value is
	 * less than zero indicating an error condition.
	 */
	bool is_error() const { return m_return_value < 0; }

	/*! \details Returns the C errno value.
	 */
	int error_number() const { return m_error_number; }

	/*! \details Returns the return value associated with the result.
	 */
	int return_value() const { return m_return_value; }


	void set_error_number(int error_number){ m_error_number = error_number; }
	void set_return_value(int return_value){ m_return_value = return_value; }

private:
	int m_error_number;
	int m_return_value;
};

/*! \brief Work Object
 * \details The WorkObject is the base
 * object for all work classes in the Stratify API.
 *
 * It is a simple object that allows the
 * inheriting class to set an error or halt
 * the program if it encouters a fatal problem.
 *
 * It is used as the base of objects that make system
 * calls so that the error generated by the
 * system can be reported through the object.
 *
 * \sa api::InfoObject
 *
 *
 */
class WorkObject : public virtual ApiObject {

public:
	WorkObject();

	enum {
		ERROR_NONE /*! No Errors */
	};

	/*! \details Returns the error number.
	  *
	  * If the error number is zero. There is
	  * no error.
	  *
	  * If the error number is greater than zero. It indicates
	  * an error indicator from the standard C library (such as
	  * ENOENT).
	  *
	  * If the error number is zero or less, it
	  * refers to a StratifyAPI defined error like
	  * ERROR_NONE.
	  *
	  */
	int error_number() const { return m_result.error_number(); }

	/*! \details Returns the return value of the last operation.
	 */
	int return_value() const { return m_result.return_value(); }

	/*! \details Returns a referenct to the result of the last
	 * operation.
	 */
	const Result & result() const { return m_result; }

	//assert?

	//some way to fatal
	static void exit_fatal(const char * message);

	/*! \details Clears the current result.
	  */
	void clear_result() const { m_result = Result(); }
	void clear_error_number() const { m_result = Result(); }

protected:
	//These methods are used internally to assign the error_number() value
	int set_error_number_if_error(int result) const;
	void * set_error_number_if_null(void * ret) const;
	void set_error_number_to_errno() const;
	void set_error_number(int value) const {
		m_result.set_error_number(value);
	}

private:
	mutable Result m_result;
};


}
#endif // API_WORK_OBJECT_HPP
