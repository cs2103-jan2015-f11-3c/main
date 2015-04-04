#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"
#include "architectureBoost.h"

// this comparison functio is for us to use the sort function in algorithm library to 
// sort our tasks in today and upcoming
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
	time_duration temp2; // can remove this?

	architectureStorage::clearUpcomingTaskList();
	architectureStorage::clearTodayTaskList();
	
	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) {
		temp = (iter->startDateTime).date();
		temp2 = (iter->startDateTime).time_of_day(); // can remove this?
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

void architectureBoost::checkOverdueTask(std:: vector<TASK>& todayTaskList) {
	std:: vector<TASK>::iterator iter;
	date dateToday = retrieveDateToday();
	date temp; 
	days dayDifference;

	for(iter = todayTaskList.begin(); iter != todayTaskList.end(); iter++) {
		temp = (iter->startDateTime).date();
		dayDifference = temp - dateToday;
		if(isTaskOverdue(dayDifference)) {
			iter->overdue = true;
		}
	}
}

bool architectureBoost::isTaskOverdue(days dayDifference) {
	days day(0);
	if (dayDifference < day) {
		return true;
	} else {
		return false;
	}
}

void architectureBoost::checkClashTask(TASK temp, std:: vector<TASK>& taskList) {
	std:: vector<TASK>::iterator iter;
	date dateToday = retrieveDateToday();
	/*
	time_period tp1(ptime(d,hours(1)), ptime(d,hours(12)));
	time_period tp2(ptime(d,hours(2)), ptime(d,hours(4)));
	tp2.intersects(tp1); // --> true

	*/
	for(iter = taskList.begin(); iter != taskList.end(); iter++) {
		if((iter->startDateTime).date() == (temp.startDateTime).date()) {
			if(iter->endTime.is_not_a_date_time() && temp.endTime.is_not_a_date_time()) {
				if(iter->startDateTime == temp.startDateTime) {
					iter->clash = true;
					temp.clash = true;
				}
			} else {
				time_period tp1(iter->startDateTime, ptime(iter->startDateTime.date(), hours(iter->endTime.hours())));
				time_period tp2(temp.startDateTime, ptime(temp.startDateTime.date(), hours(temp.endTime.hours())));
				if(tp2.intersects(tp1)) {
					temp.clash = true;
					iter->clash = true;
				}
			}
		}
	}
}