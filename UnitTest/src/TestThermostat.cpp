/**
 Student Name: Krystian Spiewak
 File description: This file is testing the Thermostat class.
 Dependencies: pch.h, CppUnitTest.h, Thermostat.h

 Last modified: 04/26/2024
 Update tests to avoid throwing exceptions.
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "HomeAutomation/Thermostat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace HomeAutomation
{
	TEST_CLASS(ThermostatTest)
	{
	public:
		TEST_METHOD(ThermostatObjectCreated)
		{
			HomeAutomation::Thermostat* testThermostat = new HomeAutomation::Thermostat("Test Thermostat", "Test Brand", "Test Model", "127.0.0.4");
			Assert::IsNotNull(testThermostat);
			delete testThermostat;
		}
		TEST_METHOD(ThermostatSetTemperature)
		{
			HomeAutomation::Thermostat* testThermostat = new HomeAutomation::Thermostat("Test Thermostat", "Test Brand", "Test Model", "127.0.0.4");
			testThermostat->SetTemperature(75.0);
			Assert::AreEqual(75.0, testThermostat->GetTemperature());
			delete testThermostat;
		}
		TEST_METHOD(ThermostatSetCurrentTemp)
		{
			HomeAutomation::Thermostat* testThermostat = new HomeAutomation::Thermostat("Test Thermostat", "Test Brand", "Test Model", "127.0.0.4");
			testThermostat->SetCurrentTemp(75.0);
			Assert::AreEqual(75.0, testThermostat->GetCurrentTemp());
			delete testThermostat;
		}
		TEST_METHOD(ThermostatPrintStatus)
		{
			HomeAutomation::Thermostat* testThermostat = new HomeAutomation::Thermostat("Test Thermostat", "Test Brand", "Test Model", "127.0.0.4");
			testThermostat->SetTemperature(75.0);
			testThermostat->SetCurrentTemp(75.0);
			testThermostat->PrintStatus();
			delete testThermostat;
		}
	};
}
