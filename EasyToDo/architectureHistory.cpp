#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureParser.h"
#include "architectureHistory.h"

std:: stack<std:: string> previousActionStack;
std:: stack<TASK> previousStateStack;
std:: vector<TASK> previousTaskList;
char architectureHistory::temp[MAXIMUM];

const std:: string architectureHistory::MESSAGE_ERROR = "ERROR! Invalid Command";
const std:: string architectureHistory::MESSAGE_UNDO = "Previous Action, \"%s\", has been undo";

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
	architectureLogic:: CommandType commandTypeAction = architectureLogic:: determineCommandType(previousCommand);

	switch(commandTypeAction) { 
	case architectureLogic:: ADD: 
		reverseAdd();
		break;
	case architectureLogic:: DELETE:
		reverseDelete();
		break;
	case architectureLogic:: CLEAR:
		reverseClear();
		break;
	case architectureLogic:: UPDATE:
		reverseUpdate();
		break;
	case architectureLogic:: INVALID:
		break;
	case architectureLogic:: UNDO:
		break;
	case architectureLogic:: EXIT: 
		exit(0);
	}
}
TASK architectureHistory::retrievePreviousState() {
	TASK previousState;
	previousState = previousStateStack.top();
	previousStateStack.pop();
	return previousState;
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

void architectureHistory::retrievePreviousTaskList(std::vector<TASK>& masterTaskList) {
	previousTaskList = masterTaskList;
	return;
}

void architectureHistory::reverseClear() {
	architectureStorage::undoClear(previousTaskList);
	return;
}