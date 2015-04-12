#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureParser.h"
#include "architectureHistory.h"
#include "architectureBoost.h"
#include "architectureInputFeedback.h"
#include "architectureSaveLoad.h"

const std:: string architectureLogic::STRING_BLANK = "";

const std:: string architectureLogic::COMMAND_INVALID = "invalid";
const std:: string architectureLogic::COMMAND_ADD = "add";
const std:: string architectureLogic::COMMAND_DELETE = "delete";
const std:: string architectureLogic::COMMAND_CLEAR = "clear";
const std:: string architectureLogic::COMMAND_EXIT = "exit";
const std:: string architectureLogic::COMMAND_UNDO = "undo";
const std:: string architectureLogic::COMMAND_DONE = "done";
const std:: string architectureLogic::COMMAND_UPDATE = "update";
const std:: string architectureLogic::COMMAND_SAVE = "save";
const std:: string architectureLogic::COMMAND_FILTER = "filter";
const std:: string architectureLogic::COMMAND_DISPLAY = "display";
const std:: string architectureLogic::COMMAND_TODAY = "today";
const std:: string architectureLogic::COMMAND_UPCOMING = "upcoming";
const std:: string architectureLogic::COMMAND_MISC = "misc";

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

const std:: string architectureLogic::MESSAGE_DISPLAY = "All tasks are displayed";

const std:: string architectureLogic::MESSAGE_ALL = "all";
const std:: string architectureLogic::MESSAGE_TODAY = "today";
const std:: string architectureLogic::MESSAGE_UPCOMING = "upcoming";
const std:: string architectureLogic::MESSAGE_FLOATING = "misc";

const std:: string architectureLogic::MESSAGE_UNDOINVALID = "No more action left to undo";

std:: string architectureLogic::_command;
std:: string architectureLogic::_content;
std:: string architectureLogic::_contentDescription;
std:: string architectureLogic::_contentStartDay;
std:: string architectureLogic::_contentStartMonth;
std:: string architectureLogic::_contentStartHours;
std:: string architectureLogic::_contentStartMinutes;
std:: string architectureLogic::_contentEndDay;
std:: string architectureLogic::_contentEndMonth;
std:: string architectureLogic::_contentEndHours;
std:: string architectureLogic::_contentEndMinutes;
std:: string architectureLogic::_taskType;
std:: string architectureLogic::_taskID;

std:: vector<std:: string> architectureLogic::parserVector;
char architectureLogic::buffer[MAX];


architectureLogic::architectureLogic(){
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

std:: vector<std:: string> architectureLogic::determineCommand(){
	assert(parserVector[0] != STRING_BLANK);

	std:: string feedback;
	std:: vector<std:: string> feedbackList;
	
	if(parserVector[0] == COMMAND_INVALID) {
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
	_contentStartDay = *iter;
	iter++;
	_contentStartMonth= *iter;
	iter++;
	_contentStartHours= *iter;
	iter++;
	//assert(_contentStartHours == "20");
	_contentStartMinutes= *iter;
	//assert( _contentStartMinutes== "00");
	iter++;
	_contentEndDay = *iter;
	//assert(_contentEndDay == "");
	iter++;
	_contentEndMonth = *iter;
	iter++;
	//assert(_contentEndMonth == "");
	_contentEndHours= *iter;
	//assert(_contentEndHours == "22");
	iter++;
	_contentEndMinutes= *iter;
	//assert(_contentEndMinutes == "00");
	assert(_command != STRING_BLANK);
}

std:: string architectureLogic::executeCommand() { 
	CommandType commandTypeAction = determineCommandType(_command);

	switch(commandTypeAction) { 
	case ADD: 
		architectureHistory::addPreviousAction(_command);
		return addTask(_contentDescription, _contentStartDay, _contentStartMonth, _contentStartHours, 
					   _contentStartMinutes, _contentEndDay, _contentEndMonth, _contentEndHours, _contentEndMinutes);
	case DELETE:
		architectureHistory::addPreviousAction(_command);
		return deleteTask(_taskType, _taskID);
	case CLEAR:
		architectureHistory::addPreviousAction(_command);
		return clearTask(_taskType);
	case UPDATE:
		architectureHistory::addPreviousAction(_command);
		return updateTask(_taskType, _taskID, _contentDescription, _contentStartDay,
			_contentStartMonth, _contentStartHours, _contentStartMinutes, _contentEndDay, _contentEndMonth, _contentEndHours, _contentEndMinutes);
	case UNDO:
		return undoTask();
	case DONE:
		architectureHistory::addPreviousAction(_command);
		return doneTask(_taskType, _taskID);
	case SAVE:
		return architectureSaveLoad::changeSavingDirectoryAndFileName(_taskType, _taskID);
	case FILTER:
		return filterTask(_taskType, _taskID);
	case DISPLAY:
		return displayTask();
	case INVALID:
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		return buffer;
	case EXIT: 
		exit(0);
	}
}

architectureLogic::CommandType architectureLogic::determineCommandType(std:: string commandAction) { 
	assert(commandAction != STRING_BLANK);

	if(isValidCommand(commandAction, COMMAND_ADD)) { 
		return CommandType::ADD; 
	} else if(isValidCommand(commandAction, COMMAND_EXIT)) { 
		return CommandType::EXIT; 
	} else if(isValidCommand(commandAction, COMMAND_DELETE)) {
		return CommandType::DELETE;
	} else if(isValidCommand(commandAction, COMMAND_CLEAR)) {
		return CommandType::CLEAR;
	} else if(isValidCommand(commandAction, COMMAND_UPDATE)) {
		return CommandType::UPDATE;
	} else if(isValidCommand(commandAction, COMMAND_UNDO)) {
		return CommandType::UNDO;
	} else if(isValidCommand(commandAction, COMMAND_DONE)) {
		return CommandType::DONE;
	} else if(isValidCommand(commandAction, COMMAND_SAVE)) {
		return CommandType::SAVE;
	} else if(isValidCommand(commandAction, COMMAND_FILTER)) {
		return CommandType::FILTER;
	} else if(isValidCommand(commandAction, COMMAND_DISPLAY)) {
		return CommandType::DISPLAY;
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

std:: string architectureLogic::addTask(std:: string _contentDescription, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
								std:: string _contentStartMinutes, std:: string _contentEndDay, std:: string _contentEndMonth, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	assert(_contentDescription != "");

	// check the validity of the time period, month, day, date
	try {
		if(_contentEndDay != STRING_BLANK) {
			if(!isDateValid(_contentEndDay,_contentEndMonth)) {
				throw MESSAGE_INVALID;
			} 
		}

		if(_contentStartDay!= STRING_BLANK){
			if(!isDateValid(_contentStartDay,_contentStartMonth)) {
				throw MESSAGE_INVALID;
			} 

			if(_contentEndHours!= STRING_BLANK) {
				if(!isTimedTimeValid(_contentStartHours,_contentStartMinutes,_contentEndHours,_contentEndMinutes)) {
					throw MESSAGE_INVALID;
				}
			} else if(!isDeadlineTimeValid(_contentStartHours,_contentStartMinutes)) {
				throw MESSAGE_INVALID;
			}
		}
	} catch (std:: string& exceptionMessage) {
		sprintf_s(buffer, exceptionMessage.c_str());
		return buffer;
	}

	architectureStorage::addToMasterStorage(_contentDescription, _contentStartDay, _contentStartMonth, _contentStartHours,
		_contentStartMinutes, _contentEndDay, _contentEndMonth, _contentEndHours, _contentEndMinutes);

	_content = concatenateString(parserVector);
	sprintf_s(buffer, MESSAGE_ADD.c_str(), _content.c_str());
	return trimTrailingSpaces(buffer);
}

bool architectureLogic::isDateValid(std:: string contentDay, std:: string contentMonth) {

	Months monthType = determineMonthType(contentMonth);
	int intDay = stringToInteger(contentDay);
	try {
		if (( monthType == Months::JAN) || (monthType == Months::MAR) || (monthType == Months::MAY ) || (monthType == Months::JUL )
			|| (monthType == Months::AUG ) || (monthType == Months::OCT) || (monthType == Months::DEC ) ) {
				if ((intDay >= 1) && (intDay <= 31)) {
					return true;
				} else {
					throw MESSAGE_INVALID;
				}
		} else if (( monthType == Months::APR) || (monthType == Months::JUN) || (monthType == Months::SEP ) || (monthType == Months::NOV )) {
			if ((intDay >= 1) && (intDay <= 30)) {
				return true;
			} else {
				throw MESSAGE_INVALID;
			}
		} else if( monthType == Months::FEB) {
			if ((intDay >= 1) && (intDay <= 28)) {
				return true;
			} else {
				throw MESSAGE_INVALID;
			}
		} else {
			throw MESSAGE_INVALID;
		}
	} catch (std:: string& exceptionMessage) {
		// LOG(INFO) << exceptionMessage; 
		return false;
	}
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

int architectureLogic::stringToInteger(std:: string input) {
	int output;
	output = atoi(input.c_str()); 
	return output;
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

std:: string architectureLogic::trimTrailingSpaces(std:: string buffer) {
	boost::algorithm::trim(buffer);
	return buffer;
}

bool architectureLogic::isTimedTimeValid(std:: string startHour, std:: string startMin, std::string endHour, std::string endMin ){
	int startIntHour = stringToInteger(startHour);
	int startIntMin = stringToInteger(startMin);
	int endIntHour = stringToInteger(endHour);
	int endIntMin = stringToInteger(endMin);

	if ((startIntHour < 0) || (startIntHour > 24)) {
		return false;
	} else if ((startIntMin < 0) || (startIntMin > 60)) {
		return false;
	} else if ((endIntHour < 0) || (endIntHour > 24)) {
		return false;
	} else if ((endIntMin < 0) || (endIntMin > 60)) {
		return false;
	} else if (startIntHour > endIntHour ) {
		return false;
    } else if (startIntHour == endIntHour ) {
		if ( startIntMin > endIntMin)
		return false;
	} else {
		return true;
	}
}

bool architectureLogic::isDeadlineTimeValid(std:: string startHour, std:: string startMin) {

	int startIntHour = stringToInteger(startHour);
	int startIntMin = stringToInteger(startMin);

	if ((startIntHour < 0) || (startIntHour > 24)) {
		return false;
	} else if ((startIntMin < 0) || (startIntMin > 60)) {
		return false;
	} else {
		return true;
	}
}

std:: string architectureLogic::deleteTask(std:: string taskType, std:: string taskID) {
	assert(taskID !=  STRING_BLANK);
	assert(taskType != STRING_BLANK);

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

architectureLogic::DateType architectureLogic::determineDateTypeAction(std:: string taskType) {
	assert(taskType != STRING_BLANK);

	if(isValidCommand(taskType, COMMAND_TODAY)) { 
		return DateType::TODAY; 
	} else if(isValidCommand(taskType, COMMAND_UPCOMING)) { 
		return DateType::UPCOMING; 
	} else if(isValidCommand(taskType, COMMAND_MISC)) {
		return DateType::MISC;
	} else {
		return DateType::UNVALID;
	}
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

std:: string architectureLogic::clearTask(std:: string _content) {
	assert(_content != STRING_BLANK);

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

std:: string architectureLogic::updateTask(std:: string taskType, std:: string taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
									std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes) {
	const std:: string temp = taskID;
	int ID = stringToInteger(taskID);
	DateType commandTypeAction = determineDateTypeAction(taskType);
	assert(ID > 0);
	assert(newTask != STRING_BLANK);

	switch(commandTypeAction) {
	case TODAY:
		if(isTodayTaskIDValid(ID)) {
			architectureStorage::updateToTodayStorage(ID, newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);
			sprintf_s(buffer, MESSAGE_UPDATETODAY.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}
	case UPCOMING:
		if(isUpcomingTaskIDValid(ID)) {
			architectureStorage::updateToUpcomingStorage(ID, newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);
			sprintf_s(buffer, MESSAGE_UPDATEUPCOMING.c_str(), temp.c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_NOTFOUND.c_str());
			return buffer;
		}
	case MISC:
		if(isFloatingTaskIDValid(ID)) {
			architectureStorage::updateToFloatingStorage(ID, newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);
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
	assert(taskID !=  STRING_BLANK);
	assert(taskType != STRING_BLANK);

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

std:: string architectureLogic::filterTask(std:: string day, std:: string month) {
	if(!isDateValid(day,month)) {
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		return buffer;
	} else {
		std:: string feedback;
		feedback = architectureStorage::filterTaskInStorage(day, month);
		return feedback;
	}
}

std:: string architectureLogic::displayTask() {
	if(architectureStorage::isMasterTaskListEmpty() && architectureStorage::isFloatingTaskListEmpty()) {
		sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
		return buffer;
	} else {
		architectureStorage::displayTaskInStorage();
		sprintf_s(buffer, MESSAGE_DISPLAY.c_str());
		return buffer;
	}
}