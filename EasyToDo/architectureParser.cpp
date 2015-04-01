#include "architectureParser.h"
#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureInputFeedback.h"

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
std::string Parser::_userInput;
std::vector<std:: string> Parser::addTaskDetails;
int Parser::output;

void Parser::pushUserInput(std:: string userInput) {
	_userInput = userInput;
	tokenizeCOMMAND();

	architectureInputFeedback::addToMasterInputList(userInput);
}

void Parser::tokenizeCOMMAND() {
	std::string tokenizeContent = _userInput;
	size_t commandFirst = 0;
	size_t commandEnd = tokenizeContent.find_first_of(" ");

	_command = tokenizeContent.substr(commandFirst,commandEnd);

	commandFirst = commandEnd + 1;
	std::string restOfContent = tokenizeContent.substr(commandFirst);

	if(_command == "add") { 
		tokenizeADDEmptyFirst(restOfContent);
	} else if(_command == "delete") {
		return tokenizeDELETE(restOfContent);
	} else if(_command == "update") {
		return tokenizeUPDATE(restOfContent);
	} else if(_command == "clear") {
		return tokenizeCLEAR(restOfContent);
	} else if(_command == "done") {
		return tokenizeDONE(restOfContent);
	}/* else if(_command == "undo") {
		return tokenizeUNDO(restOfContent);
	}*/ else {
		return tokenizeINVALID();
	}

}

void Parser::tokenizeINVALID() {
	addTaskDetails.push_back("invalid");
}
/*
bool Parser::isCommandValid(std::string input) {

	if(_command == "add" || "delete" || "clear" || "update" || "done" || "undo") {
		return true;
	} else {
		return false;
	}
}
*/
/*
bool Parser::isTaskTypeValid(std::string input) {

	if(_taskType == "today" || "upcoming" || "misc" || "all") {
		return true;
	} else {
		return false;
	}
}
*/
void Parser::tokenizeADDEmptyFirst(std::string tokenizeContent) {

	_taskType = "";
	addTaskDetails.push_back(_taskType);
	_taskID = "";
	addTaskDetails.push_back(_taskID);

	tokenizeADD(tokenizeContent);
}

void Parser::tokenizeADD(std:: string tokenizeContent) {
	_newContent = tokenizeContent;

	size_t taskFirst = 0;
	size_t taskLast = _newContent.find(" on ");

	if(taskLast!=std::string::npos){
		_taskDesc = _newContent.substr(taskFirst,taskLast);
		addTaskDetails.push_back(_taskDesc);

		taskFirst = taskLast+4;
		taskLast = _newContent.npos;
		std::string dateContent = _newContent.substr(taskFirst,taskLast);
		isDateDayValid(dateContent);
	} else{
		taskLast = _newContent.find(" by ");

		if(taskLast!=std::string::npos){

			_taskDesc = _newContent.substr(taskFirst,taskLast);
			addTaskDetails.push_back(_taskDesc);

			taskFirst = taskLast+4;
			taskLast = _newContent.npos;
			std::string dateContent = _newContent.substr(taskFirst,taskLast);
			isDateDayValid(dateContent);
		} else {

			taskLast = _newContent.find(" from ");

			if(taskLast!=std::string::npos){

				_taskDesc = _newContent.substr(taskFirst,taskLast);
				addTaskDetails.push_back(_taskDesc);

				taskFirst = taskLast+6;
				taskLast = _newContent.npos;
				std::string dateContent = _newContent.substr(taskFirst,taskLast);

				isDateDayValid(dateContent);
			} else {
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

				architectureLogic::pushParserVector(addTaskDetails);
			}
		}
	}
}

void Parser::tokenizeUPDATE(std::string tokenizeContent) {

	std::string _newContent = tokenizeContent;
	size_t taskFirst = _newContent.find_first_not_of(" ");
	size_t taskLast = _newContent.find_first_of(" ",taskFirst);
	_taskType = _newContent.substr(taskFirst,taskLast);

	addTaskDetails.push_back(_taskType);

	taskFirst = taskLast + 1;
	std::string taskIDContent =_newContent.substr(taskFirst);
	taskFirst = taskIDContent.find_first_not_of(" ");
	taskLast = taskIDContent.find_first_of(" ");
	_taskID = taskIDContent.substr(taskFirst,taskLast);
	addTaskDetails.push_back(_taskID);

	taskFirst = taskLast+1;
	taskLast = taskIDContent.npos;
	std::string updateContent = taskIDContent.substr(taskFirst,taskLast);
	tokenizeADD(updateContent);
}

void Parser::tokenizeDELETE(std::string tokenizeContent) {

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

	architectureLogic::pushParserVector(addTaskDetails);
}

void Parser::tokenizeCLEAR(std::string tokenizeContent) {

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

	architectureLogic::pushParserVector(addTaskDetails);
}

void Parser::tokenizeDONE(std::string tokenizeContent) {

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

	architectureLogic::pushParserVector(addTaskDetails);
}

void Parser::isDateDayValid(std::string tokenizeContent){

	std::string remainingContent = tokenizeContent;

	size_t taskFirst = 0;
	size_t taskLast = remainingContent.find_first_of(" ");
	_dateDay = remainingContent.substr(taskFirst,taskLast);
	addTaskDetails.push_back(_dateDay);

	taskFirst = taskLast+1;
	_newContent = remainingContent.substr(taskFirst);

	isDateMonthValid(_newContent);
}

void Parser::isDateMonthValid(std::string tokenizeContent){

	std::string remainingContent = tokenizeContent;

	size_t taskFirst = 0;
	size_t taskLast = remainingContent.find_first_of(" ");
	_dateMonth = remainingContent.substr(taskFirst,taskLast);
	taskFirst = taskLast+1;
	addTaskDetails.push_back(_dateMonth);
	_newContent = remainingContent.substr(taskFirst);

	tokenizeTime(_newContent);
}

void Parser::tokenizeTime(std::string tokenizeContent){

	size_t taskLast = tokenizeContent.find("to");

	if(taskLast!=std::string::npos)
		isTimedValid(tokenizeContent);
	else
	{
		size_t taskLast = tokenizeContent.find("-");
		if(taskLast!=std::string::npos)
			isTimedValid(tokenizeContent);
		else
			isDeadlineVaild(tokenizeContent);
	}
}


void Parser::isDeadlineVaild(std::string tokenizeContent){

	std::string remainingContent = tokenizeContent;
	size_t taskFirst = 0;
	size_t taskLast = remainingContent.find_first_of(":");

	_startHour = remainingContent.substr(taskFirst,taskLast);
	
	addTaskDetails.push_back(_startHour);

	taskFirst = taskLast+1;
	_startMin = remainingContent.substr(taskFirst);
	
	addTaskDetails.push_back(_startMin);
	_endHour = "";
	addTaskDetails.push_back(_endHour);
	_endMin = "";
	addTaskDetails.push_back(_endHour);

	architectureLogic::pushParserVector(addTaskDetails);
}

void Parser::isTimedValid(std::string tokenizeContent){

	std::string remainingContent = tokenizeContent;
	size_t taskFirst = 0;
	size_t taskLast = remainingContent.find_first_of(":");
	_startHour = remainingContent.substr(taskFirst,taskLast);
	addTaskDetails.push_back(_startHour);

	taskFirst = taskLast+1;
	taskLast = remainingContent.find_first_of(" ");
	taskLast = taskLast-3;
	_startMin = remainingContent.substr(taskFirst,taskLast);

	addTaskDetails.push_back(_startMin);

	taskFirst = remainingContent.find_last_of(" ");
	taskFirst = taskFirst+1;
	std::string endTime = remainingContent.substr(taskFirst);
	taskFirst = 0;
	taskLast = endTime.find_first_of(":");
	_endHour = endTime.substr(taskFirst,taskLast);
	
	addTaskDetails.push_back(_endHour);

	taskFirst = taskLast+1;
	_endMin = endTime.substr(taskFirst);
	
	addTaskDetails.push_back(_endMin);

	architectureLogic::pushParserVector(addTaskDetails);
}


/*
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

*/


