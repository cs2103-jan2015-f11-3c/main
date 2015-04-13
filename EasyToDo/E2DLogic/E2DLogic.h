// @author A0111378J
#ifndef E2DLOGIC_H_
#define E2DLOGIC_H_

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
class E2DLogic
{
private:
	static const std:: string STRING_BLANK;
	static const std:: string SEVERITY_LEVEL_WARNING;
	static const std:: string SEVERITY_LEVEL_INFO;
	static const std:: string SEVERITY_LEVEL_ERROR;
	static const std:: string MESSAGE_LOG_INVALID;
	static const std:: string MESSAGE_END_USAGE;
	static const std:: string COMMAND_INVALID;
	static const std:: string COMMAND_ADD;
	static const std:: string COMMAND_SHORTCUT_ADD;
	static const std:: string COMMAND_DELETE;
	static const std:: string COMMAND_SHORTCUT_DELETE;
	static const std:: string COMMAND_CLEAR;
	static const std:: string COMMAND_SHORTCUT_CLEAR;
	static const std:: string COMMAND_EXIT;
	static const std:: string COMMAND_UNDO;
	static const std:: string COMMAND_DONE;
	static const std:: string COMMAND_SHORTCUT_DONE;
	static const std:: string COMMAND_UPDATE;
	static const std:: string COMMAND_SHORTCUT_UPDATE;
	static const std:: string COMMAND_SAVE;
	static const std:: string COMMAND_FILTER;
	static const std:: string COMMAND_SHORTCUT_FILTER;
	static const std:: string COMMAND_DISPLAY;
	static const std:: string COMMAND_SHORTCUT_DISPLAY;
	static const std:: string COMMAND_SEARCH;
	static const std:: string COMMAND_SHORTCUT_SEARCH;
	static const std:: string COMMAND_TODAY;
	static const std:: string COMMAND_UPCOMING;
	static const std:: string COMMAND_FLOAT;
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
	static const std:: string MESSAGE_DISPLAY;
	static const std:: string MESSAGE_STORAGEEMPTY;
	static const std:: string MESSAGE_TODAY;
	static const std:: string MESSAGE_UPCOMING;
	static const std:: string MESSAGE_FLOATING;
	static const std:: string MESSAGE_ALL;
	static const std:: string MESSAGE_UNDOINVALID;
	static const std:: string DEFAULT_YEAR;

	static std:: string _command;
	static std:: string _content;
	static std:: string _contentDescription;
	static std:: string _contentStartDay;
	static std:: string _contentStartMonth;
	static std:: string _contentStartHours;
	static std:: string _contentStartMinutes;
	static std:: string _contentEndDay;
	static std:: string _contentEndMonth;
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
	E2DLogic(void);
	~E2DLogic(void);

	enum CommandType { 
		ADD, EXIT, DEL, INVALID, CLEAR, UPDATE, UNDO, DONE, SAVE, FILTER, DISPLAY, SEARCH
	};
	enum Months { 
		JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, NOTVALID
	};

	enum DateType {
		TODAY, UPCOMING, FLOAT, UNVALID
	};

	// this function is called by the parser to push the vector of the tokenized materials to vector
	// Pre: None. Basically it will tokenize everything
	// Post:: initiate determineCommand();
	static void pushParserVector(std:: vector<std:: string>& temp);

	// takes in a parser input to interpret the user input and initiate the action according to the first word in the vector 
	// Pre : parser will tokenize and pass me a vector of all the individual details which is in turn dependent from the user input from UI
	// Post : returns a feedback message whether each command was executed successfully which is retrieved from executeCommand which will be stored into 
	// architectureInputFeedback which will be return to the UI
	static void determineCommand();

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
	static std:: string addTask(std:: string _contentDescription, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
								std:: string _contentStartMinutes, std:: string _contentEndDay, std:: string _contentEndMonth, std:: string _contentEndHours, std:: string _contentEndMinutes);
	static bool isDateValid(std:: string contentDay, std:: string contentMonth);
	static Months determineMonthType(std:: string parserInput);
	static int stringToInteger(std:: string input);
	static std:: string concatenateString(std:: vector<std:: string>& parserVector);
	static std:: string trimTrailingSpaces(std:: string buffer);
	static bool isTimedTimeValid(std:: string startHour, std:: string startMin, std::string endHour, std::string endMin );
	static bool isMultiTimeValid(std:: string startDay,std:: string startMonth,std:: string startHour,std:: string startMin,
													std:: string endDay,std:: string endMonth,std:: string endHour, std:: string endMin);
	static bool isDeadlineTimeValid(std:: string startHour, std:: string startMin);	

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
	static std:: string updateTask(std:: string taskType, std:: string taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
									std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes);
	
	// this function allows the users to undo the previous action
	// Pre:: _command is undo, or the user type ctrl-z 
	// Post: undo the previous action and return the specific feedback message 
	static std:: string undoTask();

	// this function allow users to strike out the tasks they have completed
	// Pre: _command is done, taskType is valid, taskID is valid
	// Post: access storage to change the bool variable of the task strcuture
	static std:: string doneTask(std:: string taskType, std:: string taskID);

	// this function allow the users to filter the tasks out according to the intended date. on top of that, it will display tasks that are expiring in two days time as well
	// Pre: tasklist must not be empty
	// Post: filter the task
	static std:: string filterTask(std:: string day, std:: string month);

	// this is sort of the undo function of filter and search
	// Pre: tasklist must not be empty
	// Post: display all the tasks
	static std:: string displayTask();

	// this function allow the users to search the tasks according to the intended content description
	// Pre: tasklist must not be empty
	// Post:: search the task
	static std:: string searchTask(std:: string searchContent);
};

#endif

