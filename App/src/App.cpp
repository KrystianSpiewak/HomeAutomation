#include "HomeAutomation.h"

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


HomeAutomation::Application* HomeAutomation::CreateApplication()
{
	return new App();
}
