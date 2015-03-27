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


	public:
		static void tokenizeADD(std::string tokenizeContent);
		static void tokenizeCLEAR(std::string tokenizeContent);
		static void tokenizeDELETE(std::string tokenizeContent);
		static void tokenizeSEARCH(std::string tokenizeContent);
		static void tokenizeSingleWord(std::string tokenizeContent);
		static void tokenizeUPDATE(std::string tokenizeContent);
		static void tokenizeDayOfTheWeek(std::string tokenizeContent);
		static void tokenizeDateDay(std::string tokenizeContent);
		static void tokenizeDateMonth(std::string tokenizeContent);
		static void tokenizeTime(std::string tokenizeContent);
		static std::string Parser::getContent();
};
#endif