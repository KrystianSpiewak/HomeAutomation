#pragma once

namespace HomeAutomation {

	/**
	 * Application is the main class for HomeAutomation client applications.
	 * It is an abstract class that must be implemented by the CLIENT application.
	 * The CLIENT application must define the function CreateApplication().
	 * The CLIENT application must also include the file HomeAutomation.h.
	 */
	class Application
	{
	public:
		/**
		 * Default constructor
		 */
		Application();
		/**
		 * Default destructor
		 */
		virtual ~Application();

		/**
		 * Main entry point
		 */
		void Run();
	};

	/**
	 * Function CreateApplication(): to be defined by the CLIENT application
	 */
	Application* CreateApplication();
}