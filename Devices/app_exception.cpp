#include "app_exception.h"

AppException::AppException(const std::string& message):message{message}
{}

std::string AppException::error_message() const
{
	return message + " try again";
}
