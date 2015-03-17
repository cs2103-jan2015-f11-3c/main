
#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"

std:: vector<TASK> architectureStorage::masterTaskList;
//std:: vector<TASK> architectureStorage::todayTaskList;
//std:: vector<TASK> architectureStorage::upcomingTaskList;

architectureStorage::architectureStorage() {
}

void architectureStorage::addToStorage(std:: string task, std:: string time) {
	TASK temp;
	temp.taskDescriptionList = task;
	temp.taskTimeList = time;
	masterTaskList.push_back(temp);
	return;
}

std:: vector<std:: string> architectureStorage::retrieveMasterTaskList() {
	std:: vector<TASK>:: iterator iter;

	int counter = 1;
	std:: vector<std:: string> temp;

	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++, counter++) {
		std:: stringstream ss;
		ss << counter;
		std:: string str = ss.str();
		temp.push_back(str + ". " + iter->taskDescriptionList + ", " + iter->taskTimeList);
	}
	return temp;
}

/*
std:: vector<std:: string> architectureStorage::retrieveTodayTaskList() {

}

std:: vector<std:: string> architectureStorage::retrieveUpcomingTaskList() {

}
*/
void architectureStorage::deleteFromStorage(int taskID) {
	std:: vector<TASK>::iterator iter = findIterator(taskID);
	masterTaskList.erase(iter);
	return;
}

int architectureStorage::findTotalNumberofTask() {
	return masterTaskList.size();
}

bool architectureStorage::isTaskDescriptionListEmpty() {
	return masterTaskList.empty();
}

std:: vector<TASK>::iterator architectureStorage::findIterator(int taskID) {
	std:: vector<TASK>::iterator iter; 
	iter = masterTaskList.begin() + taskID - 1;
	return iter;
}

void architectureStorage::clearAllFromStorage() {
	masterTaskList.clear();
	return;
}

void architectureStorage::updateToStorage(int taskID, std:: string newTask, std:: string newTime) {
	TASK temp;
	temp.taskDescriptionList = newTask;
	temp.taskTimeList = newTime;
	deleteFromStorage(taskID);
	std:: vector<TASK>::iterator iter = findIterator(taskID);
	masterTaskList.insert(iter, temp);
	return;
}

/*
void architectureStorage::clearTodayFromStorage() {

}

void architectureStorage::clearUpcomingFromStorage() {

}
*/