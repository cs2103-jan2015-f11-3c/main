// @author A0111378J
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EasyToDoTest
{		
	TEST_CLASS(EasyToDoTest)
	{
	public:
		
		TEST_METHOD(ClashTaskTest)
		{
			E2DParser parser;
			E2DStorage storage;
			E2DInputFeedback feedback;

			storage.clearAllFromStorage();
			storage.clearTodayFromStorage();
			storage.clearUpcomingFromStorage();
			storage.clearFloatingFromStorage();

			parser.pushUserInput("add meet ivy on 14 may 14:00");

			std:: vector<TASK> actualList = storage.retrieveUpcomingTaskList();
			Assert::IsTrue(!actualList[0].clash);

			parser.pushUserInput("add meet zx on 17 may 14:00");

			actualList = storage.retrieveUpcomingTaskList();
			Assert::IsTrue(!actualList[0].clash);

			parser.pushUserInput("add meet reub from 14 may 14:00 to 16 may 15:00");
			actualList = storage.retrieveUpcomingTaskList();
			Assert::IsTrue(actualList[0].clash);
			Assert::IsTrue(actualList[1].clash);
		}
	};
}