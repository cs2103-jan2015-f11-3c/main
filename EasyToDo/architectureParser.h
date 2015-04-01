#ifndef ARCHITECTUREPARSER_H
#define ARCHITECTUREPARSER_H

#include <iostream>
#include <sstream>
#include <string>
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
		static int output;


	public:
		static std::vector<std::string> addTaskDetails;
		static bool tokenizeCOMMAND(std::string tokenizeContent);
		static bool tokenizeADD(std::string tokenizeContent);
		static bool tokenizeCLEAR(std::string tokenizeContent);
		static bool tokenizeDELETE(std::string tokenizeContent);
		static bool tokenizeDONE(std::string tokenizeContent);
		static bool tokenizeUNDO(std::string tokenizeContent);
		static bool tokenizeUPDATE(std::string tokenizeContent);
		static bool isDateDayValid(std::string tokenizeContent);
		static bool isDateMonthValid(std::string tokenizeContent);
		static bool tokenizeTime(std::string tokenizeContent);
		static bool isTimedValid(std::string tokenizeContent);
		static bool isDeadlineVaild(std::string tokenizeContent);
		static int stringToInt(std::string input);
		static bool isCommandValid(std::string input);
		static bool isDayValid(std::string input);
		static bool isHourTimeValid(std::string input);
		static bool isMinTimeValid(std::string input);
		static void tokenizeADDEmptyFirst(std::string tokenizeContent);
		static bool Parser::isRunningTimeValid(std::string inputStart,std::string inputEnd);
};
#endif