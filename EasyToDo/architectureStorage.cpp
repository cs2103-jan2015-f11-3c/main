#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"
#include "architectureBoost.h"
#include "architectureHistory.h"

std:: vector<TASK> architectureStorage::masterTaskList;
std:: vector<TASK> architectureStorage::todayTaskList;
std:: vector<TASK> architectureStorage::upcomingTaskList;
std:: vector<TASK> architectureStorage::floatingTaskList;

bool operator==(const TASK& a, const TASK& b) {
		return (a.taskDescriptionList == b.taskDescriptionList) && (a.startDateTime == b.startDateTime) && (a.endTime == b.endTime);
	}

architectureStorage::architectureStorage() {
}

void architectureStorage::updateTaskID(std:: vector<TASK>& input) {
	int counter = 1;
	std:: vector<TASK>::iterator iter;
	
	for(iter = input.begin(); iter != input.end(); iter++, counter++) {
		iter->taskID = counter;
	}
}

int architectureStorage::stringToInt(std:: string input) {
	int value;
	value = atoi(input.c_str());
	return value;
}

TASK architectureStorage::initializeTimedTask(std:: string _contentDescripton, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	TASK buffer;
	buffer.taskDescriptionList = _contentDescripton;
	std::string dateString; // ("2002/1/25");
	dateString = "2015," +  _contentMonth + "," + _contentDay;
	date d(from_string(dateString));
	ptime temp(d, time_duration(hours(stringToInt(_contentStartHours))+minutes(stringToInt(_contentStartMinutes))));
	buffer.startDateTime = temp;
	buffer.endTime = time_duration(hours(stringToInt(_contentEndHours))+minutes(stringToInt(_contentEndMinutes)));
	buffer.taskID = 0;
	buffer.done = false;
	return buffer;
}

TASK architectureStorage::initializeDeadlineTask(std:: string _contentDescripton, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes) {
	TASK buffer;
	buffer.taskDescriptionList = _contentDescripton;
	std::string dateString; // ("2002/1/25");
	dateString = "2015," + _contentMonth + "," + _contentDay;
	date d(from_string(dateString));
	ptime temp(d, time_duration(hours(stringToInt(_contentStartHours))+minutes(stringToInt(_contentStartMinutes))));
	buffer.startDateTime = temp;
	buffer.endTime = time_duration(not_a_date_time);
	buffer.taskID = 0;
	buffer.done = false;
	return buffer;
}

TASK architectureStorage::initializeFloatingTask(std:: string _contentDescripton) {
	TASK buffer;
	buffer.taskDescriptionList = _contentDescripton;
	ptime temp; //temp => not_a_date_time
	buffer.startDateTime = temp;
	buffer.endTime = time_duration(not_a_date_time);
	buffer.taskID = 0;
	buffer.done = false;
	return buffer;
}

void architectureStorage::addToMasterStorage(std:: string _contentDescripton, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	TASK temp;
	if(_contentEndHours == "" && _contentEndMinutes == "") {
		if(_contentStartHours == "" && _contentStartMinutes == "") {
			temp = initializeFloatingTask(_contentDescripton);
			floatingTaskList.push_back(temp);
			architectureHistory::addPreviousState(temp);
			return;
		} else {
			temp = initializeDeadlineTask(_contentDescripton, _contentDay, _contentMonth, _contentStartHours, _contentStartMinutes);
		}
	} else {
		temp = initializeTimedTask(_contentDescripton, _contentDay, _contentMonth, _contentStartHours, _contentStartMinutes, _contentEndHours, _contentEndMinutes);
	}
	architectureHistory::addPreviousState(temp);
	masterTaskList.push_back(temp);
	architectureBoost::sortTodayUpcoming(masterTaskList);
	return;
}

std:: vector<TASK> architectureStorage::retrieveTodayTaskList() {
	return todayTaskList;
}

std:: vector<TASK> architectureStorage::retrieveUpcomingTaskList() {
	return upcomingTaskList;
}

std:: vector<TASK> architectureStorage::retrieveFloatingTaskList() {
	return floatingTaskList;
}

void architectureStorage::deleteTodayFromStorage(std:: vector<TASK>::iterator iter) {
	deleteTask(*iter);
	architectureBoost::sortTodayUpcoming(masterTaskList);
	return;
}

void architectureStorage::deleteUpcomingFromStorage(std:: vector<TASK>::iterator iter) {
	deleteTask(*iter);
	architectureBoost::sortTodayUpcoming(masterTaskList);
	return;
}

void architectureStorage::deleteFloatingFromStorage(std:: vector<TASK>::iterator iter) {
	architectureHistory::addPreviousState(*iter);
	floatingTaskList.erase(iter);
	return;
}

int architectureStorage::findTotalNumberofTodayTask() {
	return todayTaskList.size();
}

int architectureStorage::findTotalNumberofUpcomingTask() {
	return upcomingTaskList.size();
}

int architectureStorage::findTotalNumberofFloatingTask() {
	return floatingTaskList.size();
}


bool architectureStorage::isMasterTaskListEmpty() {
	if(masterTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

bool architectureStorage::isTodayTaskListEmpty() {
	if(todayTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

bool architectureStorage::isUpcomingTaskListEmpty() {
	if(upcomingTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

bool architectureStorage::isFloatingTaskListEmpty() {
	if(floatingTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

std:: vector<TASK>::iterator architectureStorage::findTodayIterator(int taskID) {
	std:: vector<TASK>::iterator iter; 
	iter = todayTaskList.begin() + taskID - 1;
	return iter;
}

std:: vector<TASK>::iterator architectureStorage::findUpcomingIterator(int taskID) {
	std:: vector<TASK>::iterator iter; 
	iter = upcomingTaskList.begin() + taskID - 1;
	return iter;
}

std:: vector<TASK>::iterator architectureStorage::findFloatingIterator(int taskID) {
	std:: vector<TASK>::iterator iter; 
	iter = floatingTaskList.begin() + taskID - 1;
	return iter;
}

// for update function, i will store two previous states instead of one[add, delete] 
// thus the first one you pop from the stack "previousStateStack" would be the one you need to delete
// and the second one would be the one you need to add back cause of LIFO
void architectureStorage::updateToTodayStorage(int taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findTodayIterator(taskID);
	architectureHistory::addPreviousState(*iter);
	deleteTask(*iter);
	addToMasterStorage(newTask, newDay, newMonth, newStartHours, newStartMinutes, newEndHours, newEndMinutes);
}

void architectureStorage::updateToUpcomingStorage(int taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findUpcomingIterator(taskID);
	architectureHistory::addPreviousState(*iter);
	deleteTask(*iter);
	addToMasterStorage(newTask, newDay, newMonth, newStartHours, newStartMinutes, newEndHours, newEndMinutes);	
}

void architectureStorage::updateToFloatingStorage(int taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findFloatingIterator(taskID);
	architectureHistory::addPreviousState(*iter);
	floatingTaskList.erase(iter);
	addToMasterStorage(newTask, newDay, newMonth, newStartHours, newStartMinutes, newEndHours, newEndMinutes);
}

void architectureStorage::storeTodayTask(TASK temp) {
	todayTaskList.push_back(temp);
	return;
}

void architectureStorage::storeUpcomingTask(TASK temp) {
	upcomingTaskList.push_back(temp);
	return;
}

void architectureStorage::clearAllFromStorage() {
	architectureHistory::retrievePreviousTaskList(masterTaskList);
	masterTaskList.clear();
	todayTaskList.clear();
	floatingTaskList.clear();
	upcomingTaskList.clear();
	return;
}

void architectureStorage::clearTodayFromStorage() {
	todayTaskList.clear();
	return;
}

void architectureStorage::clearUpcomingFromStorage() {
	architectureHistory::retrievePreviousTaskList(masterTaskList);
	upcomingTaskList.clear();
	return;
}

void architectureStorage::clearFloatingFromStorage() {
	floatingTaskList.clear();
	return;
}

/**************for undo function ******************/
void architectureStorage::undoDelete(TASK& input) {
	masterTaskList.push_back(input);
	architectureBoost::sortTodayUpcoming(masterTaskList);
	return;
}

void architectureStorage::deleteTask(TASK& input) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), input);
	masterTaskList.erase(position);
	return;
}

void architectureStorage::undoAdd(TASK& input) {
	deleteTask(input);
	architectureBoost::sortTodayUpcoming(masterTaskList);
	return;
}

void architectureStorage::undoClear(std:: vector<TASK>& previousTaskList) {
	masterTaskList.clear();
	masterTaskList = previousTaskList;
	return;
}

void architectureStorage::doneTodayTask(std:: vector<TASK>::iterator iter) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), *iter);
	position->done = true;
	architectureBoost::sortTodayUpcoming(masterTaskList);
	return;
}

void architectureStorage::doneUpcomingTask(std:: vector<TASK>::iterator iter) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), *iter);
	position->done = true;
	architectureBoost::sortTodayUpcoming(masterTaskList);
	return;
}

void architectureStorage::doneFloatingTask(std:: vector<TASK>::iterator iter) {
	iter->done = true;
	return;
}