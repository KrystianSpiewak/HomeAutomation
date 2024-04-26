/**
 Student Name: Krystian Spiewak
 File description: This file is testing the SecuritySystem class.
 Dependencies: pch.h, CppUnitTest.h, SecuritySystem.h

 Last modified: 04/26/2024
 Update test cases to include parametrized constructor.
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "HomeAutomation/SecuritySystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace HomeAutomation
{
	TEST_CLASS(SecuritySystemTest)
	{
	public:
		TEST_METHOD(SecuritySystemObjectCreated)
		{
			SecuritySystem securitySystem("TestSecuritySystem", "TestBrand", "TestModel", "127.0.0.3");
			Assert::IsNotNull(&securitySystem);
			Assert::AreEqual("TestSecuritySystem", securitySystem.GetName().c_str());
			Assert::AreEqual("TestBrand", securitySystem.GetBrand().c_str());
			Assert::AreEqual("TestModel", securitySystem.GetModel().c_str());
			Assert::IsFalse(securitySystem.IsArmed());
			Assert::IsFalse(securitySystem.IsAlarmActivated());
		}
		TEST_METHOD(SecuritySystemArmed)
		{
			SecuritySystem securitySystem("TestSecuritySystem", "TestBrand", "TestModel", "127.0.0.3");
			securitySystem.ArmSystem();
			Assert::IsTrue(securitySystem.IsArmed());
		}
		TEST_METHOD(SecuritySystemDisarmed)
		{
			SecuritySystem securitySystem("TestSecuritySystem", "TestBrand", "TestModel", "127.0.0.3");
			securitySystem.ArmSystem();
			securitySystem.DisarmSystem();
			Assert::IsFalse(securitySystem.IsArmed());
		}
		TEST_METHOD(SecuritySystemAlarmActivated)
		{
			SecuritySystem securitySystem("TestSecuritySystem", "TestBrand", "TestModel", "127.0.0.3");
			securitySystem.ArmSystem();
			securitySystem.TriggerAlarm();
			securitySystem.IsAlarmActivated();
			Assert::IsTrue(securitySystem.IsAlarmActivated());
		}
		TEST_METHOD(SecuritySystemPrintStatus)
		{
			SecuritySystem securitySystem("TestSecuritySystem", "TestBrand", "TestModel", "127.0.0.3");
			securitySystem.ArmSystem();
			securitySystem.PrintStatus();
		}

	};
}
