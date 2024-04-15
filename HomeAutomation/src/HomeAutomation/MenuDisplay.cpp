/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the MenuDisplay class responsible for displaying menus in the Home Automation application.
 * Dependencies: "ha_pch.h", "MenuDisplay.h"
 */
#include "ha_pch.h"
#include "MenuDisplay.h"

namespace HomeAutomation {

    /**
     * Display the main menu for the application.
     */
    void MenuDisplay::DisplayMainMenu()
    {
        std::cout << "\n===== Home Automation Console =====" << std::endl;
        std::cout << "1. Device Management" << std::endl;
        std::cout << "2. Automation Configuration" << std::endl;
        std::cout << "3. Security System Control" << std::endl;
        std::cout << "4. Exit" << std::endl;
    }

    /**
     * Display the device management menu.
     */
    void MenuDisplay::DisplayDeviceManagementMenu()
    {
        std::cout << "\n===== Device Management =====" << std::endl;
        std::cout << "1. Display Device Status" << std::endl;
        std::cout << "2. Control Devices" << std::endl;
        std::cout << "3. Back to Main Menu" << std::endl;
    }

    /**
     * Display the automation configuration menu.
     */
    void MenuDisplay::DisplayAutomationConfigurationMenu()
    {
        std::cout << "\n===== Automation Configuration =====" << std::endl;
        std::cout << "1. Set Schedule" << std::endl;
        std::cout << "2. Back to Main Menu" << std::endl;
    }

    /**
     * Display the security system control menu.
     */
    void MenuDisplay::DisplaySecuritySystemControlMenu()
    {
        std::cout << "\n===== Security System Control =====" << std::endl;
        std::cout << "1. Arm Security System" << std::endl;
        std::cout << "2. Disarm Security System" << std::endl;
        std::cout << "3. Back to Main Menu" << std::endl;
    }

} // namespace HomeAutomation
