// @author A0115188A
#include "E2DInputFeedback.h"

std:: stack<std:: string> E2DInputFeedback::masterInputList;
std:: stack<std:: string> E2DInputFeedback::masterInputListDown;
std:: vector<std:: string> E2DInputFeedback::masterFeedbackList;


E2DInputFeedback::E2DInputFeedback(void) {
}


E2DInputFeedback::~E2DInputFeedback(void) {
}

void E2DInputFeedback::addToMasterInputList(std:: string input) {
	assert(input != "");
	masterInputList.push(input);
}

void E2DInputFeedback::addToMasterFeedbackList(std:: string feedback) {
	assert(feedback != "");
	masterFeedbackList.push_back(feedback);
}

void E2DInputFeedback::removeFromMasterInputList() {

	std:: string topInput = masterInputList.top();
	masterInputListDown.push(topInput);
	masterInputList.pop();
}

void E2DInputFeedback::removeFromMasterInputListDown() {
	
	std:: string downInput = masterInputListDown.top();
	masterInputList.push(downInput);
	masterInputListDown.pop();
}

std:: stack<std:: string> E2DInputFeedback::retrieveInputList() {
	return masterInputList;
}

std:: stack<std:: string> E2DInputFeedback::retrieveInputListDown() {

	// it needs to pop the top one out because the top of this stack will be
	// exactly the same as the previous input
	if (!masterInputListDown.empty()) {
		masterInputListDown.pop();
	}
	return masterInputListDown;
}

std:: vector<std:: string> E2DInputFeedback::retrieveFeedbackList() {
	return masterFeedbackList;
}

void E2DInputFeedback::clearMasterFeedbackList() {
	masterFeedbackList.clear();
}