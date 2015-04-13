// @author A0111378J
#include "E2DLogic.h"
#include "E2DInputFeedback.h"
#include "E2DStorage.h"
#include "E2DLogging.h"
#include "E2DHistory.h"
#include "E2DSaveLoad.h"

const std:: string E2DLogic::STRING_BLANK = "";
const std:: string E2DLogic::SEVERITY_LEVEL_WARNING = "Warning";
const std:: string E2DLogic::SEVERITY_LEVEL_INFO = "Info";
const std:: string E2DLogic::SEVERITY_LEVEL_ERROR = "Error";
const std:: string E2DLogic::MESSAGE_LOG_INVALID = "Invalid User Input";
const std:: string E2DLogic::MESSAGE_END_USAGE = "end of previous usage";

const std:: string E2DLogic::COMMAND_INVALID = "invalid";
const std:: string E2DLogic::COMMAND_ADD = "add";
const std:: string E2DLogic::COMMAND_SHORTCUT_ADD = "a";
const std:: string E2DLogic::COMMAND_DELETE = "delete";
const std:: string E2DLogic::COMMAND_SHORTCUT_DELETE = "del";
const std:: string E2DLogic::COMMAND_CLEAR = "clear";
const std:: string E2DLogic::COMMAND_SHORTCUT_CLEAR = "clr";
const std:: string E2DLogic::COMMAND_EXIT = "exit";
const std:: string E2DLogic::COMMAND_UNDO = "undo";
const std:: string E2DLogic::COMMAND_DONE = "done";
const std:: string E2DLogic::COMMAND_SHORTCUT_DONE = "d";
const std:: string E2DLogic::COMMAND_UPDATE = "update";
const std:: string E2DLogic::COMMAND_SHORTCUT_UPDATE = "up";
const std:: string E2DLogic::COMMAND_SAVE = "save";
const std:: string E2DLogic::COMMAND_FILTER = "filter";
const std:: string E2DLogic::COMMAND_SHORTCUT_FILTER = "fil";
const std:: string E2DLogic::COMMAND_DISPLAY = "display";
const std:: string E2DLogic::COMMAND_SHORTCUT_DISPLAY = "dis";
const std:: string E2DLogic::COMMAND_SEARCH = "search";
const std:: string E2DLogic::COMMAND_SHORTCUT_SEARCH = "src";
const std:: string E2DLogic::COMMAND_TODAY = "today";
const std:: string E2DLogic::COMMAND_UPCOMING = "upcoming";
const std:: string E2DLogic::COMMAND_FLOAT = "float";

const std:: string E2DLogic::MESSAGE_ADD = "Task \"%s\" is added successfully";
const std:: string E2DLogic::MESSAGE_INVALID = "ERROR! Invalid Command";
const std:: string E2DLogic::MESSAGE_NOTFOUND = "Task is not found!";

const std:: string E2DLogic::MESSAGE_DELETETODAY = "Today Task %s is deleted!";
const std:: string E2DLogic::MESSAGE_DELETEUPCOMING = "Upcoming Task %s is deleted!";
const std:: string E2DLogic::MESSAGE_DELETEFLOATING = "Floating Task %s is deleted!";

const std:: string E2DLogic::MESSAGE_DONETODAY = "Today Task %s is done!";
const std:: string E2DLogic::MESSAGE_DONEUPCOMING = "Upcoming Task %s is done!";
const std:: string E2DLogic::MESSAGE_DONEFLOATING = "Floating Task %s is done!";

const std:: string E2DLogic::MESSAGE_CLEARALL = "All task(s) are deleted!";
const std:: string E2DLogic::MESSAGE_CLEARTODAY = "Today's task(s) are deleted!";
const std:: string E2DLogic::MESSAGE_CLEARUPCOMING = "Upcoming task(s) are deleted!";
const std:: string E2DLogic::MESSAGE_CLEARFLOATING = "Floating task(s) are deleted!";
const std:: string E2DLogic::MESSAGE_STORAGEEMPTY = "Task List is already empty!";

const std:: string E2DLogic::MESSAGE_UPDATETODAY = "Today Task %s is updated successfully";
const std:: string E2DLogic::MESSAGE_UPDATEUPCOMING = "Upcoming Task %s is updated successfully";
const std:: string E2DLogic::MESSAGE_UPDATEFLOATING = "Floating Task %s is updated successfully";

const std:: string E2DLogic::MESSAGE_DISPLAY = "All tasks are displayed";

const std:: string E2DLogic::MESSAGE_ALL = "all";
const std:: string E2DLogic::MESSAGE_TODAY = "today";
const std:: string E2DLogic::MESSAGE_UPCOMING = "upcoming";
const std:: string E2DLogic::MESSAGE_FLOATING = "float";

const std:: string E2DLogic::MESSAGE_UNDOINVALID = "No more action left to undo";

const std:: string E2DLogic::DEFAULT_YEAR = "2015,"; 

std:: string E2DLogic::_command;
std:: string E2DLogic::_content;
std:: string E2DLogic::_contentDescription;
std:: string E2DLogic::_contentStartDay;
std:: string E2DLogic::_contentStartMonth;
std:: string E2DLogic::_contentStartHours;
std:: string E2DLogic::_contentStartMinutes;
std:: string E2DLogic::_contentEndDay;
std:: string E2DLogic::_contentEndMonth;
std:: string E2DLogic::_contentEndHours;
std:: string E2DLogic::_contentEndMinutes;
std:: string E2DLogic::_taskType;
std:: string E2DLogic::_taskID;

std:: vector<std:: string> E2DLogic::parserVector;
char E2DLogic::buffer[MAX];

E2DLogic::E2DLogic(){
}

void E2DLogic::pushParserVector(std:: vector<std:: string>& temp) {
	parserVector.clear();
	std:: vector<std:: string>::iterator iter;
	iter = temp.begin();
	assert((*iter) != "");
	for(iter = temp.begin(); iter != temp.end(); iter++) {
		parserVector.push_back(*iter);
	}
	determineCommand();
} 

void E2DLogic::determineCommand(){
	assert(parserVector[0] != STRING_BLANK);

	std:: string feedback;
	std:: vector<std:: string> feedbackList;
	
	if(parserVector[0] == COMMAND_INVALID) {
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__ , std:: to_string(__LINE__), MESSAGE_LOG_INVALID);
		feedback = buffer;
	} else {
		initializeCommand();
		feedback = executeCommand();
	}

	E2DInputFeedback::addToMasterFeedbackList(feedback);
}

void E2DLogic::initializeCommand() {
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
	_contentStartMinutes= *iter;
	iter++;
	_contentEndDay = *iter;
	iter++;
	_contentEndMonth = *iter;
	iter++;
	_contentEndHours= *iter;
	iter++;
	_contentEndMinutes= *iter;
	
	if(_command == STRING_BLANK) {
		E2DLogging::logToFile(SEVERITY_LEVEL_ERROR, __FILE__, std:: to_string(__LINE__), "E2DParser fail to pass me valid parserVector");
		assert(_command != STRING_BLANK);
	}
}

std:: string E2DLogic::executeCommand() { 
	CommandType commandTypeAction = determineCommandType(_command);

	switch(commandTypeAction) { 
	case ADD: 
		E2DHistory::addPreviousAction(_command);
		return addTask(_contentDescription, _contentStartDay, _contentStartMonth, _contentStartHours, 
					   _contentStartMinutes, _contentEndDay, _contentEndMonth, _contentEndHours, _contentEndMinutes);
	case DEL:
		E2DHistory::addPreviousAction(_command);
		return deleteTask(_taskType, _taskID);
	case CLEAR:
		E2DHistory::addPreviousAction(_command);
		return clearTask(_taskType);
	case UPDATE:
		E2DHistory::addPreviousAction(_command);
		return updateTask(_taskType, _taskID, _contentDescription, _contentStartDay,
			_contentStartMonth, _contentStartHours, _contentStartMinutes, _contentEndDay, _contentEndMonth, _contentEndHours, _contentEndMinutes);
	case UNDO:
		return undoTask();
	case DONE:
		E2DHistory::addPreviousAction(_command);
		return doneTask(_taskType, _taskID);
	case SAVE:
		return E2DSaveLoad::changeSavingDirectoryAndFileName(_taskType, _taskID);
	case FILTER:
		//assert(_taskType == "18");
		//assert(_taskID == "00");
		return filterTask(_taskType, _taskID);
	case DISPLAY:
		return displayTask();
	case SEARCH:
		return searchTask(_taskType);
	case INVALID:
		E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + _command);
		sprintf_s(buffer, MESSAGE_INVALID.c_str());
		return buffer;
	case EXIT: 
		E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), MESSAGE_END_USAGE);
		exit(0);
	}
}

E2DLogic::CommandType E2DLogic::determineCommandType(std:: string commandAction) { 
	assert(commandAction != STRING_BLANK);

	if(isValidCommand(commandAction, COMMAND_ADD) || isValidCommand(commandAction, COMMAND_SHORTCUT_ADD)) { 
		return CommandType::ADD; 
	} else if(isValidCommand(commandAction, COMMAND_EXIT)) { 
		return CommandType::EXIT; 
	} else if(isValidCommand(commandAction, COMMAND_DELETE) || isValidCommand(commandAction, COMMAND_SHORTCUT_DELETE)) {
		return CommandType::DEL;
	} else if(isValidCommand(commandAction, COMMAND_CLEAR) || isValidCommand(commandAction, COMMAND_SHORTCUT_CLEAR)) {
		return CommandType::CLEAR;
	} else if(isValidCommand(commandAction, COMMAND_UPDATE) || isValidCommand(commandAction, COMMAND_SHORTCUT_UPDATE)) {
		return CommandType::UPDATE;
	} else if(isValidCommand(commandAction, COMMAND_UNDO)) {
		return CommandType::UNDO;
	} else if(isValidCommand(commandAction, COMMAND_DONE) || isValidCommand(commandAction, COMMAND_SHORTCUT_DONE)) {
		return CommandType::DONE;
	} else if(isValidCommand(commandAction, COMMAND_SAVE)) {
		return CommandType::SAVE;
	} else if(isValidCommand(commandAction, COMMAND_FILTER) || isValidCommand(commandAction, COMMAND_SHORTCUT_FILTER)) {
		return CommandType::FILTER;
	} else if(isValidCommand(commandAction, COMMAND_DISPLAY) || isValidCommand(commandAction, COMMAND_SHORTCUT_DISPLAY)) {
		return CommandType::DISPLAY;
	} else if(isValidCommand(commandAction, COMMAND_SEARCH) || isValidCommand(commandAction, COMMAND_SHORTCUT_SEARCH)) {
		return CommandType::SEARCH;
	} else { 
		return CommandType::INVALID;
	} 
}

bool E2DLogic::isValidCommand(const std:: string& str1, const std:: string& str2) { 
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

std:: string E2DLogic::addTask(std:: string _contentDescription, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
								std:: string _contentStartMinutes, std:: string _contentEndDay, std:: string _contentEndMonth, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	assert(_contentDescription != "");

	// check the validity of the time period, month, day, date
	try {
		if(_contentEndDay != STRING_BLANK) {
			if(!isDateValid(_contentEndDay,_contentEndMonth)) {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "endDay/endMonth is not valid");
				throw MESSAGE_INVALID;
			} 
		}

		if(_contentStartDay!= STRING_BLANK){
			if(!isDateValid(_contentStartDay,_contentStartMonth)) {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__),  MESSAGE_LOG_INVALID + ": " + "startDay/startMonth is not valid");
				throw MESSAGE_INVALID;
			} 

			if(_contentEndHours!= STRING_BLANK && _contentEndDay == STRING_BLANK) {
				if(!isTimedTimeValid(_contentStartHours,_contentStartMinutes,_contentEndHours,_contentEndMinutes)) {
					E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "startHr/startMin/endHr/endMin is not valid");
					throw MESSAGE_INVALID;
				}
			} else if(_contentEndHours!= STRING_BLANK) {
				if(!isMultiTimeValid(_contentStartDay,_contentStartMonth,_contentStartHours,_contentStartMinutes,_contentEndDay,_contentEndMonth,_contentEndHours,_contentEndMinutes)) {
					E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "startDay/startMon/startHr/startMin/endDay/endMon/endHr/endMin is not valid");
					throw MESSAGE_INVALID;
				}
			} else if(!isDeadlineTimeValid(_contentStartHours,_contentStartMinutes)) {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__),  MESSAGE_LOG_INVALID + ": " + "startHr/startMin is not valid");
				throw MESSAGE_INVALID;
			}
		}
	} catch (std:: string& exceptionMessage) {
		sprintf_s(buffer, exceptionMessage.c_str());
		return buffer;
	}

	E2DStorage::addToMasterStorage(_contentDescription, _contentStartDay, _contentStartMonth, _contentStartHours,
		_contentStartMinutes, _contentEndDay, _contentEndMonth, _contentEndHours, _contentEndMinutes);

	_content = concatenateString(parserVector);
	sprintf_s(buffer, MESSAGE_ADD.c_str(), _content.c_str());
	return buffer;
}

bool E2DLogic::isDateValid(std:: string contentDay, std:: string contentMonth) {

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
		return false;
	}
}

E2DLogic::Months E2DLogic::determineMonthType(std:: string parserInput) {
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

int E2DLogic::stringToInteger(std:: string input) {
	int output;
	output = atoi(input.c_str()); 
	return output;
}

std:: string E2DLogic::concatenateString(std:: vector<std:: string>& parserVector) {
	std:: vector<std:: string>::iterator iter;
	std:: string temp;
	for(iter = parserVector.begin() + 1; iter != parserVector.end(); iter++) {
		if(*iter != "") {
			temp += *iter;
			temp += " ";
		}
	}

	return trimTrailingSpaces(temp);
}

std:: string E2DLogic::trimTrailingSpaces(std:: string buffer) {
	boost::algorithm::trim(buffer);
	return buffer;
}

bool E2DLogic::isTimedTimeValid(std:: string startHour, std:: string startMin, std::string endHour, std::string endMin) {
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

bool E2DLogic::isMultiTimeValid(std::string startDay,std::string startMonth,std::string startHour,std::string startMin,std::string endDay,std::string endMonth,std::string endHour, std::string endMin) {
	int startIntHour = stringToInteger(startHour);
	int startIntMin = stringToInteger(startMin);
	int endIntHour = stringToInteger(endHour);
	int endIntMin = stringToInteger(endMin);

	std::string startDateString = DEFAULT_YEAR +  startMonth + "," + startDay;
	date d1(from_string(startDateString));
	ptime temp1(d1, time_duration(hours(stringToInteger(startHour))+minutes(stringToInteger(startMin))));

	std::string endDateString = DEFAULT_YEAR + endMonth + "," + endDay;
	date d2(from_string(endDateString));
	ptime temp2(d2,time_duration(hours(stringToInteger(endHour))+minutes(stringToInteger(endMin))));


	if( temp1 > temp2 ) {
		return false; 
	} else if ((startIntHour < 0) || (startIntHour > 24)) {
		return false;
	} else if ((startIntMin < 0) || (startIntMin > 60)) {
		return false;
	} else if ((endIntHour < 0) || (endIntHour > 24)) {
		return false;
	} else if ((endIntMin < 0) || (endIntMin > 60)) {
		return false;
	} else {
		return true;
	}
}

bool E2DLogic::isDeadlineTimeValid(std:: string startHour, std:: string startMin) {
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

std:: string E2DLogic::deleteTask(std:: string taskType, std:: string taskID) {
	assert(taskID !=  STRING_BLANK);
	assert(taskType != STRING_BLANK);

	const std:: string temp = taskID;
	int ID = stringToInteger(taskID); 
	DateType commandTypeAction = determineDateTypeAction(taskType);
	std:: vector<TASK>::iterator iter;

	try {
		switch(commandTypeAction) {
		case TODAY:
			if(isTodayTaskIDValid(ID)) {
				iter = E2DStorage::findTodayIterator(ID);
				E2DHistory::addPreviousState(*iter);
				E2DStorage::deleteTodayFromStorage(iter);
				sprintf_s(buffer, MESSAGE_DELETETODAY.c_str(), temp.c_str());
				return buffer;
			} else {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found in \"today\"");
				throw MESSAGE_NOTFOUND;
			}
		case UPCOMING:
			if(isUpcomingTaskIDValid(ID)) {
				iter = E2DStorage::findUpcomingIterator(ID);
				E2DHistory::addPreviousState(*iter);
				E2DStorage::deleteUpcomingFromStorage(iter);
				sprintf_s(buffer, MESSAGE_DELETEUPCOMING.c_str(), temp.c_str());
				return buffer;
			} else {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found in \"upcoming\"");
				throw MESSAGE_NOTFOUND;
			}
		case FLOAT:
			if(isFloatingTaskIDValid(ID)) {
				iter = E2DStorage::findFloatingIterator(ID);
				E2DHistory::addPreviousState(*iter);
				E2DStorage::deleteFloatingFromStorage(iter);
				sprintf_s(buffer, MESSAGE_DELETEFLOATING.c_str(), temp.c_str());
				return buffer;
			} else {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found in \"Float\"");
				throw MESSAGE_NOTFOUND;
			}	
		case UNVALID:
			E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "invalid taskType input");
			throw MESSAGE_INVALID;
		}
	} catch (std:: string& exceptionMessage) {
		sprintf_s(buffer, exceptionMessage.c_str());
		return buffer;
	}
}

E2DLogic::DateType E2DLogic::determineDateTypeAction(std:: string taskType) {
	assert(taskType != STRING_BLANK);

	if(isValidCommand(taskType, COMMAND_TODAY)) { 
		return DateType::TODAY; 
	} else if(isValidCommand(taskType, COMMAND_UPCOMING)) { 
		return DateType::UPCOMING; 
	} else if(isValidCommand(taskType, COMMAND_FLOAT)) {
		return DateType::FLOAT;
	} else {
		return DateType::UNVALID;
	}
}

bool E2DLogic::isTodayTaskIDValid(int taskID) {
	int size = E2DStorage::findTotalNumberofTodayTask();
	assert(size >=0);
	if(size < taskID) {
		return false;
	} else {
		return true;
	}
}

bool E2DLogic::isUpcomingTaskIDValid(int taskID) {
	int size = E2DStorage::findTotalNumberofUpcomingTask();
	assert(size >=0);
	if(size < taskID) {
		return false;
	} else {
		return true;
	}
}

bool E2DLogic::isFloatingTaskIDValid(int taskID) {
	int size = E2DStorage::findTotalNumberofFloatingTask();
	assert(size >=0);
	if(size < taskID) {
		return false;
	} else {
		return true;
	}
}

std:: string E2DLogic::clearTask(std:: string _content) {
	assert(_content != STRING_BLANK);

	try {
		if (_taskType == MESSAGE_ALL) {
			if(isMasterTaskListEmpty() && isFloatingTaskListEmpty()) {
				E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), "All tasklists are already cleared");
				throw MESSAGE_STORAGEEMPTY;
			} else {
				E2DStorage::clearAllFromStorage();
				throw MESSAGE_CLEARALL;
			}
		}

		if(_taskType == MESSAGE_TODAY) {
			if(isTodayTaskListEmpty()) {
				E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), "todayTaskList is already cleared");
				throw MESSAGE_STORAGEEMPTY;
			} else {
				E2DStorage::clearTodayFromStorage();
				throw MESSAGE_CLEARTODAY;
			}
		}

		if(_taskType == MESSAGE_UPCOMING) {
			if(isUpcomingTaskListEmpty()) {
				E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), "upcomingTaskList is already cleared");
				throw MESSAGE_STORAGEEMPTY;
			} else {
				E2DStorage::clearUpcomingFromStorage();
				throw MESSAGE_CLEARUPCOMING;
			}
		}

		if(_taskType == MESSAGE_FLOATING) {
			if(isFloatingTaskListEmpty()) {
				E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), "floatingTaskList is already cleared");
				throw MESSAGE_STORAGEEMPTY;
			} else {
				E2DStorage::clearFloatingFromStorage();
				throw MESSAGE_CLEARFLOATING;
			}
		} else {
			E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID);
			throw MESSAGE_INVALID;
		}
	} catch (std:: string& exceptionMessage) {
		sprintf_s(buffer, exceptionMessage.c_str());
		return buffer;
	}
}

bool E2DLogic::isMasterTaskListEmpty() {
	return E2DStorage::isMasterTaskListEmpty();
}

bool E2DLogic::isTodayTaskListEmpty() {
	return E2DStorage::isTodayTaskListEmpty();
}

bool E2DLogic::isUpcomingTaskListEmpty() {
	return E2DStorage::isUpcomingTaskListEmpty();
}

bool E2DLogic::isFloatingTaskListEmpty() {
	return E2DStorage::isFloatingTaskListEmpty();
}

std:: string E2DLogic::updateTask(std:: string taskType, std:: string taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
									std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes) {
	const std:: string temp = taskID;
	int ID = stringToInteger(taskID);
	DateType commandTypeAction = determineDateTypeAction(taskType);
	assert(ID > 0);
	if(newTask == STRING_BLANK) {
		E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID);
		assert(newTask != STRING_BLANK);
	}

	try {
		switch(commandTypeAction) {
		case TODAY:
			if(isTodayTaskIDValid(ID)) {
				E2DStorage::updateToTodayStorage(ID, newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);
				sprintf_s(buffer, MESSAGE_UPDATETODAY.c_str(), temp.c_str());
				return buffer;
			} else {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found in \"today\"");
				throw MESSAGE_NOTFOUND;
			}
		case UPCOMING:
			if(isUpcomingTaskIDValid(ID)) {
				E2DStorage::updateToUpcomingStorage(ID, newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);
				sprintf_s(buffer, MESSAGE_UPDATEUPCOMING.c_str(), temp.c_str());
				return buffer;
			} else {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found in \"upcoming\"");
				throw MESSAGE_NOTFOUND;
			}
		case FLOAT:
			if(isFloatingTaskIDValid(ID)) {
				E2DStorage::updateToFloatingStorage(ID, newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);
				sprintf_s(buffer, MESSAGE_UPDATEFLOATING.c_str(), temp.c_str());
				return buffer;
			} else {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found in \"floating\"");
				throw MESSAGE_NOTFOUND;
			}
		case UNVALID:
			E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID);
			throw MESSAGE_INVALID;
		}
	} catch (std:: string& exceptionMessage) {
		sprintf_s(buffer, exceptionMessage.c_str());
		return buffer;
	}
}

std:: string E2DLogic::undoTask() {
	std:: string feedback;
	if(E2DHistory::isUndoStackEmpty()) {
		E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID);
		sprintf_s(buffer, MESSAGE_UNDOINVALID.c_str());
		return buffer;
	} else {
		feedback = E2DHistory::undoAction();
		return feedback;
	}
}

std:: string E2DLogic::doneTask(std:: string taskType, std:: string taskID) {
	if(taskType == STRING_BLANK) {
		E2DLogging::logToFile(SEVERITY_LEVEL_ERROR, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + "E2DParser is not tokenizing properly");
		assert(taskType !=  STRING_BLANK);
	}
	if(taskID == STRING_BLANK) {
		E2DLogging::logToFile(SEVERITY_LEVEL_ERROR, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + "E2DParser is not tokenizing properly");
		assert(taskID != STRING_BLANK);
	}

	const std:: string temp = taskID;
	int ID = stringToInteger(taskID); 
	DateType commandTypeAction = determineDateTypeAction(taskType);
	std:: vector<TASK>::iterator iter;

	try {
		switch(commandTypeAction) {
		case TODAY:
			if(isTodayTaskIDValid(ID)) {
				iter = E2DStorage::findTodayIterator(ID);
				E2DHistory::addPreviousState(*iter);
				E2DStorage::doneTodayTask(iter);
				sprintf_s(buffer, MESSAGE_DONETODAY.c_str(), temp.c_str());
				return buffer;
			} else {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found in \"today\"");
				throw MESSAGE_NOTFOUND;
			}
		case UPCOMING:
			if(isUpcomingTaskIDValid(ID)) {
				iter = E2DStorage::findUpcomingIterator(ID);
				E2DHistory::addPreviousState(*iter);
				E2DStorage::doneUpcomingTask(iter);
				sprintf_s(buffer, MESSAGE_DONEUPCOMING.c_str(), temp.c_str());
				return buffer;
			} else {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found in \"upcoming\"");
				throw MESSAGE_NOTFOUND;
			}
		case FLOAT:
			if(isFloatingTaskIDValid(ID)) {
				iter = E2DStorage::findFloatingIterator(ID);
				E2DHistory::addPreviousState(*iter);
				E2DStorage::doneFloatingTask(iter);
				sprintf_s(buffer, MESSAGE_DONEFLOATING.c_str(), temp.c_str());
				return buffer;
			} else {
				E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found in \"Float\"");
				throw MESSAGE_NOTFOUND;
			}
		case UNVALID:
			E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID);
			throw MESSAGE_INVALID;
		}
	} catch(std:: string& exceptionMessage) {
		sprintf_s(buffer, exceptionMessage.c_str());
		return buffer;
	}
}

std:: string E2DLogic::filterTask(std:: string dayOrHour, std:: string monthOrMin) {
	Months monthType = determineMonthType(monthOrMin);
	std:: string feedback;

	if(E2DStorage::isMasterTaskListEmpty() && E2DStorage::isFloatingTaskListEmpty()) {
		E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), MESSAGE_STORAGEEMPTY);
		sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
		return buffer;
	} else if (monthType != Months::NOTVALID) { // the user input is a date and month e.g filter 14 may
		if(!isDateValid(dayOrHour,monthOrMin)) {
			E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__),  MESSAGE_LOG_INVALID + ": " + "invalid day/month input");
			sprintf_s(buffer, MESSAGE_INVALID.c_str());
			return buffer;
		} else {
			feedback = E2DStorage::filterTaskByDayAndMonth(dayOrHour, monthOrMin);
			return feedback;
		}
	} else { // invalid month -> assuming the user input is a time
		if(!isDeadlineTimeValid(dayOrHour, monthOrMin)) {
			E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__),  MESSAGE_LOG_INVALID + ": " + "invalid time input");
			sprintf_s(buffer, MESSAGE_INVALID.c_str());
			return buffer;
		} else {
			feedback = E2DStorage::filterTaskByHrAndMin(dayOrHour, monthOrMin);
			return feedback;
		}
	}
}

std:: string E2DLogic::displayTask() {
	if(E2DStorage::isMasterTaskListEmpty() && E2DStorage::isFloatingTaskListEmpty()) {
		E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), MESSAGE_STORAGEEMPTY);
		sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
		return buffer;
	} else {
		E2DStorage::displayTaskInStorage();
		sprintf_s(buffer, MESSAGE_DISPLAY.c_str());
		return buffer;
	}
}

std:: string E2DLogic::searchTask(std:: string searchContent) {
	assert(searchContent != STRING_BLANK);

	if(E2DStorage::isMasterTaskListEmpty() && E2DStorage::isFloatingTaskListEmpty()) {
		E2DLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__, std:: to_string(__LINE__), MESSAGE_STORAGEEMPTY);
		sprintf_s(buffer, MESSAGE_STORAGEEMPTY.c_str());
		return buffer;
	} else {
		std:: string feedback;
		feedback = E2DStorage::searchContentInStorage(searchContent);
		return feedback;
	}
}