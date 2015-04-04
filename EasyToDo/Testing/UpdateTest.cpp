#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EasyToDoTest
{		
	TEST_CLASS(EasyToDoTest)
	{
	public:
		
		TEST_METHOD(UpdateTodayTest)
		{
			Parser parser;
			architectureStorage storage;
			
			parser.pushUserInput("add meet ivy on 14 mar 14:00");
			parser.pushUserInput("add meet zx on 5 mar 15:00");
			parser.pushUserInput("update today 1 meet reuben on 14 feb 14:00");
			std:: vector<TASK> actualList = storage.retrieveTodayTaskList();

			storage.clearTodayFromStorage();
			storage.addToMasterStorage("meet reuben", "14", "feb", "14", "00", "", "");
			storage.addToMasterStorage("meet ivy", "14", "mar", "14", "00", "", "");

			std:: vector<TASK> expectedList = storage.retrieveTodayTaskList();
			Assert::AreEqual(expectedList.size(), actualList.size());
			
			for (int i=0; i< expectedList.size(); i++) {
				Assert::AreEqual(expectedList[i].taskDescriptionList, actualList[i].taskDescriptionList);
			}
		}

		TEST_METHOD(UpdateUpcomingTest)
		{
			Parser parser;
			architectureStorage storage;

			parser.pushUserInput("add meet ivy on 14 may 14:00");
			parser.pushUserInput("add meet zx on 5 apr 15:00");
			parser.pushUserInput("update upcoming 1 meet reuben on 14 apr 14:00");
			std:: vector<TASK> actualList = storage.retrieveUpcomingTaskList();

			storage.clearUpcomingFromStorage();
			storage.addToMasterStorage("meet reuben", "14", "apr", "14", "00", "", "");
			storage.addToMasterStorage("meet ivy", "14", "may", "14", "00", "", "");

			std:: vector<TASK> expectedList = storage.retrieveUpcomingTaskList();
			Assert::AreEqual(expectedList.size(), actualList.size());
			
			for (int i=0; i< expectedList.size(); i++) {
				Assert::AreEqual(expectedList[i].taskDescriptionList, actualList[i].taskDescriptionList);
			}
		}

		TEST_METHOD(UpdateMiscTest)
		{
			Parser parser;
			architectureStorage storage;

			parser.pushUserInput("add do homework");
			parser.pushUserInput("add submit tutorial");
			parser.pushUserInput("update misc 2 submitted tutorial");
			std:: vector<TASK> actualList = storage.retrieveFloatingTaskList();

			storage.clearFloatingFromStorage();
			storage.addToMasterStorage("do homework", "", "", "", "", "", "");
			storage.addToMasterStorage("submitted tutorial", "", "", "", "", "", "");

			std:: vector<TASK> expectedList = storage.retrieveFloatingTaskList();
			Assert::AreEqual(expectedList.size(), actualList.size());
			
			for (int i=0; i< expectedList.size(); i++) {
				Assert::AreEqual(expectedList[i].taskDescriptionList, actualList[i].taskDescriptionList);
			}
		}
	};
}