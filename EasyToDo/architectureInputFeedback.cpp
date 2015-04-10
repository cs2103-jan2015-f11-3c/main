#include "architectureInputFeedback.h"

std:: stack<std:: string> architectureInputFeedback::masterInputList;
std:: stack<std:: string> architectureInputFeedback::masterInputListDown;
std:: vector<std:: string> architectureInputFeedback::masterFeedbackList;

architectureInputFeedback::architectureInputFeedback() {
}

void architectureInputFeedback::addToMasterInputList(std:: string input) {
	assert(input != "");
	masterInputList.push(input);
}

void architectureInputFeedback::addToMasterFeedbackList(std:: string feedback) {
	assert(feedback != "");
	masterFeedbackList.push_back(feedback);
}

void architectureInputFeedback::removeFromMasterInputList() {

	std:: string topInput = masterInputList.top();
	masterInputListDown.push(topInput);
	masterInputList.pop();
}

void architectureInputFeedback::removeFromMasterInputListDown() {
	
	std:: string downInput = masterInputListDown.top();
	masterInputList.push(downInput);
	masterInputListDown.pop();
}

std:: stack<std:: string> architectureInputFeedback::retrieveInputList() {
	return masterInputList;
}

std:: stack<std:: string> architectureInputFeedback::retrieveInputListDown() {

	// it needs to pop the top one out because the top of this stack will be
	// exactly the same as the previous input
	if (!masterInputListDown.empty()) {
		masterInputListDown.pop();
	}
	return masterInputListDown;
}

std:: vector<std:: string> architectureInputFeedback::retrieveFeedbackList() {
	return masterFeedbackList;
}

