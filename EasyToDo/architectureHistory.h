#ifndef ARCHITECTUREHISTORY_H_
#define ARCHITECTUREHISTORY_H_

#include <stack>
#include <sstream>
#include <vector>

#include "architectureLogic.h"


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
public:
	architectureHistory();
	enum CommandType { 
		ADD, EXIT, DELETE, INVALID, CLEAR, UPDATE, UNDO, DONE
	};
	static CommandType architectureHistory::determineCommandType(std:: string commandAction);
	static bool isValidCommand(const std:: string& str1, const std:: string& str2);
	static void addPreviousAction(std:: string commandAction);
	static void addPreviousState(TASK input);
	static bool isUndoStackEmpty();
	static std:: string undoAction();
	static void executeUndo(std:: string previousCommand);
	static void reverseDelete();
	static void reverseAdd();
	static void reverseUpdate();
	static void reverseClear();
	static void reverseDone();
	static void pushPreviousTodayUpcomingTaskList(std:: vector<TASK>& masterTaskList);
	static void pushPreviousFloatingTaskList(std:: vector<TASK>& masterTaskList);
	static TASK retrievePreviousState();

	
};

#endif