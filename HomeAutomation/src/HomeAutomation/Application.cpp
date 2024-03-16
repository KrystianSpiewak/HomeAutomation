#include "ha_pch.h"
#include "Application.h"

namespace HomeAutomation {

	Application::Application()
	{
		m_isRunning = false;
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		m_isRunning = true;
		std::cout << "Hello HomeAutomation!" << std::endl;
	}

	void Application::Close()
	{
		m_isRunning = false;
		std::cout << "Goodbye HomeAutomation!" << std::endl;
	}

	bool Application::IsRunning()
	{
		return m_isRunning;
	}

} // namespace HomeAutomation
