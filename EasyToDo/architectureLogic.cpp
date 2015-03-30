#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureParser.h"
#include "architectureHistory.h"
#include "architectureBoost.h"

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
const std:: string architectureLogic::MESSAGE_DONETODAY = "Today Task %s is deleted!";
const std:: string architectureLogic::MESSAGE_DONEUPCOMING = "Upcoming Task %s is deleted!";
const std:: string architectureLogic::MESSAGE_DONEFLOATING = "Floating Task %s is deleted!";
const std:: string architectureLogic::MESSAGE_CLEARALL = "All task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARTODAY = "Today's task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARUPCOMING = "Upcoming task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_CLEARFLOATING = "Floating task(s) are deleted!";
const std:: string architectureLogic::MESSAGE_STORAGEEMPTY = "Task List is already empty!";
const std:: string architectureLogic::MESSAGE_UPDATETODAY = "Today Task %s is updated successfully";
const std:: string architectureLogic::MESSAGE_UPDATEUPCOMING = "Upcoming Task %s is updated successfully";
const std:: string architectureLogic::MESSAGE_UPDATEFLOATING = "Floating Task %s is updated successfully";
const std:: string architectureLogic::MESSAGE_UNDOINVALID = "No more action left to undo";
const std:: string architectureLogic::MESSAGE_ALL = " all";
const std:: string architectureLogic::MESSAGE_TODAY = " today";
const std:: string architectureLogic::MESSAGE_UPCOMING = " upcoming";
const std:: string architectureLogic::MESSAGE_FLOATING = " floating";

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

std:: vector<std:: string> architectureLogic::architectureFeedbackHistory::masterFeedbackList;


char architectureLogic::buffer[MAX];

architectureLogic::architectureFeedbackHistory::architectureFeedbackHistory() {
}

void architectureLogic::architectureFeedbackHistory::addToFeedbackList(std:: string feedback) {
	masterFeedbackList.push_back(feedback);
}

std:: vector<std:: string> architectureLogic::architectureFeedbackHistory::retrieveFeedbackList(){
	std:: vector< std:: string> temp;

	for (int i=0; i<masterFeedbackList.size(); i++) {
		temp.push_back(masterFeedbackList[i]);
	}

	return temp;
}

architectureLogic::architectureLogic(){
}

std:: vector<std:: string> architectureLogic::determineCommand(std:: string content){
	assert(content != "");
	std:: string feedback;
	std:: vector<std:: string> feedbackList;

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
	trimTrailingSpaces(_content);
	assert(_command != "");
	feedback = executeCommand(_command);

	architectureFeedbackHistory::addToFeedbackList(feedback);
	feedbackList = architectureFeedbackHistory::retrieveFeedbackList();


	return feedbackList;
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

void architectureLogic::determineContentMonth(std:: string parserInput) {
	Months month;
	month = determineMonthType(parserInput);
	std:: stringstream ss;
	ss << month;
	std:: string str = ss.str();
	// assert(month != NOTVALID);
	_contentMonth = str;
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

void architectureLogic::determineTaskType(std:: string parserInput) {
	assert(parserInput != "");
	_taskType = parserInput;
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
		Parser::tokenizeDELETE(_content);
		return deleteTask(_taskType, _taskID);
	case CLEAR:
		return clearTask(_content);
	case UPDATE:
		Parser::tokenizeUPDATE(_content);
		return updateTask(_taskType, _taskID, _contentDescription, _contentDay, _contentMonth, _contentStartHours, _contentStartMinutes, _contentEndHours, _contentEndMinutes);
	case INVALID:
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		return buffer;
	case UNDO:
		return undoTask();
	case DONE:
		Parser::tokenizeDateMonth(_content);
		return doneTask(_taskType, _taskID);
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
	architectureStorage::addToMasterStorage(_contentDescription, _contentDay, _contentMonth, _contentStartHours, _contentStartMinutes, _contentEndHours, _contentEndMinutes);
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
	//assert(taskType != "");
	if(isValidCommand(taskType, "today ")) { 
		return DateType::TODAY; 
	} else if(isValidCommand(taskType, "upcoming ")) { 
		return DateType::UPCOMING; 
	} else if(isValidCommand(taskType, "misc ")) {
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

	if (_content == MESSAGE_ALL) {
		if(isMasterTaskListEmpty() && isFloatingTaskListEmpty()) {
			sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
			return buffer;
		} else {
			architectureStorage::clearAllFromStorage();
			sprintf_s(buffer, MESSAGE_CLEARALL.c_str());
			return buffer;
		}
	}

	if(_content == MESSAGE_TODAY) {
		if(isTodayTaskListEmpty()) {
			sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
			return buffer;
		} else {
			architectureStorage::clearTodayFromStorage();
			sprintf_s(buffer, MESSAGE_CLEARTODAY.c_str());
			return buffer;
		}
	}

	if(_content == MESSAGE_UPCOMING) {
		if(isUpcomingTaskListEmpty()) {
			sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
			return buffer;
		} else {
			architectureStorage::clearUpcomingFromStorage();
			sprintf_s(buffer, MESSAGE_CLEARUPCOMING.c_str());
			return buffer;
		}
	}

	if(_content == MESSAGE_FLOATING) {
		if(isFloatingTaskListEmpty()) {
			sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
			return buffer;
		} else {
			architectureStorage::clearFloatingFromStorage();
			sprintf_s(buffer, MESSAGE_CLEARFLOATING.c_str());
			return buffer;
		}
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
			// architectureHistory::addPreviousState(*iter);
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
			// architectureHistory::addPreviousState(*iter);
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
			// architectureHistory::addPreviousState(*iter);
			architectureStorage::deleteFloatingFromStorage(iter);
			architectureStorage::doneFloatingTask(iter);
			sprintf_s(buffer, MESSAGE_DONEFLOATING.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}
	}
}