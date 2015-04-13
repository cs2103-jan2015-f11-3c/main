// @author A0111472U
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EasyToDoTest
{		
	TEST_CLASS(EasyToDoTest)
	{
	public:
		
		TEST_METHOD(FilterTest)
		{
			E2DParser parser;
			E2DStorage storage;
			E2DInputFeedback feedback;
			std:: string expected; 

			feedback.clearMasterFeedbackList();
			parser.pushUserInput("clear all");
			parser.pushUserInput("clear today");
			parser.pushUserInput("clear upcoming");
			parser.pushUserInput("clear float");

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

			parser.pushUserInput("fil 12 mar");
			std:: vector<TASK> actualList = storage.retrieveTodayTaskList();
			expected = "meet ivy";
			Assert::AreEqual(expected, actualList[0].taskDescriptionList);

			parser.pushUserInput("display");

			parser.pushUserInput("filter 15 jun");
			actualList = storage.retrieveUpcomingTaskList();
			std:: vector<std:: string> expectedList;
			expectedList.push_back("meet haha");
			expectedList.push_back("meet for xbox");

			for(int i = 0; i < expectedList.size(); i++) {
				Assert::AreEqual(expectedList[i], actualList[i].taskDescriptionList);
			}

			parser.pushUserInput("display");

			// valid date and month but can't be found
			parser.pushUserInput("filter 15 dec");
			std:: vector<std:: string> actual = feedback.retrieveFeedbackList();
			expected = "Sorry, no match found!";
			Assert::AreEqual(expected, actual[12]);

			// invalid date
			parser.pushUserInput("fil 54 dec");
			actual = feedback.retrieveFeedbackList();
			expected = "ERROR! Invalid Command";
			Assert::AreEqual(expected, actual[13]);
		}
	};
}