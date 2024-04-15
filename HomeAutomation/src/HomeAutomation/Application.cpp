/**
 Student name: Krystian Spiewak
 File description: This file contains the implementation of the Home Automation Application class.
 Dependencies: ha_pch.h, Application.h
 */

#include "ha_pch.h"
#include "Application.h"

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
		this->Close();
	}

	void Application::Run()
	{
		m_isRunning = true;

		while (m_isRunning)
		{
			m_menuDisplay->DisplayMainMenu();
			int choice = m_userIOHandler->GetUserInput();

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
        m_menuDisplay->DisplayDeviceManagementMenu();
        int choice = m_userIOHandler->GetUserInput();

        // Implement device management logic based on choice
        // For simplicity, we'll just return to main menu
    }

    /**
     * Handle automation configuration operations.
     */
    void Application::HandleAutomationConfiguration()
    {
        m_menuDisplay->DisplayAutomationConfigurationMenu();
        int choice = m_userIOHandler->GetUserInput();

        // Implement automation configuration logic based on choice
        // For simplicity, we'll just return to main menu
    }

    /**
     * Handle security system control operations.
     */
    void Application::HandleSecuritySystemControl()
    {
        m_menuDisplay->DisplaySecuritySystemControlMenu();
        int choice = m_userIOHandler->GetUserInput();

        // Implement security system control logic based on choice
        // For simplicity, we'll just return to main menu
    }

}; // namespace HomeAutomation
