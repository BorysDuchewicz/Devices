#include "device_validator.h"

bool DeviceValidator::is_name_valid(const std::string& name)
{
	return std::regex_match(name, std::regex("[A-Za-z]+[ ]*[A-Za-z]*"));
}

bool DeviceValidator::is_price_valid(const double& price)
{
	return price > 0;
}

bool DeviceValidator::is_work_hours_valid(const int& work_hours)
{
	return work_hours > 0;
}

std::unordered_map<std::string, std::string> DeviceValidator::validator(const Device& device)
{
	errors.clear();
	if(!is_name_valid(device.name))
	{
		errors.emplace(std::make_pair("Name is not valid ", device.name));
	}
	if(!is_price_valid(device.price))
	{
		errors.emplace(std::make_pair("Price is not valid ",std::to_string(device.price)));
	}
	if(!is_work_hours_valid(device.work_hours))
	{
		errors.emplace(std::make_pair("Work hours are not valid ",std::to_string(device.work_hours)));
	}

	return errors;
}

std::ostream& operator<<(std::ostream& out, const DeviceValidator& val)
{
	for (const auto& car : val.errors)
	{
		out << car.first << " " << car.second << std::endl;
	}
	return out;
}
