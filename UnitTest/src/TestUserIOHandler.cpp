/**
 Student Name: Krystian Spiewak
 File description: This file is testing the UserIOHandler class.
 Dependencies: pch.h, CppUnitTest.h, UserIOHandler.h
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "HomeAutomation/UserIOHandler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace HomeAutomation
{
	TEST_CLASS(UserIOHandlerTest)
	{
	public:
		TEST_METHOD(UserIOObjectCreated)
		{
			HomeAutomation::UserIOHandler* testIO = new HomeAutomation::UserIOHandler();
			Assert::IsNotNull(testIO);
			delete testIO;
		}

	};
}
