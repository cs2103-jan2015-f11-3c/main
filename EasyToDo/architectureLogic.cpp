#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureParser.h"
#include "architectureHistory.h"
#include "architectureBoost.h"
#include "architectureInputFeedback.h"

/*
to do list requires basic support of storage/retrieval of info, display of info to user and updating 
existing info. thus to reduce coupling from the innate nature of interlinkedness, we separated the
architecture to 5 different components of UI, Parser, Logic, Storage, History
*/

/*
logic is a facade class that separate the storage vectors in Storage and the users(UI) 
*/
const std:: string architectureLogic::MESSAGE_ADD = "Task \"%s\" is added successfully";
const std:: string architectureLogic::MESSAGE_INVALID = "ERROR! Invalid Command";
const std:: string architectureLogic::MESSAGE_NOTFOUND = "Task is not found!";
const std:: string architectureLogic::MESSAGE_DELETETODAY = "Today Task %s is deleted!";
const std:: string architectureLogic::MESSAGE_DELETEUPCOMING = "Upcoming Task %s is deleted!";
const std:: string architectureLogic::MESSAGE_DELETEFLOATING = "Floating Task %s is deleted!";
const std:: string architectureLogic::MESSAGE_DONETODAY = "Today Task %s is done!";
const std:: string architectureLogic::MESSAGE_DONEUPCOMING = "Upcoming Task %s is done!";
const std:: string architectureLogic::MESSAGE_DONEFLOATING = "Floating Task %s is done!";
const std:: string architectureLogic::MESSAGE_CLEARALL = "All task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARTODAY = "Today's task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARUPCOMING = "Upcoming task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARFLOATING = "Floating task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_STORAGEEMPTY = "Task List is already empty!";
const std:: string architectureLogic::MESSAGE_UPDATETODAY = "Today Task %s is updated successfully";
const std:: string architectureLogic::MESSAGE_UPDATEUPCOMING = "Upcoming Task %s is updated successfully";
const std:: string architectureLogic::MESSAGE_UPDATEFLOATING = "Floating Task %s is updated successfully";
const std:: string architectureLogic::MESSAGE_UNDOINVALID = "No more action left to undo";
const std:: string architectureLogic::MESSAGE_ALL = "all";
const std:: string architectureLogic::MESSAGE_TODAY = "today";
const std:: string architectureLogic::MESSAGE_UPCOMING = "upcoming";
const std:: string architectureLogic::MESSAGE_FLOATING = "misc";

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
std:: string architectureLogic::_taskType;

std:: vector<std:: string> architectureLogic::parserVector;
char architectureLogic::buffer[MAX];


architectureLogic::architectureLogic(){
}

std:: vector<std:: string> architectureLogic::determineCommand(){
	std:: string feedback;
	std:: vector<std:: string> feedbackList;
	
	if(parserVector[0] == "invalid") {
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		feedback = buffer;
	} else {
		initializeCommand();
		feedback = executeCommand();
	}

	architectureInputFeedback::addToMasterFeedbackList(feedback);
	feedbackList = architectureInputFeedback::retrieveFeedbackList();

	return feedbackList;
}


void architectureLogic::initializeCommand() {
	std:: vector<std:: string>::iterator iter;
	iter = parserVector.begin();

	_command = *iter;
	iter++;
	_taskType = *iter;
	iter++;
	_taskID = *iter;
	iter++;
	_contentDescription = *iter;
	iter++;
	_contentDay = *iter;
	iter++;
	_contentMonth= *iter;
	iter++;
	_contentStartHours= *iter;
	iter++;
	_contentStartMinutes= *iter;
	iter++;
	_contentEndHours= *iter;

	assert(_command != "");
}

void architectureLogic::pushParserVector(std:: vector<std:: string>& temp) {
	parserVector.clear();
	std:: vector<std:: string>::iterator iter;
	iter = temp.begin();
	assert((*iter) != "");
	for(iter = temp.begin(); iter != temp.end(); iter++) {
		parserVector.push_back(*iter);
	}
	determineCommand();
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
	} else if(isValidCommand(commandAction, "undo") || (isValidCommand(commandAction, "undo "))) {
		return CommandType::UNDO;
	} else if(isValidCommand(commandAction, "done")) {
		return CommandType::DONE;
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

architectureLogic::Months architectureLogic::determineMonthType(std:: string parserInput) {
	if(isValidCommand(parserInput, "jan") || isValidCommand(parserInput, "january")) { 
		return Months::JAN;
	} else if(isValidCommand(parserInput, "feb") || isValidCommand(parserInput, "february")) { 
		return Months::FEB; 
	} else if(isValidCommand(parserInput, "mar") || isValidCommand(parserInput, "march")) {
		return Months::MAR;
	} else if(isValidCommand(parserInput, "apr") || isValidCommand(parserInput, "april")) {
		return Months::APR;
	} else if(isValidCommand(parserInput, "may")) {
		return Months::MAY;
	} else if(isValidCommand(parserInput, "jun") || isValidCommand(parserInput, "june")) {
		return Months::JUN;
	} else if(isValidCommand(parserInput, "jul") || isValidCommand(parserInput, "july")) {
		return Months::JUL;
	} else if(isValidCommand(parserInput, "aug") || isValidCommand(parserInput, "august")) {
		return Months::AUG;
	} else if(isValidCommand(parserInput, "sep") || isValidCommand(parserInput, "september")) {
		return Months::SEP;
	} else if(isValidCommand(parserInput, "oct") || isValidCommand(parserInput, "october")) {
		return Months::OCT;
	} else if(isValidCommand(parserInput, "nov") || isValidCommand(parserInput, "november")) {
		return Months::NOV;
	} else if(isValidCommand(parserInput, "dec") || isValidCommand(parserInput, "december")) {
		return Months::DEC;
	} else { 
		return Months::NOTVALID;
	} 
}

std:: string architectureLogic::concatenateString(std:: vector<std:: string>& parserVector) {
	std:: vector<std:: string>::iterator iter;
	std:: string temp;
	for(iter = parserVector.begin() + 1; iter != parserVector.end(); iter++) {
		temp += *iter;
		temp += " ";
	}

	return trimTrailingSpaces(temp);
}

std:: string architectureLogic::executeCommand() { 

	CommandType commandTypeAction = determineCommandType(_command);

	switch(commandTypeAction) { 
	case ADD: 
		architectureHistory::addPreviousAction(_command);
		return addTask(_contentDescription, _contentDay, _contentMonth, _contentStartHours,
					   _contentStartMinutes, _contentEndHours, _contentEndMinutes);
	case DELETE:
		architectureHistory::addPreviousAction(_command);
		return deleteTask(_taskType, _taskID);
	case CLEAR:
		architectureHistory::addPreviousAction(_command);
		return clearTask(_taskType);
	case UPDATE:
		architectureHistory::addPreviousAction(_command);
		return updateTask(_taskType, _taskID, _contentDescription, _contentDay,
						  _contentMonth, _contentStartHours, _contentStartMinutes, _contentEndHours, _contentEndMinutes);
	case UNDO:
		return undoTask();
	case DONE:
		architectureHistory::addPreviousAction(_command);
		return doneTask(_taskType, _taskID);
	case INVALID:
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		return buffer;
	case EXIT: 
		exit(0);
	}
}

std:: string architectureLogic::trimTrailingSpaces(std:: string buffer) {
	boost::algorithm::trim(buffer);
	return buffer;
}

std:: string architectureLogic::addTask(std:: string _contentDescription, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	assert(_contentDescription != "");
	
	architectureStorage::addToMasterStorage(_contentDescription, _contentDay, _contentMonth, _contentStartHours,
											_contentStartMinutes, _contentEndHours, _contentEndMinutes);

	_content = concatenateString(parserVector);
	sprintf_s(buffer, MESSAGE_ADD.c_str(), _content.c_str());
	return trimTrailingSpaces(buffer);
}

bool architectureLogic::isTodayTaskIDValid(int taskID) {
	int size = architectureStorage::findTotalNumberofTodayTask();
	assert(size >=0);
	if(size < taskID) {
		return false;
	} else {
		return true;
	}
}

bool architectureLogic::isUpcomingTaskIDValid(int taskID) {
	int size = architectureStorage::findTotalNumberofUpcomingTask();
	assert(size >=0);
	if(size < taskID) {
		return false;
	} else {
		return true;
	}
}

bool architectureLogic::isFloatingTaskIDValid(int taskID) {
	int size = architectureStorage::findTotalNumberofFloatingTask();
	assert(size >=0);
	if(size < taskID) {
		return false;
	} else {
		return true;
	}
}
architectureLogic::DateType architectureLogic::determineDateTypeAction(std:: string taskType) {
	assert(taskType != "");
	if(isValidCommand(taskType, "today")) { 
		return DateType::TODAY; 
	} else if(isValidCommand(taskType, "upcoming")) { 
		return DateType::UPCOMING; 
	} else if(isValidCommand(taskType, "misc")) {
		return DateType::MISC;
	} else {
		return DateType::UNVALID;
	}
}
std:: string architectureLogic::deleteTask(std:: string taskType, std:: string taskID) {
	assert(taskID !=  "");
	assert(taskType != "");
	const std:: string temp = taskID;
	int ID = stringToInteger(taskID); 
	DateType commandTypeAction = determineDateTypeAction(taskType);
	std:: vector<TASK>::iterator iter;

	switch(commandTypeAction) {
	case TODAY:
		if(isTodayTaskIDValid(ID)) {
			iter = architectureStorage::findTodayIterator(ID);
			architectureHistory::addPreviousState(*iter);
			architectureStorage::deleteTodayFromStorage(iter);
			sprintf_s(buffer, MESSAGE_DELETETODAY.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}
	case UPCOMING:
		if(isUpcomingTaskIDValid(ID)) {
			iter = architectureStorage::findUpcomingIterator(ID);
			architectureHistory::addPreviousState(*iter);
			architectureStorage::deleteUpcomingFromStorage(iter);
			sprintf_s(buffer, MESSAGE_DELETEUPCOMING.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}
	case MISC:
		if(isFloatingTaskIDValid(ID)) {
			iter = architectureStorage::findFloatingIterator(ID);
			architectureHistory::addPreviousState(*iter);
			architectureStorage::deleteFloatingFromStorage(iter);
			sprintf_s(buffer, MESSAGE_DELETEFLOATING.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}	
	case UNVALID:
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		return buffer;
	}
}

bool architectureLogic::isMasterTaskListEmpty() {
	return architectureStorage::isMasterTaskListEmpty();
}

bool architectureLogic::isTodayTaskListEmpty() {
	return architectureStorage::isTodayTaskListEmpty();
}

bool architectureLogic::isUpcomingTaskListEmpty() {
	return architectureStorage::isUpcomingTaskListEmpty();
}

bool architectureLogic::isFloatingTaskListEmpty() {
	return architectureStorage::isFloatingTaskListEmpty();
}

int architectureLogic::stringToInteger(std:: string input) {
	int output;
	output = atoi(input.c_str()); 
	return output;
}

std:: string architectureLogic::clearTask(std:: string _content) {
	assert(_content != "");

	if (_taskType == MESSAGE_ALL) {
		if(isMasterTaskListEmpty() && isFloatingTaskListEmpty()) {
			sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
			return buffer;
		} else {
			architectureStorage::clearAllFromStorage();
			sprintf_s(buffer, MESSAGE_CLEARALL.c_str());
			return buffer;
		}
	}
	
	if(_taskType == MESSAGE_TODAY) {
		if(isTodayTaskListEmpty()) {
			sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
			return buffer;
		} else {
			architectureStorage::clearTodayFromStorage();
			sprintf_s(buffer, MESSAGE_CLEARTODAY.c_str());
			return buffer;
		}
	}

	if(_taskType == MESSAGE_UPCOMING) {
		if(isUpcomingTaskListEmpty()) {
			sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
			return buffer;
		} else {
			architectureStorage::clearUpcomingFromStorage();
			sprintf_s(buffer, MESSAGE_CLEARUPCOMING.c_str());
			return buffer;
		}
	}

	if(_taskType == MESSAGE_FLOATING) {
		if(isFloatingTaskListEmpty()) {
			sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
			return buffer;
		} else {
			architectureStorage::clearFloatingFromStorage();
			sprintf_s(buffer, MESSAGE_CLEARFLOATING.c_str());
			return buffer;
		}
	} else {
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		return buffer;
	}
}
std:: string architectureLogic::updateTask(std:: string taskType, std:: string taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes) {
	const std:: string temp = taskID;
	int ID = stringToInteger(taskID);
	DateType commandTypeAction = determineDateTypeAction(taskType);
	assert(ID > 0);

	switch(commandTypeAction) {
	case TODAY:
		if(isTodayTaskIDValid(ID)) {
			architectureStorage::updateToTodayStorage(ID, newTask, newDay, newMonth, newStartHours, newStartMinutes, newEndHours, newEndMinutes);
			sprintf_s(buffer, MESSAGE_UPDATETODAY.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}
	case UPCOMING:
		if(isUpcomingTaskIDValid(ID)) {
			architectureStorage::updateToUpcomingStorage(ID, newTask, newDay, newMonth, newStartHours, newStartMinutes, newEndHours, newEndMinutes);
			sprintf_s(buffer, MESSAGE_UPDATEUPCOMING.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}
	case MISC:
		if(isFloatingTaskIDValid(ID)) {
			architectureStorage::updateToFloatingStorage(ID, newTask, newDay, newMonth, newStartHours, newStartMinutes, newEndHours, newEndMinutes);
			sprintf_s(buffer, MESSAGE_UPDATEFLOATING.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}
	case UNVALID:
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
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


std:: string architectureLogic::doneTask(std:: string taskType, std:: string taskID) {
	assert(taskID !=  "");
	assert(taskType != "");
	const std:: string temp = taskID;
	int ID = stringToInteger(taskID); 
	DateType commandTypeAction = determineDateTypeAction(taskType);
	std:: vector<TASK>::iterator iter;

	switch(commandTypeAction) {
	case TODAY:
		if(isTodayTaskIDValid(ID)) {
			iter = architectureStorage::findTodayIterator(ID);
			architectureHistory::addPreviousState(*iter);
			architectureStorage::doneTodayTask(iter);
			sprintf_s(buffer, MESSAGE_DONETODAY.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}
	case UPCOMING:
		if(isUpcomingTaskIDValid(ID)) {
			iter = architectureStorage::findUpcomingIterator(ID);
			architectureHistory::addPreviousState(*iter);
			architectureStorage::doneUpcomingTask(iter);
			sprintf_s(buffer, MESSAGE_DONEUPCOMING.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}
	case MISC:
		if(isFloatingTaskIDValid(ID)) {
			iter = architectureStorage::findFloatingIterator(ID);
			architectureHistory::addPreviousState(*iter);
			architectureStorage::doneFloatingTask(iter);
			sprintf_s(buffer, MESSAGE_DONEFLOATING.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}
	case UNVALID:
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		return buffer;
	}
}