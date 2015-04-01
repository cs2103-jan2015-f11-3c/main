#include "architectureInputFeedback.h"

std:: vector<std:: string> architectureInputFeedback::masterInputList;
std:: vector<std:: string> architectureInputFeedback::masterFeedbackList;

architectureInputFeedback::architectureInputFeedback() {
}

void architectureInputFeedback::addToMasterInputList(std:: string input) {
	masterInputList.push_back(input);
}

void architectureInputFeedback::addToMasterFeedbackList(std:: string feedback) {
	masterFeedbackList.push_back(feedback);
}

std:: vector<std:: string> architectureInputFeedback::retrieveInputList() {
	return masterInputList;
}

std:: vector<std:: string> architectureInputFeedback::retrieveFeedbackList() {
	return masterFeedbackList;
}

