#include "Device.hpp"
#include <iostream>

Device::Device(std::string name, double power)
	:m_name{ name },
	m_power { power }
{
	std::cout << "Device created: " << m_name << ", Power: " << m_power <<'\n';
}

Device::~Device() {
	std::cout << "Device deleted: " << m_name << ", Power: " << m_power <<'\n';
}