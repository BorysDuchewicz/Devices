#pragma once
#include "electric_device.h"
#include "device_validator.h"
class ElectricalDevicesValidator :
	public Validator<ElectricalDevice>
{
	private:
		static bool is_power_valid(const int& power);
		static bool is_active_time_valid(const double& active_time);
public:
	std::unordered_map<std::string, std::string> validator(const ElectricalDevice& electrical_device)override;
	ElectricalDevicesValidator() = default;
	~ElectricalDevicesValidator() = default;

	friend std::ostream& operator<<(std::ostream& out, const ElectricalDevicesValidator& val);
};

