/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the MenuDisplay class responsible for displaying menus in the Home Automation application.
 * Dependencies: "ha_pch.h", "MenuDisplay.h"
 */
#include "ha_pch.h"
#include "MenuDisplay.h"

namespace HomeAutomation {

	void MenuDisplay::DisplayMainMenu()
	{
		std::cout << "\n=== Main Menu ===" << std::endl;
		std::cout << "1. Device Management" << std::endl;
		std::cout << "2. Automation Configuration" << std::endl;
		std::cout << "3. Security System Control" << std::endl;
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
		std::cout << "1. Set Day Temperature" << std::endl;
		std::cout << "2. Set Evening Temperature" << std::endl;
		std::cout << "3. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplayTelevisionSystemOptions()
	{
		std::cout << "\n=== Television System Options ===" << std::endl;
		std::cout << "1. Turn On/Off" << std::endl;
		std::cout << "2. Change Channel" << std::endl;
		std::cout << "3. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplayRobotVacuumOptions()
	{
		std::cout << "\n=== Robot Vacuum Options ===" << std::endl;
		std::cout << "1. Start Cleaning" << std::endl;
		std::cout << "2. Stop Cleaning" << std::endl;
		std::cout << "3. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplayLightsOptions()
	{
		std::cout << "\n=== Lights Options ===" << std::endl;
		std::cout << "1. Turn On" << std::endl;
		std::cout << "2. Turn Off" << std::endl;
		std::cout << "3. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplaySecuritySystemOptions()
	{
		std::cout << "\n=== Security System Options ===" << std::endl;
		std::cout << "1. Set Activation Time" << std::endl;
		std::cout << "2. Set Sensitivity Level" << std::endl;
		std::cout << "3. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplayAutomationConfigurationMenu()
	{
		std::cout << "\n=== Automation Configuration ===" << std::endl;
		std::cout << "1. Set Automation Schedule" << std::endl;
		std::cout << "2. Configure Automation Rules" << std::endl;
		std::cout << "3. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

	void MenuDisplay::DisplaySecuritySystemControlMenu()
	{
		std::cout << "\n=== Security System Control ===" << std::endl;
		std::cout << "1. Arm Security System" << std::endl;
		std::cout << "2. Disarm Security System" << std::endl;
		std::cout << "3. Return to Device Management Menu" << std::endl;
		std::cout << "Enter your choice: ";
	}

} // namespace HomeAutomation
