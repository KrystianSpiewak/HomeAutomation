/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the SmartAppliance abstract class that individual smart appliances will inherit from.
 * Dependencies: None
 */

#pragma once

#include <string>


namespace HomeAutomation {
	
	/**
		 * SmartAppliance class is an abstract class that individual smart appliances will inherit from.
		 	 */
	class SmartAppliance
	{
	public:
		/**
		Turn the appliance on or off.
		*/
		virtual void TurnOnOff() = 0;

		/**
		Get the current status of the appliance.
		@return True if the appliance is on, false if it is off.
		 */
		virtual bool IsOn() = 0;

		/**
		Get the name of the appliance.
		@return The name of the appliance.
		 */
		virtual std::string GetName() = 0;
	};

} // namespace HomeAutomation
