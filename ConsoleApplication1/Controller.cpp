#include "Controller.hpp"
#include "AutomationRule.hpp"
#include <iostream>

Controller::Controller(std::string name, double params)
	: m_name(name),
	m_rule (name, params)
{
	std::cout << "Controller created: " << m_name << '\n';
}

Controller::~Controller()
{
	std::cout << "Controller deleted: " << m_name << '\n';
}

bool Controller::AddDevice(Device& device)
{
	if (m_devicesCount >= MAX_DEVICES)
	{
		std::cout << "Maximum exceeded.\n";
		return false;
	}
	for (std::uint32_t i = 0; i < m_devicesCount; ++i)
	{
		if (m_devices[i] == &device)
		{
			std::cout << "This device is already here.\n";
			return false;
		}
	}
	m_devices[m_devicesCount] = &device;
	++m_devicesCount;

	std::cout << "Device " << device.GetName() << " added.\n";

	return true;
}

bool Controller::RemoveDevice(Device& device)
{
	for (std::uint32_t i = 0; i < m_devicesCount; ++i)
	{
		if (m_devices[i] == &device)
		{
			for (std::uint32_t j = i; j + 1 < m_devicesCount; ++j)
			{
				m_devices[j] = m_devices[j + 1];
			}

			m_devices[m_devicesCount - 1] = nullptr;
			--m_devicesCount;

			std::cout << "Device " << device.GetName() << " removed.\n";

			return true;
		}
	}

	std::cout << "Device not found here.\n";
	return false;
}

bool Controller::TurnOnDevice(Device& device) {
	for (std::uint32_t i = 0; i < m_devicesCount; ++i)
	{
		if (m_devices[i] == &device)
		{
			if (device.IsOn()) {
				std::cout << "Device " << device.GetName() << " was already turned on. \n";
				return true;
			}

			if (m_rule.CheckFreePowerToTurnOn(device, GetTotalPower())) {
				device.TurnOn();
				std::cout << "Device " << device.GetName() << " turned on. \n";
				return true;	
			}

			else std::cout << "Device " << device.GetName() << " not turned on. \n";
			return false;
		}
	}
	std::cout << "Device " << device.GetName() << " not found here. \n";
	return false;
}

bool Controller::TurnOffDevice(Device& device) {
	for (std::uint32_t i = 0; i < m_devicesCount; ++i)
	{
		if (m_devices[i] == &device)
		{
			if (!device.IsOn()) {
				std::cout << "Device " << device.GetName() << " was already turned off. \n";
				return true;
			}
			device.TurnOff();
			std::cout << "Device " << device.GetName() << " turned off. \n";
			return true;
		}
	}
	std::cout << "Device " << device.GetName() << " not found here. \n";
	return false;
}
double Controller::GetTotalPower() const{
	double TotalPower = 0;
	for (std::uint32_t i = 0; i < m_devicesCount; ++i)
	{
		if (m_devices[i]->IsOn()) {
			TotalPower += m_devices[i]->GetPower();
		}
	}
	return TotalPower;
}

void Controller::PrintAllDevices() {
	std::cout << "Devices list: \n";
	for (std::uint32_t i = 0; i < m_devicesCount; ++i) {
		std::cout << "Device " << i << " Name: " << m_devices[i]->GetName() << " Power: " << m_devices[i]->GetPower() << '\n';
	}
}

void Controller::PrintConfig() {
	m_rule.PrintConfig();
}