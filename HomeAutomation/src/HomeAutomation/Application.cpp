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
		// Create an instance of the Test class
		m_menuDisplay = std::make_unique<MenuDisplay>();
	}

	Application::~Application()
	{
		this->Close();
	}

	void Application::Run()
	{
		m_isRunning = true;

		m_menuDisplay->DisplayMainMenu();
	}

	void Application::Close()
	{
		if (m_isRunning) m_isRunning = false;
		std::cout << "Goodbye!" << std::endl;
	}

	bool Application::IsRunning()
	{
		return m_isRunning;
	}

}; // namespace HomeAutomation
