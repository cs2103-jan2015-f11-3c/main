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
std::string Parser::_taskDesc;
std::string Parser::_taskType;
std::string Parser::_newContent;
std::string Parser::_taskID;
std::string Parser::_command;
std::string Parser::_userInput;
std::vector<std:: string> Parser::addTaskDetails;

void Parser::pushUserInput(std:: string userInput) {
	_userInput = userInput; // recieve command and content input from gui
	tokenizeCOMMAND();

	architectureInputFeedback::addToMasterInputList(userInput);
}

void Parser::tokenizeCOMMAND() {

	std::string tokenizeContent = _userInput;
	size_t commandFirst = 0;
	size_t commandEnd = tokenizeContent.find_first_of(" ");
	addTaskDetails.clear(); // always clear the vector before pushing anything into it
	if(commandEnd != std:: string::npos) {
		_command = tokenizeContent.substr(commandFirst,commandEnd);
		commandFirst = commandEnd + 1;
		std::string restOfContent = tokenizeContent.substr(commandFirst);
		addTaskDetails.push_back(_command);
		//push the command into vector and send the rest of the content for tokenizing
		checkCommand(_command,restOfContent);
	} else {
		addTaskDetails.push_back(_userInput);
		tokenizeUNDO(_userInput);
	}
}

void Parser::tokenizeINVALID() {

	addTaskDetails.push_back("invalid");

	addEmptyString(9); // this functions pushes back empty string into vector
}

void Parser::checkCommand(std::string _command,std::string restOfContent) {
		
	if(_command == "add") { 
		tokenizeADDEmptyFirst(restOfContent);
	} else if(_command == "delete") {
		tokenizeDELETE(restOfContent);
	} else if(_command == "update") {
		tokenizeUPDATE(restOfContent);
	} else if(_command == "clear") {
		tokenizeCLEAR(restOfContent);
	} else if(_command == "done") {
		tokenizeDONE(restOfContent);
<<<<<<< HEAD
	} else if(_command == "save") {
		tokenizeSAVE(restOfContent);
=======
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861
	} else {
		tokenizeINVALID();
	}

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
	// this function will differentiate what type of task it is adding; dealine,timed etc.
	if(taskLast!=std::string::npos){
		tokenizeDeadlineTask(tokenizeContent,taskLast); //tokenizes the task description
	} else {
		taskLast = _newContent.find(" by ");

		if(taskLast!=std::string::npos){
			tokenizeDeadlineTask(tokenizeContent,taskLast);	
		} else {

			taskLast = _newContent.find(" from ");

			if(taskLast!=std::string::npos){
				tokenizeTimedTask(tokenizeContent,taskLast);	
			} else {
				taskLast = _newContent.npos;
				_taskDesc = _newContent.substr(taskFirst,taskLast);
				addTaskDetails.push_back(_taskDesc);

				addEmptyString(6);

				return;
			}
		}
	}
}
void Parser::tokenizeDeadlineTask(std::string toknizeContent, size_t taskLast) {
	
		size_t taskFirst = 0;

		_taskDesc = toknizeContent.substr(taskFirst,taskLast);
		addTaskDetails.push_back(_taskDesc);

		taskFirst = taskLast+4;
		taskLast = toknizeContent.npos;
		std::string dateContent = toknizeContent.substr(taskFirst,taskLast);
		tokenizeDateDay(dateContent);

}

void Parser::tokenizeTimedTask(std::string toknizeContent, size_t taskLast) {

		size_t taskFirst = 0;

		_taskDesc = toknizeContent.substr(taskFirst,taskLast);
		addTaskDetails.push_back(_taskDesc);

		taskFirst = taskLast+6;
		taskLast = toknizeContent.npos;
		std::string dateContent = toknizeContent.substr(taskFirst,taskLast);
		tokenizeDateDay(dateContent);
}

void Parser::tokenizeUPDATE(std::string tokenizeContent) {

	std::string _newContent = tokenizeContent; 
	size_t taskFirst = _newContent.find_first_not_of(" ");
	size_t taskLast = _newContent.find_first_of(" ",taskFirst);
	_taskType = _newContent.substr(taskFirst,taskLast); // tokenize tasktype which is either today upcoming or misc

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

	tokenizeADD(updateContent); //sends the rest of the content to be tokenize by the adding function again
}

void Parser::tokenizeDELETE(std::string tokenizeContent) {

	std::string _newContent = tokenizeContent;
	size_t taskFirst = _newContent.find_first_not_of(" ");
	size_t taskLast = _newContent.find_first_of(" ",taskFirst);
	_taskType = _newContent.substr(taskFirst,taskLast);
	addTaskDetails.push_back(_taskType);

	taskFirst = taskLast + 1;
	std::string taskIDContent =_newContent.substr(taskFirst);
	taskFirst = taskIDContent.find_first_not_of(" ");
	_taskID = taskIDContent.substr(taskFirst);
	addTaskDetails.push_back(_taskID);

	addEmptyString(7);
}

void Parser::tokenizeCLEAR(std::string tokenizeContent) {

	std::string _newContent = tokenizeContent;
	
	size_t taskFirst = _newContent.find_first_not_of(" ");
	_taskType = _newContent.substr(taskFirst);
	
	addTaskDetails.push_back(_taskType);

	addEmptyString(8);
}

void Parser::tokenizeUNDO(std::string tokenizeContent) {

	addEmptyString(9);

}

void Parser::tokenizeDONE(std::string tokenizeContent) {

	std::string _newContent = tokenizeContent;
	size_t taskFirst = _newContent.find_first_not_of(" ");
	size_t taskLast = _newContent.find_first_of(" ",taskFirst);
	_taskType = _newContent.substr(taskFirst,taskLast);
	addTaskDetails.push_back(_taskType);

	taskFirst = taskLast + 1;
	std::string taskIDContent =_newContent.substr(taskFirst);
	taskFirst = taskIDContent.find_first_not_of(" ");
	_taskID = taskIDContent.substr(taskFirst);
	addTaskDetails.push_back(_taskID);

	addEmptyString(7);

}

void Parser::tokenizeDateDay(std::string tokenizeContent){

	std::string remainingContent = tokenizeContent;
	//tokenizing the day
	size_t taskFirst = 0;
	size_t taskLast = remainingContent.find_first_of(" ");
	_dateDay = remainingContent.substr(taskFirst,taskLast);
	addTaskDetails.push_back(_dateDay);

	taskFirst = taskLast+1;
	_newContent = remainingContent.substr(taskFirst);

	tokenizeDateMonth(_newContent);
}

void Parser::tokenizeDateMonth(std::string tokenizeContent){

	std::string remainingContent = tokenizeContent;
	//tokenizing the month
	size_t taskFirst = 0;
	size_t taskLast = remainingContent.find_first_of(" ");
	_dateMonth = remainingContent.substr(taskFirst,taskLast);
	taskFirst = taskLast+1;
	addTaskDetails.push_back(_dateMonth);
	_newContent = remainingContent.substr(taskFirst);

	checkTimedOrDeadline(_newContent);
}

void Parser::checkTimedOrDeadline(std::string tokenizeContent){

	size_t taskLast = tokenizeContent.find("to");
	//differentiate between timed and deadline task
	if(taskLast!=std::string::npos)
		tokenizeTimedTime(tokenizeContent);
	else
	{
		size_t taskLast = tokenizeContent.find("-");
		if(taskLast!=std::string::npos)
			tokenizeTimedTime(tokenizeContent);
		else
			tokenizeDeadlineTime(tokenizeContent);
	}
}


void Parser::tokenizeDeadlineTime(std::string tokenizeContent){
	//tokenizing the time part of deadline tasks
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

void Parser::tokenizeTimedTime(std::string tokenizeContent){
	//tokenizing the time part of timed tasks
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

void Parser::addEmptyString(int count) {
	//this functions pushes empty string into the vector
	for( int i = count; i!=0; i--) {

		addTaskDetails.push_back("");

	}
<<<<<<< HEAD
	architectureLogic::pushParserVector(addTaskDetails);
}

void Parser::tokenizeSAVE(std::string tokenizeContent) {

	std::string _newContent = tokenizeContent;

	size_t taskFirst = _newContent.find_last_of(" ");
	size_t taskLast = _newContent.find_last_not_of(" ");
	_taskID = _newContent.substr(taskFirst,taskLast); // filename
	_newContent.erase(taskFirst, taskLast);

	taskFirst = _newContent.find_first_not_of(" ");
	taskLast = _newContent.find_last_not_of(" ") + 1;
	_taskType = _newContent.substr(taskFirst, taskLast); // file Directory
	addTaskDetails.push_back(_taskType); 
	addTaskDetails.push_back(_taskID);
	addEmptyString(7);
}
=======

	architectureLogic::pushParserVector(addTaskDetails);
}


>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861

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


