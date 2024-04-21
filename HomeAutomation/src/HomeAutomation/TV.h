/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the TV class that inherits from the SmartAppliance class.
 * Dependencies: <string>, SmartAppliance.h
 */

#pragma once

#include <string>
#include "SmartAppliance.h"

namespace HomeAutomation {
	/**
	TV class inherits from the SmartAppliance class and represents a TV smart appliance.
	 */
	class TV : public SmartAppliance
	{
		public:

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
