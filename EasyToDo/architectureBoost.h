#ifndef ARCHITECTUREBOOST_H_
#define ARCHITECTUREBOOST_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <boost/date_time.hpp>
#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"


using namespace boost::posix_time;
using namespace boost::gregorian;

class architectureBoost {
private:
	static const std:: string SEVERITY_LEVEL_INFO;
public:
	architectureBoost();
	
	//Preconditions:: Task is stored in masterstorage
	//Description: Does neccesary operations to identify the type of task acorrding to date	
	//Postconditions: Task is stored in either today or upcoming vector according to their date
	static void sortTodayUpcoming(std:: vector<TASK>& masterTaskList);
	static date retrieveDateToday();
	static bool isValidTodayTask(days dayDifference);

	//Preconditions:: Task is stored in either today or upcoming storage
	//Description: Does neccesary operations to sort the task in chronological order
	//Postconditions: Tasks are sorted in chronological order within the vector
	static void sortWithinTodayUpcoming(std:: vector<TASK>& todayUpcomingTASKList);
	
	//Preconditions:: Task is stored in either today
	//Description: Does neccesary operations to check task's date against today's date and time
	//Postconditions: Task are identified as overdue or not overdue
	static void checkOverdueTask(std:: vector<TASK>& todayTaskList);
	static bool isTaskOverdue(days dayDifference);

	//Preconditions:: Task is stored in either today or upcoming storage
	//Description: Does neccesary operations to check if time clashes with other task's time
	//Postconditions: Task are identified as clashed or not clashed
	static TASK checkClashTask(TASK temp, std:: vector<TASK>& taskList);
};
#endif
