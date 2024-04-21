/**
 Student Name: Krystian Spiewak
 File description: This file is testing the Thermostat class.
 Dependencies: pch.h, CppUnitTest.h, Thermostat.h
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
			HomeAutomation::Thermostat* testThermostat = new HomeAutomation::Thermostat();
			Assert::IsNotNull(testThermostat);
			delete testThermostat;
		}
		TEST_METHOD(ThermostatSetTemperature)
		{
			HomeAutomation::Thermostat* testThermostat = new HomeAutomation::Thermostat();
			testThermostat->SetTemperature(20.0);
			Assert::AreEqual(20.0, testThermostat->GetTemperature());
			delete testThermostat;
		}
		TEST_METHOD(ThermostatSetCurrentTemp)
		{
			HomeAutomation::Thermostat* testThermostat = new HomeAutomation::Thermostat();
			testThermostat->SetCurrentTemp(20.0);
			Assert::AreEqual(20.0, testThermostat->GetCurrentTemp());
			delete testThermostat;
		}
		TEST_METHOD(ThermostatPrintStatus)
		{
			HomeAutomation::Thermostat* testThermostat = new HomeAutomation::Thermostat();
			testThermostat->SetTemperature(20.0);
			testThermostat->SetCurrentTemp(20.0);
			testThermostat->PrintStatus();
			delete testThermostat;
		}
	};
}
