/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the VacuumRobot class that inherits from the SmartAppliance class.
 * Dependencies: "ha_pch.h", "VacuumRobot.h"
 */

#include "ha_pch.h"
#include "VacuumRobot.h"

namespace HomeAutomation {

	void VacuumRobot::ToggleOnOff()
	{
		m_isOn = !m_isOn;
	}

	bool VacuumRobot::IsOn() const
	{
		return m_isOn;
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
}