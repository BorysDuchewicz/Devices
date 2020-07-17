#include "electrical_devices_validator.h"

bool ElectricalDevicesValidator::is_power_valid(const int& power)
{
	return power > 0;
}

bool ElectricalDevicesValidator::is_active_time_valid(const double& active_time)
{
	return active_time > 0 && active_time < 1;
}

std::unordered_map<std::string, std::string> ElectricalDevicesValidator::validator(
	const ElectricalDevice& electrical_device)
{
	errors.clear();
	DeviceValidator device_validator;
	device_validator.validator(Device{ electrical_device.name,electrical_device.price,electrical_device.work_hours,electrical_device.category });

	if(!is_power_valid(electrical_device.power))
	{
		errors.emplace(std::make_pair("Power is not valid ", std::to_string(electrical_device.power)));
	}
	if(!is_active_time_valid(electrical_device.active_time))
	{
		errors.emplace(std::make_pair("Price is not valid ", std::to_string(electrical_device.active_time)));
	}

	return errors;
}

std::ostream& operator<<(std::ostream& out, const ElectricalDevicesValidator& val)
{
	for (const auto& car : val.errors)
	{
		out << car.first << " " << car.second << std::endl;
	}
	return out;
}
