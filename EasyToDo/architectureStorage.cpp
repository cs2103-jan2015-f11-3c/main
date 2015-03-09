#include "architectureStorage.h"
#include "architectureLogic.h"

vector<string> architectureStorage::taskList;
const string architectureStorage::MESSAGE_ADD = "is added";
const string architectureStorage::MESSAGE_EMPTY = "Storage is empty";

void architectureStorage::showToUser(string task) { 
	cout << task << endl;
}

architectureStorage::architectureStorage() {
}

int architectureStorage::sizeOfStorage() {
	return taskList.size();
}

void architectureStorage::addToStorage(string task) {
	taskList.push_back(task);
	showToUser(task + MESSAGE_ADD + "\n");
	return;
}

void architectureStorage::deleteFromStorage(int taskID) {
	vector<string>::iterator iter = taskList.begin() + taskID;
	taskList.erase(iter);
	return;
}

void architectureStorage::clearFromStorage() {
	taskList.clear();
	return;
}

void architectureStorage::displayFromStorage() {
	int counter = 1;

	if(taskList[0].empty()) { 
		showToUser(MESSAGE_EMPTY);
	} else { 
		for(vector<string>::iterator iter = taskList.begin(); iter != taskList.end(); iter++) { 
			cout << counter+1; 
			showToUser(". " + *iter + "\n"); 
		} 
	} 
	return;
}