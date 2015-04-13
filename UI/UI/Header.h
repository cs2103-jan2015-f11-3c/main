
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>


class Header {
	private:
		//string that that will store all the command information
		 std::string content;
		//this string contains all the different command add, delete... etc
		 std::string command;






	public:
		Header();
		//function makes you type in your command
		void getCommand();
		//function gets the keywords from the content and stores into array
		void getKeyWords();
		std:: string testing(std:: string stringInput);






};




#endif