/**
 Student Name: Krystian Spiewak
 File description: This file is testing the Home Automation Utility functions.
 Dependencies: pch.h, CppUnitTest.h, HA_Utilities.h
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "HomeAutomation/HA_Utilities.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HomeAutomation
{
	TEST_CLASS(HA_UtilitiesTest)
	{
	public:
		TEST_METHOD(IsValidIPAddress)
		{
			std::string ipAddr = "";
			Assert::IsFalse(HA_Utilities::IsValidIPAddress(ipAddr));
			ipAddr = "55.55.5";
			Assert::IsFalse(HA_Utilities::IsValidIPAddress(ipAddr));
			ipAddr = "127.0.0.1";
			Assert::IsTrue(HA_Utilities::IsValidIPAddress(ipAddr));
		}
		TEST_METHOD(DisplayDeviceState)
		{
			std::string deviceName = "Thermostat";
			double state = 72.5;
			HA_Utilities::DisplayDeviceState(deviceName, state);
		}
		/*TEST_METHOD(SaveDeviceStateToFile)
		{
			std::string deviceName = "Thermostat";
			double state = 72.5;

			try {
				HA_Utilities::SaveDeviceStateToFile(deviceName, state);
			}
			catch (std::runtime_error& e) {
				Assert::Fail(L"Failed to open the file for writing device state");
			}
		}
		TEST_METHOD(LoadDeviceStateFromFile)
		{
			std::string deviceName = "Thermostat";
			double state = HA_Utilities::LoadDeviceStateFromFile<double>(deviceName);
			try {
				Assert::AreEqual(72.5, state);
			}
			catch (std::runtime_error& e) {
				Assert::Fail(L"Failed to open the file for reading device state");

			}
		}*/
	};
}
