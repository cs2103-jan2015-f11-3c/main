#include "architectureParser.h"
#include "architectureLogic.h"
#include "architectureStorage.h"

std::string Parser::_time;
std::string Parser::_taskDesc;
std::string Parser::_tokenizeContent;
std::string Parser::_newContent;


void Parser::tokenizeADD(std:: string tokenizeContent) {
	
	/*
	size_t position = 0;
	position = content.find_first_of(" ");
	command = content.substr(0,position); 
	std::cout << command << std::endl; //command is your userinput
	architectureLogic::determineUserInput(command);
	std::cout << "command is: " << command << std::endl;
	if(command == "add")
	*/

		_newContent = tokenizeContent;
		size_t taskFirst = 0;
		size_t taskLast = 0;
		taskLast = _newContent.find("on");
		taskLast = taskLast-1;
		_taskDesc = _newContent.substr(taskFirst,taskLast); //taskDesc is taskID
		architectureLogic::determineContentDescription(_taskDesc);
		
		size_t timeFirst = 0;
		size_t timeLast = _newContent.npos;
		timeFirst = _newContent.find("on");
		timeFirst = timeFirst+3;
		_time = _newContent.substr(timeFirst,timeLast);
		architectureLogic::determineContentTime(_time);

return;

}

void Parser::tokenizeUpdate(std:: string tokenizeContent) {
	// format of input: update 3 meet ivy on friday 3pm
	// 3 is taskID, "meet ivy..." into newTask, newTime)
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