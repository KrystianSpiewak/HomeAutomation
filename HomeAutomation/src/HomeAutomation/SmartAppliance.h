/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the SmartAppliance abstract class that individual smart appliances will inherit from.
 * Dependencies: <string>
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
		Method to set the name of the appliance.
		 */
		void SetName(std::string name);

		/**
		Method to set the brand of the appliance.
		 */
		void SetBrand(std::string brand);

		/**
		Method to set the model of the appliance.
		 */
		void SetModel(std::string model);

		/**
		Method to set the network address of the appliance.
		 */
		void SetNetAddr(std::string netAddr);

		/**
		Virtual method to print the appliance status.
		 */
		virtual void PrintStatus() = 0;

		/**
		Method to get the name of the appliance.
		@return The name of the appliance.
		 */
		std::string GetName();

		/**
		Method to get the brand of the appliance.
		@return The brand of the appliance.
		 */
		std::string GetBrand();

		/**
		Method to get the model of the appliance.
		@return The model of the appliance.
		 */
		std::string GetModel();

		/**
		Method to get the network address of the appliance.
		@return The network address of the appliance.
		 */
		std::string GetNetAddr();

	private:
		
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
