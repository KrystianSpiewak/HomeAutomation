/**
 Student name: Krystian Spiewak
 File description: This file contains the implementation of the Home Automation Application class.
 Dependencies: ha_pch.h, Application.h, Thermostat.h, Light.h, SecuritySystem.h, TV.h, VacuumRobot.h
 Last modified: 04/26/2024
 Added the cases 2 and 3 for saving and loading devices to and from a file.
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
			std::shared_ptr<Thermostat> testThermostat = std::make_shared<Thermostat>("NewThermostat", "NewBrand", "NewModel", "127.0.0.4");
			std::shared_ptr<Light> testLight = std::make_shared<Light>("NewLight", "NewBrand", "NewModel", "127.0.0.2");
			std::shared_ptr<SecuritySystem> testSecuritySystem = std::make_shared<SecuritySystem>("NewSecuritySystem", "NewBrand", "NewModel", "127.0.0.3");
			//std::shared_ptr<TV> testTV = std::make_shared<TV>();
			//std::shared_ptr<VacuumRobot> testVacuumRobot = std::make_shared<VacuumRobot>();

			AddDevice(testThermostat);
			AddDevice(testLight);
			AddDevice(testSecuritySystem);
			//AddDevice(testTV);
			//AddDevice(testVacuumRobot);

			switch (choice)
			{
			case 1:
				HandleDeviceManagement();
				break;
			case 2:
				// TODO: save devices to file

				// Display a message to the user
				m_userIOHandler->DisplayMessage("Devices have been saved to a file.");

				// Wait for the user to press a key
				m_userIOHandler->WaitForUserInput();
				break;
			case 3:
				// TODO: load devices from file

				// Display a message to the user
				m_userIOHandler->DisplayMessage("Devices have been loaded from a file.");

				// Wait for the user to press a key
				m_userIOHandler->WaitForUserInput();
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
				choice = m_userIOHandler->GetUserInput({ 1, 4 });

				switch (choice)
				{
					case 1:
						// TODO: Check current temperature
						break;
					case 2:
						// TODO: Set new temperature
						break;
					case 3:
						// TODO: Display status
						break;
					case 4:
						// Return to previous menu
						break;
					default:
						m_userIOHandler->DisplayMessage("Invalid choice. Please try again.");
						break;
				}

				break;

			case 2:
				m_menuDisplay->DisplayTelevisionSystemOptions();
				choice = m_userIOHandler->GetUserInput({ 1, 8 });
				
				switch (choice)
				{
					case 1:
						// TODO: Turn on/off
						break;
					case 2:
						// TODO: Set channel
						break;
					case 3:
						// TODO: Change channel up
						break;
					case 4:
						// TODO: Change channel down
					break;
					case 5:
						// TODO: Increase volume
						break;
					case 6:
						// TODO: Decrease volume
						break;
					case 7:
						// TODO: Display status
						break;
					case 8:
						// Return to previous menu
						break;
					default:
						m_userIOHandler->DisplayMessage("Invalid choice. Please try again.");
						break;
				}
				break;

			case 3:
				m_menuDisplay->DisplayRobotVacuumOptions();
				choice = m_userIOHandler->GetUserInput({ 1, 6 });
				
				switch (choice)
				{
					case 1:
						// TODO: Turn on/off
						break;
					case 2:
						// TODO: Start cleaning
						break;
					case 3:
						// TODO: Check battery level
						break;
					case 4:
						// TODO: Return to base
						break;
					case 5:
						// TODO: Display status
						break;
					case 6:
						// Return to previous menu
						break;
					default:
						m_userIOHandler->DisplayMessage("Invalid choice. Please try again.");
						break;
				}
				break;

			case 4:
				m_menuDisplay->DisplayLightsOptions();
				choice = m_userIOHandler->GetUserInput({ 1, 4 });

				switch (choice)
				{
					case 1:
						// TODO: Turn on/off
						break;
					case 2:
						// TODO: Set brightness level
						break;
					case 3:
						// TODO: Display status
					case 4:
						// Return to previous menu
						break;
					default:
						m_userIOHandler->DisplayMessage("Invalid choice. Please try again.");
						break;
				}
				break;

			case 5:
				m_menuDisplay->DisplaySecuritySystemOptions();
				choice = m_userIOHandler->GetUserInput({ 1, 4 });
				
				switch (choice)
				{
					case 1:
						// TODO: Arm system
						break;
					case 2:
						// TODO: Disarm system
						break;
					case 3:
						// TODO: Display status
						break;
					case 4:
						// Return to previous menu
						break;
					default:
						m_userIOHandler->DisplayMessage("Invalid choice. Please try again.");
						break;
				}
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


	void Application::AddDevice(std::shared_ptr<SmartAppliance> device)
	{
		m_smartAppliances.push_back(device);
	}

}; // namespace HomeAutomation
