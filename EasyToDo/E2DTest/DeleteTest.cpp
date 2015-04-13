// @author A0111378J
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EasyToDoTest
{		
	TEST_CLASS(EasyToDoTest)
	{
	public:

		TEST_METHOD(DeleteTest)
		{
			E2DStorage storageDelete;
			E2DParser parser;
			size_t expected;
			storageDelete.clearAllFromStorage();
			storageDelete.clearTodayFromStorage();
			storageDelete.clearUpcomingFromStorage();
			storageDelete.clearFloatingFromStorage();

			storageDelete.addToMasterStorage("meet ivy", "4", "april", "17", "00", "", "", "", "");
			storageDelete.addToMasterStorage("meet reuben", "4", "april", "18", "00", "", "", "", "");
			parser.pushUserInput("delete today 1");

			std:: vector<TASK> actual = storageDelete.retrieveTodayTaskList();  
			expected = 1; 
			Assert::AreEqual(expected,actual.size());

			storageDelete.addToMasterStorage("meet ivy", "27", "december", "17", "00", "", "", "", ""); 
			storageDelete.addToMasterStorage("meet reuben", "27", "april", "18", "00", "", "", "", "");

			expected = 2;
			actual = storageDelete.retrieveUpcomingTaskList(); 
			Assert::AreEqual(expected,actual.size());

			expected = 3; 
			actual = storageDelete.retrieveMasterTaskList(); 
			Assert::AreEqual(expected,actual.size());

			parser.pushUserInput("delete upcoming 1");
			expected = 1; 
			actual = storageDelete.retrieveUpcomingTaskList(); 
			Assert::AreEqual(expected,actual.size());

			storageDelete.addToMasterStorage("go to school", "", "", "", "", "", "", "", ""); 
			storageDelete.addToMasterStorage("submit project", "", "", "", "", "", "", "", "");
			expected = 2; 
			actual = storageDelete.retrieveFloatingTaskList(); 
			Assert::AreEqual(expected,actual.size());

			parser.pushUserInput("delete float 1");
			expected = 1; 
			actual = storageDelete.retrieveFloatingTaskList();
			Assert::AreEqual(expected,actual.size()); 
		}
	};
}