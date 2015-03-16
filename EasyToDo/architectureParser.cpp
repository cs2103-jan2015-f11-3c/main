#include "architectureParser.h"
#include "architectureLogic.h"
#include "architectureStorage.h"

std::string Parser::taskDesc;
std::string Parser::tokenizeContent;
std::string Parser::newContent;
/*
Parser::Parser(char *argv[])
{
	std::cout << "EASYTODO ";

	return;
}
*/

void Parser::tokenizeADD(string tokenizeContent) {
	/*
	size_t position = 0;
	position = content.find_first_of(" ");
	command = content.substr(0,position); 
	std::cout << command << std::endl; //command is your userinput
	architectureLogic::determineUserInput(command);
	std::cout << "command is: " << command << std::endl;
	if(command == "add")
	*/

		newContent = tokenizeContent;
		size_t taskFirst = 0;
		size_t taskLast = 0;
		taskFirst = newContent.find_first_of(" ");
		taskFirst = taskFirst+1;
		taskLast = newContent.find("on");
		taskLast = taskLast-4;
		taskDesc = newContent.substr(taskFirst,taskLast); //taskDesc is taskID
		architectureLogic::determineContentDescription(taskDesc);
		
		size_t timeFirst = 0;
		size_t timeLast = newContent.npos;
		timeFirst = newContent.find("on");
		timeFirst = timeFirst+3;
		time = newContent.substr(timeFirst,timeLast);
		architectureLogic::determineContentTime(time);

return;

}
/*	if(command == "delete"){
void Parser::tokenizeDELETE(string tokenizeContent)

		size_t taskFirst = position;
		size_t taskLast = content.npos;
		std::string temptaskDesc = content.substr(taskFirst,taskLast);
		taskFirst = temptaskDesc.find_first_not_of(" ");
		taskLast = temptaskDesc.npos;
		taskDesc = temptaskDesc.substr(taskFirst,taskLast);
		std::cout << "taskDesc is: "<< taskDesc << std::endl;
	
	}


	if(command == "search"){
	
		size_t taskFirst = position;
		size_t taskLast = content.npos;
		std::string temptaskDesc = content.substr(taskFirst,taskLast);
		taskFirst = temptaskDesc.find_first_not_of(" ");
		taskLast = temptaskDesc.npos;
		taskDesc = temptaskDesc.substr(taskFirst,taskLast);
		std::cout << "taskDesc is: "<< taskDesc << std::endl;
	
	}


		return;
}

int main(int argc, char *argv[]) 
{
	
	if (argc > 1)
	{
		Parser createFile(argv);

		createFile.getKeyWords();
	}

	return 0;
} */