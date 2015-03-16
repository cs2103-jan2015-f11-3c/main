caa 16/3

#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"

std:: vector<std:: string> architectureStorage::taskDescriptionList;
std:: vector<std:: string> architectureStorage::taskTimeList;

architectureStorage::architectureStorage() {
}

void architectureStorage::addToStorage(std:: string task, std:: string time) {
	taskDescriptionList.push_back(task);
	taskTimeList.push_back(time);
	return;
}

std:: vector<std:: string> architectureStorage::retrieveVector() {
	std:: vector<std:: string>:: iterator iter1;
	std:: vector<std:: string>:: iterator iter2;
	int counter = 1;
	std:: vector<std:: string> temp;

	for(iter1 = taskDescriptionList.begin(), iter2 = taskTimeList.begin(); iter1 != taskDescriptionList.end(); iter1++, iter2++, counter++) {
		std:: stringstream ss;
		ss << counter;
		std:: string str = ss.str();
		temp.push_back( str + ". " + *iter1 + ", " + *iter2 );
	}
	return temp;
}

void architectureStorage::deleteFromStorage(int taskID) {
	std:: vector<std:: string>::iterator iter1 = taskDescriptionList.begin() + taskID - 1;
	std:: vector<std:: string>::iterator iter2 = taskTimeList.begin() + taskID - 1;

	taskDescriptionList.erase(iter1);
	taskTimeList.erase(iter2);
	return;
}

int architectureStorage::findTotalNumberofTask() {
	return taskDescriptionList.size();
}

bool architectureStorage::isTaskDescriptionListEmpty() {
	return taskDescriptionList.empty();
}