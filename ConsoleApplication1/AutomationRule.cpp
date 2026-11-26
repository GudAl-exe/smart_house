#include "AutomationRule.hpp"
#include "Controller.hpp"
#include <iostream>

AutomationRule::AutomationRule(std::string name, double maxpower)
	: m_name { name }, 
	m_maxpower { maxpower }
{
	std::cout << "Automation rule created: " << m_name << '\n';
}

AutomationRule::~AutomationRule()
{
	std::cout << "Automation rule deleted: " << m_name << '\n';
}

bool AutomationRule::CheckFreePowerToTurnOn(Device& device, double totalpower) const
{
	if (device.GetPower() + totalpower > m_maxpower) {
		return false;
	}
	return true;
}

void AutomationRule::PrintConfig() {
	std::cout << "Current config\nName: " << m_name << '\n' << "Max power: " << m_maxpower << '\n';
}