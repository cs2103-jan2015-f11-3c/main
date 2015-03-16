#ifndef ARCHITECTURESTORAGE_H_
#define ARCHITECTURESTORAGE_H_

#include <vector>
#include <string>
#include <sstream>

class architectureStorage {
private:
	static std:: vector<std:: string> taskDescriptionList;
	static std:: vector<std:: string> taskTimeList;
public:
	architectureStorage();
	static void addToStorage(std:: string task, std:: string time);
	static std:: vector<std:: string> architectureStorage::retrieveVector();
	static int findTotalNumberofTask();
	static void deleteFromStorage(int taskID);
	static bool isTaskDescriptionListEmpty();
};
#endif