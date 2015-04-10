#ifndef ARCHITECTURELOGIC_H_
#define ARCHITECTURELOGIC_H_

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <boost/algorithm/string.hpp>

#undef DELETE

// to do list requires basic support of storage/retrieval of info, display of info to user and updating 
// existing info. thus to reduce coupling from the innate nature of interlinkedness, we separated the
// architecture to 8 different components of UI, InputFeedBack, Parser, Logic, Storage, History, SaveLoad, Boost

// architectureLogic is responsible for all the "thinking" in the program
// being the facade of this program, it will separate the user from the storage variables
class architectureLogic {
private:
	static const std:: string COMMAND_INVALID;
	static const std:: string COMMAND_ADD;
	static const std:: string COMMAND_DELETE;
	static const std:: string COMMAND_CLEAR;
	static const std:: string COMMAND_EXIT;
	static const std:: string COMMAND_UNDO;
	static const std:: string COMMAND_DONE;
	static const std:: string COMMAND_UPDATE;
	static const std:: string COMMAND_SAVE;
	static const std:: string COMMAND_TODAY;
	static const std:: string COMMAND_UPCOMING;
	static const std:: string COMMAND_MISC;
	static const std:: string MESSAGE_ADD;
	static const std:: string MESSAGE_INVALID;
	static const std:: string MESSAGE_NOTFOUND;
	static const std:: string MESSAGE_DELETETODAY;
	static const std:: string MESSAGE_DELETEUPCOMING;
	static const std:: string MESSAGE_DELETEFLOATING;
	static const std:: string MESSAGE_DONETODAY;
	static const std:: string MESSAGE_DONEUPCOMING;
	static const std:: string MESSAGE_DONEFLOATING;
	static const std:: string MESSAGE_CLEARALL;
	static const std:: string MESSAGE_CLEARTODAY;
	static const std:: string MESSAGE_CLEARUPCOMING;
	static const std:: string MESSAGE_CLEARFLOATING;
	static const std:: string MESSAGE_UPDATETODAY;
	static const std:: string MESSAGE_UPDATEUPCOMING;
	static const std:: string MESSAGE_UPDATEFLOATING;
	static const std:: string MESSAGE_STORAGEEMPTY;
	static const std:: string MESSAGE_TODAY;
	static const std:: string MESSAGE_UPCOMING;
	static const std:: string MESSAGE_FLOATING;
	static const std:: string MESSAGE_ALL;
	static const std:: string MESSAGE_UNDOINVALID;

	static std:: string _command;
	static std:: string _content;
	static std:: string _contentDescription;
	static std:: string _contentDay;
	static std:: string _contentMonth;
	static std:: string _contentStartHours;
	static std:: string _contentStartMinutes;
	static std:: string _contentEndHours;
	static std:: string _contentEndMinutes;
	static std:: string _newTask;
	static std:: string _newTime;
	static std:: string _taskType;
	static std:: string _taskID;
	
	static const int MAX = 255;
	static char buffer[MAX];
	static std:: vector<std:: string> parserVector;
public:
	enum CommandType { 
		ADD, EXIT, DELETE, INVALID, CLEAR, UPDATE, UNDO, DONE, SAVE
	};
	enum Months { 
		JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, NOTVALID
	};

	enum DateType {
		TODAY, UPCOMING, MISC, UNVALID
	};

	architectureLogic();

	// this function is called by the parser to push the vector of the tokenized materials to vector
	// Pre: None. Basically it will tokenize everything
	// Post:: initiate determineCommand();
	static void pushParserVector(std:: vector<std:: string>& temp);

	// takes in a parser input to interpret the user input and initiate the action according to the first word in the vector 
	// Pre : parser will tokenize and pass me a vector of all the individual details which is in turn dependent from the user input from UI
	// Post : returns a feedback message whether each command was executed successfully which is retrieved from executeCommand which will be stored into 
	// architectureInputFeedback which will be return to the UI
	static std:: vector<std:: string> determineCommand();

	//this function intialize the string to the glpbal variables in a chronological order according to the vector passed from the parser
	//Pre : the first word in the vector string cannot be "invalid"
	//Post : None
	static void initializeCommand();

	// this function execute the individual command according to the _command which is initialized from the first word
	// Pre: valid function will result in the respective feedback. else unrecognised _command will result in invalid message
	// Post: return a feedback message
	static std:: string executeCommand();

	// this function allow for a flexible input where user may accidentally key in command with different casing supported by the function, isValidCommand
	// Pre: None
	// Post: return a enum commandType
	static CommandType determineCommandType(std:: string commandAction);
	static bool isValidCommand(const std:: string& str1, const std:: string& str2);

	// this function passes the global variables to the next architecture, storage, for them to be initialized into a task for storage
	// Pre: the _command is "add"
	// Post: cocantenate the tokenized variables to return a string of the details of the task added
	// the following group of functions support the add function
	static std:: string addTask(std:: string _contentDescription, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, 
								std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes);
	static bool architectureLogic::isDateValid(std:: string contentDay, std:: string contentMonth);
	static Months architectureLogic::determineMonthType(std:: string parserInput);
	static int stringToInteger(std:: string input);
	static std:: string concatenateString(std:: vector<std:: string>& parserVector);
	static std:: string trimTrailingSpaces(std:: string buffer);
	static bool architectureLogic::isTimedTimeValid(std:: string startHour, std:: string startMin, std::string endHour, std::string endMin );
	static bool architectureLogic::isDeadlineTimeValid(std:: string startHour, std:: string startMin);	

	// this function differentiate the different datatype that is required to delete and remove from the storage
	// Pre: the _command is delete, _taskType is a valid string(today, upcoming, misc) and valid taskID in the respective taskType
	// Post: return a successful deleted string message else if the task is deleted and access storage to execute the delete
	// the following group of functions support the delete function
	static std:: string deleteTask(std:: string taskType, std:: string taskID);
	static DateType determineDateTypeAction(std:: string commandAction);
	static bool isTodayTaskIDValid(int taskID);
	static bool isUpcomingTaskIDValid(int taskID);
	static bool isFloatingTaskIDValid(int taskID);

	// this function clear all the storage memory specified by the user
	// Pre: the _command is clear and the taskType is valid
	// Post: access storage to delete all the respective tasks in the taskType
	// the following group of functions support the clear function
	static std:: string clearTask(std:: string content);
	static bool isMasterTaskListEmpty();
	static bool isTodayTaskListEmpty();
	static bool isUpcomingTaskListEmpty();
	static bool isFloatingTaskListEmpty();

	// this function edit the details specified by the user. it uses the current create a new task and replace the current task by
	// using the current add and delete function
	// Pre: _command is update, taskType is valid, taskId is valid, followed by a valid task content
	// Post: access storage and delete the previous task and add in the new task
	static std:: string updateTask(std:: string taskType, std:: string taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes);
	
	// this function allows the users to undo the previous action
	// Pre:: _command is undo, or the user type ctrl-z 
	// Post: undo the previous action and return the specific feedback message 
	static std:: string undoTask();

	// this function allow users to strike out the tasks they have completed
	// Pre: _command is done, taskType is valid, taskID is valid
	// Post: access storage to change the bool variable of the task strcuture
	static std:: string doneTask(std:: string taskType, std:: string taskID);
};
#endif