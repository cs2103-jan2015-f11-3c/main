// @author A0115188A
#ifndef E2DInputFeedback_H_
#define E2DInputFeedback_H_
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "assert.h"


// this class stores both the input and feedback using stack and vector respectively
// it should be used if the user wants to see a feedback or to have shortcuts regarding the input

class E2DInputFeedback
{
private:
	static std:: stack<std:: string> masterInputList;
	static std:: stack<std:: string> masterInputListDown;
	static std:: vector<std:: string> masterFeedbackList;

public:
	E2DInputFeedback(void);
	~E2DInputFeedback(void);
	static void addToMasterInputList(std:: string input);
	static void addToMasterFeedbackList(std:: string feedback);

	// as the user press UP, it will move the input from masterInputList to masterInputListDown
	static void removeFromMasterInputList();
	
	// as the user press DOWN, it will move the input from masterInputListDown to masterInputList
	static void removeFromMasterInputListDown();
	
	static std:: stack<std:: string> retrieveInputList();
	static std:: stack<std:: string> retrieveInputListDown();
	static std:: vector<std:: string> retrieveFeedbackList();
	static void clearMasterFeedbackList();
};
#endif