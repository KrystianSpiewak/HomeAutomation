/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the UserIOHandler class responsible for managing user input and output in the Home Automation application.
 * Dependencies: "ha_pch.h", "UserIOHandler.h"
 */

#include "ha_pch.h"
#include "UserIOHandler.h"

namespace HomeAutomation {

    /**
     * Get user input from the console.
     *
     * @return The user's choice as an integer.
     */
    int UserIOHandler::GetUserInput()
    {
        int choice;
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        return choice;
    }

    /**
     * Display a message to the console.
     *
     * @param message The message to display.
     */
    void UserIOHandler::DisplayMessage(const std::string& message)
    {
        std::cout << message << std::endl;
    }

} // namespace HomeAutomation
