#ifndef ARCHITECTURESTORAGE_H_
#define ARCHITECTURESTORAGE_H_

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/time_zone_base.hpp"
#include "boost/date_time/local_time/local_time.hpp"

using namespace boost::posix_time;
using namespace boost::gregorian;
using boost::posix_time::ptime;
using boost::local_time::local_time_input_facet;

// deadline: add meet ivy on 14 April from 14:00 - 1800 
// floating: add meet ivy
// timed: add meet ivy on 14 april at 1400
struct TASK {
	std:: string taskDescriptionList;
	//std:: string taskDateList;
	//std:: string taskStartTimeList;
	//std:: string taskEndTimeList;
	//date d;
	ptime startDateTime; //time t2(date(2002,Jan,10), hours(1)+nanosec(5));
	time_duration endTime;
	int taskID;
};

class architectureStorage {
private:
	static std:: vector<TASK> masterTaskList;
	//static std:: vector<TASK> floatingTaskList; //Task that do not have a specific deadline
	//static std:: vector<TASK> timedTaskList; //Task that has specific timeframe
	//static std:: vector<TASK> deadlineTaskList; //Task that has a due date or target time
	//static std:: vector<TASK> todayTaskList;
	//static std:: vector<TASK> upcomingTaskList;
public:
	architectureStorage();
	static int stringToInt(std:: string input);
	static void updateTaskID();
	static TASK initializeTask(std:: string _contentDescripton, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes);
	static void addToMasterStorage(std:: string task, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes);
	static void addToFloatingStorage(std:: string task, std:: string date, std:: string startTime, std:: string endTime);
	static void addToDeadlineStorage(std:: string task, std:: string date, std:: string startTime, std:: string endTime);
	static void addToTimedStorage(std:: string task, std:: string date, std:: string startTime, std:: string endTime);
	static std:: vector<std:: string> architectureStorage::retrieveMasterTaskList();
	// static std:: vector<std:: string> architectureStorage::retrieveTodayTaskList();
	// static std:: vector<std:: string> architectureStorage::retrieveUpcomingTaskList();
	static int findTotalNumberofTask();
	static void deleteFromStorage(int taskID);
	static void updateToStorage(int taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes);
	static bool isTaskDescriptionListEmpty();
	static void updateToStorage(int taskID, std:: string newTask, std:: string newDate, std:: string newStartTime, std:: string newEndTime);
	static bool isMasterTaskListEmpty();
	static void clearAllFromStorage();
	static std:: vector<TASK>::iterator findIterator(int taskID);
	static void sortStorage();
	// static void clearTodayFromStorage();
	// static void clearUpcomingFromStorage();
};
#endif