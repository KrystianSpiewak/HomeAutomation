/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the declaration of the UserIOHandler class responsible for managing user input and output in the Home Automation application.
 * Dependencies: <string>
 */
#pragma once

#include <string>

namespace HomeAutomation {

    /**
     UserIOHandler class manages user input and output operations for the Home Automation application.
     */
    class UserIOHandler
    {
    public:
        /**
         Get user input from the console.
         @return The user's choice as an integer.
         */
        int GetUserInput(const std::pair<int, int>& range);

        /**
		 Display a message to the console.
		 @param message The message to display.
         */
        void DisplayMessage(const std::string& message);
    };

} // namespace HomeAutomation
