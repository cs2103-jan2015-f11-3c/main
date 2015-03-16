caa 16/3

#include "architectureStorage.h"
#include "architectureLogic.h"
#include "Parser.h"

vector<string> architectureStorage::taskDescriptionList;
vector<string> architectureStorage::taskTimeList;
const string architectureStorage::MESSAGE_ADD = "is added";
const string architectureStorage::MESSAGE_EMPTY = "Storage is empty";

void architectureStorage::showToUser(string task) { 
	cout << task << endl;
}

architectureStorage::architectureStorage() {
}

int architectureStorage::sizeOfStorage() {
	return taskDescriptionList.size();
}

void architectureStorage::addToStorage(string task, string time) {
	taskDescriptionList.push_back(task);
	taskTimeList.push_back(time);
	showToUser(task + MESSAGE_ADD + "\n");
	return;
}

void architectureStorage::deleteFromStorage(int taskID) {
	vector<string>::iterator iter = taskDescriptionList.begin() + taskID;

	taskDescriptionList.erase(iter);
	taskTimeList.erase(iter);
	return;
}

void architectureStorage::clearFromStorage() {
	taskDescriptionList.clear();
	taskTimeList.clear();
	return;
}

void architectureStorage::displayFromStorage() {
	int counter = 1;

	if(taskDescriptionList[0].empty()) { 
		showToUser(MESSAGE_EMPTY);
	} else { 
		for(vector<string>::iterator iter = taskTimeList.begin(); iter != taskTimeList.end(); iter++) { 
			cout << counter+1; 
			showToUser(". " + *iter + "\n"); 
		} 
	} 
	return;
}