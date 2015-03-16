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
		static std::string _tokenizeContent;
		static std::string _newContent;


	public:
		static void tokenizeADD(std::string tokenizeContent);
		static void tokenizeCLEAR(std::string tokenizeContent);
	
};
#endif