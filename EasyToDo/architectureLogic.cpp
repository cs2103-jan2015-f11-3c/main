#include "architectureLogic.h"
#include "architectureStorage.h"

const string architectureLogic::MESSAGE_INVALID = "ERROR! Invalid Command.";
char architectureLogic::buffer[MAX];
bool isProgramValid = true;
const string architectureLogic::MESSAGE_ERROR = "Invalid command type. Type any character to terminate the program.";

void architectureLogic::showToUser(string task) { 
	cout << task << endl;
}

architectureLogic::architectureLogic(){
}

void architectureLogic::determineUserInput(string task) {
	userInput = task;
}

void architectureLogic::determineTaskID(int inputID) {
	taskID = inputID;
}

void architectureLogic::determineTotalNumberofTask() {
	totalNumberofTask = architectureStorage::sizeOfStorage(); 
}

void architectureLogic::addTask(string task) {
	architectureStorage::addToStorage(task);
	return;
}

void architectureLogic::deleteText(int taskID) {
	architectureStorage::deleteFromStorage(taskID);
	return;
}
	
void architectureLogic::clearTask() {
	architectureStorage::clearFromStorage();
	return;
}

void architectureLogic::displayTask() {
	architectureStorage::displayFromStorage();
	return;
}

void architectureLogic::executeCommand(string commandAction) { 
	CommandType commandTypeAction = determineCommandType(commandAction); 

	switch(commandTypeAction) { 
	case ADD: 
		addTask(userInput); 
		return;
	case DISPLAY:
		displayTask(); 
		return;
	case DELETE: 
		deleteText(taskID);
		return;
		/*
	case CLEAR: 
		return clearText(outputFile); 
	case SORT: 
		sortText(); 
		return MESSAGE_SORT; 
	case SEARCH: searchText(userInput); 
		return ""; 
		*/
	case INVALID:{ 
		showToUser(MESSAGE_INVALID);
		return; 
				 }
	case EXIT: { 
		isProgramValid = false; 
		exit(0); } 
	default: 
		showToUser(MESSAGE_ERROR); 
		getchar(); 
		exit(EXIT_FAILURE); 
	} 
}

architectureLogic::CommandType architectureLogic::determineCommandType(string commandAction) { 
	if(isValidCommand(commandAction, "add")) { 
		return CommandType::ADD; 
	} else if (isValidCommand(commandAction,"display")) { 
		return CommandType::DISPLAY; 
	} else if(isValidCommand(commandAction, "clear")) { 
		return CommandType::CLEAR; 
	} else if(isValidCommand(commandAction, "delete")) { 
		return CommandType::DELETE; 
	} else if(isValidCommand(commandAction, "sort")) { 
		return CommandType::SORT;
	} else if(isValidCommand(commandAction, "search")) { 
		return CommandType::SEARCH;
	} else if(isValidCommand(commandAction, "exit")) { 
		return CommandType::EXIT; 
	} else { 
		return CommandType::INVALID;
	} 
}

bool architectureLogic::isValidCommand(const string& str1, const string& str2) { 
	if (str1.size() != str2.size()) { 
		return false; 
	} 
	
	for (string::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2) {
		if (tolower(*c1) != tolower(*c2)) { 
			return false; 
		} 
	} return true; 
}