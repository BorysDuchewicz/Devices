#pragma once
#include <string>
#include <exception>


//klasa obslugi wyjatkow
class AppException
{
private:
	std::string message;
public:
	AppException(const std::string& message);

	std::string error_message()const;
};

