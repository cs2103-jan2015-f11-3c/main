#ifndef ARCHITECTURESAVELOAD_H_
#define ARCHITECTURESAVELOAD_H_
#include <sstream>
#include <fstream>

// this class execute writing and reading tasks details into external textfile as well as the capability to enable user to specify
// the file directory and file name 
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
	static const std:: string STORAGELOCATION_FILENAME;
	static const std:: string MESSAGE_DEFAULT_SAVE;
	static const std:: string MESSAGE_SUCCESSFUL_SAVE;
	static const std:: string MESSAGE_FAILED_SAVE;
	
	static const int MAXIMUM = 255;
	static char transitory[MAXIMUM];
public:
	architectureSaveLoad();
	
	// this function is called by architectureStorage when there isn't an existing pathname to store a default pathname
	// in other words, the user did not specify a save file directory and filename before he starts to input tasks onto the commandline
	// as such this function create a pathname.txt when the program fail to load from an existing file
	// Pre: None
	// Post: a pathName.txt created in the UI folder in the project file which contains the default pathname 
	// "C:\\Users\\Choo\\Desktop\\EasyToDo.txt"
	static void initializePathName();

	// this function is called every single time an action is executed successfully in the logic
	// this duplicates the tasks in the two vectors(combined by the function 'combineVector') 
	// and write them on the textfile at the specific path and filename retrieved from PathName.txt
	// Pre: None
	// Post: txt file created in the specific directory 
	static void saveToTextFile(std:: vector<TASK>& masterTaskList, std:: vector<TASK>& floatingTaskList);
	static std:: string retrievePathName();
	static std:: vector<TASK> combineVector(std:: vector<TASK>& masterTaskList, std:: vector<TASK>& floatingTaskList);

	// this function retrieve the tasks details from the path location as stated in the pathName.txt 
	// utilising the supporting function, initializeTempVector, to intialize individual tasks 
	// using the supporting function, differtiateVector, will separate the tasks into their respective vector(taskList)
	// Pre: it will only read if the file exist in the path location
	// Post: allow for pre-exit vectors to be available again
	static bool loadFromTextFile();
	static void initializeTempVector(std:: vector<std:: string>& tempStringVector);
	static TASK initializeTaskFromString();
	static void differentiateVector(std:: vector<TASK>& vector);

	// this two functions allow storage to call them to retrieve the duplicated copies of vector<TASK> created according to the textfile
	// Pre: text file must exist and must not be empty
	// Post: the masterTaskList and FloatingTaskList will be initialized according to the architectureSaveLoad
	static std:: vector<TASK> passMasterTaskVector();
	static std:: vector<TASK> passFloatingTaskVector();
	
	// this function allow the user to have the flexible to specify his own path location and filename
	// if the input is simply 'save', the file directory and filename will be set to default
	// or any of the input is determined to be empty, it will be set to empty
	// basically, i have an external default pathname.txt that will store the pathname which will either be default or specified by the user
	// using the function, changePathName, we change the path location in the pathName.txt which save and load will retrieve from
	static std:: string changeSavingDirectoryAndFileName(std:: string directoryName, std:: string fileName);
	static void changePathName(std:: string newPathName);
	static void initializeDefaultPathAndFileName(std:: string directoryName, std:: string fileName);
	static bool isPathNameValid(std:: string directoryName);
	static std:: string concatenateString(std:: string _directoryName, std:: string _fileName);
};
#endif
