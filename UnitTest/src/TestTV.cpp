/**
 Student Name: Krystian Spiewak
 File description: This file is testing the TV class.
 Dependencies: pch.h, CppUnitTest.h, TV.h

 Last modified: 04/26/2024
 Update tests to avoid throwing exceptions.
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "HomeAutomation/TV.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace HomeAutomation
{
	TEST_CLASS(TVTest)
	{
	public:
		TEST_METHOD(TVObjectCreated)
		{
			HomeAutomation::TV* testTV = new HomeAutomation::TV();
			Assert::IsNotNull(testTV);
			delete testTV;
		}
		TEST_METHOD(TVTogglePower)
		{
			HomeAutomation::TV* testTV = new HomeAutomation::TV();
			testTV->ToggleOnOff();
			Assert::IsTrue(testTV->IsOn());
			testTV->ToggleOnOff();
			Assert::IsFalse(testTV->IsOn());
			delete testTV;
		}
		TEST_METHOD(TVIncreaseVolume)
		{
			HomeAutomation::TV* testTV = new HomeAutomation::TV();
			testTV->IncreaseVolume();
			Assert::AreEqual(1, testTV->GetVolume());
			delete testTV;
		}
		TEST_METHOD(TVDecreaseVolume)
		{
			HomeAutomation::TV* testTV = new HomeAutomation::TV();
			testTV->IncreaseVolume();
			testTV->DecreaseVolume();
			Assert::AreEqual(0, testTV->GetVolume());
			delete testTV;
		}
		TEST_METHOD(TVSetChannel)
		{
			HomeAutomation::TV* testTV = new HomeAutomation::TV();
			testTV->SetChannel(20);
			Assert::AreEqual(20, testTV->GetChannel());
			delete testTV;
		}
		TEST_METHOD(TVChangeChannelUp)
		{
			HomeAutomation::TV* testTV = new HomeAutomation::TV();
			testTV->SetChannel(20);
			testTV->ChangeChannelUp();
			Assert::AreEqual(21, testTV->GetChannel());
			delete testTV;
		}
		TEST_METHOD(TVChangeChannelDown)
		{
			HomeAutomation::TV* testTV = new HomeAutomation::TV();
			testTV->SetChannel(20);
			testTV->ChangeChannelDown();
			Assert::AreEqual(19, testTV->GetChannel());
			delete testTV;
		}
		TEST_METHOD(TVPrintStatus)
		{
			HomeAutomation::TV* testTV = new HomeAutomation::TV();
			testTV->SetChannel(20);
			testTV->PrintStatus();
			delete testTV;
		}

	};
}
