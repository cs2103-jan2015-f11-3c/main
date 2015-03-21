#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureParser.h"
#include "architectureFeedbackHistory.h"

/*
to do list requires basic support of storage/retrieval of info, display of info to user and updating 
existing info. thus to reduce coupling from the innate nature of interlinkedness, we separated the
architecture to 5 different components of UI, Parser, Logic, Storage, History
*/

/*
logic is a facade class that separate the storage vectors in Storage and the users(UI) 
*/
const std:: string architectureLogic::MESSAGE_ADD = "Task \"%s %s %s %s\" is added successfully";
const std:: string architectureLogic::MESSAGE_INVALID = "ERROR! Invalid Command";
const std:: string architectureLogic::MESSAGE_NOTFOUND = "Task is not found!";
const std:: string architectureLogic::MESSAGE_DELETE = "Task %s is deleted!";
const std:: string architectureLogic::MESSAGE_CLEARALL = "All task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARTODAY = "Today's task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARUPCOMING = "Upcoming task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_STORAGEEMPTY = "Task List is already empty!";
const std:: string architectureLogic::MESSAGE_UPDATE = "Task %s is updated successfully";
const std:: string architectureLogic::MESSAGE_ALL = "all";
const std:: string architectureLogic::MESSAGE_TODAY = "today";
const std:: string architectureLogic::MESSAGE_UPCOMING = "upcoming";


std:: string architectureLogic::_command;
std:: string architectureLogic::_content;
std:: string architectureLogic::_contentDescription;
std:: string architectureLogic::_contentStartTime;
std:: string architectureLogic::_contentEndTime;
std:: string architectureLogic::_contentDate;
std:: string architectureLogic::_taskID;

char architectureLogic::buffer[MAX];

architectureLogic::architectureLogic(){
}

std:: vector<std:: string> architectureLogic::determineCommand(std:: string content){
	std:: string feedBack;
	std:: vector<std:: string> temp;
	
	// next three codes can SLAP

	size_t pos = 0;
	
	while ( ( pos = content.find ("\r\n",pos) ) != std::string::npos ) {
		content.erase ( pos, 2 );
	}
	if (content == "")
		throw std::invalid_argument("recieved empty string");
	size_t positionStart = content.find_first_not_of(" ");
	assert(positionStart >= 0);
	size_t positionEnd = content.find_first_of(" ");
	assert(positionEnd >= 0);

	_command = content.substr(positionStart, positionEnd);
	_content = content.substr(positionEnd);
	assert(_command != "");
	feedBack = executeCommand(_command);
	
	architectureFeedbackHistory::addToFeedbackList(feedBack);

	temp = architectureFeedbackHistory::retrieveFeedbackList();
	
	return temp;
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
	} /*else if(isValidCommand(commandAction, "undo")) {
		return CommandType::UNDO;
	} */else { 
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

void architectureLogic::determineContentStartTime(std:: string parserInput) {
	_contentStartTime = parserInput;
}

void architectureLogic::determineContentEndTime(std:: string parserInput) {
	_contentEndTime = parserInput;
}

void architectureLogic::determineContentDate(std:: string parserInput) {
	_contentDate = parserInput;
}

void architectureLogic::determineTaskID(std:: string parserInput) {
	_taskID = parserInput;
}
/*
command pattern: execute the command without knowing the specific type of command
*/
std:: string architectureLogic::executeCommand(std:: string commandAction) { 
	assert(commandAction != "");
	// architectureHistory::determinePreviousAction(commandAction);
	CommandType commandTypeAction = determineCommandType(commandAction);

	switch(commandTypeAction) { 
	case ADD: 
		Parser::tokenizeADD(_content);
		return addTask(_contentDescription, _contentDate, _contentStartTime, _contentEndTime);
	case DELETE:
		return deleteTask(_content);
	case CLEAR:
		return clearTask(_content);
	case UPDATE:
		Parser::tokenizeUPDATE(_content);
		return updateTask(_taskID, _contentDescription, _contentDate, _contentStartTime, _contentEndTime);
	case INVALID:
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		return buffer;
	/* case UNDO:
		return undoTask();*/
	case EXIT: 
		exit(0);
	}
}

std:: string architectureLogic::addTask(std:: string task, std:: string date, std:: string startTime, std:: string endTime) {
	assert(task != "");
	/*
	if(endTime == "") {
		if(startTime == "") {
			LOG(TASK_INFO, "this is a floating task");
		} else {
			LOG(TASK_INFO, "this is a deadline task");
		}
	} else {
		LOG(TASK_INFO, "this is a timed task");
	}
	*/
	architectureStorage::addToMasterStorage(task, date, startTime, endTime);
	architectureStorage::sortStorage();
	architectureStorage::updateTaskID();

	sprintf_s(buffer, MESSAGE_ADD.c_str(), task.c_str(), date.c_str(), startTime.c_str(), endTime.c_str());
	return buffer;
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
	if(isTaskIDValid(ID)) {
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
		architectureStorage::clearAllFromStorage();
		sprintf_s(buffer, MESSAGE_CLEARALL.c_str());
		return buffer;
	} 
	/*else if(_content == MESSAGE_TODAY) {
	  architectureStorage::clearTodayFromStorage();
	  sprintf_s(buffer, MESSAGE_CLEARTODAY.c_str());
	  return buffer;
	  } else if(_content == MESSAGE_UPCOMING) {
	  architectureStorage::clearUpcomingFromStorage();
	  sprintf_s(buffer, MESSAGE_CLEARUPCOMING.c_str());
	  return buffer;
	  }*/
}

std:: string architectureLogic::updateTask(std:: string taskID, std:: string newTask, std:: string newDate, std:: string newStartTime, std:: string newEndTime) {
	const std:: string temp = taskID;
	int ID = stringToInteger(taskID);
	if(isTaskIDValid(ID)) {
		architectureStorage::updateToStorage(ID, newTask, newDate, newStartTime, newEndTime);
		architectureStorage::sortStorage();
		architectureStorage::updateTaskID();
		sprintf_s(buffer, MESSAGE_UPDATE.c_str(), temp.c_str());
		return buffer;
	} else {
		sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
		return buffer;
	}
}
/*
std:: string architectureLogic::undoTask() {
	if(isUndoValid()) {
		std:: string previousCommand;
		previousCommand = previousActionStack.top();
		CommandType commandTypeAction = determineCommandType(previousCommand);
	}
}

bool architectureLogic::isUndoValid() {
	if(undoStack.empty()) {
		return false;
	} else {
		return true;
	}
}
*/