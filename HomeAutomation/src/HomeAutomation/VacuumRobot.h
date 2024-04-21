/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the VacuumRobot class that inherits from the SmartAppliance class.
 * Dependencies:SmartAppliance.h
 */

#pragma once

#include "SmartAppliance.h"

namespace HomeAutomation {
	/**
		VacuumRobot class inherits from the SmartAppliance class and represents a vacuum robot smart appliance.
			 */
	class VacuumRobot : public SmartAppliance
	{
		public:

		/**
		Toggles the vacuum robot on or off.
		 */
		void ToggleOnOff();

		/**
		Method to get the power status of the vacuum robot.
		 */
		bool IsOn() const;

		/**
		Method to get the battery level of the vacuum robot.
		 */
		int GetBatteryLevel() const;

		/**
		Method to set the battery level of the vacuum robot.
		@param batteryLevel The battery level to set.
		 */
		void SetBatteryLevel(int batteryLevel);

		/**
		 Method to return the robot to the charging station.
		 */
		void ReturnToBase();

		/**
		Method to print the status of the vacuum robot.
		 */
		void PrintStatus();

		private:
			/**
			Flag to indicate if the vacuum robot is on or off.
			 */
			bool m_isOn = false;

			/**
			The battery level of the vacuum robot.
			 */
			int m_BatteryLevel = 100;
	};
}
