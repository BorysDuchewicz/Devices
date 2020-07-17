#pragma once
#include "libs.h"

//struktura przechowujaca informacje o urzadzeniu
struct Device
{
	std::string name;
	double price;
	int work_hours;
	Category category;
	Device() = default;
	Device(const std::string& name, const double& price, const int& work_hours, const Category& category) :name{ name }, price{ price }, work_hours{ work_hours }, category{ category } {}
};

inline std::ostream& operator<<(std::ostream& out, const Device& device)
{
	return out <<"Nazwa: "<< device.name << "\nCena: " << device.price << "\nGodziny pracy: " << device.work_hours << "\nKategoria: " <<category_to_str(device.category);
}