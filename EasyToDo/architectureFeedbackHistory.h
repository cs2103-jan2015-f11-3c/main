#ifndef ARCHITECTUREFEEDBACKHISTORY_H_
#define ARCHITECTUREFEEDBACKHISTORY_H_

#include "architectureLogic.h"

#include <iostream>
#include <vector>
#include <algorithm>

class architectureLogic::architectureFeedbackHistory {
	private:
		static std:: vector<std:: string> masterFeedbackList;
	public:
		architectureFeedbackHistory();
		static void addToFeedbackList(std:: string feedback);
		static std:: vector<std:: string>architectureFeedbackHistory::retrieveFeedbackList();
};

#endif