#pragma once
#include "electrical_device_utils.h"

//klasa przechowujaca liste urzadzen elektrycznych i pozwalajaca na wykonywanioe operacji na nich
class ElectricalDevicesUtils
{
private:
	std::vector <std::unique_ptr<ElectricalDevice>> devices;
public:
	ElectricalDevicesUtils() = default;
	ElectricalDevicesUtils(const std::string& file_name);

	//for uniques
	ElectricalDevicesUtils(const ElectricalDevicesUtils& device_utils);
	ElectricalDevicesUtils(ElectricalDevicesUtils&& device_utils) noexcept;
	ElectricalDevicesUtils operator=(const ElectricalDevicesUtils& device);
	ElectricalDevicesUtils& operator=(ElectricalDevicesUtils&& device) noexcept;
	//------------//

	ElectricalDevicesUtils final_price();//zwraca wartosc urzadzenia po uwzglednieniu czasu pracy i aktywnosci na godzine
	std::map<std::string,double> power_use();//zwraca ile dane urzadzenie zuzylo mocy
	friend std::ostream& operator<<(std::ostream & out, const ElectricalDevicesUtils& device);
};

