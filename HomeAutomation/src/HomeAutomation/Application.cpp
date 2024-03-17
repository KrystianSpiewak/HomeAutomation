/**
 Student name: Krystian Spiewak
 File description: This file contains the implementation of the Home Automation Application class.
 Dependencies: ha_pch.h, Application.h
 */

#include "ha_pch.h"
#include "Application.h"

namespace HomeAutomation {

	Application::Application()
	{
		m_isRunning = false;
	}

	Application::~Application()
	{
		this->Close();
	}

	void Application::Run()
	{
		m_isRunning = true;
		std::cout << "Hello HomeAutomation!" << std::endl;
	}

	void Application::Close()
	{
		if (m_isRunning) m_isRunning = false;
		std::cout << "Goodbye HomeAutomation!" << std::endl;
	}

	bool Application::IsRunning()
	{
		return m_isRunning;
	}

}; // namespace HomeAutomation
