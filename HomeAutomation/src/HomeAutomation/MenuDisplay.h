/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the MenuDisplay class responsible for displaying menus in the Home Automation application.
 * Dependencies: None
 */
#pragma once

namespace HomeAutomation {
        
    /**
     MenuDisplay class handles displaying various menus for the Home Automation application.
     */
    class MenuDisplay
    {
    public:
        /**
            * Display the main menu for the application.
            */
        void DisplayMainMenu();

        /**
            * Display the device management menu.
            */
        void DisplayDeviceManagementMenu();

        /**
            * Display smart thermostat options.
            */
        void DisplaySmartThermostatOptions();

        /**
            * Display television system options.
            */
        void DisplayTelevisionSystemOptions();

        /**
            * Display robot vacuum options.
            */
        void DisplayRobotVacuumOptions();

        /**
            * Display lights options.
            */
        void DisplayLightsOptions();

        /**
            * Display security system options.
            */
        void DisplaySecuritySystemOptions();

        /**
            * Display automation configuration menu.
            */
        void DisplayAutomationConfigurationMenu();

        /**
            * Display security system control menu.
            */
        void DisplaySecuritySystemControlMenu();

    };

} // namespace HomeAutomation
