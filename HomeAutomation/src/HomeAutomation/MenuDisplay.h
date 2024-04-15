/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the MenuDisplay class responsible for displaying menus in the Home Automation application.
 * Dependencies: None
 */
#pragma once

namespace HomeAutomation {

    /**
     * MenuDisplay class handles displaying various menus for the Home Automation application.
     */
    class MenuDisplay
    {
    public:
        /**
         * Display the main menu for the application.
         */
        void DisplayMainMenu();

    private:
        /**
         * Display the device management menu.
         */
        void DisplayDeviceManagementMenu();

        /**
         * Display the automation configuration menu.
         */
        void DisplayAutomationConfigurationMenu();

        /**
         * Display the security system control menu.
         */
        void DisplaySecuritySystemControlMenu();
    };

} // namespace HomeAutomation
