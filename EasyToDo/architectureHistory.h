#ifndef ARCHITECTUREHISTORY_H_
#define ARCHITECTUREHISTORY_H_

#include <stack>
#include <sstream>
#include <vector>

#include "architectureLogic.h"

// this class allows the users to undo the previous functions that he executed. this function can be executed infinitely
// this function is extended to add, update, delete, clear, done
// it does not support save, filter, search as the reverse action would be display.
// this mechanism uses the idea of two stacks to store the previousAction and the previousState
// after every valid action that is supported by undo, it will be pushed into the previousState
// the previous task of action will be stored
// the only unique case will be clear where the updating state and the new state is stored
class architectureHistory {
private:
	static std:: stack<std:: string> previousActionStack;
	static std:: stack<TASK> previousStateStack;
	static const int MAXIMUM = 255;
	static char temp[MAXIMUM];
	static std:: vector<TASK> previousTodayUpcomingTaskList;
	static std:: vector<TASK> previousFloatingTaskList;
	
	static const std:: string MESSAGE_ERROR;
	static const std:: string MESSAGE_UNDO;
	static const std:: string SEVERITY_LEVEL_ERROR;
public:
	architectureHistory();
	enum CommandType { 
		ADD, EXIT, DELETE, INVALID, CLEAR, UPDATE, UNDO, DONE
	};

	// this function allow architectureLogic::executeCommand to store the previousAction
	// Pre: add, delete, update, clear, done
	// Post: store the string command in a stack
	static void addPreviousAction(std:: string commandAction);
	// similarly, this function store the state. However, this function is called from the architectureStorage when the command is being executed
	// Pre: same
	// Post: previous intended task is stored in a stack
	static void addPreviousState(TASK input);
	static bool isUndoStackEmpty();
	
	// this group of function basically execute the action retrieve on the top of stack.
	// undoAction retrieve the top of the stack
	// executeUndo does the thinking to execute whichever command
	// the followings are the supporting function
	// Pre: stack not empty
	// Post: return a feedback string and execute the command
	static std:: string undoAction();
	static void executeUndo(std:: string previousCommand);
	static CommandType architectureHistory::determineCommandType(std:: string commandAction);
	static bool isValidCommand(const std:: string& str1, const std:: string& str2);
	
	// this are the functions that undo support
	static void reverseDelete();
	static void reverseAdd();
	static void reverseUpdate();
	static void reverseDone();
	static TASK retrievePreviousState();

	// this function allow the user to undo the previous clear all/today/all/misc
	// the supporting functions allow the storage to push the temp taskList to be stored in History to undo the clear function
	// Pre: none
	// Post: reverse the clear action
	static void reverseClear();
	static void pushPreviousTodayUpcomingTaskList(std:: vector<TASK>& masterTaskList);
	static void pushPreviousFloatingTaskList(std:: vector<TASK>& masterTaskList);
};

#endif