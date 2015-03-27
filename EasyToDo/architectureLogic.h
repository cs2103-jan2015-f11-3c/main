#ifndef ARCHITECTURELOGIC_H_
#define ARCHITECTURELOGIC_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <boost/algorithm/string.hpp>

#undef DELETE

class architectureLogic {
private:
	static const std:: string MESSAGE_ADD;
	static const std:: string MESSAGE_INVALID;
	static const std:: string MESSAGE_NOTFOUND;
	static const std:: string MESSAGE_DELETETODAY;
	static const std:: string MESSAGE_DELETEUPCOMING;
	static const std:: string MESSAGE_DELETEFLOATING;
	static const std:: string MESSAGE_CLEARALL;
	static const std:: string MESSAGE_CLEARTODAY;
	static const std:: string MESSAGE_CLEARUPCOMING;
	static const std:: string MESSAGE_CLEARFLOATING;
	static const std:: string MESSAGE_UPDATETODAY;
	static const std:: string MESSAGE_UPDATEUPCOMING;
	static const std:: string MESSAGE_UPDATEFLOATING;
	static const std:: string MESSAGE_STORAGEEMPTY;
	static const std:: string MESSAGE_TODAY;
	static const std:: string MESSAGE_UPCOMING;
	static const std:: string MESSAGE_FLOATING;
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
	static std:: string _taskType;

	static const int MAX = 255;
	static char buffer[MAX];
	
public:
	class architectureFeedbackHistory {
	private:
		static std:: vector<std:: string> masterFeedbackList;
	public:
		architectureFeedbackHistory();
		static void addToFeedbackList(std:: string feedback);
		static std:: vector<std:: string>retrieveFeedbackList();
	};
	architectureLogic();
	enum CommandType { 
		ADD, EXIT, DELETE, INVALID, CLEAR, UPDATE, UNDO
	};
	enum Months { 
		JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, NOTVALID
	};

	enum DateType {
		TODAY, UPCOMING, MISC
	};

	static std:: vector<std:: string> determineCommand(std:: string content);
	static std:: string addTask(std:: string _contentDescription, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes);
	static std:: string deleteTask(std:: string taskType, std:: string taskID);
	static std:: string executeCommand(std:: string commandAction);
	static std:: string clearTask(std:: string content);
	static std:: string updateTask(std:: string taskType, std:: string taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes);
	static std:: string undoTask();
	static void determineContentDescription(std:: string parserInput);
	static void determineContentDay(std:: string parserInput);
	static Months architectureLogic::determineMonthType(std:: string parserInput);
	static void determineContentMonth(std:: string parserInput);
	static void determineContentStartHours(std:: string parserInput);
	static void determineContentStartMinutes(std:: string parserInput);
	static void determineContentEndHours(std:: string parserInput);
	static void determineContentEndMinutes(std:: string parserInput);
	static std:: string trimTrailingSpaces(std:: string buffer);
	static void determineTaskID(std:: string parserInput);
	static void determineTaskType(std:: string parserInput);
	static CommandType determineCommandType(std:: string commandAction);
	static DateType determineDateTypeAction(std:: string commandAction);
	static bool isValidCommand(const std:: string& str1, const std:: string& str2);
	static bool isTodayTaskIDValid(int taskID);
	static bool isUpcomingTaskIDValid(int taskID);
	static bool isFloatingTaskIDValid(int taskID);
	static bool isMasterTaskListEmpty();
	static bool isTodayTaskListEmpty();
	static bool isUpcomingTaskListEmpty();
	static bool isFloatingTaskListEmpty();
	static int stringToInteger(std:: string input);
	// static void tokenizeDELETE(std::string tokenizeContent);
};
#endif