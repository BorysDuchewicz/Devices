#include "electrical_device_utils.h"
#include "electrical_devices_validator.h"
std::vector<std::unique_ptr<ElectricalDevice>> ElectricalDeviceUtils::read_electrical_devices_from_file(
	const std::string& file_name)
{

	std::vector<std::unique_ptr<ElectricalDevice>> device_utils;
	ElectricalDevicesValidator validator;
	std::ifstream reader;

	reader.open(file_name + ".json");

	if (reader.is_open())
	{
		json j;
		reader >> j;
		for (const auto& devices : j)
		{
			ElectricalDevice device;

			device.name = devices["name"].get<std::string>();

			device.price = devices["price"].get<double>();

			device.work_hours = devices["work_hours"].get<int>();

			std::string category = devices["category"].get<std::string>();
			device.category = str_to_category(category);

			device.power = devices["power"].get<int>();
			device.active_time = devices["active_time"].get<double>();
			
			if (validator.validator(device).empty())
			{
				device_utils.emplace_back(std::make_unique<ElectricalDevice>(device));
			}
			else
			{
				std::cout << validator << std::endl;
			}
		}
		reader.close();
	}
	else
	{
		std::cout << "Reader error" << std::endl;
	}
	return device_utils;
}
