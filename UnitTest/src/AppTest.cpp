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
		TEST_METHOD(TestAppNotRunning)
		{
			HomeAutomation::Application* testApp = HomeAutomation::CreateApplication();
			Assert::IsNotNull(testApp);
			Assert::IsFalse(testApp->IsRunning());
			delete testApp;
		}
		TEST_METHOD(TestAppRunAndStop)
		{
			HomeAutomation::Application* testApp = HomeAutomation::CreateApplication();
			testApp->Run();
			Assert::IsTrue(testApp->IsRunning());
			testApp->Close();
			Assert::IsFalse(testApp->IsRunning());
			delete testApp;
		}
	};
}

class TestApp : public HomeAutomation::Application
{
public:
	TestApp()
	{
	}

	~TestApp()
	{
	}
};

HomeAutomation::Application* HomeAutomation::CreateApplication()
{
	return new TestApp();
}
