#ifndef ARCHITECTURESTORAGE_H_
#define ARCHITECTURESTORAGE_H_

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <boost/date_time.hpp>
#include <assert.h>

using namespace boost::posix_time;
using namespace boost::gregorian;

// Timed: add meet ivy on 14 April from 14:00 to 18:00 
// (MISC)Floating: add meet ivy
// Deadline: add meet ivy on 14 april at 1400
struct TASK {
	std:: string taskDescriptionList;
	ptime startDateTime; 
	time_duration startTime;
	ptime endDateTime;
	time_duration endTime;
	int taskID;
	bool done; // check if the task is done. initialized as false
	bool newTask; // check if the task is recently added to EasyToDo to enable us to highlight the newest task added. initialized as true
	bool overdue; // check if the task is overdue else highlight in red. initialized as false.
	bool clash; // check if there is any task that have timeline that clashes with each other. initialized as false.
};

// this class, it where after the logic has processed the user's intention, execute the respective action and make changes to the variable
// stored in this class
class architectureStorage {
private:
	static std:: vector<TASK> masterTaskList; // stores both timed and deadline task
	static std:: vector<TASK> floatingTaskList; 
	static std:: vector<TASK> todayTaskList;
	static std:: vector<TASK> upcomingTaskList;
	static std:: vector<TASK> tempFloatingTaskList;

	static const std:: string DEFAULT_HOURS;
	static const std:: string DEFAULT_MINUTES;
	static const std:: string STRING_BLANK;

	static const std:: string MESSAGE_FILTER_UNSUCCESSFUL;
	static const std:: string MESSAGE_FILTER_SUCCESSFUL;
	static const std:: string MESSAGE_SEARCH_UNSUCCESSFUL;
	static const std:: string MESSAGE_SEARCH_SUCCESSFUL;

	static const int MAX = 255;
	static char buffer[MAX];
public:
	architectureStorage();
	// the GUI will call this function for theindividual taskType column to get the numbering for the task to be displayed
	// Pre: None
	// Post: the taskID in the structure of the task is assigned with a number
	static void updateTaskID(std:: vector<TASK>& input);

	// the UI will actually call this function to retrieve the saved tasks in the textfile to initialise the taskLists
	// Pre: None 
	// Post: if true, the UI will pop out a window saying Welcome back to EasyToDo for repeated user and display whatever tasks saved previously
	// if false, the UI will pop out a window saying welcome to easyToDo for first time user. 
	static bool loadProgram();

	// this function call for supporting functions to initialise the task and add them into their respective task type
	// deadline and timed tasks are added to masterTaskList while floating are added to floating tasklist
	// the tasks in masterTaskList are then sorted into their individual taskList using Boost::sortTodayUpcoming
	// before adding any new task, it will call updateNewTask to change the bool of new to false for GUI to recognise
	// Pre: task != "" 
	// Post: Save the program after every action. 
	static void addToMasterStorage(std:: string _contentDescripton, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
											 std:: string _contentStartMinutes, std:: string _contentEndDay, std:: string _contentEndMonth, std:: string _contentEndHours, std:: string _contentEndMinutes);
	static void updateNewTask();
	static TASK initializeFloatingTask(std:: string _contentDescription);
	static TASK initializeDeadlineTask(std:: string _contentDescription, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
										std:: string _contentStartMinutes);
	static TASK initializeTimedTask(std:: string _contentDescription, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
											  std:: string _contentStartMinutes, std:: string _contentEndDay, std:: string _contentEndMonth, std:: string _contentEndHours, std:: string _contentEndMinutes);
	static int stringToInt(std:: string input);

	// if the taskType is today or upcoming, this function calls for deleteTask to find the task in mastertasklit and remove it
	// and Boost::sortTodayUpcoming to update the today and upcoming TaskList
	// if the taskType is floating, it will simply remove the task from floatingtasklist
	// Pre: valid iter
	// Post: save program after every action
	static void deleteTodayFromStorage(std:: vector<TASK>::iterator iter);
	static void deleteUpcomingFromStorage(std:: vector<TASK>::iterator iter);
	static void deleteFloatingFromStorage(std:: vector<TASK>::iterator iter);
	static void deleteTask(TASK& input);
	
	// this function clears all the contents of the vector<TASK> in both masterTaskList and floatingTaskList
	// Pre: None
	// Post:: save program after every action
	static void clearAllFromStorage();
	// this function replaces the masterTaskList with the upcomingTaskList to remove all the todayTasks
	static void clearTodayFromStorage();
	// Similarly, this function replaces the masterTaskList with the todayTaskList to remove all the UpcomingTasks
	static void clearUpcomingFromStorage();
	// this function clear all the contents of the floatingTaskList
	static void clearFloatingFromStorage();

	// for update function, i will store two previous states instead of one[add, delete] 
	// thus the first one you pop from the stack "previousStateStack" would be the one you need to delete
	// and the second one would be the one you need to add back cause of LIFO
	// this function basically uses the addtoMasterStorage and deleteTask to execute update
	// this allow the user change one tasktype to another
	// Pre: pre-conditions are already fulfilled in logic
	// Post: Save the program after every action. 
	static void updateToTodayStorage(int taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
									std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes);
	static void updateToUpcomingStorage(int taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
									std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes);
	static void updateToFloatingStorage(int taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
									std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes);
	static std:: vector<TASK>::iterator findTodayIterator(int taskID);
	static std:: vector<TASK>::iterator findUpcomingIterator(int taskID);
	static std:: vector<TASK>::iterator findFloatingIterator(int taskID);

	// this group of functions supports the functions in architectureHistory to execute the command undo
	// Pre: the stack sotring the previousAction is not empty
	// Post: execute the reverse action and save the program
	static void undoDelete(TASK& input);
	static void undoAdd(TASK& input);
	static void undoClear(std:: vector<TASK>& previousTodayUpcomingTaskList, std:: vector<TASK>& previousFloatingTaskList);
	static void undoDone(TASK& input);

	// this group of functions execute the user intention to strke out completed tasks. they change the bool done in the task struct 
	// Pre: valid iter
	// Post: change the bool from false to true and save program
	static void doneTodayTask(std:: vector<TASK>::iterator iter);
	static void doneUpcomingTask(std:: vector<TASK>::iterator iter);
	static void doneFloatingTask(std:: vector<TASK>::iterator iter);

	// this group of functions support the GUI's functions
	static std:: vector<TASK> retrieveTodayTaskList();
	static std:: vector<TASK> retrieveUpcomingTaskList();
	static std:: vector<TASK> retrieveFloatingTaskList();
	
	// this group of functions support architectureLogic's function to verify taskID
	static int findTotalNumberofTodayTask();
	static int findTotalNumberofUpcomingTask();
	static int findTotalNumberofFloatingTask();
	
	// this group of functions support architectureLogic's function for clearTask
	static bool isMasterTaskListEmpty();
	static bool isTodayTaskListEmpty();
	static bool isUpcomingTaskListEmpty();
	static bool isFloatingTaskListEmpty();

	// this group of functions support architectureBoost::sortTodayUpcoming
	// to differentiate the today and upcoming tasks
	// Pre: None
	// Post: masterTaskList will have a copy of all the today and upcoming tasks and the respective taskLists will contain their own tasks
	static void storeTodayTask(TASK temp);
	static void storeUpcomingTask(TASK temp);
	static void clearTodayTaskList();
	static void clearUpcomingTaskList();
	// when the tasks are differentiated into the task, this function is called to check if it clashes with any of the stored tasks
	// in the same taskList to update the bool clash
	// Pre: none
	// Post: check the clash period of the incoming task with all the stored tasks
	static void updateClashStatus(TASK& task);

	// this function calls save function in architectureSaveLoad to save the masterTaskList and floatingTextList to external text file
	// Pre: None
	// Post: according to the pathname stated in the PathName.txt(default or specify by user), the tasks are stored in the text file
	static void saveProgram();

	// this function allows the user to filter the task according to the dates. to aid jim, we will display tasks that are due in two days time from the intened date 
	// to give him ample time to complete his time 
	// Pre: the day and month must be valid inputs and the storage cannot be empty
	// Post: return a feedback string and input the tasks in the indivdual tasktype box
	static std:: string filterTaskInStorage(std:: string day, std:: string month);
	static std:: string incrementDay(std:: string day); 
	static bool areDatesFound(date d, date d1, date d2, TASK& task);
	static date getTodayDate();

	// this function allow the user to display all the task once again if filter and search are successful
	// Pre: none
	// Post: display all the tasks in masterTaskList and floatingTaskList
	static void displayTaskInStorage();

	// this function allow the users to search through all the tasks for the intended content description
	// Pre: storage must not be empty
	// Post: return all the tasks that contain the user string in their individual boxes 
	static std:: string searchContentInStorage(std:: string& searchContent);
	static std:: vector<TASK> architectureStorage::searchInTodayTaskList(std::string& searchContent);
	static std:: vector<TASK> architectureStorage::searchInUpcomingTaskList(std::string& searchContent);
	static std:: vector<TASK> architectureStorage::searchInFloatingTaskList(std::string& searchContent);

	// integration testing function
	static std:: vector<TASK> retrieveMasterTaskList();
};
#endif