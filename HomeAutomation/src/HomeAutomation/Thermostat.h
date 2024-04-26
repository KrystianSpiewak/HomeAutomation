/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the Thermostat class that inherits from the SmartAppliance class.
 * Dependencies: SmartAppliance.h
 */

#pragma once

#include "SmartAppliance.h"

namespace HomeAutomation {
	/**
	 Thermostat class inherits from the SmartAppliance class and represents a thermostat smart appliance.
	*/
	class Thermostat : public SmartAppliance
	{
	public:
		/**
		 Constructor for the Thermostat class.
		 @param name The name of the thermostat.
		 @param brand The brand of the thermostat.
		 @param model The model of the thermostat.
		 @param netAddr The network address of the thermostat.
		 */
		Thermostat(const std::string& name, const std::string& brand, const std::string& model, const std::string& netAddr);

		/**
		Set the temperature that the thermostat should maintain.
		@param temperature The temperature that the thermostat should maintain.
		 */
		void SetTemperature(double temperature);

		/**
		Set the current temperature measured by the thermostat.
		@param currentTemp The current temperature measured by the thermostat.
		 */

		void SetCurrentTemp(double currentTemp);

		/**
		 Get the temperature that the thermostat is set to maintain.
		@return The temperature that the thermostat is set to maintain.
		 */
		double GetTemperature() const;

		/**
		Get the current temperature measured by the thermostat.
		@return The current temperature measured by the thermostat.
		 */
		double GetCurrentTemp() const;

		/**
		Print the status of the thermostat.
		 */
		void PrintStatus() override;

	private:
		double m_Temperature;
		double m_CurrentTemp;
	};

} // namespace HomeAutomation
