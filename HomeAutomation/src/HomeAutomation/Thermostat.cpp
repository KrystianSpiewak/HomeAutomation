/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the Thermostat class that inherits from the SmartAppliance class.
 * Dependencies: "ha_pch.h", "Thermostat.h"
 */

#include "ha_pch.h"
#include "Thermostat.h"

namespace HomeAutomation {

	void Thermostat::SetTemperature(double temperature)
	{
		// TODO: Handle exceptions for invalid temperature values
		m_Temperature = temperature;
	}

	void Thermostat::SetCurrentTemp(double currentTemp)
	{
		// TODO: Handle exceptions for invalid currentTemp values
		m_CurrentTemp = currentTemp;
	}

	double Thermostat::GetTemperature() const
	{
		return m_Temperature;
	}

	double Thermostat::GetCurrentTemp() const
	{
		return m_CurrentTemp;
	}

	void Thermostat::PrintStatus()
	{
		std::cout << "Thermostat Status: " << std::endl;
		std::cout << "Name: " << GetName() << std::endl;
		std::cout << "Brand: " << GetBrand() << std::endl;
		std::cout << "Model: " << GetModel() << std::endl;
		std::cout << "Network Address: " << GetNetAddr() << std::endl;
		std::cout << "Temperature: " << GetTemperature() << std::endl;
		std::cout << "Current Temperature: " << GetCurrentTemp() << std::endl;
	}

} // namespace HomeAutomation
