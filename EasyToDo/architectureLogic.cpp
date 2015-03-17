#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureParser.h"

const std:: string architectureLogic::MESSAGE_ADD = "%s, %s added successfully";
const std:: string architectureLogic::MESSAGE_INVALID = "ERROR! Invalid Command";
const std:: string architectureLogic::MESSAGE_NOTFOUND = "Task is not found!";
const std:: string architectureLogic::MESSAGE_DELETE = "Task%s is deleted!";
const std:: string architectureLogic::MESSAGE_CLEARALL = "All task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARTODAY = "Today's task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARUPCOMING = "Upcoming task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_STORAGEEMPTY = "Task List is already empty!";
const std:: string architectureLogic::MESSAGE_TODAY = "all";
const std:: string architectureLogic::MESSAGE_TODAY = "today";
const std:: string architectureLogic::MESSAGE_UPCOMING = "upcoming";


std:: string architectureLogic::_command;
std:: string architectureLogic::_content;
std:: string architectureLogic::_contentDescription;
std:: string architectureLogic::_contentTime;

char architectureLogic::buffer[MAX];

architectureLogic::architectureLogic(){
}

std:: string architectureLogic::determineCommand(std:: string content){
	std:: string feedBack;

	// next three codes can SLAP
	size_t position = 0;
	position = content.find_first_of(" ");
	_command = content.substr(0,position);
	_content = content.substr(position);
	feedBack = executeCommand(_command);
	return feedBack;
}

architectureLogic::CommandType architectureLogic::determineCommandType(std:: string commandAction) { 
	if(isValidCommand(commandAction, "add")) { 
		return CommandType::ADD; 
	} else if(isValidCommand(commandAction, "exit")) { 
		return CommandType::EXIT; 
	} else if(isValidCommand(commandAction, "delete")) {
		return CommandType::DELETE;
	} else { 
		return CommandType::INVALID;
	} 
}

bool architectureLogic::isValidCommand(const std:: string& str1, const std:: string& str2) { 
	if (str1.size() != str2.size()) { 
		return false; 
	} 
	std:: string::const_iterator c1;
	std:: string::const_iterator c2;

	for (c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2) {
		if (tolower(*c1) != tolower(*c2)) { 
			return false; 
		} 
	} return true; 
}

void architectureLogic::determineContentDescription(std:: string parserInput) {
	_contentDescription = parserInput;
}

void architectureLogic::determineContentTime(std:: string parserInput) {
	_contentTime = parserInput;
}

std:: string architectureLogic::executeCommand(std:: string commandAction) { 
	CommandType commandTypeAction = determineCommandType(commandAction);
	std:: string added;

	switch(commandTypeAction) { 
	case ADD: 
		Parser::tokenizeADD(_content);
		added = addTask(_contentDescription, _contentTime); 
		return added;
	case INVALID:
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		return buffer;
	case DELETE:
		return deleteTask(_content);
	case CLEAR:
		return clear(_content);
	case EXIT: 
		exit(0);
	}
}


std:: string architectureLogic::addTask(std:: string task, std:: string time) {
	architectureStorage::addToStorage(task, time);
	sprintf_s(buffer, MESSAGE_ADD.c_str(), task.c_str(), time.c_str());
	return buffer;
}

bool architectureLogic::isTaskIDValid(int taskID) {
	int size = architectureStorage::findTotalNumberofTask();
	if(size < taskID) {
		return false;
	} else {
		return true;
	}
}

std:: string architectureLogic::deleteTask(std:: string input) {
	const std:: string temp = input;
	int taskID;
	taskID = atoi(input.c_str()); 
	if(isTaskIDValid(taskID)) {
		architectureStorage::deleteFromStorage(taskID);
		// next three lines can SLAP into a function
		sprintf_s(buffer, MESSAGE_DELETE.c_str(), temp.c_str());
		return buffer;
	} else {
		sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
		return buffer;
	}
}

bool architectureLogic::isStorageEmpty() {
	return architectureStorage::isTaskDescriptionListEmpty();
}

std:: string architectureLogic::clear(std:: string _content) {
	if(isStorageEmpty()) { 
		sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
		return buffer;
	} else if(_content == MESSAGE_TODAY) {
		architectureStorage::clearTodayFromStorage();
		sprintf_s(buffer, MESSAGE_CLEARTODAY.c_str());
		return buffer;
	} else if(_content == MESSAGE_UPCOMING) {
		architectureStorage::clearUpcomingFromStorage();
		sprintf_s(buffer, MESSAGE_CLEARUPCOMING.c_str());
		return buffer;
	} else if(_content == MESSAGE_CLEARALL) {
		architectureStorage::clearAllFromStorage();
		sprintf_s(buffer, MESSAGE_ALL.c_str());
		return buffer;
	}
}
