// @author A0111472U
#ifndef E2DPARSER_H
#define E2DPARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>

class E2DParser {
	private:
		//strings that that will store all the command information
		//strings contains all the different command add, delete... etc
		static std::string _command;
		static std::string _userInput;
		static std::string _taskID;
		static std::string _time;
		static std::string _taskDesc;
		static std::string _taskType;
		static std::string _newContent;
		static std::string _dateDay;
		static std::string _dateMonth;
		static std::string _startHour;
		static std::string _startMin;
		static std::string _endDay;
		static std::string _endMonth;
		static std::string _endHour;
        static std::string _endMin;
		
	public:
		E2DParser(void);
		~E2DParser(void);
		static std::vector<std::string> addTaskDetails;
		static void pushUserInput(std::string userInput);

		//Preconditions:: Command line content is contained inside Userinput 
		//Description: Does neccesary operations to parse the command and checking of command is done.
		//Postconditions: command is parsed is stored into a vector. Type of command is identified
		static void tokenizeCommand();
		static void checkCommand(std::string _command, std::string tokenizeContent);
		static void tokenizeAddEmptyStringFirst(std::string tokenizeContent);

		//Preconditions:: command is parsed and UserInput is left with the rest of the content
		//Description: Does neccesary operations to parse the required content
		//Postconditions: tasktype/taskID/task description is parsed and stored into a vector and will call tokenizeDateDay to tokenize the the content
		//Description is similar for the following functions 
		static void tokenizeInvalid();
		static void tokenizeAdd(std::string tokenizeContent);
		static void tokenizeClear(std::string tokenizeContent);
		static void tokenizeDeleteOrDone(std::string tokenizeContent);
		static void tokenizeUndo(std::string tokenizeContent);
		static void tokenizeUpdate(std::string tokenizeContent);
		static void tokenizeSave(std::string tokenizeContent);
		static void tokenizeSearch(std::string tokenizeContent);
		static void tokenizeFilter(std::string tokenizeContent);
		static void tokenizeDeadlineTask(std::string tokenizeContent,size_t taskLast);
		static void tokenizeTimedTask(std::string tokenizeContent, size_t taskLast);

		//Preconditions:: task description is parsed and UserInput is left with the rest of the content
		//Description: Does neccesary operations to parse the required content
		//Postconditions: DateDay is parsed and stored into a vector
		static void tokenizeDateDay(std::string tokenizeContent);

		//Preconditions:: dateDay is parsed and UserInput is left with the rest of the content
		//Description: Does neccesary operations to parse the required content
		//Postconditions: Month is parsed and stored into a vector.
		static void tokenizeDateMonth(std::string tokenizeContent);

		//Preconditions:: month is parsed and UserInput is left with the rest of the content
		//Description: Does neccesary operations to check the type of task is it
		//Postconditions: type of task is identified and calls functions to tokenize the input time
		static void checkAllDayTask(std::string tokenizeContent); 
		
		//Preconditions:: UserInput is left with the rest of the content ( date and time ) 
		//Description: Does neccesary operations to parse the required content and check what kind of task it is
		//Postconditions: start time is parsed and stored into a vector and sends the remaining to be checked for multi task 
		static void tokenizeStartTime(std::string tokenizeContent);
		
				
		//Preconditions:: startTime is parsed and UserInput is left with the rest of the content 
		//Description: Does neccesary operations to check the type of task
		//Postconditions: type of task if identified and returns vector to logic if it is a deadline task
		static void checkDeadlineorTimed(std::string tokenizeContent);

					
		//Preconditions:: deadline is not considered as a possible type of task
		//Description: Does neccesary operations to check the remaining possible type of task
		//Postconditions: type of task if identified and call functions to tokenize end time
		static void checkTimedOrMulti(std::string tokenizeContent);

		//Preconditions:: task is identified as multiday task
		//Description: Does neccesary operations to parsed the required content
		//Postconditions: Day and month are parsed and stored into a vector and calls functions to tokenize the end time
		static void tokenizeMultiTaskDay(std::string tokenizeContent);
		static void tokenizeMultiTaskMonth(std::string tokenizeContent);

		//Preconditions:: all the other content have been parsed and userInput is left with only time to be parsed
		//Description: Does neccesary operations to parse the required content
		//Postconditions: time is parsed and stored into a vector wwhich will be returned to the logic
		static void tokenizeEndTime(std::string tokenizeContent);

		static void addEmptyString(int count);

};
#endif