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


void Parser::tokenizeADD(std:: string tokenizeContent) {
	
		
		_newContent = tokenizeContent;
		size_t taskFirst = 0;
		size_t taskLast = _newContent.find("on");
		
		if(taskLast!=std::string::npos){

		taskLast = taskLast-1;
		_taskDesc = _newContent.substr(taskFirst,taskLast); //taskDesc is taskID
		architectureLogic::determineContentDescription(_taskDesc);
		
		size_t timeFirst = _taskDesc.find_first_of(" ");
		size_t timeLast = _taskDesc.find_last_of(" ");
		_date = _newContent.substr(timeFirst,timeLast);
		architectureLogic::determineContentDate(_date);

		taskFirst =  _taskDesc.find_last_of(" ");
		taskLast = _taskDesc.npos;
		_startTime = _taskDesc.substr(timeFirst,timeLast);
		architectureLogic::determineContentStartTime(_startTime);

		_endTime = "";
		architectureLogic::determineContentEndTime(_endTime);
		


		}

		taskLast = _newContent.find("by");
		
		if(taskLast!=std::string::npos){

		taskLast = taskLast-1;
		_taskDesc = _newContent.substr(taskFirst,taskLast); //taskDesc is taskID
		architectureLogic::determineContentDescription(_taskDesc);
		
		size_t timeFirst = _taskDesc.find_first_of(" ");
		size_t timeLast = _taskDesc.find_last_of(" ");
		_date = _newContent.substr(timeFirst,timeLast);
		architectureLogic::determineContentDate(_date);

		taskFirst =  _taskDesc.find_last_of(" ");
		taskLast = _taskDesc.npos;
		_startTime = _taskDesc.substr(timeFirst,timeLast);
		architectureLogic::determineContentStartTime(_startTime);

		_endTime = "";
		architectureLogic::determineContentEndTime(_endTime);
		

		}

		taskLast = _newContent.find("from");
		if(taskLast!=std::string::npos){
		
		taskLast = taskLast-1;
		_taskDesc = _newContent.substr(taskFirst,taskLast); //taskDesc is taskID
		architectureLogic::determineContentDescription(_taskDesc);
		
		size_t timeFirst = _taskDesc.find_first_of(" ");
		size_t timeLast = _taskDesc.find_last_of(" ");
		_date = _newContent.substr(timeFirst,timeLast);
	    architectureLogic::determineContentDate(_date);

		taskFirst = taskLast+1;
		taskLast = _taskDesc.npos;
		_newContent = _taskDesc.substr(taskFirst,taskLast);
		taskFirst = _taskDesc.find_first_of(" ");
		taskLast = _taskDesc.find_first_of("-");
		_startTime = _taskDesc.substr(timeFirst,timeLast);
		architectureLogic::determineContentStartTime(_startTime);

		timeFirst = _taskDesc.find_first_of("-");
		timeLast = _taskDesc.npos;
		_endTime = _taskDesc.substr(taskFirst,taskLast);
		architectureLogic::determineContentEndTime(_endTime);
		}
		else
		{
			taskLast = _newContent.npos;
			_taskDesc = _newContent.substr(taskFirst,taskLast); //taskDesc is taskID
			architectureLogic::determineContentDescription(_taskDesc);
			_date = "";
			architectureLogic::determineContentDate(_date);
			_startTime = "";
			architectureLogic::determineContentStartTime(_startTime);
			_endTime = "";
			architectureLogic::determineContentEndTime(_endTime);
		}

		


		


return;

}

void Parser::tokenizeUPDATE(std::string tokenizeContent) {
		
		_newContent = tokenizeContent;
		size_t taskFirst = 0;
		size_t taskLast = _newContent.find_first_of(" ");
		_taskID = _newContent.substr(taskFirst,taskLast);
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