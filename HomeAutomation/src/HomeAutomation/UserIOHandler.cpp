/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the UserIOHandler class responsible for managing user input and output in the Home Automation application.
 * Dependencies: "ha_pch.h", "UserIOHandler.h"
 * 
 * Last modified: 04/26/2024
 * Added the implementation of the WaitForUserInput method.
 * Fixed multiple characters or string input validation.
 */

#include "ha_pch.h"
#include "UserIOHandler.h"

namespace HomeAutomation {

    /**
     * Get user input from the console.
     *
     * @return The user's choice as an integer.
     */
    int UserIOHandler::GetUserInput(const std::pair<int, int>& range)
    {
		int choice;
		bool isValidInput = false;

		do
		{
			std::cout << "Enter your choice (" << range.first << "-" << range.second << "): ";

			if (!(std::cin >> choice) || choice < range.first || choice > range.second)
			{
				std::cout << "Invalid input. Please enter a valid number between " << range.first << " and " << range.second << "." << std::endl;
				std::cin.clear(); // Clear the error flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input buffer
			}
			// if user inputs multiple characters or a string treat it as invalid input
			else if (std::cin.peek() != '\n')
			{
				std::cout << "Invalid input. Please enter a valid number between " << range.first << " and " << range.second << "." << std::endl;
				std::cin.clear(); // Clear the error flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input buffer
			}
			else
			{
				isValidInput = true;
			}

		} while (!isValidInput);

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

	void UserIOHandler::WaitForUserInput()
	{
		std::cout << "Press any key to continue...";

		// Wait for the user to press a key
		system("pause > nul"); // Windows only command to pause the console
	}

} // namespace HomeAutomation
