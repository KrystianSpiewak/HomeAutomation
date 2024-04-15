/**
 Student Name: Krystian Spiewak
 File description: This file contains the definition of the Home Automation Application class.
 Dependencies: None
 */

#pragma once

#include "MenuDisplay.h"
#include "UserIOHandler.h"
#include <memory>

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
			Handle device management operations.
			*/
			void HandleDeviceManagement();

			/**
			Handle automation configuration operations.
			 */
			void HandleAutomationConfiguration();

			/**
			Handle security system control operations.
			 */
			void HandleSecuritySystemControl();
	};

	/**
	Function CreateApplication(): to be defined by the CLIENT application
	 */
	Application* CreateApplication();
}; // namespace HomeAutomation
