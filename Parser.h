
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

class Parser {
	private:
		//string that that will store all the command information
		std::string content;
		//this string contains all the different command add, delete... etc
		std::string command;
		std::string time;
		std::string taskDesc; 






	public:
		Parser(char *[]);
		//function makes you type in your command
		void getCommand();
		//function gets the keywords from the content and stores into array
		void getKeyWords();

		void testing(std:: string stringInput);






};




#endif