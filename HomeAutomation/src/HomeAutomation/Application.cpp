/**
 Student name: Krystian Spiewak
 File description: This file contains the implementation of the Home Automation Application class.
 Dependencies: ha_pch.h, Application.h, Thermostat.h, Light.h, SecuritySystem.h, TV.h, VacuumRobot.h
 Last modified: 04/21/2024
 */

#include "ha_pch.h"
#include "Application.h"

#include "Thermostat.h"
#include "Light.h"
#include "SecuritySystem.h"
#include "TV.h"
#include "VacuumRobot.h"

namespace HomeAutomation {

	Application::Application()
	{
		// Create an instance of the Test class
		m_menuDisplay = std::make_unique<MenuDisplay>();

		// Create an instance of the UserIOHandler class
		m_userIOHandler = std::make_unique<UserIOHandler>();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		m_isRunning = true;

		std::cout << "Welcome to the Home Automation System!" << std::endl;

		while (m_isRunning)
		{
			m_menuDisplay->DisplayMainMenu();
			int choice = m_userIOHandler->GetUserInput(std::make_pair(1, 4));

			// Add test smart appliances to the m_smartAppliances vector
			m_smartAppliances.push_back(std::make_shared<Thermostat>());
			m_smartAppliances.push_back(std::make_shared<Light>());
			m_smartAppliances.push_back(std::make_shared<SecuritySystem>());
			m_smartAppliances.push_back(std::make_shared<TV>());
			m_smartAppliances.push_back(std::make_shared<VacuumRobot>());

			switch (choice)
			{
			case 1:
				HandleDeviceManagement();
				break;
			case 2:
				HandleAutomationConfiguration();
				break;
			case 3:
				HandleSecuritySystemControl();
				break;
			case 4:
				Close();
				break;
			default:
				m_userIOHandler->DisplayMessage("Invalid choice. Please try again.");
				break;
			}
		}
	}

	void Application::Close()
	{
		if (m_isRunning) m_isRunning = false;

		std::cout << "Shutting down the Home Automation System..." << std::endl;
	}

	bool Application::IsRunning() const
	{
		return m_isRunning;
	}

    /**
     * Handle device management operations.
     */
	void Application::HandleDeviceManagement()
	{
		const std::pair<int, int> deviceRange = { 1, 6 }; // Updated range to include return option
		int choice;

		do
		{
			m_menuDisplay->DisplayDeviceManagementMenu();
			choice = m_userIOHandler->GetUserInput(deviceRange);

			switch (choice)
			{
			case 1:
				m_menuDisplay->DisplaySmartThermostatOptions();
				choice = m_userIOHandler->GetUserInput({ 1, 3 });
				// Implement thermostat control logic based on choice
				break;

			case 2:
				m_menuDisplay->DisplayTelevisionSystemOptions();
				choice = m_userIOHandler->GetUserInput({ 1, 3 });
				// Implement TV control logic based on choice
				break;

			case 3:
				m_menuDisplay->DisplayRobotVacuumOptions();
				choice = m_userIOHandler->GetUserInput({ 1, 3 });
				// Implement vacuum control logic based on choice
				break;

			case 4:
				m_menuDisplay->DisplayLightsOptions();
				choice = m_userIOHandler->GetUserInput({ 1, 3 });
				// Implement lights control logic based on choice
				break;

			case 5:
				m_menuDisplay->DisplaySecuritySystemOptions();
				choice = m_userIOHandler->GetUserInput({ 1, 3 });
				// Implement security system control logic based on choice
				break;

			case 6:
				// Return to previous menu
				return;

			default:
				m_userIOHandler->DisplayMessage("Invalid choice. Please try again.");
				break;
			}

		} while (choice != 0);
	}

    /**
     * Handle automation configuration operations.
     */
    void Application::HandleAutomationConfiguration()
    {
        m_menuDisplay->DisplayAutomationConfigurationMenu();
        int choice = m_userIOHandler->GetUserInput(std::make_pair(1, 3));

        // Implement automation configuration logic based on choice
        // For now return to main menu
    }

    /**
     * Handle security system control operations.
     */
    void Application::HandleSecuritySystemControl()
    {
        m_menuDisplay->DisplaySecuritySystemControlMenu();
        int choice = m_userIOHandler->GetUserInput(std::make_pair(1, 3));

        // Implement security system control logic based on choice
        // For now return to main menu
    }

}; // namespace HomeAutomation
