/**
 Student Name: Krystian Spiewak
 File description: This file contains the definition of the Home Automation Application class.
 Dependencies: MenuDisplay.h, "UserIOHandler.h, <memory>, SmartAppliance.h, <vector>
 Last modified: 04/21/2024
 */

#pragma once

#include "MenuDisplay.h"
#include "UserIOHandler.h"
#include <memory>
#include <vector>

#include "Thermostat.h"
#include "Light.h"
#include "SecuritySystem.h"
#include "TV.h"
#include "VacuumRobot.h"

/**
 Namespace for HomeAutomation identifiers
 */
namespace HomeAutomation {

	/**
	 Application is the main class for HomeAutomation client applications.
	 It is an abstract class that must be implemented by the CLIENT application.
	 The CLIENT application must define the function CreateApplication().
	 The CLIENT application must also include the file HomeAutomation.h.
	 */
	class Application
	{
	public:
		/**
		Default constructor
		 */
		Application();
		/**
		 Default destructor
		 */
		virtual ~Application();

		/**
		 Main entry point
		 */
		void Run();

		/**
		Close the application
		 */
		void Close();

		/**
		Check if the application is running
		 */
		bool IsRunning() const;

	private:
		/**
		 Flag to indicate if the application is running
		*/
		bool m_isRunning{ false };

		/**
		Pointer to the MenuDisplay object
		 */
		std::unique_ptr<MenuDisplay> m_menuDisplay;

		/**
		Pointer to the UserIOHandler object
		 */
		std::unique_ptr<UserIOHandler> m_userIOHandler;

		/**
		Vector to hold the devices connected to the system
		*/
		std::vector<std::shared_ptr<SmartAppliance>> m_smartAppliances{};

		/**
		Handle device management operations.
		*/
		void HandleDeviceManagement();

		/**
		Method to add a new device to the m_smartAppliances field.
		@param device: shared pointer to the device to be added.
		*/
		void AddDevice(std::shared_ptr<SmartAppliance> device);


		std::shared_ptr<Thermostat> m_TestThermostat{ nullptr };
		std::shared_ptr<Light> m_TestLight{ nullptr };
		std::shared_ptr<SecuritySystem> m_TestSecuritySystem{ nullptr };
		std::shared_ptr<TV> m_TestTV{ nullptr };
		std::shared_ptr<VacuumRobot> m_TestVacuumRobot{ nullptr };
	};

	/**
	Function CreateApplication(): to be defined by the CLIENT application
	 */
	Application* CreateApplication();
}; // namespace HomeAutomation
