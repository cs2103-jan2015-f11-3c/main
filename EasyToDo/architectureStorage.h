#ifndef ARCHITECTURESTORAGE_H_
#define ARCHITECTURESTORAGE_H_

#include <vector>
#include <string>
#include <sstream>

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
	static void addToStorage(std:: string task, std:: string time);
	static std:: vector<std:: string> architectureStorage::retrieveMasterTaskList();
	// static std:: vector<std:: string> architectureStorage::retrieveTodayTaskList();
	// static std:: vector<std:: string> architectureStorage::retrieveUpcomingTaskList();
	static int findTotalNumberofTask();
	static void deleteFromStorage(int taskID);
	static bool isTaskDescriptionListEmpty();
	static void clearAllFromStorage();
	// static void clearTodayFromStorage();
	// static void clearUpcomingFromStorage();
};
#endif