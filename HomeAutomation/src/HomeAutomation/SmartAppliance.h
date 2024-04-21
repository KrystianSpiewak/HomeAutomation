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
		 Virtual method to set the name of the appliance.
		 */
		virtual void SetName(std::string name) = 0;

		/**
		 Virtual method to set the brand of the appliance.
		 */
		virtual void SetBrand(std::string brand) = 0;

		/**
		 Virtual method to set the model of the appliance.
		 */
		virtual void SetModel(std::string model) = 0;

		/**
		Virtual method to set the network address of the appliance.
		 */
		virtual void SetNetAddr(std::string netAddr) = 0;

		/**
		Virtual method to turn the appliance on or off.
		*/
		virtual void ToggleOnOff() = 0;

		/**
		Virtual method to get the boolean representing the power status of the appliance.
		@return True if the appliance is on, false if it is off.
		 */
		virtual bool IsOn() = 0;

		/**
		Virtual method to print the appliance status.
		 */
		virtual void PrintStatus() = 0;

		/**
		Virtual method to get the name of the appliance.
		@return The name of the appliance.
		 */
		virtual std::string GetName() = 0;

		/**
		Virtual method to get the brand of the appliance.
		@return The brand of the appliance.
		 */
		virtual std::string GetBrand() = 0;

		/**
		Virtual method to get the model of the appliance.
		@return The model of the appliance.
		 */
		virtual std::string GetModel() = 0;

		/**
		Virtual method to get the network address of the appliance.
		@return The network address of the appliance.
		 */
		virtual std::string GetNetAddr() = 0;

	private:
		/**
		Flag to indicate if the appliance is on or off.
		 */
		bool m_isOn{ false };

		/**
		Name of the appliance.
		 */
		std::string m_Name;

		/**
		Band of the appliance.
		 */
		std::string m_Brand;

		/**
		Model of the appliance.
		*/
		std::string m_Model;

		/**
		Network address of the appliance.
		*/
		std::string m_NetAddr;
	};

} // namespace HomeAutomation
