#ifndef ARCHITECTURESAVELOAD_H_
#define ARCHITECTURESAVELOAD_H_
#include <sstream>
#include <fstream>

class architectureSaveLoad {
private:
	static std:: string _taskDescription;
	static std:: string _startDateTime;
	static std:: string _endTime;
	static std:: string _endDateTime;
	static std:: string _taskID;
	static std:: string _done;
	static std:: string _newTask;
	static std:: string _overdue;
	static std:: string _clash;
	static std:: vector<TASK> _tempVector;
	static std:: vector<TASK> _tempMasterVector;
	static std:: vector<TASK> _tempFloatingVector;
	static std:: string _fileName;
	static std:: string _directoryName;
	static std:: string _pathName;
	
	static const std:: string DEFAULT_PATHNAME;
	static const std:: string DEFAULT_TEXTFILENAME;
	static const std:: string DEFAULT_DIRECTORYNAME;
	static const std:: string MESSAGE_DEFAULT_SAVE;
	static const std:: string MESSAGE_SUCCESSFUL_SAVE;
	static const std:: string MESSAGE_FAILED_SAVE;
	
	static const int MAXIMUM = 255;
	static char transitory[MAXIMUM];
public:
	architectureSaveLoad();
	static std:: string retrievePathName();
	static void saveToTextFile(std:: vector<TASK>& masterTaskList, std:: vector<TASK>& floatingTaskList);
	static std:: vector<TASK> combineVector(std:: vector<TASK>& masterTaskList, std:: vector<TASK>& floatingTaskList);
	static bool loadFromTextFile();
	static std:: vector<TASK> passMasterTaskVector();
	static std:: vector<TASK> passFloatingTaskVector();
	static TASK initializeTaskFromString();
	static void differentiateVector(std:: vector<TASK>& vector);
	static std:: string changeSavingDirectoryAndFileName(std:: string directoryName, std:: string fileName);
	static void changePathName(std:: string newPathName);
	static void initializeDefaultPathAndFileName(std:: string directoryName, std:: string fileName);
	static bool isPathNameValid();
	// static void writeArchivedFile();
};
#endif
