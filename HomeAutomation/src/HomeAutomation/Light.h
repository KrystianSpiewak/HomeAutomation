/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the Light class that inherits from the SmartAppliance class.
 * Dependencies: SmartAppliance.h
 */

#pragma once

#include "SmartAppliance.h"

namespace HomeAutomation {

	class Light : public SmartAppliance
	{
	public:
		/**
		Default constructor.
		@param name The name of the light.
		@param brand The brand of the light.
		@param model The model of the light.
		@param netAddr The network address of the light.
		 */
		Light(std::string name, std::string brand, std::string model, std::string netAddr);

		/**
		 Method to toggle the light on and off.
		 */
		void ToggleOnOff();

		/**
		Method to check if the light is on.
		 */
		bool IsOn() const;

		/**
		Method to set the brightness of the light.
		@param brightness The brightness level to set the light to.
		*/
		void SetBrightness(int brightness);

		/**
		Method to get the brightness of the light.
		*/
		int GetBrightness() const;

		/**
		Method to print the status of the light.
		*/
		void PrintStatus();

	private:
		bool m_isOn{ false };
		int m_Brightness{ 0 };
	};

} // namespace HomeAutomation
