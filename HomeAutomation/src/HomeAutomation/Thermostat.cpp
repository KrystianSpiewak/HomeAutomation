/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the Thermostat class that inherits from the SmartAppliance class.
 * Dependencies: "ha_pch.h", "Thermostat.h"
 * 
 * Last modified: 4/26/2024
 * Added exception handling for invalid temperature values.
 */

#include "ha_pch.h"
#include "Thermostat.h"

namespace HomeAutomation {

	Thermostat::Thermostat(const std::string& name, const std::string& brand, const std::string& model, const std::string& netAddr)
	{
		SetName(name);
		SetBrand(brand);
		SetModel(model);
		SetNetAddr(netAddr);

		// Set the default temperature to 70 degrees Fahrenheit
		SetTemperature(70);
		SetCurrentTemp(70);
	}

	void Thermostat::SetTemperature(double temperature)
	{
		// Handle exceptions for invalid temperature values
		if (temperature < 60 || temperature > 90)
		{
			throw std::invalid_argument("Invalid temperature value. Temperature must be between 60 and 90 degrees Fahrenheit.");
		}

		m_Temperature = temperature;
	}

	void Thermostat::SetCurrentTemp(double currentTemp)
	{
		// Handle exceptions for invalid currentTemp values
		if (currentTemp < 32 || currentTemp > 120)
		{
			throw std::invalid_argument("Invalid current temperature value. Current temperature must be between 32 and 120 degrees Fahrenheit.");
		}

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
