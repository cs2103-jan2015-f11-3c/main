#ifndef ARCHITECTURELOGIC_H_
#define ARCHITECTURELOGIC_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

#undef DELETE

class architectureLogic {
private:
	static const std:: string MESSAGE_ADD;
	static const std:: string MESSAGE_INVALID;
	static const std:: string MESSAGE_NOTFOUND;
	static const std:: string MESSAGE_DELETE;
	static const std:: string MESSAGE_CLEARALL;
	static const std:: string MESSAGE_CLEARTODAY;
	static const std:: string MESSAGE_CLEARUPCOMING;
	static const std:: string MESSAGE_UPDATE;
	static const std:: string MESSAGE_STORAGEEMPTY;
	static const std:: string MESSAGE_TODAY;
	static const std:: string MESSAGE_UPCOMING;
	static const std:: string MESSAGE_ALL;

	static std:: string _command;
	static std:: string _content;
	static std:: string _contentDescription;
	static std:: string _contentStartTime;
	static std:: string _contentEndTime;
	static std:: string _contentDate;
	static std:: string _newTask;
	static std:: string _newTime;
	static std:: string _taskID;

	static const int MAX = 255;
	static char buffer[MAX];
	

public:
	architectureLogic();
	enum CommandType { 
		ADD, EXIT, DELETE, INVALID, CLEAR, UPDATE,
	};
	std:: string determineCommand(std:: string content);
	std:: string addTask(std:: string task, std:: string date, std:: string startTime, std:: string endTime);
	std:: string deleteTask(std:: string input);
	std:: string executeCommand(std:: string commandAction);
	std:: string clearTask(std:: string content);
	std:: string updateTask(std:: string taskID, std:: string newTask, std:: string newDate, std:: string newStartTime, std:: string newEndTime) ;
	static void determineContentDescription(std:: string parserInput);
	static void determineContentStartTime(std:: string parserInput);
	static void determineContentEndTime(std:: string parserInput);
	static void determineContentDate(std:: string parserInput);
	static void determineTaskID(std:: string parserInput);
	CommandType determineCommandType(std:: string commandAction);
	bool isValidCommand(const std:: string& str1, const std:: string& str2);
	bool isTaskIDValid(int taskID);
	bool isStorageEmpty();
	int stringToInteger(std:: string input);
	bool isUndoValid();

};
#endif