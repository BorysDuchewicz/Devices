#pragma once

#include "electric_device.h"

//klasa sluzaca do odczytania informacji z pliku json
class ElectricalDeviceUtils final
{
public:
	static std::vector<std::unique_ptr<ElectricalDevice>> read_electrical_devices_from_file(const std::string& file_name);

	ElectricalDeviceUtils() = delete;
	~ElectricalDeviceUtils() = delete;

};

