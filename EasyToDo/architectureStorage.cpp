#include "architectureStorage.h"
#include "architectureLogic.h"

vector<string> architectureStorage::taskList;

void architectureStorage::addToStorage(string task) {
	taskList.push_back(task);
	return;
}

void architectureStorage::deleteFromStorage(int taskID) {
	vector<string>::iterator iter = taskList.begin() + taskID;
	taskList.erase(iter);
	return;
}