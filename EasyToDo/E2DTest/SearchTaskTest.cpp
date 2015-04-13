// @author A0111472U
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EasyToDoTest
{		
	TEST_CLASS(EasyToDoTest)
	{
	public:
		
		TEST_METHOD(SearchTest)
		{
			E2DParser parser;
			E2DStorage storage;
			E2DInputFeedback feedback;

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
			parser.pushUserInput("add meet zx on 5 mar 15:00");
			parser.pushUserInput("add do homework");
			parser.pushUserInput("add submit tutorial");

			parser.pushUserInput("search submit");
			std:: vector<TASK> actual = storage.retrieveFloatingTaskList();
			std:: string expected = "submit tutorial";
			Assert::AreEqual(expected, actual[0].taskDescriptionList);

			parser.pushUserInput("display");

			// test search shortcut
			parser.pushUserInput("src et i");
			actual = storage.retrieveTodayTaskList();		
			expected = "meet ivy";
			Assert::AreEqual(expected, actual[0].taskDescriptionList);
			
			// search an invalid content
			parser.pushUserInput("search asdfdfd");
			std:: vector<std:: string> actualList = feedback.retrieveFeedbackList();
			expected = "Sorry, no match found!";
			Assert::AreEqual(expected, actualList[7]);
		}
	};
}