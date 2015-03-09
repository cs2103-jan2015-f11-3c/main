#ifndef ARCHITECTURELOGIC_H_
#define ARCHITECTURELOGIC_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class architectureLogic {
private:
	static const string MESSAGE_ERROR;
	static const string MESSAGE_INVALID;
	static const int MAX = 255; 
	static char buffer[MAX];
public:
	architectureLogic();
	enum CommandType { 
		ADD, DELETE, DISPLAY, CLEAR, INVALID, SORT, SEARCH, EXIT 
	};

	void addTask(string task);
	void deleteText(int taskID);
	void clearTask();
	void displayTask();
	void executeCommand(string commandAction);
	bool isValidCommand(const string& str1, const string& str2);
	CommandType determineCommandType(string commandAction);
	
	void showToUser(string task);

};
#endif