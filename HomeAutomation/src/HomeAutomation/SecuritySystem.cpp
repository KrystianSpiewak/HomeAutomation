/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the SecuritySystem class that inherits from the SmartAppliance class.
 * Dependencies: "ha_pch.h", "SecuritySystem.h"
 * 
 * Last modified: 04/26/2024
 * Added constructor for the SecuritySystem class.
 */

#include "ha_pch.h"
#include "SecuritySystem.h"

namespace HomeAutomation {

	SecuritySystem::SecuritySystem(const std::string& name, const std::string& brand, const std::string& model, const std::string& netAddr)
	{
		SetName(name);
		SetBrand(brand);
		SetModel(model);
		SetNetAddr(netAddr);
	}

	void SecuritySystem::ArmSystem()
	{
		if (m_isAlarmActive)
		{
			std::cout << "Cannot arm the system while the alarm is active." << std::endl;
			return;
		}
		m_isArmed = true;
	}

	void SecuritySystem::DisarmSystem()
	{
		if (m_isAlarmActive)
		{
			std::cout << "Cannot disarm the system while the alarm is active." << std::endl;
			return;
		}
		m_isArmed = false;
	}

	bool SecuritySystem::IsArmed() const
	{
		return m_isArmed;
	}

	void SecuritySystem::TriggerAlarm()
	{
		if (!m_isArmed)
		{
			std::cout << "Cannot trigger the alarm while the system is disarmed." << std::endl;
			return;
		}
		m_isAlarmActive = true;
	}

	bool SecuritySystem::IsAlarmActivated() const
	{
		// Temporary output for testing purposes
		if (m_isAlarmActive)
		{
			std::cout << "Alarm is active!" << std::endl;
		}
		else
		{
			std::cout << "Alarm is not active." << std::endl;
		}
		return m_isAlarmActive;
	}

	void SecuritySystem::PrintStatus()
	{
		std::cout << "Security System Status: " << std::endl;
		std::cout << "Is Armed: " << m_isArmed << std::endl;
		std::cout << "Is Alarm Active: " << m_isAlarmActive << std::endl;
	}

} // namespace HomeAutomation
