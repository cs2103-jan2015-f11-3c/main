#ifndef ARCHITECTURELOGIC_H_
#define ARCHITECTURELOGIC_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>
#include <stdexcept>

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
	static const std:: string MESSAGE_UNDOINVALID;
	static const std:: string MESSAGE_UNDO;

	static std:: string _command;
	static std:: string _content;
	static std:: string _contentDescription;
	static std:: string _contentDay;
	static std:: string _contentMonth;
	static std:: string _contentStartHours;
	static std:: string _contentStartMinutes;
	static std:: string _contentEndHours;
	static std:: string _contentEndMinutes;
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
	std:: string addTask(std:: string _contentDescription, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes);
	std:: string deleteTask(std:: string input);
	std:: string executeCommand(std:: string commandAction);
	std:: string clearTask(std:: string content);
	std:: string updateTask(std:: string taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes);
	std:: string undoTask();
	static void determineContentDescription(std:: string parserInput);
	static void determineContentDay(std:: string parserInput);
	static void determineContentMonth(std:: string parserInput);
	static void determineContentStartHours(std:: string parserInput);
	static void determineContentStartMinutes(std:: string parserInput);
	static void determineContentEndHours(std:: string parserInput);
	static void determineContentEndMinutes(std:: string parserInput);
	std:: string trimTrailingSpaces(std:: string buffer);
	static void determineTaskID(std:: string parserInput);
	CommandType determineCommandType(std:: string commandAction);
	bool isValidCommand(const std:: string& str1, const std:: string& str2);
	bool isTaskIDValid(int taskID);
	bool isStorageEmpty();
	int stringToInteger(std:: string input);
	// bool isUndoValid();

};
#endif