/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the TV class that inherits from the SmartAppliance class.
 * Dependencies: SmartAppliance.h
 * 
 * Last modified: 4/26/2024
 * Added parametrized constructor for the TV class.
 * Added GetState method.
 */

#pragma once

#include "SmartAppliance.h"

namespace HomeAutomation {
	
	/**
	TV class inherits from the SmartAppliance class and represents a TV smart appliance.
	 */
	class TV : public SmartAppliance
	{
		public:

		/**
		 Constructor for the TV class.
		 @param name The name of the TV.
		 @param brand The brand of the TV.
		 @param model The model of the TV.
		 @param netAddr The network address of the TV.
		 */
		TV(const std::string& name, const std::string& brand, const std::string& model, const std::string& netAddr);

		/**
		Toggles the TV on or off.
		 */
		void ToggleOnOff();

		/**
		Method to get the power status of the TV.
		 */
		bool IsOn() const;

		/**
		Set the current channel that the TV is set to.
		@param currentChannel The current channel that the TV is set to.
		 */
		void SetChannel(int currentChannel);

		/**
		Get the current channel that the TV is set to.
		@return The current channel that the TV is set to.
		 */
		int GetChannel() const;

		/**
		Method to get the volume level of the TV.
		 */
		int GetVolume() const;

		/**
		Method to change channel up by one.
		 */
		void ChangeChannelUp();

		/**
		Method to change channel down by one.
		 */
		void ChangeChannelDown();

		/**
		 Method to increase the volume by one.
		 */
		void IncreaseVolume();

		/**
		 Method to decrease the volume by one.
		 */
		void DecreaseVolume();

		/**
		Print the status of the TV.
		 */
		void PrintStatus() override;

		/**
		Get the state of the TV.
		@return The state of the TV.
		 */
		std::string GetState() override;

	private:
		/**
		* The current channel that the TV is set to.
		*/
		int m_CurrentChannel{ 0 };
		
		/**
		Flag to indicate if the appliance is on or off.
		 */
		bool m_isOn{ false };

		/**
		The current volume level of the TV.
		 */
		int m_Volume{ 0 };
	};
} // namespace HomeAutomation
