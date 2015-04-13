// @author A0111472U
#include "E2DParser.h"
#include "E2DLogic.h"
#include "E2DInputFeedback.h"

std::string E2DParser::_startHour;
std::string E2DParser::_startMin;
std::string E2DParser::_endHour;
std::string E2DParser::_endMin;
std::string E2DParser::_dateDay;
std::string E2DParser::_dateMonth;
std::string E2DParser::_taskDesc;
std::string E2DParser::_taskType;
std::string E2DParser::_newContent;
std::string E2DParser::_taskID;
std::string E2DParser::_command;
std::string E2DParser::_userInput;
std::string E2DParser::_endDay;
std::string E2DParser::_endMonth;
std::vector<std:: string> E2DParser::addTaskDetails;

E2DParser::E2DParser(void) {
}


E2DParser::~E2DParser(void) {
}
void E2DParser::pushUserInput(std:: string userInput) {
	_userInput = userInput; // recieve command and content input from gui
	tokenizeCommand();

	E2DInputFeedback::addToMasterInputList(userInput);
}

void E2DParser::tokenizeCommand() {

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
		tokenizeUndo(_userInput);
	}
}

void E2DParser::tokenizeInvalid() {

	addTaskDetails.push_back("invalid");

	addEmptyString(11); // this functions pushes back empty string into vector
}

void E2DParser::checkCommand(std::string _command,std::string restOfContent) {
		
	if(_command == "add" || _command == "a" ) { 
		tokenizeAddEmptyStringFirst(restOfContent);
	} else if(_command == "delete" || _command == "del" ) {
		tokenizeDeleteOrDone(restOfContent);
	} else if(_command == "update" || _command == "up" ) {
		tokenizeUpdate(restOfContent);
	} else if(_command == "clear" || _command == "clr" ) {
		tokenizeClear(restOfContent);
	} else if(_command == "done" || _command == "d" ) {
		tokenizeDeleteOrDone(restOfContent);
	} else if(_command == "save") {
		tokenizeSave(restOfContent);
	} else if(_command == "filter" || _command == "fil" ) {
		tokenizeFilter(restOfContent);
	} else if(_command == "search" || _command == "src" ) {
		tokenizeSearch(restOfContent);
	} else {
		tokenizeInvalid();
	}
}

void E2DParser::tokenizeAddEmptyStringFirst(std::string tokenizeContent) {

	_taskType = "";
	addTaskDetails.push_back(_taskType);
	_taskID = "";
	addTaskDetails.push_back(_taskID);

	tokenizeAdd(tokenizeContent);
}

void E2DParser::tokenizeAdd(std:: string tokenizeContent) {
	assert(tokenizeContent!="");
	_newContent = tokenizeContent;

	size_t taskFirst = 0;
	size_t taskLast = _newContent.find(" on ");
	// this function will differentiate what type of task it is adding; deadline,timed etc.
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

				addEmptyString(8);

				return;
			}
		}
	}
}
void E2DParser::tokenizeDeadlineTask(std::string tokenizeContent, size_t taskLast) {
		assert(tokenizeContent!="");	
		size_t taskFirst = 0;

		_taskDesc = tokenizeContent.substr(taskFirst,taskLast);
		addTaskDetails.push_back(_taskDesc);

		taskFirst = taskLast+4;
		taskLast = tokenizeContent.npos;
		std::string dateContent = tokenizeContent.substr(taskFirst,taskLast);
		tokenizeDateDay(dateContent);

}

void E2DParser::tokenizeTimedTask(std::string tokenizeContent, size_t taskLast) {
		assert(tokenizeContent!="");
		size_t taskFirst = 0;

		_taskDesc = tokenizeContent.substr(taskFirst,taskLast);
		addTaskDetails.push_back(_taskDesc);

		taskFirst = taskLast+6;
		taskLast = tokenizeContent.npos;
		std::string dateContent = tokenizeContent.substr(taskFirst,taskLast);
		tokenizeDateDay(dateContent);
}

void E2DParser::tokenizeUpdate(std::string tokenizeContent) {
	assert(tokenizeContent!="");
	std::string _newContent = tokenizeContent; 
	size_t taskFirst = _newContent.find_first_not_of(" ");
	size_t taskLast = _newContent.find_first_of(" ",taskFirst);
	_taskType = _newContent.substr(taskFirst,taskLast); // tokenize tasktype which is either today upcoming or misc
	assert(_taskType!="");
	addTaskDetails.push_back(_taskType);

	taskFirst = taskLast + 1;
	std::string taskIDContent =_newContent.substr(taskFirst);
	taskFirst = taskIDContent.find_first_not_of(" ");
	taskLast = taskIDContent.find_first_of(" ");
	_taskID = taskIDContent.substr(taskFirst,taskLast);
	assert(_taskID!="");
	addTaskDetails.push_back(_taskID);

	taskFirst = taskLast+1;
	taskLast = taskIDContent.npos;
	std::string updateContent = taskIDContent.substr(taskFirst,taskLast);

	tokenizeAdd(updateContent); //sends the rest of the content to be tokenize by the adding function again
}

void E2DParser::tokenizeDeleteOrDone(std::string tokenizeContent) {
	assert(tokenizeContent!="");
	std::string _newContent = tokenizeContent;
	size_t taskFirst = _newContent.find_first_not_of(" ");
	size_t taskLast = _newContent.find_first_of(" ",taskFirst);
	_taskType = _newContent.substr(taskFirst,taskLast); //tokenize the first word
	addTaskDetails.push_back(_taskType);
	assert(_taskType!="");
	taskFirst = taskLast + 1;
	std::string taskIDContent =_newContent.substr(taskFirst);
	taskFirst = taskIDContent.find_first_not_of(" ");
	_taskID = taskIDContent.substr(taskFirst); //tokenize the 2nd word
	assert(_taskID!="");
	addTaskDetails.push_back(_taskID);

	addEmptyString(9);
}

void E2DParser::tokenizeClear(std::string tokenizeContent) {
	assert(tokenizeContent!="");
	std::string _newContent = tokenizeContent;
	
	size_t taskFirst = _newContent.find_first_not_of(" ");
	_taskType = _newContent.substr(taskFirst);
	assert(_taskType!="");
	addTaskDetails.push_back(_taskType);

	addEmptyString(10);
}

void E2DParser::tokenizeUndo(std::string tokenizeContent) {
	assert(tokenizeContent != "");
	addEmptyString(11);

}

void E2DParser::tokenizeFilter(std::string tokenizeContent) {
	assert(tokenizeContent!="");
	size_t taskFirst = tokenizeContent.find_first_not_of(" ");
	size_t taskLast = tokenizeContent.find_first_of(":");

	if(taskLast!= tokenizeContent.npos) { //check if the word is a time
		_startHour = tokenizeContent.substr(taskFirst,taskLast);
		addTaskDetails.push_back(_startHour);
		assert(_startHour!="");
		taskLast = taskLast + 1;
		_startMin = tokenizeContent.substr(taskLast);
		assert(_startMin!="");
		addTaskDetails.push_back(_startMin);
		addEmptyString(9);
	} else {
		tokenizeDeleteOrDone(tokenizeContent);
	}
}



void E2DParser::tokenizeSave(std::string tokenizeContent) {
	assert(tokenizeContent!="");
	std::string _newContent = tokenizeContent;

	size_t taskFirst = _newContent.find_last_of(" ") - 1;
	size_t taskLast = _newContent.find_last_not_of(" ");
	_taskID = _newContent.substr(taskFirst,taskLast); // filename
	_newContent.erase(taskFirst, taskLast);
	assert(_taskID!="");
	taskFirst = _newContent.find_first_not_of(" ");
	taskLast = _newContent.find_last_not_of(" ") + 1;
	_taskType = _newContent.substr(taskFirst, taskLast); // file Directory
	assert(_taskType!="");
	addTaskDetails.push_back(_taskType); 
	addTaskDetails.push_back(_taskID);

	addEmptyString(9);
}

void E2DParser::tokenizeSearch(std::string tokenizeContent) {
	assert(tokenizeContent!="");
	addTaskDetails.push_back(tokenizeContent);

	addEmptyString(10);
} 


void E2DParser::tokenizeDateDay(std::string tokenizeContent){
	assert(tokenizeContent!="");
	std::string remainingContent = tokenizeContent;
	size_t taskFirst = 0;
	size_t taskLast = remainingContent.find_first_of(" ");
	_dateDay = remainingContent.substr(taskFirst,taskLast);	//tokenizing the day
	assert(_dateDay!="");
	addTaskDetails.push_back(_dateDay);

	taskFirst = taskLast+1;
	_newContent = remainingContent.substr(taskFirst);

	tokenizeDateMonth(_newContent);
}

void E2DParser::tokenizeDateMonth(std::string tokenizeContent){
	assert(tokenizeContent!="");
	std::string remainingContent = tokenizeContent;
	size_t taskFirst = 0;
	size_t taskLast = remainingContent.find_first_of(" ");
	_dateMonth = remainingContent.substr(taskFirst,taskLast);//tokenizing the month
	assert(_dateMonth!="");
	addTaskDetails.push_back(_dateMonth);
	
	taskFirst = taskLast+1;
	_newContent = remainingContent.substr(taskFirst);

	checkAllDayTask(_newContent);
}

void E2DParser::checkAllDayTask(std::string tokenizeContent) {
	assert(tokenizeContent!="");
	size_t findCollen = tokenizeContent.find(":");

	if(findCollen!=tokenizeContent.npos){
		tokenizeStartTime(tokenizeContent);
	} else { 
		addEmptyString(6);
	}
}

void E2DParser::tokenizeStartTime(std::string tokenizeContent){
	assert(tokenizeContent!="");
	std::string remainingContent = tokenizeContent;
	size_t taskFirst = 0;
	size_t taskLast = remainingContent.find_first_of(":");
	
	_startHour = remainingContent.substr(taskFirst,taskLast);	//tokenizing the time part of deadline tasks
	assert(_startHour!="");	
	addTaskDetails.push_back(_startHour);
	taskFirst = taskLast+1;
	taskLast =  taskFirst+2;
	std::string checkcontent = remainingContent.substr(taskFirst,taskLast); //removing start mins out

	size_t minFirst = checkcontent.find_first_not_of(" ");
	size_t minLast = minFirst + 2;
	_startMin = checkcontent.substr(minFirst,minLast);
	assert(_startMin!="");	
	addTaskDetails.push_back(_startMin);
	
	remainingContent = remainingContent.substr(taskLast);
	checkDeadlineorTimed(remainingContent);
}

void E2DParser::checkDeadlineorTimed(std::string tokenizeContent){
	size_t taskLast = tokenizeContent.find("to");
	if(taskLast!=std::string::npos) {	//differentiate between timed and deadline task
		checkTimedOrMulti(tokenizeContent);
	} else {
		size_t taskLast = tokenizeContent.find("-");
		if(taskLast!=std::string::npos) {
			checkTimedOrMulti(tokenizeContent);
		} else {
			addEmptyString(4);
		}
	}
}

void E2DParser::checkTimedOrMulti(std::string tokenizeContent){
	assert(tokenizeContent!="");
	//removing to/-
	std::string remainingContent = tokenizeContent;
	size_t taskFirst = remainingContent.find_first_not_of(" ");
	size_t taskLast = remainingContent.find_first_of(" ",taskFirst);
	taskLast = taskLast + 1;
	remainingContent = remainingContent.substr(taskLast);
	//check next word 
	taskFirst = remainingContent.find_first_not_of(" ");
	taskLast = remainingContent.find_first_of(" ",taskFirst);
	std::string checkDate = remainingContent.substr(taskFirst,taskLast);

	size_t collen = checkDate.find(":");
	if (collen != checkDate.npos) {
		addTaskDetails.push_back("");
		addTaskDetails.push_back("");
		tokenizeEndTime(remainingContent);
	} else {
		tokenizeMultiTaskDay(remainingContent);	
	}

}

void E2DParser::tokenizeMultiTaskDay(std::string tokenizeContent) {
	assert(tokenizeContent!="");
	size_t taskFirst =  tokenizeContent.find_first_not_of(" ");
	size_t taskLast = tokenizeContent.find_first_of(" ",taskFirst);
	_endDay = tokenizeContent.substr(taskFirst,taskLast);	//tokenizing the day
	assert(_endDay!="");
	addTaskDetails.push_back(_endDay);

	taskFirst = taskLast+1;
	_newContent = tokenizeContent.substr(taskFirst);

	tokenizeDateMonth(_newContent);
}

void E2DParser::tokenizeMultiTaskMonth(std::string tokenizeContent) {
	assert(tokenizeContent!="");
	size_t taskFirst =  tokenizeContent.find_first_not_of(" ");
	size_t taskLast = tokenizeContent.find_first_of(" ",taskFirst);
	_endMonth = tokenizeContent.substr(taskFirst,taskLast);	//tokenizing the month
	assert(_endMonth!="");	
	addTaskDetails.push_back(_endMonth);

	taskFirst = taskLast+1;
	_newContent = tokenizeContent.substr(taskFirst);

	tokenizeEndTime(_newContent);
}
void E2DParser::tokenizeEndTime(std::string tokenizeContent) {
	assert(tokenizeContent!="");
	size_t taskFirst = tokenizeContent.find_last_of(" ");
	taskFirst = taskFirst+1;
	std::string endTime = tokenizeContent.substr(taskFirst);
	taskFirst = 0;
	size_t taskLast = endTime.find_first_of(":");
	_endHour = endTime.substr(taskFirst,taskLast);
	
	addTaskDetails.push_back(_endHour);
	assert(_endHour!="");
	taskFirst = taskLast+1;
	_endMin = endTime.substr(taskFirst);        
	assert(_endHour!="");
	addTaskDetails.push_back(_endMin);

	E2DLogic::pushParserVector(addTaskDetails);
}

void E2DParser::addEmptyString(int count) {
	//this functions pushes empty string into the vector
	for( int i = count; i!=0; i--) {

		addTaskDetails.push_back("");

	}
	E2DLogic::pushParserVector(addTaskDetails);
}
