// @author A0111472U
#include "E2DBoost.h"
#include "E2DLogging.h"

const std:: string E2DBoost::SEVERITY_LEVEL_INFO = "Info";
// this comparison functio is for us to use the sort function in algorithm library to 
// sort our tasks in today and upcoming
bool compareStartTime(const TASK &a, const TASK &b) {
	if(a.startDateTime.date() == b.startDateTime.date()) {
		return a.startDateTime.time_of_day() < b.startDateTime.time_of_day();
	} else {
		return a.startDateTime.date() < b.startDateTime.date();
	}
}

E2DBoost::E2DBoost(void) {
}


E2DBoost::~E2DBoost(void) {
}

void E2DBoost::sortTodayUpcoming(std:: vector<TASK>& masterTaskList) {

	std:: vector<TASK>::iterator iter;
	
	date dateToday = retrieveDateToday();
	date inputDate; 
	days dayDifference;

	E2DStorage::clearUpcomingTaskList();
	E2DStorage::clearTodayTaskList();
	//goes through all the task in masterstorage to check if task is considered today or upcoming
	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) { 
		
		inputDate = (iter->startDateTime).date();
		dayDifference = inputDate - dateToday;

		if(isValidTodayTask(dayDifference)) {
			E2DStorage::storeUpcomingTask(*iter);
		} else {
			E2DStorage::storeTodayTask(*iter);
		}
	}
}

bool E2DBoost::isValidTodayTask(days dayDifference) {
	days day(1);
	if (dayDifference >= day) {
		return true;
	} else {
		return false;
	}
}

date E2DBoost::retrieveDateToday() {
	ptime today = second_clock::local_time();
	date dateToday = today.date();
	return dateToday;
}

void E2DBoost::sortWithinTodayUpcoming(std:: vector<TASK>& todayUpcomingTaskList) {
	std::sort(todayUpcomingTaskList.begin(),todayUpcomingTaskList.end(),compareStartTime);
}

void E2DBoost::checkOverdueTask(std:: vector<TASK>& todayTaskList) {
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
			E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), iter->taskDescriptionList + " is overdue");
		}
		if(dayDifference == day){
			if( today.time_of_day() > (iter->startDateTime).time_of_day()) {
				iter->overdue = true;
				E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), iter->taskDescriptionList + " is overdue");
			}
		}
	}
}


bool E2DBoost::isTaskOverdue(days dayDifference) {
	days day(0);
	if (dayDifference < day) {
		return true;
	} else {
		return false;
	}
}

TASK E2DBoost::checkClashTask(TASK temp, std:: vector<TASK>& taskList) {
	std:: vector<TASK>::iterator iter;
	date dateToday = retrieveDateToday();

	//goes through all the task in the tasklist to check if tasks are clashed
	for(iter = taskList.begin(); iter != taskList.end(); iter++) {
		if((iter->startDateTime).date() == (temp.startDateTime).date()) {
			if(iter->endTime.is_not_a_date_time() && temp.endTime.is_not_a_date_time()) {
				if(iter->startDateTime == temp.startDateTime) {
					iter->clash = true;
					temp.clash = true;
					E2DStorage::updateClashStatus(*iter);
					E2DStorage::updateClashStatus(temp);
					E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), iter->taskDescriptionList + " clash with " + temp.taskDescriptionList);
				}
			} else {
				time_period tp1(iter->startDateTime, ptime(iter->startDateTime.date(), hours(iter->endTime.hours())));
				time_period tp2(temp.startDateTime, ptime(temp.startDateTime.date(), hours(temp.endTime.hours())));
				if(tp2.intersects(tp1)) {
					iter->clash = true;
					temp.clash = true;
					E2DStorage::updateClashStatus(*iter);
					E2DStorage::updateClashStatus(temp);
					E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), iter->taskDescriptionList + " clash with " + temp.taskDescriptionList);
				}
			}
		}
	}

	return temp;
}