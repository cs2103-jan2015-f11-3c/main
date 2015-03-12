#ifndef PARSER_H
#define PARSER_H

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
		static std::string time;
		static std::string taskDesc; 
		static std::string tokenizeContent;
		static std::string newContent;

	public:
		static void tokenizeADD(std::string tokenizeContent);
	
};
#endif