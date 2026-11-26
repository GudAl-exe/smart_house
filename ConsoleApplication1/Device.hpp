#pragma once
#include <string>
class Device
{
private:
	std::string m_name{};
	double m_power{};
	bool m_isOn{};
public:
	Device(std::string name, double power);
	Device() = delete;
	~Device();
	void TurnOn() {
		m_isOn = true;
	}
	void TurnOff() {
		m_isOn = false;
	}
	std::string GetName() const {
		return m_name;
	}
	double GetPower() const {
		return m_power;
	}
	bool IsOn() const {
		return m_isOn;
	}
};