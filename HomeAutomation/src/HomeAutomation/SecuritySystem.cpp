/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the SecuritySystem class that inherits from the SmartAppliance class.
 * Dependencies: "ha_pch.h", "SecuritySystem.h"
 */

#include "ha_pch.h"
#include "SecuritySystem.h"

namespace HomeAutomation {

	void SecuritySystem::ArmSystem()
	{
		m_isArmed = true;
	}

	void SecuritySystem::DisarmSystem()
	{
		m_isArmed = false;
	}

	bool SecuritySystem::IsArmed() const
	{
		return m_isArmed;
	}

	void SecuritySystem::TriggerAlarm()
	{
		m_isAlarmActive = true;
	}

	bool SecuritySystem::IsAlarmActivated()
	{
		return m_isAlarmActive;
	}

	void SecuritySystem::PrintStatus()
	{
		std::cout << "Security System Status: " << std::endl;
		std::cout << "Is Armed: " << m_isArmed << std::endl;
		std::cout << "Is Alarm Active: " << m_isAlarmActive << std::endl;
	}

} // namespace HomeAutomation
