/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the SmartAppliance abstract class that individual smart appliances will inherit from.
 * Dependencies: <string>
 * 
 * Last modified: 04/26/2024
 * Added default constructor and constructor with parameters.
 * Add GetState pure virtual method.
 */

#pragma once

#include <string>
#include <sstream>


namespace HomeAutomation {
	
	/**
	SmartAppliance class is an abstract class that individual smart appliances will inherit from.
	 */
	class SmartAppliance
	{
	public:
		/**
		Default constructor.
		*/
		SmartAppliance() = default;

		/**
		Constructor with parameters.
		*/
		SmartAppliance(const std::string& m_Name, const std::string& m_Brand, const std::string& m_Model, const std::string& m_NetAddr);


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
		Get state of the device.
		@return The string representing the device state.
		 */
		virtual std::string GetState() = 0;

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

		/**
		 Utility function to check if a string is a valid IP address.
		 @param ipAddress The IP address to check.
		 @return True if the IP address is valid, false otherwise.
		 */
		bool IsValidIPAddress(const std::string& ipAddress) {

			// Check if the IP address is empty
			if (ipAddress.empty()) {
				return false;
			}

			// Check if the IP address has 4 parts separated by '.'
			int count = 0;
			for (char c : ipAddress) {
				if (c == '.') {
					count++;
				}
			}

			if (count != 3) {
				return false;
			}

			// Check if each part of the IP address is a number between 0 and 255
			std::string part;
			int num;
			std::istringstream ss(ipAddress);
			while (std::getline(ss, part, '.')) {
				if (part.empty()) {
					return false;
				}
				num = std::stoi(part);
				if (num < 0 || num > 255) {
					return false;
				}
			}

			return true;
		}
	};


} // namespace HomeAutomation
