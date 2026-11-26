#pragma once
#include <string>
#include "AutomationRule.hpp"
#include "Device.hpp"
class Controller
{
private:
	static constexpr std::size_t MAX_DEVICES = 10;
	std::string m_name{};
	AutomationRule m_rule;
	Device* m_devices[MAX_DEVICES] {};
	std::uint32_t m_devicesCount{};
public:
	Controller() = delete;
	Controller(std::string name, double params);
	~Controller();
	bool AddDevice(Device& device);
	bool RemoveDevice(Device& device);
	bool TurnOnDevice(Device& device);
	bool TurnOffDevice(Device& device);
	void PrintAllDevices();
	void PrintConfig();
	double GetTotalPower() const;
};

