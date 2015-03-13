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

	static string userInput;
	static int taskID;
	static int totalNumberofTask;
	static string commandAction;
public:
	architectureLogic();
	enum CommandType { 
		ADD, DELETE, DISPLAY, CLEAR, INVALID, SORT, SEARCH, EXIT 
	};

	void determineUserInput(string task);
	void determineTaskID(int inputID);
	void determineTotalNumberofTask();

	void executeCommand(string commandAction);
	void addTask(string task);
	void deleteText(int taskID);
	void clearTask();
	void displayTask();

	bool isValidCommand(const string& str1, const string& str2);
	CommandType determineCommandType(string commandAction);
	
	void showToUser(string task);

};
#endif