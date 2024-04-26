/**
 Student Name: Krystian Spiewak
 File description: This file is testing the Light class.
 Dependencies: pch.h, CppUnitTest.h, Light.h
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "HomeAutomation/Light.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace HomeAutomation
{
	TEST_CLASS(LightTest)
	{
	public:
		TEST_METHOD(LightObjectCreated)
		{
			HomeAutomation::Light* testLight = new HomeAutomation::Light("Test Light", "Test Brand", "Test Model", "127.0.0.2");
			Assert::IsNotNull(testLight);
			delete testLight;
		}
		TEST_METHOD(LightTogglePower)
		{
			HomeAutomation::Light* testLight = new HomeAutomation::Light("Test Light", "Test Brand", "Test Model", "127.0.0.2");
			testLight->ToggleOnOff();
			Assert::IsTrue(testLight->IsOn());
			testLight->ToggleOnOff();
			Assert::IsFalse(testLight->IsOn());
			delete testLight;
		}
		TEST_METHOD(LightSetBrightness)
		{
			HomeAutomation::Light* testLight = new HomeAutomation::Light("Test Light", "Test Brand", "Test Model", "127.0.0.2");
			testLight->SetBrightness(50);
			Assert::AreEqual(50, testLight->GetBrightness());
			delete testLight;
		}
		TEST_METHOD(LightPrintStatus)
		{
			HomeAutomation::Light* testLight = new HomeAutomation::Light("Test Light", "Test Brand", "Test Model", "127.0.0.2");
			testLight->PrintStatus();
			delete testLight;
		}
		TEST_METHOD(LightSetBrightnessException)
		{
			HomeAutomation::Light* testLight = new HomeAutomation::Light("Test Light", "Test Brand", "Test Model", "127.0.0.2");
			try
			{
				testLight->SetBrightness(101);
			}
			catch (std::invalid_argument e)
			{
				Assert::AreEqual("Brightness level must be between 10 and 100.", e.what());
			}
			delete testLight;
		}
		TEST_METHOD(LightSetBrightnessException2)
		{
			HomeAutomation::Light* testLight = new HomeAutomation::Light("Test Light", "Test Brand", "Test Model", "127.0.0.2");
			try
			{
				testLight->SetBrightness(9);
			}
			catch (std::invalid_argument e)
			{
				Assert::AreEqual("Brightness level must be between 10 and 100.", e.what());
			}
			delete testLight;
		}

	};
}
