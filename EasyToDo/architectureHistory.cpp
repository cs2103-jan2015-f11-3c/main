#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureParser.h"
#include "architectureHistory.h"

std:: stack<std:: string> architectureHistory::previousActionStack;
std:: stack<TASK> architectureHistory::previousStateStack;
std:: vector<TASK> architectureHistory::previousTodayUpcomingTaskList;
std:: vector<TASK> architectureHistory::previousFloatingTaskList;

char architectureHistory::temp[MAXIMUM];

const std:: string architectureHistory::MESSAGE_ERROR = "ERROR! Invalid Command";
const std:: string architectureHistory::MESSAGE_UNDO = "Previous Action, \"%s\", has been undo";

architectureHistory::architectureHistory() {
}

void architectureHistory::addPreviousAction(std:: string commandAction) {
	previousActionStack.push(commandAction);
}

void architectureHistory::addPreviousState(TASK input) {
	previousStateStack.push(input);
}

bool architectureHistory::isUndoStackEmpty() {
	if(previousActionStack.empty()) {
		return true;
	} else {
		return false;
	}
}

std:: string architectureHistory::undoAction() {
	std:: string previousCommand;
	previousCommand = previousActionStack.top();
	previousActionStack.pop();
	executeUndo(previousCommand);
	sprintf_s(temp, MESSAGE_UNDO.c_str(), previousCommand.c_str());
	return temp;
}

void architectureHistory::executeUndo(std:: string previousCommand) {
	architectureHistory:: CommandType commandTypeAction = architectureHistory:: determineCommandType(previousCommand);

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
		break;
	case UNDO:
		break;
	case EXIT: 
		exit(0);
	}
}

architectureHistory::CommandType architectureHistory::determineCommandType(std:: string commandAction) { 
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
	} else if(isValidCommand(commandAction, "done")) {
		return CommandType::DONE;
	} else { 
		return CommandType::INVALID;
	} 
}

bool architectureHistory::isValidCommand(const std:: string& str1, const std:: string& str2) { 
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

void architectureHistory::reverseDelete() {
	TASK previousState;
	previousState = retrievePreviousState();
	architectureStorage::undoDelete(previousState);
	return;
}

void architectureHistory::reverseAdd() {
	TASK previousState;
	previousState = retrievePreviousState();
	architectureStorage::undoAdd(previousState);
	return;
}

void architectureHistory::reverseUpdate() {
	TASK previousStateToAddBack;
	TASK previousStateToDelete;

	previousStateToDelete = retrievePreviousState();
	previousStateToAddBack = retrievePreviousState();

	architectureStorage::undoAdd(previousStateToDelete);
	architectureStorage::undoDelete(previousStateToAddBack);
	return;
}

void architectureHistory::reverseDone() {
	TASK previousState;
	previousState = retrievePreviousState();
	architectureStorage::undoDone(previousState);
	return;
}

TASK architectureHistory::retrievePreviousState() {
	TASK previousState;
	previousState = previousStateStack.top();
	previousStateStack.pop();
	return previousState;
}

void architectureHistory::reverseClear() {
	architectureStorage::undoClear(previousTodayUpcomingTaskList, previousFloatingTaskList);
	previousTodayUpcomingTaskList.clear();
	previousFloatingTaskList.clear();
	return;
}

void architectureHistory::pushPreviousTodayUpcomingTaskList(std::vector<TASK>& taskList) {
	std:: vector<TASK>::iterator iter;
	for(iter = taskList.begin(); iter != taskList.end(); iter++) {
		previousTodayUpcomingTaskList.push_back(*iter);
	}
	return;
}

void architectureHistory::pushPreviousFloatingTaskList(std::vector<TASK>& taskList) {
	std:: vector<TASK>::iterator iter;
	for(iter = taskList.begin(); iter != taskList.end(); iter++) {
		previousFloatingTaskList.push_back(*iter);
	}
	return;
}