#ifndef ARCHITECTUREHISTORY_H_
#define ARCHITECTUREHISTORY_H_
#include <stack>
#include <sstream>
#include <vector>


class architectureHistory {
private:
	static std:: stack<std:: string> previousActionStack;
	static std:: stack<TASK> previousStateStack;
	static const int MAXIMUM = 255;
	static char temp[MAXIMUM];
	static std:: vector<TASK> previousTaskList;
	static const std:: string MESSAGE_ERROR;
	static const std:: string MESSAGE_UNDO;
public:
	static void addPreviousAction(std:: string commandAction);
	static void addPreviousState(TASK input);
	static bool isUndoStackEmpty();
	static std:: string undoAction();
	static void executeUndo(std:: string previousCommand);
	static void reverseDelete();
	static void reverseAdd();
	static void reverseUpdate();
	static void reverseClear();
	static void retrievePreviousTaskList(std:: vector<TASK>& masterTaskList);

	static TASK retrievePreviousState();

	
};

#endif