/**
 Student Name: Krystian Spiewak
 File description: This file is the main entry point for the Home Automation application client.
 Dependencies: HomeAutomation.h

 Abstract function HomeAutomation::CreateApplication() function is defined here to create the application object.
 */


#include "HomeAutomation.h"

/**
 App is the main class for the Home Automation application client.
 */
class App : public HomeAutomation::Application
{
public:
	App()
	{
	}

	~App()
	{
	}
};

/**
 Function HomeAutomation::CreateApplication(): creates the application object.
 @return Pointer to an instance of the application object.
 */
HomeAutomation::Application* HomeAutomation::CreateApplication()
{
	return new App();
}
