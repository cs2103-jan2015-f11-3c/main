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
	static std:: string _newTask;
	static std:: string _overdue;
	static std:: string _clash;
	static std:: vector<TASK> _tempVector;
public:
	architectureSaveLoad();
	static void saveToTextFile(std:: vector<TASK>& masterTaskList);
	static bool loadFromTextFile();
	static std:: vector<TASK> passTaskVector();
	static TASK initializeTaskFromString();
	static void pushToStorage(TASK task);
};
#endif
