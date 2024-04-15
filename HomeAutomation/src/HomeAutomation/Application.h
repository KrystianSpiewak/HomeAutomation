/**
 Student Name: Krystian Spiewak
 File description: This file contains the definition of the Home Automation Application class.
 Dependencies: None
 */

#pragma once

#include "MenuDisplay.h"
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
		bool IsRunning();

		private:
			/**
			 Flag to indicate if the application is running
			*/
			bool m_isRunning{ false };

			/**
			 Instance of the Test class
			 */
			std::unique_ptr<MenuDisplay> m_menuDisplay;
	};

	/**
	Function CreateApplication(): to be defined by the CLIENT application
	 */
	Application* CreateApplication();
}; // namespace HomeAutomation
