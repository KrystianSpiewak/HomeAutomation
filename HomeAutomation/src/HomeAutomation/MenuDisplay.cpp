/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the MenuDisplay class responsible for displaying menus in the Home Automation application.
 * Dependencies: "ha_pch.h", "MenuDisplay.h"
 Last modified: 04/21/2024
 */
#include "ha_pch.h"
#include "MenuDisplay.h"

namespace HomeAutomation {

	void MenuDisplay::DisplayMainMenu()
	{
		std::cout << "\n=== Main Menu ===" << std::endl;
		std::cout << "1. Device Management" << std::endl;
		std::cout << "2. Save devices to file." << std::endl;
		std::cout << "3. Load devices from file" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplayDeviceManagementMenu()
	{
		std::cout << "\n=== Device Management ===" << std::endl;
		std::cout << "1. Smart Thermostat" << std::endl;
		std::cout << "2. Television System" << std::endl;
		std::cout << "3. Robot Vacuum" << std::endl;
		std::cout << "4. Lights" << std::endl;
		std::cout << "5. Security System" << std::endl;
		std::cout << "6. Return to Previous Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplaySmartThermostatOptions()
	{
		std::cout << "\n=== Smart Thermostat Options ===" << std::endl;
		std::cout << "1. Check current temperature" << std::endl;
		std::cout << "2. Set New Temperature" << std::endl;
		std::cout << "3. Display Status" << std::endl;
		std::cout << "4. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplayTelevisionSystemOptions()
	{
		std::cout << "\n=== Television System Options ===" << std::endl;
		std::cout << "1. Turn On/Off" << std::endl;
		std::cout << "2. Set Channel" << std::endl;
		std::cout << "3. Change Channel Up" << std::endl;
		std::cout << "4. Change Channel Down" << std::endl;
		std::cout << "5. Increase Volume" << std::endl;
		std::cout << "6. Decrease Volume" << std::endl;
		std::cout << "7. Display Status" << std::endl;
		std::cout << "8. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplayRobotVacuumOptions()
	{
		std::cout << "\n=== Robot Vacuum Options ===" << std::endl;
		std::cout << "1. Turn On/Off" << std::endl;
		std::cout << "2. Start Cleaning" << std::endl;
		std::cout << "3. Check battery level" << std::endl;
		std::cout << "4. Return to base" << std::endl;
		std::cout << "5. Display Status" << std::endl;
		std::cout << "6. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplayLightsOptions()
	{
		std::cout << "\n=== Lights Options ===" << std::endl;
		std::cout << "1. Turn On/Off" << std::endl;
		std::cout << "2. Set Brightness level" << std::endl;
		std::cout << "3. Display Status" << std::endl;
		std::cout << "4. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplaySecuritySystemOptions()
	{
		std::cout << "\n=== Security System Options ===" << std::endl;
		std::cout << "1. Arm System" << std::endl;
		std::cout << "2. Disarm System" << std::endl;
		std::cout << "3. Display Status" << std::endl;
		std::cout << "4. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

} // namespace HomeAutomation
