#pragma once
#include "device_utils.h"
//klasa przechowujaca liste urzadzen i pozwalajaca na wykonywanioe operacji na nich
class DevicesUtils
{
private:
	std::vector <std::unique_ptr<Device>> devices;
public:
	DevicesUtils() = default;
	DevicesUtils(const std::string& file_name);

	//konstruktory przenoszace i kopiujace aby wygodniej operowac na unique ptr
	DevicesUtils(const DevicesUtils& device_utils);
	DevicesUtils(DevicesUtils&& device_utils) noexcept;	
	DevicesUtils operator=(const DevicesUtils& device);
	DevicesUtils& operator=(DevicesUtils&& device) noexcept;
	//------------//

	DevicesUtils final_price();
	
	friend std::ostream& operator<<(std::ostream& out, const DevicesUtils& device);
};

