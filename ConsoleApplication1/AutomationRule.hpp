#pragma once
#include <string>
#include "Device.hpp"
class AutomationRule
{
private:
	std::string m_name{};
	double m_maxpower{};

public: 
	AutomationRule(std::string name, double maxpower);
	AutomationRule() = delete;
	~AutomationRule();
	bool CheckFreePowerToTurnOn(Device& device, double totalpower) const;
	void PrintConfig();
};

