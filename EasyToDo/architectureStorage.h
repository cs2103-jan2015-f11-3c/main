#ifndef ARCHITECTURESTORAGE_H_
#define ARCHITECTURESTORAGE_H_

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct TASK {
	std:: string taskDescriptionList;
	std:: string taskDateList;
	std:: string taskStartTimeList;
	std:: string taskEndTimeList;
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
	static void updateTaskID();
	static TASK initializeTask(std:: string task, std:: string date, std:: string startTime, std:: string endTime);
	static void addToMasterStorage(std:: string task, std:: string date, std:: string startTime, std:: string endTime);
	static void addToFloatingStorage(std:: string task, std:: string date, std:: string startTime, std:: string endTime);
	static void addToDeadlineStorage(std:: string task, std:: string date, std:: string startTime, std:: string endTime);
	static void addToTimedStorage(std:: string task, std:: string date, std:: string startTime, std:: string endTime);
	static std:: vector<std:: string> architectureStorage::retrieveMasterTaskList();
	// static std:: vector<std:: string> architectureStorage::retrieveTodayTaskList();
	// static std:: vector<std:: string> architectureStorage::retrieveUpcomingTaskList();
	static int findTotalNumberofTask();
	static void deleteFromStorage(int taskID);
	static void updateToStorage(int taskID, std:: string newTask, std:: string newDate, std:: string newStartTime, std:: string newEndTime);
	static bool isTaskDescriptionListEmpty();
	static void clearAllFromStorage();
	static std:: vector<TASK>::iterator findIterator(int taskID);
	static void sortStorage();
	bool compareByTime(const TASK& a, const TASK& b);
	// static void clearTodayFromStorage();
	// static void clearUpcomingFromStorage();
};
#endif