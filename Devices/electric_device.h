#pragma once
#include "device.h"


//structura przechowujaca elementy z device + dodatkowe tylko dla elektrycznych urzadzen
struct ElectricalDevice: public Device
{
	int power;
	double active_time;

	ElectricalDevice(const std::string& name, const double& price, const int& work_hours, const Category& category, const int& power, const double& active_time) :Device{ name, price, work_hours, category }, power{ power }, active_time{ active_time } {}
	ElectricalDevice() = default;
};
inline std::ostream& operator<<(std::ostream& out, const ElectricalDevice& device)
{
	return out <<"Nazwa: "<< device.name << "\nCena: " << device.price << "\nGodziny pracy: " << device.work_hours << "\nKategoria: " << category_to_str(device.category)<<"\nMoc: "<<device.power<<"\nDlugosc aktywnosci: "<<device.active_time<<std::endl;
}