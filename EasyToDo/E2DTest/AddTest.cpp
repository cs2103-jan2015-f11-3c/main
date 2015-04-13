// @author A0115188A
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace E2DTest
{		
	TEST_CLASS(E2DTest)
	{
	public:
		
		
		// addToMasterStorage(std:: string _contentDescripton, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
		// std:: string _contentStartMinutes, std:: string _contentEndDay, std:: string _contentEndMonth, std:: string _contentEndHours, std:: string _contentEndMinutes)

		TEST_METHOD(AddTest)
		{
			// TODO: Your test code here
			E2DStorage storageAdd;
			size_t expected;
			
			storageAdd.clearAllFromStorage();
			// test for timed task with multiple day -> added to masterTaskList & upcomingTaskList
			storageAdd.addToMasterStorage("meet ivy", "4", "jun", "17", "00", "6", "jun", "14", "56");
			// test for timed task with same startDate and endDate -> added to masterTaskList & upcomingTaskList
			storageAdd.addToMasterStorage("meet ivy", "4", "jun", "15", "00", "", "", "17", "00");
			// test for deadline task -> added to masterTaskList & upcomingTaskList
			storageAdd.addToMasterStorage("meet ivy", "4", "jun", "18", "00", "", "", "", "");
			// test for all day task -> added to masterTaskList & upcomingTaskList
			storageAdd.addToMasterStorage("meet ivy", "4", "jun", "", "", "", "", "", "");
			// test for floating task -> added to floatingTaskList
			storageAdd.addToMasterStorage("meet ivy", "", "", "", "", "", "", "", "");
			
			expected = 4;
			std:: vector<TASK> actual = storageAdd.retrieveMasterTaskList();
			Assert::AreEqual(expected, actual.size());

			actual = storageAdd.retrieveUpcomingTaskList();
			Assert::AreEqual(expected, actual.size());

			expected = 1;
			actual = storageAdd.retrieveFloatingTaskList();
			Assert::AreEqual(expected, actual.size());

			// task will be overdue tmr but they will stil be included in todayTaskList
			// test for timed task with multiple day -> added to masterTaskList & todayTaskList
			storageAdd.addToMasterStorage("meet ivy", "4", "april", "17", "00", "6", "jun", "14", "56");
			// test for timed task with same startDate and endDate -> added to masterTaskList & todayTaskList
			storageAdd.addToMasterStorage("meet ivy", "4", "april", "15", "00", "", "", "17", "00");
			// test for deadline task -> added to masterTaskList & todayTaskList
			storageAdd.addToMasterStorage("meet ivy", "4", "april", "18", "00", "", "", "", "");
			// test for all day task -> added to masterTaskList & todayTaskList
			storageAdd.addToMasterStorage("meet ivy", "4", "april", "", "", "", "", "", "");
			// test for floating task -> added to floatingTaskList
			storageAdd.addToMasterStorage("study for finals", "", "", "", "", "", "", "", "");
			

			expected = 8; 
			actual = storageAdd.retrieveMasterTaskList();
			Assert::AreEqual(expected, actual.size());

			expected = 2; 
			actual = storageAdd.retrieveFloatingTaskList();
			Assert::AreEqual(expected, actual.size());
		}

		TEST_METHOD(AddInvalidTest)
		{
			// TODO: Your test code here
			E2DStorage storage;
			E2DParser parser;
			E2DInputFeedback feedback;

			feedback.clearMasterFeedbackList();

			parser.pushUserInput("clear all");
			storage.clearAllFromStorage();
			// invalid startdate
			parser.pushUserInput("add meet ivy on 34 may 14:00");
			// invalid startmonth
			parser.pushUserInput("add meet ivy on 12 poe 14:00");
			// invalid starthour
			parser.pushUserInput("add meet ivy on 12 may 26:00");
			// invalid startmin
			parser.pushUserInput("add meet ivy on 12 may 14:61");
			// invalid endDate
			parser.pushUserInput("add meet ivy from 12 may 14:00 - 29 feb 15:00");
			// invalid endMonth
			parser.pushUserInput("add meet ivy from 12 may 14:00 - 29 asd 15:00");
			// invalid endHour
			parser.pushUserInput("add meet ivy from 12 may 14:00 - 29 feb 34:00");
			// invalid endMin
			parser.pushUserInput("add meet ivy from 12 may 14:00 - 29 feb 12:76");

			std:: vector<std:: string> actual = feedback.retrieveFeedbackList();
			std:: string expected = "ERROR! Invalid Command";
			for(int i = 0; i < actual.size(); i++) {
				Assert::AreEqual(expected, actual[i]);
			}
		}

	};
}