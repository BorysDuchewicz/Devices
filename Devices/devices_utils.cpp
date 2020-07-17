#include "devices_utils.h"


DevicesUtils::DevicesUtils(const std::string& file_name)
{
	this->devices = DeviceUtils::read_devices_from_file(file_name);
}

DevicesUtils::DevicesUtils(const DevicesUtils& device_utils)
{
	for(auto& i:device_utils.devices)
	{
		this->devices.emplace_back(std::make_unique<Device>(*i));
	}
}

DevicesUtils::DevicesUtils(DevicesUtils&& device_utils) noexcept
{
	this->devices = std::move(device_utils.devices);
}

std::ostream& operator<<(std::ostream& out, const DevicesUtils& device)
{
	for(const auto& i:device.devices)
	{
		out <<*i<<std::endl;
	}
	return out;
}

DevicesUtils DevicesUtils::operator=(const DevicesUtils& device)
{
	if(this != &device)
	{
		for(const auto& i:device.devices)
		{
			this->devices.emplace_back(std::make_unique<Device>(*i));
		}
	}
	return *this;
}

DevicesUtils& DevicesUtils::operator=(DevicesUtils&& device) noexcept
{
	if (this != &device)
	{
		this->devices = std::move(device.devices);
	}
	return *this;
}

DevicesUtils DevicesUtils::final_price()
{
	for(auto& i:this->devices)
	{
		const auto start_price = i->price;
		i->price -= (i->price * (0.01))*i->work_hours;
		if(i->price<start_price/2 && category_to_str(i->category)=="A")
		{
			i->price = start_price / 2;
		}
		else if(i->price <= start_price / 2 && category_to_str(i->category) == "B")
		{
			i->price = start_price / 2 - start_price * 0.1;
		}
		else if (i->price <= start_price / 2 && category_to_str(i->category) == "C")
		{
			i->price = start_price / 2 - start_price * 0.15;
		}
	}
	return *this;
}
