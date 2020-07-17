#pragma once
#include "validator.h";
#include "device.h";
class DeviceValidator:public Validator<Device>
{
private:
	static bool is_name_valid(const std::string& name);
	static bool is_price_valid(const double& price);
	static bool is_work_hours_valid(const int& work_hours);
	
public:
	std::unordered_map<std::string, std::string> validator(const Device& device)override;
	DeviceValidator() = default;
	~DeviceValidator() = default;
	
	friend std::ostream& operator<<(std::ostream& out, const DeviceValidator& val);
};

