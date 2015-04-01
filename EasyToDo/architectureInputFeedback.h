#ifndef ARCHITECTUREINPUTFEEDBACK_H_
#define ARCHITECTUREINPUTFEEDBACK_H_

#include <iostream>
#include <vector>
#include <string>

class architectureInputFeedback {
private:
	static std:: vector<std:: string> masterInputList;
	static std:: vector<std:: string> masterFeedbackList;

public:
	architectureInputFeedback();
	static void addToMasterInputList(std:: string input);
	static void addToMasterFeedbackList(std:: string feedback);
	static std:: vector<std:: string> retrieveInputList();
	static std:: vector<std:: string> retrieveFeedbackList();
};
#endif

