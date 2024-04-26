/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the Light class that inherits from the SmartAppliance class.
 * Dependencies: "ha_pch.h", "Light.h"
 */

#include "ha_pch.h"
#include "Light.h"

namespace HomeAutomation {

	Light::Light(std::string name, std::string brand, std::string model, std::string netAddr)
	{
		SetName(name);
		SetBrand(brand);
		SetModel(model);
		SetNetAddr(netAddr);
	}

	void Light::ToggleOnOff()
	{
		m_isOn = !m_isOn;
	}

	bool Light::IsOn() const
	{
		return m_isOn;
	}

	int Light::GetBrightness() const
	{
		return m_Brightness;
	}

	void Light::SetBrightness(int brightness)
	{
		// Handle exceptions for invalid brightness values
		if (brightness < 10 || brightness > 100)
		{
			throw std::invalid_argument("Brightness level must be between 10 and 100.");
		}
		m_Brightness = brightness;
	}

	void Light::PrintStatus()
	{
		std::cout << "Light Status: " << std::endl;
		std::cout << "Is On: " << m_isOn << std::endl;
		std::cout << "Brightness: " << m_Brightness << std::endl;
	}

} // namespace HomeAutomation
