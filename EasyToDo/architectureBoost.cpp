#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"
#include "architectureBoost.h"

bool compareStartTime(const TASK &a, const TASK &b) {
	if(a.startDateTime.date() == b.startDateTime.date()) {
		return a.startDateTime.time_of_day() < b.startDateTime.time_of_day();
	} else {
		return a.startDateTime.date() < b.startDateTime.date();
	}
}

architectureBoost::architectureBoost() {
}

void architectureBoost::sortTodayUpcoming(std:: vector<TASK>& masterTaskList) {

	std:: vector<TASK>::iterator iter;
	
	date dateToday = retrieveDateToday();
	date temp; 
	days dayDifference;
	time_duration temp2;

	architectureStorage::clearUpcomingFromStorage();
	architectureStorage::clearTodayFromStorage();
	
	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) {
		temp = (iter->startDateTime).date();
		temp2 = (iter->startDateTime).time_of_day();
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

void architectureBoost::sortWithinTodayUpcoming(std:: vector<TASK>& todayUpcomingTaskList) {
	std::sort(todayUpcomingTaskList.begin(),todayUpcomingTaskList.end(),compareStartTime);
}

