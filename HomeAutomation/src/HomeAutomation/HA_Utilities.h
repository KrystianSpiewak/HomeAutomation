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
	@brief Template function to display the state of a device.
	@tparam T The type of the state to display.
	@param deviceName The name of the device.
	@param state The state of the device.
	 */
	template <typename T>
	void DisplayDeviceState(const std::string& deviceName, const T& state) {
		std::cout << deviceName << " State: " << state << std::endl;
	}

	/**
	 Utility function to save the state of a device to a file.
	 @param deviceName The name of the device.
	 @param state The state of the device.
	 */
	void SaveDeviceStateToFile(const std::string& deviceName, const std::string state) {
		std::ofstream file;
		file.open("device_states.txt", std::ios::app);

		if (file.is_open()) {
			file << deviceName << ": " << state << std::endl;
			file.close();
		}
		else {
			throw std::runtime_error("Failed to open the file for writing device state");
		}
	}

	/**
	 Utility function to load the state of a device from a file.
	 @param deviceName The name of the device.
	 @return The state of the device.
	 */
	std::string LoadDeviceStateFromFile(const std::string& deviceName) {

		std::ifstream file;
		file.open("device_states.txt");

		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) { // Read each line in the file
				if (line.find(deviceName) != std::string::npos) {	// Check if the device name is in the line
					std::string stateStr = line.substr(line.find(":") + 2);	// Get the state value
					file.close();
					return stateStr; // Convert the state value to the correct type and return it
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
	 Utility function to delete the save file.
	 */
	void DeleteSaveFile() {
		if (std::remove("device_states.txt") != 0) {
			throw std::runtime_error("Failed to delete the save file");
		}
		std::cout << "Save file deleted." << std::endl;
	}

	/**
	Utility function to clear the contents of the file.
	 */
	void ClearFileContents() {
		std::ofstream file;
		file.open("device_states.txt", std::ios::trunc);

		if (!file.is_open()) {
			throw std::runtime_error("Failed to open the file for clearing contents");
		}

		file.close();

		std::cout << "File contents cleared." << std::endl;
	}
} // namespace HA_Utilities
