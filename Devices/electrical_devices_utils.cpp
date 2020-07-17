#include "electrical_devices_utils.h"

ElectricalDevicesUtils::ElectricalDevicesUtils(const std::string& file_name)
{
	this->devices = ElectricalDeviceUtils::read_electrical_devices_from_file(file_name);
}


ElectricalDevicesUtils::ElectricalDevicesUtils(const ElectricalDevicesUtils& device_utils)
{
	for (auto& i : device_utils.devices)
	{
		this->devices.emplace_back(std::make_unique<ElectricalDevice>(*i));
	}
}

ElectricalDevicesUtils::ElectricalDevicesUtils(ElectricalDevicesUtils&& device_utils) noexcept
{
	this->devices = std::move(device_utils.devices);
}

ElectricalDevicesUtils ElectricalDevicesUtils::operator=(const ElectricalDevicesUtils& device)
{
	if (this != &device)
	{
		for (const auto& i : device.devices)
		{
			this->devices.emplace_back(std::make_unique<ElectricalDevice>(*i));
		}
	}
	return *this;
}

ElectricalDevicesUtils& ElectricalDevicesUtils::operator=(ElectricalDevicesUtils&& device) noexcept
{
	if (this != &device)
	{
		this->devices = std::move(device.devices);
	}
	return *this;
}

ElectricalDevicesUtils ElectricalDevicesUtils::final_price()
{
	for (auto& i : this->devices)
	{
		const auto start_price = i->price;
		if (i->active_time >= 0.75)
		{
			i->price -= (start_price * (0.00105)) * i->work_hours;
			
		}
		else if (i->active_time >= 0.5)
		{
			i->price -= (start_price * (0.00102)) * i->work_hours;
	
		}
		else {
		i->price -= (start_price * (0.001)) * i->work_hours;
		}
		if (i->price < start_price / 2 && category_to_str(i->category) == "A")
		{
			i->price = start_price / 2;
		}
		else if (i->price <= start_price / 2 && category_to_str(i->category) == "B")
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

std::map<std::string, double> ElectricalDevicesUtils::power_use()
{
	std::map<std::string, double> power_use;
	for(const auto& i:this->devices)
	{
		power_use.emplace(std::make_pair(i->name,i->power*i->active_time*i->work_hours/1000));
	}
	
	return power_use;
}


std::ostream& operator<<(std::ostream& out, const ElectricalDevicesUtils& device)
{
	for (const auto& i : device.devices)
	{
		out << *i << std::endl;
	}
	return out;
}
