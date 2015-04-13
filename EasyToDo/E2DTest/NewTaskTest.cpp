// @author A0111472U
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EasyToDoTest
{		
	TEST_CLASS(EasyToDoTest)
	{
	public:
		// addToMasterStorage(std:: string _contentDescripton, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
		// std:: string _contentStartMinutes, std:: string _contentEndDay, std:: string _contentEndMonth, std:: string _contentEndHours, std:: string _contentEndMinutes)

		TEST_METHOD(NewTaskTest)
		{
			E2DStorage storage;
			E2DParser parser;
			E2DInputFeedback feedback;
			
			feedback.clearMasterFeedbackList();
			parser.pushUserInput("clear all");

			parser.pushUserInput("add meet ivy on 12 may 14:00");
			std:: vector<TASK> actual = storage.retrieveMasterTaskList();
			Assert::IsTrue(actual[0].newTask);

			parser.pushUserInput("add meet ivy today");
			actual = storage.retrieveMasterTaskList();
			Assert::IsTrue(!actual[0].newTask);

			actual = storage.retrieveFloatingTaskList();
			Assert::IsTrue(actual[0].newTask);
		}
	};
}