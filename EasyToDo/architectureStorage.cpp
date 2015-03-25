#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"
#include "architectureBoost.h"
#include "architectureHistory.h"

std:: vector<TASK> architectureStorage::masterTaskList;
std:: vector<TASK> architectureStorage::todayTaskList;
std:: vector<TASK> architectureStorage::upcomingTaskList;
std:: vector<TASK> architectureStorage::floatingTaskList;

architectureStorage::architectureStorage() {
}

void architectureStorage::updateTaskID() {
	int counter = 1;
	std:: vector<TASK>::iterator iter;
	
	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++, counter++) {
		iter->taskID = counter;
	}
}

int architectureStorage::stringToInt(std:: string input) {
	int value;
	value = atoi(input.c_str());
	return value;
}

TASK architectureStorage::initializeDeadlineTask(std:: string _contentDescripton, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	TASK buffer;
	buffer.taskDescriptionList = _contentDescripton;
	std::string dateString; // ("2002/1/25");
	dateString = "2015" + '/' + _contentMonth + '/' + _contentDay;
	date d(from_string(dateString));
	ptime temp(d, time_duration(hours(stringToInt(_contentStartHours))+minutes(stringToInt(_contentStartMinutes))));
	buffer.startDateTime = temp;
	buffer.endTime = time_duration(hours(stringToInt(_contentEndHours)) + minutes(stringToInt(_contentEndMinutes)));
	buffer.taskID = 0;
	return buffer;
}

TASK architectureStorage::initializeTimedTask(std:: string _contentDescripton, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes) {
	TASK buffer;
	buffer.taskDescriptionList = _contentDescripton;
	std::string dateString; // ("2002/1/25");
	dateString = "2015" + '/' + _contentMonth + '/' + _contentDay;
	date d(from_string(dateString));
	ptime temp(d, time_duration(hours(stringToInt(_contentStartHours))+minutes(stringToInt(_contentStartMinutes))));
	buffer.startDateTime = temp;
	buffer.endTime = time_duration(not_a_date_time);
	buffer.taskID = 0;
	return buffer;
}

TASK architectureStorage::initializeFloatingTask(std:: string _contentDescripton) {
	TASK buffer;
	buffer.taskDescriptionList = _contentDescripton;
	std::string dateString; // ("2002/1/25");
	dateString = "";
	date d(from_string(dateString));
	ptime temp(d, time_duration(not_a_date_time));
	buffer.startDateTime = temp;
	buffer.endTime = time_duration(not_a_date_time);
	buffer.taskID = 0;
	return buffer;
}

void architectureStorage::addToMasterStorage(std:: string _contentDescripton, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	TASK temp;
	if(_contentEndHours == "" && _contentEndMinutes == "") {
		if(_contentStartHours == "" && _contentStartMinutes == "") {
			temp = initializeFloatingTask(_contentDescripton);
			floatingTaskList.push_back(temp);
		} else {
			temp = initializeTimedTask(_contentDescripton, _contentDay, _contentMonth, _contentStartHours, _contentStartMinutes);
		}
	} else {
		temp = initializeDeadlineTask(_contentDescripton, _contentDay, _contentMonth, _contentStartHours, _contentStartMinutes, _contentEndHours, _contentEndMinutes);
	}
	architectureHistory::addPreviousState(temp);
	masterTaskList.push_back(temp);
	architectureBoost::sortTodayUpcoming(masterTaskList);
	return;
}

std:: vector<std:: string> architectureStorage::retrieveMasterTaskList() {
	std:: vector<TASK>:: iterator iter;
	std:: vector<std:: string> temp;

	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) {
		std:: stringstream ss;
		ss << iter->taskID;
		std:: string str = ss.str();
		temp.push_back(str + ". " + iter->taskDescriptionList + " " + boost::posix_time::to_simple_string(iter->startDateTime).c_str() + "-" + to_simple_string(iter->endTime).c_str());
	}
	return temp;
}

std:: vector<std:: string> architectureStorage::retrieveTodayTaskList() {
	std:: vector<TASK>:: iterator iter;
	std:: vector<std:: string> temp;

	for(iter = todayTaskList.begin(); iter != todayTaskList.end(); iter++) {
		std:: stringstream ss;
		ss << iter->taskID;
		std:: string str = ss.str();
		temp.push_back(str + ". " + iter->taskDescriptionList + " " + boost::posix_time::to_simple_string(iter->startDateTime).c_str() + "-" + to_simple_string(iter->endTime).c_str());
	}
	return temp;
}

std:: vector<std:: string> architectureStorage::retrieveUpcomingTaskList() {
	std:: vector<TASK>:: iterator iter;
	std:: vector<std:: string> temp;

	for(iter = upcomingTaskList.begin(); iter != upcomingTaskList.end(); iter++) {
		std:: stringstream ss;
		ss << iter->taskID;
		std:: string str = ss.str();
		temp.push_back(str + ". " + iter->taskDescriptionList + " " + boost::posix_time::to_simple_string(iter->startDateTime).c_str() + "-" + to_simple_string(iter->endTime).c_str());
	}
	return temp;
}

std:: vector<std:: string> architectureStorage::retrieveTodayTaskList() {
	std:: vector<TASK>:: iterator iter;
	std:: vector<std:: string> temp;

	for(iter = todayTaskList.begin(); iter != todayTaskList.end(); iter++) {
		std:: stringstream ss;
		ss << iter->taskID;
		std:: string str = ss.str();
		temp.push_back(str + ". " + iter->taskDescriptionList + " " + boost::posix_time::to_simple_string(iter->startDateTime).c_str() + "-" + to_simple_string(iter->endTime).c_str());
	}
	return temp;
}

void architectureStorage::deleteFromStorage(int taskID) {
	std:: vector<TASK>::iterator iter = findIterator(taskID);
	architectureHistory::addPreviousState(*iter);
	masterTaskList.erase(iter);
	architectureBoost::sortTodayUpcoming(masterTaskList);
	return;
}

int architectureStorage::findTotalNumberofTask() {
	return masterTaskList.size();
}

bool architectureStorage::isMasterTaskListEmpty() {
	if(masterTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

std:: vector<TASK>::iterator architectureStorage::findIterator(int taskID) {
	std:: vector<TASK>::iterator iter; 
	iter = masterTaskList.begin() + taskID - 1;
	return iter;
}

// for update function, i will store two previous states instead of one[add, delete] 
// thus the first one you pop from the stack "previousStateStack" would be the one you need to delete
// and the second one would be the one you need to add back cause of LIFO
void architectureStorage::updateToStorage(int taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findIterator(taskID);
	architectureHistory::addPreviousState(*iter);
	addToMasterStorage(newTask, newDay, newMonth, newStartHours, newStartMinutes, newEndHours, newEndMinutes);
	deleteFromStorage(taskID);
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
	return;
}

void architectureStorage::clearTodayFromStorage() {
	architectureHistory::retrievePreviousTaskList(masterTaskList);
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
	std:: string temp = "";
	TASK task; 
	task = initializeFloatingTask(temp);
	architectureHistory::addPreviousState(task);
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
	if (position != masterTaskList.end()) {
		masterTaskList.erase(position);
	}
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