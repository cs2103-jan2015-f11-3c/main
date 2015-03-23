#include "architectureParser.h"
#include "architectureLogic.h"
#include "architectureStorage.h"

std::string Parser::_startTime;
std::string Parser::_endTime;
std::string Parser::_date;
std::string Parser::_taskDesc;
std::string Parser::_tokenizeContent;
std::string Parser::_newContent;
std::string Parser::_taskID;
std::string lower;
Parser::Parser(char *argv[])
{
	std::cout << "EASYTODO ";


	return;
}

void Parser::tokenizeADD(std:: string tokenizeContent) {
	
		
		_newContent = tokenizeContent;
	
		size_t taskFirst = 0;
		size_t taskLast = _newContent.find("on");
		
		if(taskLast!=std::string::npos){

		taskLast = taskLast-1;
		_taskDesc = _newContent.substr(taskFirst,taskLast);
		std::cout << "task: "<<_taskDesc << std::endl;
		//architectureLogic::determineContentDescription(_taskDesc);
		
		taskFirst = taskLast+4;
		taskLast = _newContent.npos;
		std::string dateTimeContent = _newContent.substr(taskFirst,taskLast);
		std::cout <<dateTimeContent<<std::endl;
		taskFirst = 0;
		taskLast = dateTimeContent.find_first_of(" ");
		_date = dateTimeContent.substr(taskFirst,taskLast);
		std::cout << "date: "<<_date << std::endl;
		//architectureLogic::determineContentDate(_date);

		taskFirst =  _newContent.find_last_of(" ");
		taskFirst = taskFirst + 1;
		taskLast = _newContent.npos;
		_startTime = _newContent.substr(taskFirst,taskLast);
		std::cout << "startTime: "<<_startTime << std::endl;
		//architectureLogic::determineContentStartTime(_startTime);

		_endTime = "";
		//architectureLogic::determineContentEndTime(_endTime);
		


		}

		taskLast = _newContent.find("by");
		
		if(taskLast!=std::string::npos){

		taskLast = taskLast-1;
		_taskDesc = _newContent.substr(taskFirst,taskLast);
		std::cout << "task: "<<_taskDesc << std::endl;
		//architectureLogic::determineContentDescription(_taskDesc);
		
		taskFirst = taskLast+4;
		taskLast = _newContent.npos;
		std::string dateTimeContent = _newContent.substr(taskFirst,taskLast);
		std::cout <<dateTimeContent<<std::endl;
		taskFirst = 0;
		taskLast = dateTimeContent.find_first_of(" ");
		_date = dateTimeContent.substr(taskFirst,taskLast);
		std::cout << "date: "<<_date << std::endl;
		//architectureLogic::determineContentDate(_date);

		taskFirst =  _newContent.find_last_of(" ");
		taskFirst = taskFirst + 1;
		taskLast = _newContent.npos;
		_startTime = _newContent.substr(taskFirst,taskLast);
		std::cout << "startTime: "<<_startTime << std::endl;
		//architectureLogic::determineContentStartTime(_startTime);

		_endTime = "";
		//architectureLogic::determineContentEndTime(_endTime);
		

		}

		taskLast = _newContent.find("from");
		if(taskLast!=std::string::npos){
		
		taskLast = taskLast-1;
		_taskDesc = _newContent.substr(taskFirst,taskLast);
		std::cout << "task: "<<_taskDesc << std::endl;
		//architectureLogic::determineContentDescription(_taskDesc);
		
		taskFirst = taskLast+6;
		taskLast = _newContent.npos;
		std::string dateTimeContent = _newContent.substr(taskFirst,taskLast);
		std::cout <<dateTimeContent<<std::endl;
		taskFirst = 0;
		taskLast = dateTimeContent.find_first_of(" ");
		_date = dateTimeContent.substr(taskFirst,taskLast);
		std::cout << "date: "<<_date << std::endl;
		//architectureLogic::determineContentDate(_date);

		taskFirst = taskLast+1;
		taskLast = dateTimeContent.npos;
		std::string timeContent = dateTimeContent.substr(taskFirst,taskLast);
		taskFirst = 0;
		taskLast = timeContent.find_first_of("-");
		_startTime = timeContent.substr(taskFirst,taskLast);
		std::cout << "startTime: "<<_startTime << std::endl;
		//architectureLogic::determineContentStartTime(_startTime);

		taskFirst = _newContent.find_last_of("-");
		taskFirst = taskFirst+1;
		taskLast = _newContent.npos;
		_endTime = _newContent.substr(taskFirst,taskLast);
		std::cout << "endTime: "<<_endTime << std::endl;
		//architectureLogic::determineContentEndTime(_endTime);
		}
		else
		{
			taskLast = _newContent.npos;
			_taskDesc = _newContent.substr(taskFirst,taskLast); //taskDesc is taskID
			//architectureLogic::determineContentDescription(_taskDesc);
			_date = "";
			//architectureLogic::determineContentDate(_date);
			_startTime = "";
			//architectureLogic::determineContentStartTime(_startTime);
			_endTime = "";
			//architectureLogic::determineContentEndTime(_endTime);
		}

		


		


return;

}

void Parser::tokenizeUPDATE(std::string tokenizeContent) {
		
		_newContent = tokenizeContent;
		size_t taskFirst = _newContent.find_first_not_of(" ");
		size_t taskLast = _newContent.find_first_of(" ");
		_taskID = _newContent.substr(taskFirst,taskLast);
		std::cout << _taskID << std::endl;
		taskFirst = taskLast+1;
		taskLast = _newContent.npos;
		std::string updateContent = _newContent.substr(taskFirst,taskLast);
		tokenizeADD(updateContent);
		
}



/*
void Parser::tokenizeDELETE(std::string tokenizeContent){

	tokenizeSingleWord(tokenizeContent);
}


void Parser::tokenizeSEARCH(std::string tokenizeContent){

	tokenizeSingleWord(tokenizeContent);	
}

void Parser::tokenizeSingleWord(std::string tokenizeContent){

		_newContent = tokenizeContent;
		size_t taskFirst = 0;
		size_t taskLast = _newContent.npos;
		_taskDesc = _newContent.substr(taskFirst,taskLast);
		architectureLogic::determineContentDescription(_taskDesc);
	
}

*/
int main(int argc, char *argv[]) 
{
	
	if (argc > 1)
	{
		Parser createFile(argv);
		std::string content;
		std::cin >> std::ws;
		getline(std::cin, content);
		createFile.tokenizeUPDATE(content);
	}

	return 0;
}