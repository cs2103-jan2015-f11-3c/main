#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EasyToDoTest
{		
	TEST_CLASS(EasyToDoTest)
	{
	public:
		
		TEST_METHOD(UndoTest)
		{
			Parser parser;
			architectureStorage storage;
			
			parser.pushUserInput("add meet ivy on 14 mar 14:00");
			parser.pushUserInput("add meet zx on 5 mar 15:00");
			parser.pushUserInput("add meet reuben on 14 feb 14:00");
			parser.pushUserInput("undo");
			std:: vector<TASK> actualList = storage.retrieveTodayTaskList();

			storage.clearTodayFromStorage();
			storage.addToMasterStorage("meet zx", "5", "feb", "15", "00", "", "");
			storage.addToMasterStorage("meet ivy", "14", "mar", "14", "00", "", "");

			std:: vector<TASK> expectedList = storage.retrieveTodayTaskList();
			Assert::AreEqual(expectedList.size(), actualList.size());
			
			for (int i=0; i< expectedList.size(); i++) {
				Assert::AreEqual(expectedList[i].taskDescriptionList, actualList[i].taskDescriptionList);
			}
		}
	};
}