#include "architectureLogic.h"
#include "architectureStorage.h"

const string architectureLogic::MESSAGE_ADD = "is added";
char architectureLogic::buffer[MAX];

void architectureLogic::addTask(string task) {
	architectureStorage::addToStorage(task);
	showToUser(task + messageAdd + "\n");
	return;
}

void architectureLogic::deleteText(int taskID) {
	architectureStorage::deleteFromStorage(taskID);
	return;
}
void architectureLogic::showToUser(string task) { 
	cout << task << endl;
}
	

