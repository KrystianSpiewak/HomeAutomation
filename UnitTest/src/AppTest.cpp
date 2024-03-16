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
