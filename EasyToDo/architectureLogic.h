#ifndef ARCHITECTURELOGIC_H_
#define ARCHITECTURELOGIC_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#undef DELETE

class architectureLogic {
private:
	static const std:: string MESSAGE_ADD;
	static const std:: string MESSAGE_INVALID;
	static const std:: string MESSAGE_NOTFOUND;
	static const std:: string MESSAGE_DELETE;

	static std:: string _command;
	static std:: string _content;
	static std:: string _contentDescription;
	static std:: string _contentTime;

	static const int MAX = 255;
	static char buffer[MAX];

public:
	architectureLogic();
	enum CommandType { 
		ADD, EXIT, DELETE, INVALID
	};
	std:: string determineCommand(std:: string content);
	std:: string addTask(std:: string task, std:: string time);
	std:: string deleteTask(std:: string input);
	std:: string executeCommand(std:: string commandAction);
	static void determineContentDescription(std:: string parserInput);
	static void determineContentTime(std:: string parserInput);
	CommandType determineCommandType(std:: string commandAction);
	bool isValidCommand(const std:: string& str1, const std:: string& str2);
	bool isTaskIDValid(int taskID);

};
#endif