#include "architectureBoost.h"
#include "architectureLogging.h"

const std:: string architectureBoost::SEVERITY_LEVEL_INFO = "Info";
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
	date inputDate; 
	days dayDifference;

	architectureStorage::clearUpcomingTaskList();
	architectureStorage::clearTodayTaskList();
	//goes through all the task in masterstorage to check if task is considered today or upcoming
	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) { 
		
		inputDate = (iter->startDateTime).date();
		dayDifference = inputDate - dateToday;

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
	days day(0);
	ptime today =  second_clock::local_time();
	//goes through all the task in the tasklist to check if task is overdued
	for(iter = todayTaskList.begin(); iter != todayTaskList.end(); iter++) {
		temp = (iter->startDateTime).date();
		dayDifference = temp - dateToday;
		if(isTaskOverdue(dayDifference)) {
			iter->overdue = true;
			architectureLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), iter->taskDescriptionList + " is overdue");
		}
		if(dayDifference == day){
			if( today.time_of_day() > (iter->startDateTime).time_of_day()) {
				iter->overdue = true;
				architectureLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), iter->taskDescriptionList + " is overdue");
			}
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

TASK architectureBoost::checkClashTask(TASK temp, std:: vector<TASK>& taskList) {
	std:: vector<TASK>::iterator iter;
	date dateToday = retrieveDateToday();

	//goes through all the task in the tasklist to check if tasks are clashed
	for(iter = taskList.begin(); iter != taskList.end(); iter++) {
		if((iter->startDateTime).date() == (temp.startDateTime).date()) {
			if(iter->endTime.is_not_a_date_time() && temp.endTime.is_not_a_date_time()) {
				if(iter->startDateTime == temp.startDateTime) {
					iter->clash = true;
					temp.clash = true;
					architectureStorage::updateClashStatus(*iter);
					architectureStorage::updateClashStatus(temp);
					architectureLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), iter->taskDescriptionList + " clash with " + temp.taskDescriptionList);
				}
			} else {
				time_period tp1(iter->startDateTime, ptime(iter->startDateTime.date(), hours(iter->endTime.hours())));
				time_period tp2(temp.startDateTime, ptime(temp.startDateTime.date(), hours(temp.endTime.hours())));
				if(tp2.intersects(tp1)) {
					iter->clash = true;
					temp.clash = true;
					architectureStorage::updateClashStatus(*iter);
					architectureStorage::updateClashStatus(temp);
					architectureLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), iter->taskDescriptionList + " clash with " + temp.taskDescriptionList);
				}
			}
		}
	}

	return temp;
}