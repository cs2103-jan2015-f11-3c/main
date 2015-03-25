#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureParser.h"
#include "architectureHistory.h"
#include "architectureBoost.h"
#include <assert.h>

/*
to do list requires basic support of storage/retrieval of info, display of info to user and updating 
existing info. thus to reduce coupling from the innate nature of interlinkedness, we separated the
architecture to 5 different components of UI, Parser, Logic, Storage, History
*/

/*
logic is a facade class that separate the storage vectors in Storage and the users(UI) 
*/
const std:: string architectureLogic::MESSAGE_ADD = "Task \"%s %s %s %s %s %s %s\" is added successfully";
const std:: string architectureLogic::MESSAGE_INVALID = "ERROR! Invalid Command";
const std:: string architectureLogic::MESSAGE_NOTFOUND = "Task is not found!";
const std:: string architectureLogic::MESSAGE_DELETE = "Task %s is deleted!";
const std:: string architectureLogic::MESSAGE_CLEARALL = "All task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARTODAY = "Today's task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARUPCOMING = "Upcoming task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_STORAGEEMPTY = "Task List is already empty!";
const std:: string architectureLogic::MESSAGE_UPDATE = "Task %s is updated successfully";
const std:: string architectureLogic::MESSAGE_UNDOINVALID = "No more action left to undo";
const std:: string architectureLogic::MESSAGE_ALL = "all";
const std:: string architectureLogic::MESSAGE_TODAY = "today";
const std:: string architectureLogic::MESSAGE_UPCOMING = "upcoming";

std:: string architectureLogic::_command;
std:: string architectureLogic::_content;
std:: string architectureLogic::_contentDescription;
std:: string architectureLogic::_contentDay;
std:: string architectureLogic::_contentMonth;
std:: string architectureLogic::_contentStartHours;
std:: string architectureLogic::_contentStartMinutes;
std:: string architectureLogic::_contentEndHours;
std:: string architectureLogic::_contentEndMinutes;
std:: string architectureLogic::_taskID;

char architectureLogic::buffer[MAX];

architectureLogic::architectureLogic(){
}

std:: string architectureLogic::determineCommand(std:: string content){
	std:: string feedBack;
	
	// next three codes can SLAP

	size_t pos = 0;
	while ( ( pos = content.find ("\r\n",pos) ) != std::string::npos ) {
		content.erase ( pos, 2 );
	}
	if (content == "") {
		throw std::invalid_argument("recieved empty string");
	}
	size_t positionStart = content.find_first_not_of(" ");
	assert(positionStart >= 0);
	size_t positionEnd = content.find_first_of(" ");
	assert(positionEnd >= 0);

	_command = content.substr(positionStart, positionEnd);
	_content = content.substr(positionEnd);
	assert(_command != "");
	feedBack = executeCommand(_command);

	return feedBack;
}

architectureLogic::CommandType architectureLogic::determineCommandType(std:: string commandAction) { 
	assert(commandAction != "");
	if(isValidCommand(commandAction, "add")) { 
		return CommandType::ADD; 
	} else if(isValidCommand(commandAction, "exit")) { 
		return CommandType::EXIT; 
	} else if(isValidCommand(commandAction, "delete")) {
		return CommandType::DELETE;
	} else if(isValidCommand(commandAction, "clear")) {
		return CommandType::CLEAR;
	} else if(isValidCommand(commandAction, "update")) {
		return CommandType::UPDATE;
	} else if(isValidCommand(commandAction, "undo")) {
		return CommandType::UNDO;
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
	assert(parserInput != "");
	_contentDescription = parserInput;
}

void architectureLogic::determineContentDay(std:: string parserInput) {
	_contentDay = parserInput;
}

void architectureLogic::determineContentMonth(std:: string parserInput) {
	_contentMonth = parserInput;
}

void architectureLogic::determineContentStartHours(std:: string parserInput) {
	_contentStartHours = parserInput;
}

void architectureLogic::determineContentStartMinutes(std:: string parserInput) {
	_contentStartMinutes = parserInput;
}

void architectureLogic::determineContentEndHours(std:: string parserInput) {
	_contentEndHours = parserInput;
}

void architectureLogic::determineContentEndMinutes(std:: string parserInput) {
	_contentEndMinutes = parserInput;
}

void architectureLogic::determineTaskID(std:: string parserInput) {
	_taskID = parserInput;
}

/*
command pattern: execute the command without knowing the specific type of command
*/

std:: string architectureLogic::executeCommand(std:: string commandAction) { 
	assert(commandAction != "");
	architectureHistory::addPreviousAction(commandAction);
	CommandType commandTypeAction = determineCommandType(commandAction);

	switch(commandTypeAction) { 
	case ADD: 
		Parser::tokenizeADD(_content);
		return addTask(_contentDescription, _contentDay, _contentMonth, _contentStartHours, _contentStartMinutes, _contentEndHours, _contentEndMinutes);
	case DELETE:
		return deleteTask(_content);
	case CLEAR:
		return clearTask(_content);
	case UPDATE:
		Parser::tokenizeUPDATE(_content);
		return updateTask(_taskID, _contentDescription, _contentDay, _contentMonth, _contentStartHours, _contentStartMinutes, _contentEndHours, _contentEndMinutes);
	case INVALID:
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		return buffer;
	case UNDO:
		return undoTask();
	case EXIT: 
		exit(0);
	}
}

std:: string trimTrailingSpaces(std:: string buffer) {
	size_t endpos = buffer.find_last_not_of(" \t");
	if(std:: string::npos != endpos )
	{
		buffer = buffer.substr(0, endpos+1);
	}
	return buffer;
}

std:: string architectureLogic::addTask(std:: string _contentDescription, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	assert(_contentDescription != "");
	architectureStorage::addToMasterStorage(_contentDescription, _contentDay, _contentMonth, _contentStartHours, _contentStartMinutes, _contentEndHours, _contentEndMinutes);
	architectureStorage::updateTaskID();
	sprintf_s(buffer, MESSAGE_ADD.c_str(), _contentDescription.c_str(), _contentDay.c_str(), _contentMonth.c_str(), _contentStartHours.c_str(), _contentStartMinutes.c_str(), _contentEndHours.c_str(), _contentEndMinutes.c_str());
	return trimTrailingSpaces(buffer);
}

bool architectureLogic::isTaskIDValid(int taskID) {
	int size = architectureStorage::findTotalNumberofTask();
	assert(size >=0);
	if(size < taskID) {
		return false;
	} else {
		return true;
	}
}

std:: string architectureLogic::deleteTask(std:: string taskID) {
	assert(taskID !=  "");
	const std:: string temp = taskID;
	int ID = stringToInteger(taskID); 
	std:: vector<TASK>::iterator iter;
	iter = architectureStorage::findIterator(ID);
	if(isTaskIDValid(ID)) {
		architectureHistory::addPreviousState(*iter);
		architectureStorage::deleteFromStorage(ID);
		architectureStorage::updateTaskID();
		sprintf_s(buffer, MESSAGE_DELETE.c_str(), temp.c_str());
		return buffer;
	} else {
		sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
		return buffer;
	}
}

bool architectureLogic::isStorageEmpty() {
	return architectureStorage::isMasterTaskListEmpty();
}

int architectureLogic::stringToInteger(std:: string input) {
	int taskID;
	taskID = atoi(input.c_str()); 
	return taskID;
}

std:: string architectureLogic::clearTask(std:: string _content) {
	if(isStorageEmpty()) { 
		sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
		return buffer;
	}  else {
		if (_content == MESSAGE_ALL) {
			architectureStorage::clearAllFromStorage();
			sprintf_s(buffer, MESSAGE_CLEARALL.c_str());
			return buffer;
		} 
		if(_content == MESSAGE_TODAY) {
			architectureStorage::clearTodayFromStorage();
			sprintf_s(buffer, MESSAGE_CLEARTODAY.c_str());
			return buffer;
		}  
		if(_content == MESSAGE_UPCOMING) {
			architectureStorage::clearUpcomingFromStorage();
			sprintf_s(buffer, MESSAGE_CLEARUPCOMING.c_str());
			return buffer;
		}
	}
}

std:: string architectureLogic::updateTask(std:: string taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes) {
	const std:: string temp = taskID;
	int ID = stringToInteger(taskID);
	assert(ID > 0);
	if(isTaskIDValid(ID)) {
		architectureStorage::updateToStorage(ID, newTask, newDay, newMonth, newStartHours, newStartMinutes, newEndHours, newEndMinutes);
		architectureStorage::updateTaskID();
		sprintf_s(buffer, MESSAGE_UPDATE.c_str(), temp.c_str());
		return buffer;
	} else {
		sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
		return buffer;
	}
}

std:: string architectureLogic::undoTask() {
	std:: string feedback;
	if(architectureHistory::isUndoStackEmpty()) {
		sprintf_s(buffer, MESSAGE_UNDOINVALID.c_str());
		return buffer;
	} else {
		feedback = architectureHistory::undoAction();
		return feedback;
	}
}

