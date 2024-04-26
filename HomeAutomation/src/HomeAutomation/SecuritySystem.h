/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the SecuritySystem class that inherits from the SmartAppliance class.
 * Dependencies: SmartAppliance.h
 * 
 * Last modified: 04/26/2024
 * Added constructor for the SecuritySystem class.
 */

#pragma once

#include "SmartAppliance.h"

namespace HomeAutomation {

	class SecuritySystem : public SmartAppliance
	{
	public:
		/**
		 Constructor for the SecuritySystem class.
		@param name The name of the security system.
		@param brand The brand of the security system.
		@param model The model of the security system.
		@param netAddr The network address of the security system.
		*/
		SecuritySystem(const std::string& name, const std::string& brand, const std::string& model, const std::string& netAddr);

		/**
		 Method to arm the security system.
		 */
		void ArmSystem();

		/**
		Method to disarm the security system.
		 */
		void DisarmSystem();

		/**
		Method to check if the security system is on.
		 */
		bool IsArmed() const;

		/**
		 Method to trigger the alarm.
		 */
		void TriggerAlarm();

		/**
		Method to check if the alarm is activated.
		@return True if the alarm is activated, false otherwise.
		*/
		bool IsAlarmActivated() const;

		/**
		Method to print the status of the security system.
		*/
		void PrintStatus();

	private:
		/**
		 Flag to indicate if the security system is armed.
		 */
		bool m_isArmed{ false };
		/**
		 Flag to indicate if the alarm is active.
		 */
		bool m_isAlarmActive{ false };
	};

} // namespace HomeAutomation