#pragma once
#include "device.h"

//klasa sluzaca do wczytywania informacji o urzadzeniach
class DeviceUtils final
{
public:
	static std::vector<std::unique_ptr<Device>> read_devices_from_file(const std::string& file_name);

	DeviceUtils() = delete;
	~DeviceUtils() = delete;
	
};

