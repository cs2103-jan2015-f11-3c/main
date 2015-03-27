#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"
#include "architectureBoost.h"

architectureBoost::architectureBoost() {
}

void architectureBoost::sortTodayUpcoming(std:: vector<TASK>& masterTaskList) {

	std:: vector<TASK>::iterator iter;
	
	date dateToday = retrieveDateToday();
	date temp; 
	days dayDifference;

	architectureStorage::clearUpcomingFromStorage();
	architectureStorage::clearTodayFromStorage();
	
	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) {
		temp = (iter->startDateTime).date();
		dayDifference = temp - dateToday;

		if(isValidTodayTask(dayDifference)) {
			architectureStorage::storeUpcomingTask(*iter);
		} else {
			architectureStorage::storeTodayTask(*iter);
		}
	}

}

bool architectureBoost::isValidTodayTask(days dayDifference) {
	days day(1);
	if (dayDifference >= day) {
		return true;
	} else {
		return false;
	}

}

date architectureBoost::retrieveDateToday() {
	ptime today = second_clock::local_time();
	date dateToday = today.date();
	return dateToday;
}
