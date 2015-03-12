#include "architectureLogic.h"
#include "architectureStorage.h"
#include "Parser.h"

const string architectureLogic::MESSAGE_INVALID = "ERROR! Invalid Command.";
char architectureLogic::buffer[MAX];
bool isProgramValid = true;
const string architectureLogic::MESSAGE_ERROR = "Invalid command type. Type any character to terminate the program.";
string architectureLogic::contentDescription;
string architectureLogic::contentTime;

void architectureLogic::showToUser(string task) { 
	cout << task << endl;
}

architectureLogic::architectureLogic(){
}

void architectureLogic::determineCommand(string content){
	size_t position = 0;
	position = content.find_first_of(" ");
	command = content.substr(0,position);
	executeCommand(command);
	//std::cout << "command is: " << command << std::endl;
}

/************ for architectureParser to change*************/ 
void architectureLogic::determineContentDescription(string parserInput) {
	contentDescription = parserInput;
}

void architectureLogic::determineContentTime(string parserInput) {
	contentTime = parserInput;
}

void architectureLogic::determineTaskID(int inputID) {
	taskID = inputID;
}

void architectureLogic::determineTotalNumberofTask() {
	totalNumberofTask = architectureStorage::sizeOfStorage(); 
}

/***************end*****************/

void architectureLogic::addTask(string task, string time) {
	architectureStorage::addToStorage(task, time);
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
		Parser::tokenizeADD(content);
		addTask(contentDescription, contentTime); 
		return;
	case DISPLAY:
		// Parser::tokenizeDISPLAY(content);
		displayTask(); 
		return;
	case DELETE: 
		Parser::tokenizeDELETE(content);
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