/**
 Student Name: Krystian Spiewak
 File description: This file is the main entry point for the Test HomeAutomation Application client.
 Dependencies: pch.h, CppUnitTest.h, HomeAutomation.h

 Abstract function HomeAutomation::CreateApplication() function is defined here to create the application object.
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "HomeAutomation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace HomeAutomation
{
	TEST_CLASS(AppTest)
	{
	public:
		TEST_METHOD(TestAppCreated)
		{
			HomeAutomation::Application* testApp = HomeAutomation::CreateApplication();
			Assert::IsNotNull(testApp);
			delete testApp;
		}
		TEST_METHOD(TestAppNotRunningOnCreation)
		{
			HomeAutomation::Application* testApp = HomeAutomation::CreateApplication();
			Assert::IsNotNull(testApp);
			Assert::IsFalse(testApp->IsRunning());
			delete testApp;
		}
	};
}

/**
 TestApp is the main class for the Test HomeAutomation application client.
 */
class TestApp : public HomeAutomation::Application
{
public:
	/**
	 Default constructor for Test Application
	 */
	TestApp()
	{
	}

	/**
	 Default destructor for Test Application
	 */
	~TestApp()
	{
	}
};

/**
 Function HomeAutomation::CreateApplication(): creates the application object.
 @return Pointer to an instance of the test application object.
 */
HomeAutomation::Application* HomeAutomation::CreateApplication()
{
	return new TestApp();
}
