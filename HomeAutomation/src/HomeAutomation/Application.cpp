/**
 Student name: Krystian Spiewak
 File description: This file contains the implementation of the Home Automation Application class.
 Dependencies: ha_pch.h, Application.h, Thermostat.h, Light.h, SecuritySystem.h, TV.h, VacuumRobot.h

 Last modified: 04/26/2024
 Added the cases 2 and 3 for saving and loading devices to and from a file.
 Using parametrized constructor for the smart appliances.
 Added test smart devices fields.
 Added Device menu options handling.
 */

#include "ha_pch.h"
#include "Application.h"
#include "HomeAutomation/HA_Utilities.h"


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
			m_TestThermostat = std::make_shared<Thermostat>("NewThermostat", "NewBrand", "NewModel", "127.0.0.4");
			m_TestLight = std::make_shared<Light>("NewLight", "NewBrand", "NewModel", "127.0.0.2");
			m_TestSecuritySystem = std::make_shared<SecuritySystem>("NewSecuritySystem", "NewBrand", "NewModel", "127.0.0.3");
			m_TestTV = std::make_shared<TV>("NewTV", "NewBrand", "NewModel", "127.0.0.5");
			m_TestVacuumRobot = std::make_shared<VacuumRobot>("NewVacuumRobot", "NewBrand", "NewModel", "127.0.0.6");

			AddDevice(m_TestThermostat);
			AddDevice(m_TestLight);
			AddDevice(m_TestSecuritySystem);
			AddDevice(m_TestTV);
			AddDevice(m_TestVacuumRobot);

			switch (choice)
			{
			case 1:
				HandleDeviceManagement();
				break;
			case 2:
				// clear contents of the file before saving
				HA_Utilities::ClearFileContents();

				// save devices to file
				for (const auto& device : m_smartAppliances)
				{
					// Save the device state to a file
					HA_Utilities::SaveDeviceStateToFile(device->GetName(), device->GetState());
				}

				// Display a message to the user
				m_userIOHandler->DisplayMessage("Devices have been saved to a file.");

				// Wait for the user to press a key
				m_userIOHandler->WaitForUserInput();
				break;
			case 3:
				// load devices from file
				for (const auto& device : m_smartAppliances)
				{
					// Load the device state from a file
					std::string state = HA_Utilities::LoadDeviceStateFromFile(device->GetName());
					HA_Utilities::DisplayDeviceState(device->GetName(), state);
				}

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
			int requestedTemp = 0;
			int requestedChannel = 0;
			int requestedBrightness = 0;

			switch (choice)
			{
			case 1:
				m_menuDisplay->DisplaySmartThermostatOptions();
				choice = m_userIOHandler->GetUserInput({ 1, 4 });

				switch (choice)
				{
					case 1:
						// Check current temperature
						std::cout << "Current temperature: " << m_TestThermostat->GetTemperature() << " degrees Fahrenheit" << std::endl;
						break;
					case 2:
						//  prompt user for new temperature
						m_userIOHandler->DisplayMessage("Enter the new temperature (between 50 and 90 degrees Fahrenheit): ");

						requestedTemp = m_userIOHandler->GetUserInput({ 50, 90 });
						// Set new temperature
						m_TestThermostat->SetTemperature(requestedTemp);

						// Display the new temperature
						std::cout << "New temperature set to: " << m_TestThermostat->GetTemperature() << " degrees Fahrenheit" << std::endl;
						break;
					case 3:
						// Display status
						m_TestThermostat->PrintStatus();
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
						// Turn on/off
						m_TestTV->ToggleOnOff();
						std::cout << "TV is now " << (m_TestTV->IsOn() ? "on" : "off") << std::endl;

						break;
					case 2:
						// Set channel
						m_userIOHandler->DisplayMessage("Enter the channel number: ");
						requestedChannel = m_userIOHandler->GetUserInput({ 1, 999 });
						m_TestTV->SetChannel(requestedChannel);
						std::cout << "Channel set to: " << m_TestTV->GetChannel() << std::endl;

						break;
					case 3:
						// Change channel up
						m_TestTV->ChangeChannelUp();
						std::cout << "Channel changed to: " << m_TestTV->GetChannel() << std::endl;
						break;
					case 4:
						// Change channel down
						m_TestTV->ChangeChannelDown();
						std::cout << "Channel changed to: " << m_TestTV->GetChannel() << std::endl;
					break;
					case 5:
						// Increase volume
						m_TestTV->IncreaseVolume();
						std::cout << "Volume increased to: " << m_TestTV->GetVolume() << std::endl;
						break;
					case 6:
						// Decrease volume
						m_TestTV->DecreaseVolume();
						std::cout << "Volume decreased to: " << m_TestTV->GetVolume() << std::endl;
						break;
					case 7:
						// Display status
						m_TestTV->PrintStatus();
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
						// Turn on/off
						m_TestVacuumRobot->ToggleOnOff();
						std::cout << "Vacuum Robot is now " << (m_TestVacuumRobot->IsOn() ? "on" : "off") << std::endl;
						break;
					case 2:
						// Start cleaning
						m_TestVacuumRobot->StartCleaning();
						break;
					case 3:
						// Check battery level
						std::cout << "Battery level: " << m_TestVacuumRobot->GetBatteryLevel() << "%" << std::endl;
						break;
					case 4:
						// Return to base
						m_TestVacuumRobot->ReturnToBase();
						break;
					case 5:
						// Display status
						m_TestVacuumRobot->PrintStatus();
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
						// Turn on/off
						m_TestLight->ToggleOnOff();
						std::cout << "Light is now " << (m_TestLight->IsOn() ? "on" : "off") << std::endl;
						break;
					case 2:
						// Set brightness level
						m_userIOHandler->DisplayMessage("Enter the brightness level (between 10 and 100): ");
						requestedBrightness = m_userIOHandler->GetUserInput({ 10, 100 });
						m_TestLight->SetBrightness(requestedBrightness);
						std::cout << "Brightness set to: " << m_TestLight->GetBrightness() << std::endl;
						break;
					case 3:
						// Display status
						m_TestLight->PrintStatus();
						break;
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
						// Arm system
						m_TestSecuritySystem->ArmSystem();
						std::cout << "Security System is now armed." << std::endl;
						break;
					case 2:
						// Disarm system
						m_TestSecuritySystem->DisarmSystem();
						std::cout << "Security System is now disarmed." << std::endl;
						break;
					case 3:
						// Display status
						m_TestSecuritySystem->PrintStatus();
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
