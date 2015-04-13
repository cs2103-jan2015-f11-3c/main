// @author A0111472U
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EasyToDoTest
{		
	TEST_CLASS(EasyToDoTest)
	{
	public:
		
		TEST_METHOD(OverdueTaskTest)
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
			parser.pushUserInput("a do homework");

			std:: vector<TASK> actualList = storage.retrieveTodayTaskList();
			Assert::IsTrue(actualList[0].overdue);

			actualList = storage.retrieveFloatingTaskList();
			Assert::IsTrue(!actualList[0].overdue);

			parser.pushUserInput("up today 1 meet haha from 15 jun 14:00 to 17 jun 15:00");
			actualList = storage.retrieveUpcomingTaskList();
			Assert::IsTrue(!actualList[0].overdue);
		}
	};
}