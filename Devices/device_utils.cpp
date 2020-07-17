#include "device_utils.h"
#include"device_validator.h"

std::vector<std::unique_ptr<Device>> DeviceUtils::read_devices_from_file(const std::string& file_name)
{
	std::vector<std::unique_ptr<Device>> device_utils;
	DeviceValidator validator{};
	std::ifstream reader;

	reader.open(file_name + ".json");

	if(reader.is_open())
	{
		json j;
		reader >> j;
		for(const auto& devices:j)
		{
			Device device;
			
			device.name = devices["name"].get<std::string>();
			
			device.price = devices["price"].get<double>();
			
			device.work_hours = devices["work_hours"].get<int>();
			
			std::string category = devices["category"].get<std::string>();
			device.category = str_to_category(category);
			

			
			if (validator.validator(device).empty())
			{
				device_utils.emplace_back(std::make_unique<Device>(device));
			}
			else
			{
				std::cout << validator<<std::endl;
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
