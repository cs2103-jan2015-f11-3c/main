#include "architectureFeedbackHistory.h"

std:: vector<std:: string> architectureLogic::architectureFeedbackHistory::masterFeedbackList;
architectureLogic::architectureFeedbackHistory::architectureFeedbackHistory() {
}

void architectureLogic::architectureFeedbackHistory::addToFeedbackList(std:: string feedback) {
	masterFeedbackList.push_back(feedback);
}

std:: vector<std:: string> architectureLogic::architectureFeedbackHistory::retrieveFeedbackList() {
	std:: vector< std:: string> temp;

	for (int i=0; i<masterFeedbackList.size(); i++) {
			temp.push_back(masterFeedbackList[i]);
	}

	return temp;

}