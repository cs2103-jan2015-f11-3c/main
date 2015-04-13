// @author A0111472U
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EasyToDoTest
{		
	TEST_CLASS(EasyToDoTest)
	{
	public:
		
		TEST_METHOD(displayTest)
		{
			E2DParser parser;
			E2DStorage storage;
			E2DInputFeedback feedback;
			std:: string expected; 

			storage.clearAllFromStorage();
			storage.clearTodayFromStorage();
			storage.clearUpcomingFromStorage();
			storage.clearFloatingFromStorage();

			parser.pushUserInput("add meet ivy on 14 mar 14:00");
			parser.pushUserInput("add meet zx on 15 mar 15:00");
			parser.pushUserInput("add meet zx from 15 mar 15:00 to 18:00");
			parser.pushUserInput("add meet at kfc from 15 mar 15:00 to 17 mar 18:00");
			parser.pushUserInput("add meet haha from 15 jun 14:00 to 17 jun 15:00");
			parser.pushUserInput("add meet for xbox from 15 jun 14:00 to 16:00");
			parser.pushUserInput("add do homework");
			parser.pushUserInput("add submit tutorial");

			parser.pushUserInput("filter 12 mar");
			std:: vector<TASK> actualList = storage.retrieveTodayTaskList();
			expected = "meet ivy";
			Assert::AreEqual(expected, actualList[0].taskDescriptionList);
		}
	};
}