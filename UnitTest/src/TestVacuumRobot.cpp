/**
 Student Name: Krystian Spiewak
 File description: This file is testing the VacuumRobot class.
 Dependencies: pch.h, CppUnitTest.h, TV.h
 *
 * Last modified: 04/26/2024
 * Modified test cases to use parametrized constructor for the VacuumRobot class.
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "HomeAutomation/VacuumRobot.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace HomeAutomation
{
	TEST_CLASS(VacuumRobotTest)
	{
	public:
		TEST_METHOD(VacuumRobotObjectCreated)
		{
			HomeAutomation::VacuumRobot* testVacuumRobot = new HomeAutomation::VacuumRobot("NewVacuumRobot", "NewBrand", "NewModel", "127.0.0.6");
			Assert::IsNotNull(testVacuumRobot);
			delete testVacuumRobot;
		}
		TEST_METHOD(VacuumRobotTogglePower)
		{
			HomeAutomation::VacuumRobot* testVacuumRobot = new HomeAutomation::VacuumRobot("NewVacuumRobot", "NewBrand", "NewModel", "127.0.0.6");
			testVacuumRobot->ToggleOnOff();
			Assert::IsTrue(testVacuumRobot->IsOn());
			testVacuumRobot->ToggleOnOff();
			Assert::IsFalse(testVacuumRobot->IsOn());
			delete testVacuumRobot;
		}
		TEST_METHOD(VacuumRobotSetBatteryLevel)
		{
			HomeAutomation::VacuumRobot* testVacuumRobot = new HomeAutomation::VacuumRobot("NewVacuumRobot", "NewBrand", "NewModel", "127.0.0.6");
			testVacuumRobot->SetBatteryLevel(50);
			Assert::AreEqual(50, testVacuumRobot->GetBatteryLevel());
			delete testVacuumRobot;
		}
		TEST_METHOD(VacuumRobotReturnToBase)
		{
			HomeAutomation::VacuumRobot* testVacuumRobot = new HomeAutomation::VacuumRobot("NewVacuumRobot", "NewBrand", "NewModel", "127.0.0.6");
			testVacuumRobot->ReturnToBase();
			delete testVacuumRobot;
		}
		TEST_METHOD(VacuumRobotPrintStatus)
		{
			HomeAutomation::VacuumRobot* testVacuumRobot = new HomeAutomation::VacuumRobot("NewVacuumRobot", "NewBrand", "NewModel", "127.0.0.6");
			testVacuumRobot->PrintStatus();
			delete testVacuumRobot;
		}
		TEST_METHOD(VacuumRobotSetBatteryLevelException)
		{
			HomeAutomation::VacuumRobot* testVacuumRobot = new HomeAutomation::VacuumRobot("NewVacuumRobot", "NewBrand", "NewModel", "127.0.0.6");
			try
			{
				testVacuumRobot->SetBatteryLevel(101);
			}
			catch (std::invalid_argument e)
			{
				Assert::AreEqual("Battery level must be between 0 and 100.", e.what());
			}
			delete testVacuumRobot;
		}

	};
}
