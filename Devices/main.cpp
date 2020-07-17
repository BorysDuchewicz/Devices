#include "electrical_devices_utils.h"

int main()
{
	try
	{
		ElectricalDevicesUtils d{ "devices" };
		std::cout << "Urzadzenia:" << std::endl;
		std::cout << d << std::endl;

		std::cout << "Zuzycie energii:" << std::endl;
		for (const auto& i : d.power_use())
		{
			std::cout << i.first << " " << i.second << "kWH" << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Wartosc koncowa urzadzen: " << std::endl;
		std::cout << d.final_price() << std::endl;
	}
	catch(const AppException& e)
	{
		std::cout << e.error_message() << std::endl;
	}

	return 0;
}  