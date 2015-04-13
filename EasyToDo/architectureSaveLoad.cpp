#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureParser.h"
#include "architectureHistory.h"
#include "architectureSaveLoad.h"
#include "architectureBoost.h"
#include "architectureLogging.h"
#include <boost/filesystem.hpp>

std:: string architectureSaveLoad::_taskDescription;
std:: string architectureSaveLoad::_startDateTime;
std:: string architectureSaveLoad::_endTime;
std:: string architectureSaveLoad::_endDateTime;
std:: string architectureSaveLoad::_taskID;
std:: string architectureSaveLoad::_done;
std:: string architectureSaveLoad::_newTask;
std:: string architectureSaveLoad::_overdue;
std:: string architectureSaveLoad::_clash;
std:: vector<TASK> architectureSaveLoad::_tempVector;
std:: vector<TASK> architectureSaveLoad::_tempMasterVector;
std:: vector<TASK> architectureSaveLoad::_tempFloatingVector;

std:: string architectureSaveLoad::_fileName;
std:: string architectureSaveLoad::_directoryName;
std:: string architectureSaveLoad::_pathName;

const std:: string architectureSaveLoad::DEFAULT_PATHNAME = "C:\\Users\\Default\\EasyToDo.txt";
const std:: string architectureSaveLoad::DEFAULT_TEXTFILENAME = "EasyToDo.txt";
const std:: string architectureSaveLoad::STORAGELOCATION_FILENAME = "pathName.txt";
const std:: string architectureSaveLoad::DEFAULT_DIRECTORYNAME = "C:\\Users\\Default\\";
const std:: string architectureSaveLoad::MESSAGE_DEFAULT_SAVE = "Save directory and filename is set to default!";
const std:: string architectureSaveLoad::MESSAGE_SUCCESSFUL_SAVE = "Save directory and filename changed!";
const std:: string architectureSaveLoad::MESSAGE_FAILED_SAVE = "Sorry. Invalid directory! Save directory not changed";

const std:: string architectureSaveLoad::SEVERITY_LEVEL_INFO = "Info";

char architectureSaveLoad::transitory[MAXIMUM];

architectureSaveLoad::architectureSaveLoad() {
}

void:: architectureSaveLoad::initializePathName() {
	std:: ofstream initialize;
	initialize.open(STORAGELOCATION_FILENAME);
	initialize << DEFAULT_PATHNAME;
	initialize.close();
	return;
}

void architectureSaveLoad::saveToTextFile(std:: vector<TASK>& masterTaskList, std:: vector<TASK>& floatingTaskList) {
	std:: vector<TASK>::iterator iter;
	std:: ofstream saveFile(retrievePathName());
	std:: vector<TASK> taskList;
	
	taskList = combineVector(masterTaskList, floatingTaskList);

	for(iter = taskList.begin(); iter != taskList.end(); iter++) {
		saveFile << iter->taskDescriptionList;
		saveFile << std:: endl;

		saveFile << boost::posix_time::to_simple_string(iter->startDateTime).c_str();
		saveFile << std:: endl;

		saveFile << boost::posix_time::to_simple_string(iter->endTime).c_str();
		saveFile << std:: endl;

		saveFile << boost::posix_time::to_simple_string(iter->endDateTime).c_str();
		saveFile << std:: endl;

		saveFile << std:: to_string(iter->taskID);
		saveFile << std:: endl;

		saveFile << boost::lexical_cast<std::string>(iter->done);
		saveFile << std:: endl;

		saveFile << boost::lexical_cast<std::string>(iter->newTask);
		saveFile << std:: endl;
		
		saveFile << boost::lexical_cast<std::string>(iter->overdue);
		saveFile << std:: endl;

		saveFile << boost::lexical_cast<std::string>(iter->clash);

		if (iter != taskList.end() - 1) {
			saveFile << std:: endl;
		}		
	}
	saveFile.close();  
}

std:: string architectureSaveLoad::retrievePathName() {
	std:: ifstream read(STORAGELOCATION_FILENAME);
	std:: string line;
	getline(read,line);
	return line;
}

std:: vector<TASK> architectureSaveLoad::combineVector(std:: vector<TASK>& masterTaskList, std:: vector<TASK>& floatingTaskList) {
	std:: vector<TASK>::iterator iter;
	std:: vector<TASK> tempVector;

	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) {
		tempVector.push_back(*iter);
	}

	for(iter = floatingTaskList.begin(); iter != floatingTaskList.end(); iter++) {
		tempVector.push_back(*iter);
	}

	return tempVector;
}

bool architectureSaveLoad::loadFromTextFile() {
	std:: string buffer;
	std:: vector<std:: string> tempStringVector;

	std:: ifstream readFile(retrievePathName());
	
	if (!readFile.is_open()) { // if file doesn't exists
		architectureLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__ , std:: to_string(__LINE__), "file does not exist");
		std:: ofstream writeFile(retrievePathName());
		writeFile.close();
		return false;
	} else {
		while (std:: getline(readFile,buffer)) {
			tempStringVector.push_back(buffer);
		} 

		initializeTempVector(tempStringVector);
		differentiateVector(_tempVector);
		readFile.close();
		return true;
	}
}

void architectureSaveLoad::initializeTempVector(std:: vector<std:: string>& tempStringVector) {
	int size = tempStringVector.size();
	int i=0;
	TASK temp;

	while (i<size) {
		_taskDescription = tempStringVector[i];
		i++;
		_startDateTime = tempStringVector[i];
		i++;
		_endTime = tempStringVector[i];
		i++;
		_endDateTime = tempStringVector[i];
		i++;
		_taskID = tempStringVector[i];
		i++;
		_done = tempStringVector[i];
		i++;
		_newTask = tempStringVector[i];
		i++;
		_overdue = tempStringVector[i];
		i++;
		_clash = tempStringVector[i];
		i++;

		temp = initializeTaskFromString();
		_tempVector.push_back(temp);
	}
}

TASK architectureSaveLoad::initializeTaskFromString() {

	TASK temp;

	temp.taskDescriptionList = _taskDescription;

	ptime stringDateTime;
	boost::posix_time::time_input_facet *timeFacet = new boost::posix_time::time_input_facet;
    timeFacet->format("%Y-%b-%d %H:%M");
	std::istringstream iss(_startDateTime);
    iss.imbue(std::locale(std::locale::classic(), timeFacet));
	iss >> stringDateTime;
	temp.startDateTime = stringDateTime;

	temp.startTime = stringDateTime.time_of_day();

	ptime stringTimeDuration;
	boost::posix_time::time_input_facet *timeFacetEnd = new boost::posix_time::time_input_facet;
	timeFacetEnd->format("%Y-%b-%d %H:%M");
	std::istringstream ss(_endDateTime);
	ss.imbue(std::locale(std::locale::classic(), timeFacet));
	ss >> stringTimeDuration;
	temp.endDateTime = stringTimeDuration;

	temp.endTime = stringTimeDuration.time_of_day();

	temp.taskID =  atoi(_taskID.c_str());
	temp.done = boost::lexical_cast<bool>(_done);
	temp.newTask = boost::lexical_cast<bool>(_newTask);
	temp.overdue = boost::lexical_cast<bool>(_overdue);
	temp.clash = boost::lexical_cast<bool>(_clash);

	return temp;
}

void architectureSaveLoad::differentiateVector(std:: vector<TASK>& vector) {
	std:: vector<TASK>::iterator iter;

	for(iter = vector.begin(); iter != vector.end(); iter++) {
		if(iter->endTime.is_not_a_date_time() && iter->startDateTime.is_not_a_date_time()) {
			_tempFloatingVector.push_back(*iter);
		} else {
			_tempMasterVector.push_back(*iter);
		}
	}
	return;
}

std:: vector<TASK> architectureSaveLoad::passMasterTaskVector() {
	return _tempMasterVector;
}

std:: vector<TASK> architectureSaveLoad::passFloatingTaskVector() {
	return _tempFloatingVector;
}

std:: string architectureSaveLoad::changeSavingDirectoryAndFileName(std:: string directoryName, std:: string fileName) {
	try {
		if(directoryName == "" && fileName == "") {
			architectureLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__ , std:: to_string(__LINE__), MESSAGE_DEFAULT_SAVE + ": " + DEFAULT_PATHNAME);
			_pathName = DEFAULT_PATHNAME;
			changePathName(_pathName);
			throw MESSAGE_DEFAULT_SAVE;
		} else {
			initializeDefaultPathAndFileName(directoryName, fileName);
			_pathName =  concatenateString(_directoryName, _fileName);

			if (isPathNameValid(_directoryName)) { 
				architectureLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__ , std:: to_string(__LINE__), MESSAGE_SUCCESSFUL_SAVE + ": " + _pathName);
				changePathName(_pathName);
				throw MESSAGE_SUCCESSFUL_SAVE;
			} else {
				architectureLogging::logToFile(SEVERITY_LEVEL_INFO, __FILE__ , std:: to_string(__LINE__), MESSAGE_FAILED_SAVE + ": " + _pathName);
				throw MESSAGE_FAILED_SAVE;
			}
		}
	} catch (std:: string& exceptionMessage) {
		sprintf_s(transitory, exceptionMessage.c_str());
		return transitory;
	}
}

void architectureSaveLoad::changePathName(std:: string newPathName) {
	std:: ofstream file;
	file.open(STORAGELOCATION_FILENAME);
	file << newPathName;
	file.close();
}

void architectureSaveLoad::initializeDefaultPathAndFileName(std:: string directoryName, std:: string fileName) {
	if(fileName == "") {
		_fileName = DEFAULT_TEXTFILENAME;
	} else {
		_fileName = fileName;
	}

	if(directoryName == "") {
		_directoryName = DEFAULT_DIRECTORYNAME;
	} else {
		_directoryName = directoryName;
	} 
	return;
}

bool architectureSaveLoad::isPathNameValid(std:: string directoryName) {
	if (boost::filesystem::exists(directoryName)) { 
		return true;
	} else {
		return false;
	}
}

std:: string architectureSaveLoad::concatenateString(std:: string _directoryName, std:: string _fileName) {
	return _directoryName + _fileName;
}
