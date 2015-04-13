// @author A0115188A
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EasyToDoTest
{		
	TEST_CLASS(EasyToDoTest)
	{
	public:
		// undo is extended to add, update, delete, clear, done
		TEST_METHOD(UndoTest)
		{
			E2DParser parser;
			E2DStorage storage;
			size_t expected;
			std:: vector<TASK> actual;

			parser.pushUserInput("clear all");
			parser.pushUserInput("clear today");
			parser.pushUserInput("clear upcoming");
			parser.pushUserInput("clear float");
			
			storage.clearAllFromStorage();
			storage.clearTodayFromStorage();
			storage.clearUpcomingFromStorage();
			storage.clearFloatingFromStorage();

			parser.pushUserInput("add meet ivy on 14 mar 14:00");
			parser.pushUserInput("add meet zx on 5 mar 15:00");
			parser.pushUserInput("add meet reuben on 14 feb 14:00");
			parser.pushUserInput("undo");
			actual = storage.retrieveTodayTaskList();
			expected = 2;
			Assert::AreEqual(expected,actual.size());

			parser.pushUserInput("clear all");
			parser.pushUserInput("undo");
			Assert::AreEqual(expected,actual.size());

			parser.pushUserInput("delete today 1");
			parser.pushUserInput("undo");
			Assert::AreEqual(expected,actual.size());

			// shift one task from todayTaskList to floatingTaskList
			parser.pushUserInput("update today 1 gym more frequently");
			expected = 1;
			actual = storage.retrieveFloatingTaskList();
			Assert::AreEqual(expected,actual.size());

			parser.pushUserInput("undo");
			expected = 2;
			actual = storage.retrieveTodayTaskList();
			Assert::AreEqual(expected,actual.size());

			parser.pushUserInput("done today 1");
			actual = storage.retrieveTodayTaskList();
			Assert::IsTrue(actual[0].done);

			parser.pushUserInput("undo");
			actual = storage.retrieveTodayTaskList();
			Assert::IsTrue(!actual[0].done);
		}
	};
}