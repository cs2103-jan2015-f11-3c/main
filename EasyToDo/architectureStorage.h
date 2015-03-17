#ifndef ARCHITECTURESTORAGE_H_
#define ARCHITECTURESTORAGE_H_

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct TASK {
	std:: string taskDescriptionList;
	std:: string taskTimeList;
};

class architectureStorage {
private:
	static std:: vector<TASK> masterTaskList;
	//static std:: vector<TASK> todayTaskList;
	// static std:: vector<TASK> upcomingTaskList;
public:
	architectureStorage();
	static TASK initializeTask(std:: string task, std:: string time);
	static void addToStorage(std:: string task, std:: string time);
	static std:: vector<std:: string> architectureStorage::retrieveMasterTaskList();
	// static std:: vector<std:: string> architectureStorage::retrieveTodayTaskList();
	// static std:: vector<std:: string> architectureStorage::retrieveUpcomingTaskList();
	static int findTotalNumberofTask();
	static void deleteFromStorage(int taskID);
	static void updateToStorage(int taskID, std:: string newTask, std:: string newTime);
	static bool isTaskDescriptionListEmpty();
	static void clearAllFromStorage();
	static std:: vector<TASK>::iterator findIterator(int taskID);
	static void sortStorage();
	bool compareByTime(const TASK& a, const TASK& b);
	// static void clearTodayFromStorage();
	// static void clearUpcomingFromStorage();
};
#endif