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
std::string Parser::_tokenizeContent;
std::string Parser::_newContent;
std::string Parser::_taskID;

void Parser::tokenizeADD(std:: string tokenizeContent) {
	
		
		_newContent = tokenizeContent;
	
		size_t taskFirst = 0;
		size_t taskLast = _newContent.find(" on ");
		
		if(taskLast!=std::string::npos){

		_taskDesc = _newContent.substr(taskFirst,taskLast);
		architectureLogic::determineContentDescription(_taskDesc);
		
		taskFirst = taskLast+4;
		taskLast = _newContent.npos;
		std::string dateContent = _newContent.substr(taskFirst,taskLast);
		tokenizeDateDay(dateContent);
		}

		else{

		taskLast = _newContent.find(" by ");
		
		if(taskLast!=std::string::npos){

		_taskDesc = _newContent.substr(taskFirst,taskLast);
		architectureLogic::determineContentDescription(_taskDesc);
		
		taskFirst = taskLast+4;
		taskLast = _newContent.npos;
		std::string dateContent = _newContent.substr(taskFirst,taskLast);
		tokenizeDateDay(dateContent);
		}

		else{
			
		taskLast = _newContent.find(" from ");
		
		if(taskLast!=std::string::npos){

		_taskDesc = _newContent.substr(taskFirst,taskLast);
		architectureLogic::determineContentDescription(_taskDesc);
		
		taskFirst = taskLast+6;
		taskLast = _newContent.npos;
		std::string dateContent = _newContent.substr(taskFirst,taskLast);
		tokenizeDateDay(dateContent);
		
		}
		else
		{
			taskLast = _newContent.npos;
			_taskDesc = _newContent.substr(taskFirst,taskLast);
			architectureLogic::determineContentDescription(_taskDesc);
			_dayOfTheWeek = "";
			architectureLogic::determineContentDate(_dayOfTheWeek);
			_dateDay = "";
			architectureLogic::determineContentDay(_dateDay);
			_dateMonth = "";
			architectureLogic::determineContentMonth(_dateMonth);
			_startHour = "";
			architectureLogic::determineContentStartHours(_startHour);
			_startMin = "";
			architectureLogic::determineContentStartMinutes(_startMin);
			_endHour = "";
			architectureLogic::determineContentEndHour(_endHour);
			_endMin = "";
			architectureLogic::determineContentEndMinutes(_endMin);
			}
		}
	}

		


		


return;

}

void Parser::tokenizeUPDATE(std::string tokenizeContent) {
		
		_newContent = tokenizeContent;
		size_t taskFirst = _newContent.find_first_not_of(" ");
		size_t taskLast = _newContent.find_first_of(" ");
		_taskID = _newContent.substr(taskFirst,taskLast);
		taskFirst = taskLast+1;
		taskLast = _newContent.npos;
		std::string updateContent = _newContent.substr(taskFirst,taskLast);
		tokenizeADD(updateContent);
		
}
/*
void Parser::tokenizeDayOfTheWeek(std::string tokenizeContent) {

	std::string remainingContent = tokenizeContent;

		size_t taskFirst = 0;
		size_t taskLast = remainingContent.find_first_of(" ");
		_dayOfTheWeek = remainingContent.substr(taskFirst,taskLast);
		std::cout << "dayoftheweek: "<<_dayOfTheWeek << std::endl;
		//architectureLogic::determineContentDay(_dayOfTheWeek);
		taskFirst = taskLast+1;
		_newContent = remainingContent.substr(taskFirst);
		tokenizeDateDay(_newContent);

}
*/
void Parser::tokenizeDateDay(std::string tokenizeContent){

		std::string remainingContent = tokenizeContent;

		size_t taskFirst = 0;
		size_t taskLast = remainingContent.find_first_of(" ");
		_dateDay = remainingContent.substr(taskFirst,taskLast);
		architectureLogic::determineContentDay(_dateDay);
		taskFirst = taskLast+1;
		_newContent = remainingContent.substr(taskFirst);
		tokenizeDateMonth(_newContent);


}

void Parser::tokenizeDateMonth(std::string tokenizeContent){

		std::string remainingContent = tokenizeContent;

		size_t taskFirst = 0;
		size_t taskLast = remainingContent.find_first_of(" ");
		_dateMonth = remainingContent.substr(taskFirst,taskLast);
		architectureLogic::determineContentMonth(_dateMonth);
		taskFirst = taskLast+1;
		_newContent = remainingContent.substr(taskFirst);
		tokenizeTime(_newContent);

}

void Parser::tokenizeTime(std::string tokenizeContent){

		std::string remainingContent = tokenizeContent;
		size_t taskFirst = 0;
		size_t taskLast = remainingContent.find("to");
		
		if(taskLast!=std::string::npos){

			taskLast = remainingContent.find_first_of(":");
			_startHour = remainingContent.substr(taskFirst,taskLast);
			architectureLogic::determineContentStartHours(_startHour);

			taskFirst = taskLast+1;
			taskLast = remainingContent.find_first_of(" ");
			taskLast = taskLast-3;
			_startMin = remainingContent.substr(taskFirst,taskLast);
			architectureLogic::determineContentStartMinutes(_startMin);

			taskFirst = remainingContent.find_last_of(" ");
			taskFirst = taskFirst+1;
			std::string endTime = remainingContent.substr(taskFirst);
			taskFirst = 0;
			taskLast = endTime.find_first_of(":");
			_endHour = endTime.substr(taskFirst,taskLast);
			architectureLogic::determineContentEndHours(_endHour);

			taskFirst = taskLast+1;
			_endMin = endTime.substr(taskFirst);
			architectureLogic::determineContentEndMin(_EndMin);
		}
		
		else {

			taskLast = remainingContent.find_first_of(":");
			_startHour = remainingContent.substr(taskFirst,taskLast);
			architectureLogic::determineContentStartHours(_startHour);

			taskFirst = taskLast+1;
			_startMin = remainingContent.substr(taskFirst);
			architectureLogic::determineContentStartMin(_startMin);

			_endHour = "";
			architectureLogic::determineContentEndHours(_endHour);

			_endMin = "";
			architectureLogic::determineContentEndMin(_endMin);
		}



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