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
	static string command;
	static string content;
	static string contentDescription;
	static string contentTime;

public:
	architectureLogic();
	enum CommandType { 
		ADD, DELETE, DISPLAY, CLEAR, INVALID, SORT, SEARCH, EXIT 
	};

	static void determineUserInput(string task);
	static void determineTaskID(int inputID);
	void determineTotalNumberofTask();
<<<<<<< HEAD

	void executeCommand(string commandAction);
	void addTask(string task);
=======
	void addTask(string task, string time);
>>>>>>> ad1f7da12bad6f08108b61ddb5c3ff170a653f29
	void deleteText(int taskID);
	void determineCommand(string content);
	void clearTask();
	void displayTask();

	bool isValidCommand(const string& str1, const string& str2);
	CommandType determineCommandType(string commandAction);

	void showToUser(string task);
	static void determineContentDescription(string parserInput);
	static void determineContentTime(string parserInput);

};
#endif