/**
 Student Name: Krystian Spiewak
 File description: This file is testing the Menu class.
 Dependencies: pch.h, CppUnitTest.h, MenuDisplay.h
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "HomeAutomation/MenuDisplay.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace HomeAutomation
{
	TEST_CLASS(MenuDisplayTest)
	{
	public:
		TEST_METHOD(MenuObjectCreated)
		{
			HomeAutomation::MenuDisplay* testMenu = new HomeAutomation::MenuDisplay();
			Assert::IsNotNull(testMenu);
			delete testMenu;
		}
		
	};
}
