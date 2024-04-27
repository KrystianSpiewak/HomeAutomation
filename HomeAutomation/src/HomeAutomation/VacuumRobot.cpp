/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the VacuumRobot class that inherits from the SmartAppliance class.
 * Dependencies: "ha_pch.h", "VacuumRobot.h"
 *
 * Last modified: 04/26/2024
 * Added parametrized constructor for the VacuumRobot class.
 */

#include "ha_pch.h"
#include "VacuumRobot.h"

namespace HomeAutomation {

	VacuumRobot::VacuumRobot(const std::string& name, const std::string& brand, const std::string& model, const std::string& netAddr)
	{
		SetName(name);
		SetBrand(brand);
		SetModel(model);
		SetNetAddr(netAddr);
		m_isOn = false;
		m_BatteryLevel = 100;
	}

	void VacuumRobot::ToggleOnOff()
	{
		m_isOn = !m_isOn;
	}

	bool VacuumRobot::IsOn() const
	{
		return m_isOn;
	}

	void VacuumRobot::StartCleaning()
	{
		// dispatch a message to the vacuum robot to start cleaning
		std::cout << "Vacuum Robot is starting to clean." << std::endl;
	}

	int VacuumRobot::GetBatteryLevel() const
	{
		return m_BatteryLevel;
	}

	void VacuumRobot::SetBatteryLevel(int batteryLevel)
	{
		// Handle exceptions for invalid batteryLevel values
		if (batteryLevel < 0 || batteryLevel > 100)
		{
			throw std::invalid_argument("Battery level must be between 0 and 100.");
		}
		m_BatteryLevel = batteryLevel;
	}

	void VacuumRobot::ReturnToBase()
	{
		// dispatch a message to the vacuum robot to return to the charging station
		std::cout << "Vacuum Robot is returning to the charging station." << std::endl;
	}

	void VacuumRobot::PrintStatus()
	{
		std::cout << "Vacuum Robot Status: " << std::endl;
		std::cout << "Is On: " << m_isOn << std::endl;
		std::cout << "Battery Level: " << m_BatteryLevel << std::endl;
	}

	std::string VacuumRobot::GetState()
	{
		std::string state = "Vacuum Robot State: ";
		state += "Name: " + GetName() + ", ";
		state += "Brand: " + GetBrand() + ", ";
		state += "Model: " + GetModel() + ", ";
		state += "Network Address: " + GetNetAddr() + ", ";
		state += "Is On: " + std::to_string(m_isOn) + ", ";
		state += "Battery Level: " + std::to_string(m_BatteryLevel) + "%";
		return state;
	}

}