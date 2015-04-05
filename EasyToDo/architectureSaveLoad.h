#ifndef ARCHITECTURESAVELOAD_H_
#define ARCHITECTURESAVELOAD_H_
#include <sstream>
#include <fstream>

class architectureSaveLoad {
private:
	static std:: string _taskDescription;
	static std:: string _startDateTime;
	static std:: string _endTime;
	static std:: string _taskID;
	static std:: string _done;
public:
	architectureSaveLoad();
	static void saveToTextFile(std:: vector<TASK>& masterTaskList);
	static std:: vector<TASK> loadFromTextFile();
	static TASK initializeTaskFromString(std:: string _taskDescription, std:: string _startDateTime, std:: string _endTime, std:: string _taskID, std:: string _done);
	static void pushToStorage(TASK task);
};
#endif
