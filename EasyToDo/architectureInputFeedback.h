#ifndef ARCHITECTUREINPUTFEEDBACK_H_
#define ARCHITECTUREINPUTFEEDBACK_H_

#include <iostream>
#include <vector>
#include <stack>
#include <string>

class architectureInputFeedback {
private:
	static std:: stack<std:: string> masterInputList;
	static std:: stack<std:: string> masterInputListDown;
	static std:: vector<std:: string> masterFeedbackList;

public:
	architectureInputFeedback();
	static void addToMasterInputList(std:: string input);
	static void addToMasterFeedbackList(std:: string feedback);
	static void removeFromMasterInputList();
	static void removeFromMasterInputListDown();
	static std:: stack<std:: string> retrieveInputList();
	static std:: stack<std:: string> retrieveInputListDown();
	static std:: vector<std:: string> retrieveFeedbackList();
	
};
#endif

