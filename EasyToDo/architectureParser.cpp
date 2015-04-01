#include "architectureParser.h"
#include "architectureLogic.h"
#include "architectureStorage.h"


std::string Parser::_startHour;
std::string Parser::_startMin;
std::string Parser::_endHour;
std::string Parser::_endMin;
std::string Parser::_dateDay;
std::string Parser::_dateMonth;
std::string Parser::_dayOfTheWeek;
std::string Parser::_taskDesc;
std::string Parser::_taskType;
std::string Parser::_tokenizeContent;
std::string Parser::_newContent;
std::string Parser::_taskID;
std::string Parser::_command;
std::vector<std:: string> Parser::addTaskDetails;
int Parser::output;

bool Parser::tokenizeCOMMAND(std:: string tokenizeContent) {

	size_t commandFirst = 0;
	size_t commandEnd = tokenizeContent.find_first_of(" ");

	_command = tokenizeContent.substr(commandFirst,commandEnd);

	if(!isCommandValid(_command))
		return false;

	commandFirst = commandEnd + 1;
	std::string restOfContent = tokenizeContent.substr(commandFirst);
	
	if(_command == "add")
		tokenizeADDEmptyFirst(restOfContent);
	if(_command == "delete")
		return tokenizeDELETE(restOfContent);
	if(_command == "update")
		return tokenizeUPDATE(restOfContent);
	if(_command == "clear")
		return tokenizeCLEAR(restOfContent);
	if(_command == "done")
		return tokenizeDONE(restOfContent);
	if(_command == "undo")
		return tokenizeUNDO(restOfContent);

}

bool Parser::isCommandValid(std::string input) {

	if(_command == "add" || "delete" || "clear" || "update" || "done" || "undo")
		return true;
	else
		return false;
}

void Parser::tokenizeADDEmptyFirst(std::string tokenizeContent) {

		_taskType = "";
		addTaskDetails.push_back(_taskType);
		_taskID = "";
		addTaskDetails.push_back(_taskID);
		
		 tokenizeADD(tokenizeContent);
}

bool Parser::tokenizeADD(std:: string tokenizeContent) {
	

		_newContent = tokenizeContent;
	
		size_t taskFirst = 0;
		size_t taskLast = _newContent.find(" on ");
		
		if(taskLast!=std::string::npos){

		_taskDesc = _newContent.substr(taskFirst,taskLast);
		addTaskDetails.push_back(_taskDesc);
		
		taskFirst = taskLast+4;
		taskLast = _newContent.npos;
		std::string dateContent = _newContent.substr(taskFirst,taskLast);
		return isDateDayValid(dateContent);
		}

		else{

		taskLast = _newContent.find(" by ");
		
		if(taskLast!=std::string::npos){

		_taskDesc = _newContent.substr(taskFirst,taskLast);
		addTaskDetails.push_back(_taskDesc);
		
		taskFirst = taskLast+4;
		taskLast = _newContent.npos;
		std::string dateContent = _newContent.substr(taskFirst,taskLast);
		return isDateDayValid(dateContent);
		}


		else{
			
		taskLast = _newContent.find(" from ");
		
		if(taskLast!=std::string::npos){

		_taskDesc = _newContent.substr(taskFirst,taskLast);
		addTaskDetails.push_back(_taskDesc);
		
		taskFirst = taskLast+6;
		taskLast = _newContent.npos;
		std::string dateContent = _newContent.substr(taskFirst,taskLast);

		return isDateDayValid(dateContent);
		}

		else
		{
			taskLast = _newContent.npos;
			_taskDesc = _newContent.substr(taskFirst,taskLast);
			addTaskDetails.push_back(_taskDesc);

			_dateDay = "";
			addTaskDetails.push_back(_dateDay);
			_dateMonth = "";
			addTaskDetails.push_back(_dateMonth);
			_startHour = "";
			addTaskDetails.push_back(_startHour);
			_startMin = "";
			addTaskDetails.push_back(_startMin);
			_endHour = "";
			addTaskDetails.push_back(_endHour);
			_endMin = "";
			addTaskDetails.push_back(_endMin);

			return architectureLogic::pushParserVector(addTaskDetails);
			}
		}
	}

		
}

bool Parser::tokenizeUPDATE(std::string tokenizeContent) {
		
	std::string _newContent = tokenizeContent;
	size_t taskFirst = _newContent.find_first_not_of(" ");
	size_t taskLast = _newContent.find_first_of(" ",taskFirst);
	_taskDesc = _newContent.substr(taskFirst,taskLast);
	addTaskDetails.push_back(_taskDesc);

	taskFirst = taskLast + 1;
	std::string taskIDContent =_newContent.substr(taskFirst);
	taskFirst = taskIDContent.find_first_not_of(" ");
	taskLast = taskIDContent.find_first_of(" ");
	_taskID = taskIDContent.substr(taskFirst,taskLast);
	addTaskDetails.push_back(_taskID);
	
	taskFirst = taskLast+1;
	taskLast = taskIDContent.npos;
	std::string updateContent = taskIDContent.substr(taskFirst,taskLast);

	
	return tokenizeADD(updateContent);
		
}

bool Parser::tokenizeDELETE(std::string tokenizeContent) {
		
	std::string _newContent = tokenizeContent;
	size_t taskFirst = _newContent.find_first_not_of(" ");
	size_t taskLast = _newContent.find_first_of(" ",taskFirst);
	taskLast = taskLast - 1;
	_taskType = _newContent.substr(taskFirst,taskLast);
	addTaskDetails.push_back(_taskType);

	taskFirst = taskLast + 2;
	std::string taskIDContent =_newContent.substr(taskFirst);
	taskFirst = taskIDContent.find_first_not_of(" ");
	_taskID = taskIDContent.substr(taskFirst);
	addTaskDetails.push_back(_taskID);

	_taskDesc = "";
	addTaskDetails.push_back(_taskDesc);
	_dateDay = "";
	addTaskDetails.push_back(_dateDay);
	_dateMonth = "";
	addTaskDetails.push_back(_dateMonth);
	_startHour = "";
	addTaskDetails.push_back(_startHour);
	_startMin = "";
	addTaskDetails.push_back(_startMin);
	_endHour = "";
	addTaskDetails.push_back(_endHour);
	_endMin = "";
	addTaskDetails.push_back(_endMin);
	
	return architectureLogic::pushParserVector(addTaskDetails);
}

bool Parser::tokenizeCLEAR(std::string tokenizeContent) {
		
	std::string _newContent = tokenizeContent;
	size_t taskFirst = _newContent.find_first_not_of(" ");
	_taskType = _newContent.substr(taskFirst);
	addTaskDetails.push_back(_taskType);

	_taskID = "";
	addTaskDetails.push_back(_taskID);
	_taskDesc = "";
	addTaskDetails.push_back(_taskDesc);
	_dateDay = "";
	addTaskDetails.push_back(_dateDay);
	_dateMonth = "";
	addTaskDetails.push_back(_dateMonth);
	_startHour = "";
	addTaskDetails.push_back(_startHour);
	_startMin = "";
	addTaskDetails.push_back(_startMin);
	_endHour = "";
	addTaskDetails.push_back(_endHour);
	_endMin = "";
	addTaskDetails.push_back(_endMin);
	
	return architectureLogic::pushParserVector(addTaskDetails);
}

bool Parser::tokenizeDONE(std::string tokenizeContent) {

	std::string _newContent = tokenizeContent;
	size_t taskFirst = _newContent.find_first_not_of(" ");
	size_t taskLast = _newContent.find_first_of(" ",taskFirst);
	taskLast = taskLast - 1;
	_taskType = _newContent.substr(taskFirst,taskLast);
	addTaskDetails.push_back(_taskType);

	taskFirst = taskLast + 2;
	std::string taskIDContent =_newContent.substr(taskFirst);
	taskFirst = taskIDContent.find_first_not_of(" ");
	_taskID = taskIDContent.substr(taskFirst);
	addTaskDetails.push_back(_taskID);

	_taskDesc = "";
	addTaskDetails.push_back(_taskDesc);
	_dateDay = "";
	addTaskDetails.push_back(_dateDay);
	_dateMonth = "";
	addTaskDetails.push_back(_dateMonth);
	_startHour = "";
	addTaskDetails.push_back(_startHour);
	_startMin = "";
	addTaskDetails.push_back(_startMin);
	_endHour = "";
	addTaskDetails.push_back(_endHour);
	_endMin = "";
	addTaskDetails.push_back(_endMin);
	
	return architectureLogic::pushParserVector(addTaskDetails);

}

bool Parser::isDateDayValid(std::string tokenizeContent){

		std::string remainingContent = tokenizeContent;

		size_t taskFirst = 0;
		size_t taskLast = remainingContent.find_first_of(" ");
		_dateDay = remainingContent.substr(taskFirst,taskLast);
		if (!isDayValid(_dateDay))
			return false;
		addTaskDetails.push_back(_dateDay);
		
		taskFirst = taskLast+1;
		_newContent = remainingContent.substr(taskFirst);

		return isDateMonthValid(_newContent);



}

bool Parser::isDateMonthValid(std::string tokenizeContent){

		std::string remainingContent = tokenizeContent;

		size_t taskFirst = 0;
		size_t taskLast = remainingContent.find_first_of(" ");
		_dateMonth = remainingContent.substr(taskFirst,taskLast);
		taskFirst = taskLast+1;
		addTaskDetails.push_back(_dateMonth);
		_newContent = remainingContent.substr(taskFirst);

		tokenizeTime(_newContent);
}

bool Parser::tokenizeTime(std::string tokenizeContent){

		size_t taskLast = tokenizeContent.find("to");
		
		if(taskLast!=std::string::npos)
			return isTimedValid(tokenizeContent);
		else
		{
			size_t taskLast = tokenizeContent.find("-");
			 if(taskLast!=std::string::npos)
				 return isTimedValid(tokenizeContent);
			 else
				 return isDeadlineVaild(tokenizeContent);
		}
}


bool Parser::isDeadlineVaild(std::string tokenizeContent){

		std::string remainingContent = tokenizeContent;
		size_t taskFirst = 0;
		size_t taskLast = remainingContent.find_first_of(":");

		_startHour = remainingContent.substr(taskFirst,taskLast);
		isHourTimeValid(_startHour);
		addTaskDetails.push_back(_startHour);

		taskFirst = taskLast+1;
		_startMin = remainingContent.substr(taskFirst);
		isMinTimeValid(_startMin);
		addTaskDetails.push_back(_startMin);
		_endHour = "";
		addTaskDetails.push_back(_endHour);
		_endMin = "";
		addTaskDetails.push_back(_endHour);

		return architectureLogic::pushParserVector(addTaskDetails);


}

bool Parser::isTimedValid(std::string tokenizeContent){
	
			std::string remainingContent = tokenizeContent;
			size_t taskFirst = 0;
			size_t taskLast = remainingContent.find_first_of(":");
			_startHour = remainingContent.substr(taskFirst,taskLast);
			if(!isHourTimeValid(_startHour))
				return false;
			addTaskDetails.push_back(_startHour);

			taskFirst = taskLast+1;
			taskLast = remainingContent.find_first_of(" ");
			taskLast = taskLast-3;
			_startMin = remainingContent.substr(taskFirst,taskLast);
			if(!isMinTimeValid(_startMin))
				return false;
			addTaskDetails.push_back(_startMin);

			taskFirst = remainingContent.find_last_of(" ");
			taskFirst = taskFirst+1;
			std::string endTime = remainingContent.substr(taskFirst);
			taskFirst = 0;
			taskLast = endTime.find_first_of(":");
			_endHour = endTime.substr(taskFirst,taskLast);
			if(!isHourTimeValid(_endHour))
				return false;
			addTaskDetails.push_back(_endHour);

			taskFirst = taskLast+1;
			_endMin = endTime.substr(taskFirst);
			if(!isMinTimeValid(_endMin))
				return false;
			addTaskDetails.push_back(_endMin);

			if(!isRunningTimeValid(_startHour,_endHour))
				return false;

			return architectureLogic::pushParserVector(addTaskDetails);

		}



int Parser::stringToInt(std::string input) {

	output = atoi(input.c_str()); 
	
	return output;
}

bool Parser::isDayValid (std::string input){

	stringToInt(input);

	if(output > 0 || output < 32)
		return true;
	else
		return false;
}

bool Parser::isHourTimeValid(std::string input){

	stringToInt(input);

	if (output > 0 || output < 24)
		return true;
	else
		return false;
}

bool Parser::isMinTimeValid(std::string input){

 	stringToInt(input);

	if (output < 60 || output > 0)
		return true;
	else
		return false;
}

bool Parser::isRunningTimeValid(std::string inputStart,std::string inputEnd){

	int outputStart = atoi(inputStart.c_str());
	int outputEnd = atoi(inputEnd.c_str());

	if (outputStart <= outputEnd)
		return true;
	else
		return false;
}






/*
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