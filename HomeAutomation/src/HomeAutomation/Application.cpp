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

		// Create an instance of the UserIOHandler class
		m_userIOHandler = std::make_unique<UserIOHandler>();
	}

	Application::~Application()
	{
		this->Close();
	}

	void Application::Run()
	{
		m_isRunning = true;

		m_menuDisplay->DisplayMainMenu();
		m_userIOHandler->DisplayMessage("Welcome to the Home Automation Console!");
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
