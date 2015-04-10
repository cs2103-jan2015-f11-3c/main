#ifndef ARCHITECTUREINPUTFEEDBACK_H_
#define ARCHITECTUREINPUTFEEDBACK_H_

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "assert.h"


// this class stores both the input and feedback using stack and vector respectively
// it should be used if the user wants to see a feedback or to have shortcuts regarding the input
class architectureInputFeedback {
private:
	static std:: stack<std:: string> masterInputList;
	static std:: stack<std:: string> masterInputListDown;
	static std:: vector<std:: string> masterFeedbackList;

public:
	architectureInputFeedback();
	static void addToMasterInputList(std:: string input);
	static void addToMasterFeedbackList(std:: string feedback);

	// as the user press UP, it will move the input from masterInputList to masterInputListDown
	static void removeFromMasterInputList();
	
	// as the user press DOWN, it will move the input from masterInputListDown to masterInputList
	static void removeFromMasterInputListDown();
	
	static std:: stack<std:: string> retrieveInputList();
	static std:: stack<std:: string> retrieveInputListDown();
	static std:: vector<std:: string> retrieveFeedbackList();
	
};
#endif

