/*
 Student Name: Krystian Spiewak
 File description: This file contains the definitions of the utility functions and templates for the Home Automation program.
 Dependencies: None
 */

#pragma once

#include <string>
#include <fstream>


namespace HA_Utilities {

	/**
	 * @brief Template function to display the state of a device.
	 * @tparam T The type of the state to display.
	 * @param deviceName The name of the device.
	 * @param state The state of the device.
	 */
	template <typename T>
	void DisplayDeviceState(const std::string& deviceName, const T& state) {
		std::cout << deviceName << " State: " << state << std::endl;
	}

	/**
	 Utility function to save the state of a device to a file.
	 @tparam T The type of the state to save.
	 @param deviceName The name of the device.
	 @param state The state of the device.
	 */
	template <typename T>
	void SaveDeviceStateToFile(const std::string& deviceName, const T& state) {

		std::ofstream file;
		file.open("device_states.txt", std::ios::app);

		if (file.is_open()) {
			file << deviceName << " State: " << state << std::endl;
			file.close();
		}
		else {
			throw std::runtime_error("Failed to open the file for writing device state");
		}
	}

	/**
	 Utility function to load the state of a device from a file.
	 @tparam T The type of the state to load.
	 @param deviceName The name of the device.
	 @return The state of the device.
	 */
	template <typename T>
	T LoadDeviceStateFromFile(const std::string& deviceName) {

		std::ifstream file;
		file.open("device_states.txt");

		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) { // Read each line in the file
				if (line.find(deviceName) != std::string::npos) {	// Check if the device name is in the line
					std::string stateStr = line.substr(line.find(":") + 2);	// Get the state value
					file.close();
					return static_cast<T>(stateStr); // Convert the state value to the correct type and return it
				}
			}
			file.close();
		}
		else {
			throw std::runtime_error("Failed to open the file for reading device state");
		}

		throw std::runtime_error("Device state not found in file");
	}

	/**
	 * @brief Utility function to check if a string is a valid IP address.
	 * @param ipAddress The IP address to check.
	 * @return True if the IP address is valid, false otherwise.
	 */
	bool IsValidIPAddress(const std::string& ipAddress) {

		// Check if the IP address is empty
		if (ipAddress.empty()) {
			return false;
		}

		// Check if the IP address has 4 parts separated by '.'
		int count = 0;
		for (char c : ipAddress) {
			if (c == '.') {
				count++;
			}
		}

		if (count != 3) {
			return false;
		}

		// Check if each part of the IP address is a number between 0 and 255
		std::string part;
		int num;
		std::istringstream ss(ipAddress);
		while (std::getline(ss, part, '.')) {
			if (part.empty()) {
				return false;
			}
			num = std::stoi(part);
			if (num < 0 || num > 255) {
				return false;
			}
		}

		return true;
	}
} // namespace HA_Utilities
