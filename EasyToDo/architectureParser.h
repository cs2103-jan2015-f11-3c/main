#ifndef ARCHITECTUREPARSER_H
#define ARCHITECTUREPARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>

class Parser {
	private:
		//string that that will store all the command information
		//this string contains all the different command add, delete... etc
		static std::string _time;
		static std::string _taskDesc;
		static std::string _taskType;
		static std::string _tokenizeContent;
		static std::string _newContent;
		static std::string _startHour;
		static std::string _startMin;
		static std::string _endHour;
        static std::string _endMin;
        static std::string _dayOfTheWeek;
		static std::string _dateDay;
		static std::string _dateMonth;
		static std::string _taskID;
		static std::string _delContent;
		static std::string _command;
		static std::string _userInput;


	public:
		static std::vector<std::string> addTaskDetails;
		static void pushUserInput(std::string userInput);
		static void tokenizeCOMMAND();
		static void checkCommand(std::string _command, std::string tokenizeContent);
		static void tokenizeADD(std::string tokenizeContent);
		static void tokenizeCLEAR(std::string tokenizeContent);
		static void tokenizeDELETE(std::string tokenizeContent);
		static void tokenizeDONE(std::string tokenizeContent);
		static void tokenizeUNDO(std::string tokenizeContent);
		static void tokenizeUPDATE(std::string tokenizeContent);
		static void tokenizeDateDay(std::string tokenizeContent);
		static void tokenizeDateMonth(std::string tokenizeContent);
		static void tokenizeTime(std::string tokenizeContent);
		static void tokenizeTimedTime(std::string tokenizeContent);
		static void tokenizeDeadlineTime(std::string tokenizeContent);
		static void tokenizeDeadlineTask(std::string toknizeContent,size_t taskLast);
		static void tokenizeTimedTask(std::string toknizeContent, size_t taskLast);
		static void addEmptyString(int count);
		static void tokenizeINVALID();
		// static int stringToInt(std::string input);
		// static bool isCommandValid(std::string input);
		// static bool isDayValid(std::string input);
		// static bool isHourTimeValid(std::string input);
		// static bool isMinTimeValid(std::string input);
		static void tokenizeADDEmptyFirst(std::string tokenizeContent);
		// static bool Parser::isRunningTimeValid(std::string inputStart,std::string inputEnd);
};
#endif