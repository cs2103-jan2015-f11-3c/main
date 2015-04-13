// @author A0111378J
#include "E2DHistory.h"
#include "E2DLogging.h"
#include "E2DStorage.h"

std:: stack<std:: string> E2DHistory::previousActionStack;
std:: stack<TASK> E2DHistory::previousStateStack;
std:: vector<TASK> E2DHistory::previousTodayUpcomingTaskList;
std:: vector<TASK> E2DHistory::previousFloatingTaskList;

const std:: string E2DHistory::COMMAND_ADD = "add";
const std:: string E2DHistory::COMMAND_SHORTCUT_ADD = "a";
const std:: string E2DHistory::COMMAND_DELETE = "delete";
const std:: string E2DHistory::COMMAND_SHORTCUT_DELETE = "del";
const std:: string E2DHistory::COMMAND_CLEAR = "clear";
const std:: string E2DHistory::COMMAND_SHORTCUT_CLEAR = "clr";
const std:: string E2DHistory::COMMAND_EXIT = "exit";
const std:: string E2DHistory::COMMAND_UNDO = "undo";
const std:: string E2DHistory::COMMAND_DONE = "done";
const std:: string E2DHistory::COMMAND_SHORTCUT_DONE = "d";
const std:: string E2DHistory::COMMAND_UPDATE = "update";
const std:: string E2DHistory::COMMAND_SHORTCUT_UPDATE = "up";

char E2DHistory::temp[MAXIMUM];

const std:: string E2DHistory::MESSAGE_ERROR = "ERROR! Invalid Command";
const std:: string E2DHistory::MESSAGE_UNDO = "Previous Action, \"%s\", has been undo";

const std:: string E2DHistory::SEVERITY_LEVEL_ERROR = "Error";

E2DHistory::E2DHistory(void) {
}


E2DHistory::~E2DHistory(void) {
}

void E2DHistory::addPreviousAction(std:: string commandAction) {
	previousActionStack.push(commandAction);
}

void E2DHistory::addPreviousState(TASK input) {
	previousStateStack.push(input);
}

bool E2DHistory::isUndoStackEmpty() {
	if(previousActionStack.empty()) {
		return true;
	} else {
		return false;
	}
}

std:: string E2DHistory::undoAction() {
	std:: string previousCommand;
	previousCommand = previousActionStack.top();
	previousActionStack.pop();
	executeUndo(previousCommand);
	sprintf_s(temp, MESSAGE_UNDO.c_str(), previousCommand.c_str());
	return temp;
}

void E2DHistory::executeUndo(std:: string previousCommand) {
	E2DHistory:: CommandType commandTypeAction = E2DHistory:: determineCommandType(previousCommand);

	switch(commandTypeAction) { 
	case ADD: 
		reverseAdd();
		break;
	case DELETE:
		reverseDelete();
		break;
	case CLEAR:
		reverseClear();
		break;
	case UPDATE:
		reverseUpdate();
	case DONE:
		reverseDone();
		break;
	case INVALID:
		E2DLogging::logToFile(SEVERITY_LEVEL_ERROR, __FILE__, std:: to_string(__LINE__), "fault in E2DHistory::executeCommand");
		break;
	case UNDO:
		E2DLogging::logToFile(SEVERITY_LEVEL_ERROR, __FILE__, std:: to_string(__LINE__), "fault in E2DHistory::executeCommand");
		break;
	case EXIT: 
		E2DLogging::logToFile(SEVERITY_LEVEL_ERROR, __FILE__, std:: to_string(__LINE__), "fault in E2DHistory::executeCommand");
		exit(0);
	}
}

E2DHistory::CommandType E2DHistory::determineCommandType(std:: string commandAction) { 
	assert(commandAction != "");

	if(isValidCommand(commandAction, COMMAND_ADD) || isValidCommand(commandAction, COMMAND_SHORTCUT_ADD)) { 
		return CommandType::ADD; 
	} else if(isValidCommand(commandAction, COMMAND_EXIT)) { 
		return CommandType::EXIT; 
	} else if(isValidCommand(commandAction, COMMAND_DELETE) || isValidCommand(commandAction, COMMAND_SHORTCUT_DELETE)) {
		return CommandType::DELETE;
	} else if(isValidCommand(commandAction, COMMAND_CLEAR) || isValidCommand(commandAction, COMMAND_SHORTCUT_CLEAR)) {
		return CommandType::CLEAR;
	} else if(isValidCommand(commandAction, COMMAND_UPDATE) || isValidCommand(commandAction, COMMAND_SHORTCUT_UPDATE)) {
		return CommandType::UPDATE;
	} else if(isValidCommand(commandAction, COMMAND_UNDO)) {
		return CommandType::UNDO;
	} else if(isValidCommand(commandAction, COMMAND_DONE) || isValidCommand(commandAction, COMMAND_SHORTCUT_DONE)) {
		return CommandType::DONE;
	} else { 
		return CommandType::INVALID;
	} 
}

bool E2DHistory::isValidCommand(const std:: string& str1, const std:: string& str2) { 
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

void E2DHistory::reverseDelete() {
	TASK previousState;
	previousState = retrievePreviousState();
	E2DStorage::undoDelete(previousState);
	return;
}

void E2DHistory::reverseAdd() {
	TASK previousState;
	previousState = retrievePreviousState();
	E2DStorage::undoAdd(previousState);
	return;
}

void E2DHistory::reverseUpdate() {
	TASK previousStateToAddBack;
	TASK previousStateToDelete;

	previousStateToDelete = retrievePreviousState();
	previousStateToAddBack = retrievePreviousState();

	E2DStorage::undoAdd(previousStateToDelete);
	E2DStorage::undoDelete(previousStateToAddBack);
	return;
}

void E2DHistory::reverseDone() {
	TASK previousState;
	previousState = retrievePreviousState();
	E2DStorage::undoDone(previousState);
	return;
}

TASK E2DHistory::retrievePreviousState() {
	TASK previousState;
	previousState = previousStateStack.top();
	previousStateStack.pop();
	return previousState;
}

void E2DHistory::reverseClear() {
	E2DStorage::undoClear(previousTodayUpcomingTaskList, previousFloatingTaskList);
	previousTodayUpcomingTaskList.clear();
	previousFloatingTaskList.clear();
	return;
}

void E2DHistory::pushPreviousTodayUpcomingTaskList(std::vector<TASK>& taskList) {
	std:: vector<TASK>::iterator iter;
	for(iter = taskList.begin(); iter != taskList.end(); iter++) {
		previousTodayUpcomingTaskList.push_back(*iter);
	}
	return;
}

void E2DHistory::pushPreviousFloatingTaskList(std::vector<TASK>& taskList) {
	std:: vector<TASK>::iterator iter;
	for(iter = taskList.begin(); iter != taskList.end(); iter++) {
		previousFloatingTaskList.push_back(*iter);
	}
	return;
}