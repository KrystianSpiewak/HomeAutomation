#pragma once

// Entry point for Windows platform
#ifdef HA_PLATFORM_WINDOWS

/**
 * Funtion CreateApplication(): to be defined by the CLIENT application
 */
extern HomeAutomation::Application* HomeAutomation::CreateApplication();

/**
 * Main entry point
 */
int main(int argc, char** argv)
{
	auto app = HomeAutomation::CreateApplication();
	app->Run();
	delete app;
}

#endif // HA_PLATFORM_WINDOWS
