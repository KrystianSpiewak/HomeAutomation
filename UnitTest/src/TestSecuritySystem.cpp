/**
 Student Name: Krystian Spiewak
 File description: This file is testing the SecuritySystem class.
 Dependencies: pch.h, CppUnitTest.h, SecuritySystem.h
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
			SecuritySystem securitySystem;
			Assert::IsTrue(securitySystem.GetName().empty());
			Assert::IsTrue(securitySystem.GetBrand().empty());
			Assert::IsTrue(securitySystem.GetModel().empty());
			Assert::IsTrue(securitySystem.GetNetAddr().empty());
			Assert::IsFalse(securitySystem.IsArmed());
			Assert::IsFalse(securitySystem.IsAlarmActivated());
		}
		TEST_METHOD(SecuritySystemArmed)
		{
			SecuritySystem securitySystem;
			securitySystem.ArmSystem();
			Assert::IsTrue(securitySystem.IsArmed());
		}
		TEST_METHOD(SecuritySystemDisarmed)
		{
			SecuritySystem securitySystem;
			securitySystem.ArmSystem();
			securitySystem.DisarmSystem();
			Assert::IsFalse(securitySystem.IsArmed());
		}
		TEST_METHOD(SecuritySystemAlarmActivated)
		{
			SecuritySystem securitySystem;
			securitySystem.ArmSystem();
			securitySystem.TriggerAlarm();
			securitySystem.IsAlarmActivated();
			Assert::IsTrue(securitySystem.IsAlarmActivated());
		}
		TEST_METHOD(SecuritySystemPrintStatus)
		{
			SecuritySystem securitySystem;
			securitySystem.ArmSystem();
			securitySystem.PrintStatus();
		}

	};
}
