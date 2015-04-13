// @author A0111378J
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EasyToDoTest
{		
	TEST_CLASS(EasyToDoTest)
	{
	public:

		TEST_METHOD(ClearTest)
		{
			E2DStorage storage;
			E2DBoost boost;
			size_t expected;
			std:: vector<TASK> actual;

			expected = 0;

			// clear all
			storage.addToMasterStorage("meet ivy", "4", "april", "17", "00", "", "", "", ""); 
			storage.addToMasterStorage("meet reuben", "4", "april", "18", "00", "", "", "", "");
			storage.addToMasterStorage("meet ivy", "27", "jun", "17", "00", "", "", "", ""); 
			storage.addToMasterStorage("meet reuben", "27", "jun", "18", "00", "", "", "", ""); 
			storage.clearAllFromStorage();
			actual = storage.retrieveMasterTaskList(); 
			Assert::AreEqual(expected,actual.size());

			// clear today
			storage.addToMasterStorage("meet ivy", "4", "april", "17", "00", "", "", "", ""); 
			storage.addToMasterStorage("meet reuben", "4", "april", "18", "00", "", "", "", ""); 
			storage.clearTodayFromStorage();
			actual = storage.retrieveTodayTaskList(); 
			Assert::AreEqual(expected,actual.size());

			// clear upcoming
			storage.addToMasterStorage("meet ivy", "27", "jun", "17", "00", "", "", "", ""); 
			storage.addToMasterStorage("meet reuben", "27", "jun", "18", "00", "", "", "", ""); 
			storage.clearUpcomingFromStorage();
			actual = storage.retrieveUpcomingTaskList();
			Assert::AreEqual(expected,actual.size());

			// clear float
			storage.addToMasterStorage("go to school", "", "", "", "", "", "", "", ""); 
			storage.addToMasterStorage("submit project", "", "", "", "", "", "", "", ""); 
			storage.clearFloatingFromStorage();
			actual = storage.retrieveFloatingTaskList();
			Assert::AreEqual(expected,actual.size());
		}		
	};
}