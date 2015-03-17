
#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"

std:: vector<_task> architectureStorage::masterTaskList;

architectureStorage::architectureStorage() {
}

void architectureStorage::addToStorage(std:: string task, std:: string time) {
	_task temp;
	temp.taskDescriptionList = task;
	temp.taskTimeList = time;
	masterTaskList.push_back(temp);
	return;
}

std:: vector<std:: string> architectureStorage::retrieveMasterTaskList() {
	std:: vector<_task>:: iterator iter;

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

void architectureStorage::deleteFromStorage(int taskID) {
	std:: vector<_task>::iterator iter = masterTaskList.begin() + taskID - 1;
	masterTaskList.erase(iter);
	return;
}

int architectureStorage::findTotalNumberofTask() {
	return masterTaskList.size();
}

bool architectureStorage::isTaskDescriptionListEmpty() {
	return masterTaskList.empty();
}

void architectureStorage::clearAllFromStorage() {

}

void architectureStorage::clearTodayFromStorage() {

}

void architectureStorage::clearUpcomingFromStorage() {

}
