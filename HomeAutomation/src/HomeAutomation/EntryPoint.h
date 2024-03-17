/**
 Student Name: Krystian Spiewak
 File description: This file is the main entry point for the Home Automation application client.
 It defines the main function for the Home Automation application client.
 */

#pragma once

// Entry point for Windows platform
#ifdef HA_PLATFORM_WINDOWS

/**
 Entry Point for HomeAutomation client applications
 */
extern HomeAutomation::Application* HomeAutomation::CreateApplication();

/**
 * Main entry point
 */
int main(int argc, char** argv)
{
	/**
	 Pointer to the application object
	 */
	auto application = HomeAutomation::CreateApplication();
	application->Run(); // run the application
	delete application; // delete the application object, free memory, set pointer to null
}

#endif // HA_PLATFORM_WINDOWS
