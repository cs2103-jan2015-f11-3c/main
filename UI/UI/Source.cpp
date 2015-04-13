
#include "HEader.h"

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>


Header::Header()
{
	std::cout << "EASYTODO";

	return;
}

void Header::getKeyWords(){
	std::cout << std::endl << "command :";
	std::cin >> std::ws;
	getline(std::cin, content);

	size_t position = 0;
	position = content.find_first_of(" ");
	command = content.substr(0,position); 
	std::cout << command << std::endl;

	if(command == "add"){
		size_t taskFirst = 0;
		size_t taskLast = 0;
		taskFirst = content.find_first_of(" ");
		taskFirst = taskFirst+1;
		taskLast = content.find("on");
		taskLast = taskLast-4;
		std::string taskDesc = content.substr(taskFirst,taskLast);
		std::cout << "taskDesc is: " << taskDesc << std::endl;

		size_t timeFirst = 0;
		size_t timeLast = content.npos;
		timeFirst = content.find("on");
		timeFirst = timeFirst+3;
		std::string time = content.substr(timeFirst,timeLast);
		std::cout << "time is: " << time << std::endl;
	}




		return;
}

std:: string Header::testing(std:: string stringInput) {

	stringInput = "ok " + stringInput + " ok";

	return stringInput;
}
/*
int main(int argc, char *argv[]) 
{
	
	if (argc > 1)
	{
		Header createFile(argv);

		createFile.getKeyWords();
	}

	return 0;
}
*/