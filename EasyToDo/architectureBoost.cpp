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

	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) {

		temp = (iter->startDateTime).date();

		dayDifference = temp - dateToday;

		if(isValidTodayTask(dayDifference)) {

			architectureStorage::storeTodayTask(*iter);

		} else {

			architectureStorage::storeUpcomingTask(*iter);

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
