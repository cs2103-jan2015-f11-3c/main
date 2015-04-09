#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureParser.h"
#include "architectureHistory.h"
#include "architectureSaveLoad.h"
#include "architectureBoost.h"
<<<<<<< HEAD
#include <boost/filesystem.hpp>
=======
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861

std:: string architectureSaveLoad::_taskDescription;
std:: string architectureSaveLoad::_startDateTime;
std:: string architectureSaveLoad::_endTime;
<<<<<<< HEAD
std:: string architectureSaveLoad::_endDateTime;
=======
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861
std:: string architectureSaveLoad::_taskID;
std:: string architectureSaveLoad::_done;
std:: string architectureSaveLoad::_newTask;
std:: string architectureSaveLoad::_overdue;
std:: string architectureSaveLoad::_clash;
std:: vector<TASK> architectureSaveLoad::_tempVector;
<<<<<<< HEAD
std:: vector<TASK> architectureSaveLoad::_tempMasterVector;
std:: vector<TASK> architectureSaveLoad::_tempFloatingVector;

std:: string architectureSaveLoad::_fileName;
std:: string architectureSaveLoad::_directoryName;
std:: string architectureSaveLoad::_pathName;

const std:: string architectureSaveLoad::DEFAULT_PATHNAME = "C:\\Users\\Choo\\Desktop\\EasyToDo.txt";
const std:: string architectureSaveLoad::DEFAULT_TEXTFILENAME = "EasyToDo.txt";
const std:: string architectureSaveLoad::DEFAULT_DIRECTORYNAME = "C:\\Users\\Choo\\Desktop\\";
const std:: string architectureSaveLoad::MESSAGE_DEFAULT_SAVE = "Save directory and filename is set to default!";
const std:: string architectureSaveLoad::MESSAGE_SUCCESSFUL_SAVE = "Save directory and filename changed!";
const std:: string architectureSaveLoad::MESSAGE_FAILED_SAVE = "Sorry. Invalid directory! Save directory not changed";


char architectureSaveLoad::transitory[MAXIMUM];
=======
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861

architectureSaveLoad::architectureSaveLoad() {
}

<<<<<<< HEAD
std:: string architectureSaveLoad::retrievePathName() {
	std:: ifstream read("PathName.txt");
	std:: string line;
	getline(read,line);
	return line;
}
void architectureSaveLoad::saveToTextFile(std:: vector<TASK>& masterTaskList, std:: vector<TASK>& floatingTaskList) {
	std:: vector<TASK>::iterator iter;
	std:: ofstream saveFile(retrievePathName());
	std:: vector<TASK> taskList;
	
	taskList = combineVector(masterTaskList, floatingTaskList);
=======
void architectureSaveLoad::saveToTextFile(std:: vector<TASK>& taskList) {
	std:: vector<TASK>::iterator iter;
	std:: string textFileName;
	textFileName = "task.txt";
	std:: ofstream saveFile(textFileName);
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861

	for(iter = taskList.begin(); iter != taskList.end(); iter++) {
		saveFile << iter->taskDescriptionList;
		saveFile << std:: endl;

		saveFile << boost::posix_time::to_simple_string(iter->startDateTime).c_str();
		saveFile << std:: endl;

		saveFile << boost::posix_time::to_simple_string(iter->endTime).c_str();
		saveFile << std:: endl;

<<<<<<< HEAD
		saveFile << boost::posix_time::to_simple_string(iter->endDateTime).c_str();
		saveFile << std:: endl;

=======
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861
		saveFile << std:: to_string(iter->taskID);
		saveFile << std:: endl;

		saveFile << boost::lexical_cast<std::string>(iter->done);
		saveFile << std:: endl;

		saveFile << boost::lexical_cast<std::string>(iter->newTask);
		saveFile << std:: endl;
		
		saveFile << boost::lexical_cast<std::string>(iter->overdue);
		saveFile << std:: endl;

		saveFile << boost::lexical_cast<std::string>(iter->clash);
<<<<<<< HEAD

		if (iter != taskList.end() - 1) {
			saveFile << std:: endl;
		}		
	}
	saveFile.close();  
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

// load from archivedFile
bool architectureSaveLoad::loadFromTextFile() {
=======
		if (iter != taskList.end() - 1) {
			saveFile << std:: endl;
		}
			
	}
	 saveFile.close();  
}

bool architectureSaveLoad::loadFromTextFile() {
	std:: string textFileName = "task.txt";
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861
	TASK temp;
	std:: string buffer;
	std:: vector<std:: string> tempStringVector;

<<<<<<< HEAD
	std:: ifstream readFile(retrievePathName());
	
	if (!readFile.is_open()) { // if file doesn't exists
		std:: ofstream writeFile(retrievePathName());
=======
	std:: ifstream readFile(textFileName);
	
	if (!readFile.is_open()) { // if file doesn't exists
		std:: ofstream writeFile(textFileName);
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861
		writeFile.close();
		return false;
	} else {

		while (std:: getline(readFile,buffer)) {
			tempStringVector.push_back(buffer);
		} 
		int size = tempStringVector.size();
		int i=0;
		
		while (i<size) {

			_taskDescription = tempStringVector[i];
<<<<<<< HEAD
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
		differentiateVector(_tempVector);
=======

			_startDateTime = tempStringVector[i+1];

			_endTime = tempStringVector[i+2];

			_taskID = tempStringVector[i+3];

			_done = tempStringVector[i+4];
			
			_newTask = tempStringVector[i+5];

			_overdue = tempStringVector[i+6];

			_clash = tempStringVector[i+7];

			temp = initializeTaskFromString();
			_tempVector.push_back(temp);

			i+=8;
			
		}

		
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861
		readFile.close();
		return true;
	}
	
}

<<<<<<< HEAD
std:: vector<TASK> architectureSaveLoad::passMasterTaskVector() {
	return _tempMasterVector;
}

std:: vector<TASK> architectureSaveLoad::passFloatingTaskVector() {
	return _tempFloatingVector;
=======
std:: vector<TASK> architectureSaveLoad::passTaskVector() {
	return _tempVector;
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861
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

//	below is still wrong
<<<<<<< HEAD
	ptime stringTimeDuration;
	boost::posix_time::time_input_facet *timeFacetEnd = new boost::posix_time::time_input_facet;
	timeFacetEnd->format("%H:%M");
	std::istringstream ss(_endDateTime);
	ss.imbue(std::locale(std::locale::classic(), timeFacet));
	ss >> stringTimeDuration;
	temp.endDateTime = stringTimeDuration;

	temp.endTime = stringTimeDuration.time_of_day();

	// temp.endTime = boost::posix_time::duration_from_string(_endTime);
=======
//	time_duration stringTimeDuration;
//	boost::posix_time::time_input_facet *timeFacetEnd = new boost::posix_time::time_input_facet;
//   timeFacetEnd->format("%H:%M");
//	std::istringstream iss(_endTime);
//	iss.imbue(std::locale(std::locale::classic(), timeFacet));
//	iss >> stringTimeDuration;
//	temp.endTime = stringTimeDuration;
//	temp.endTime = boost::posix_time::duration_from_string(_endTime);
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861

	temp.taskID =  atoi(_taskID.c_str());
	temp.done = boost::lexical_cast<bool>(_done);
	temp.newTask = boost::lexical_cast<bool>(_newTask);
	temp.overdue = boost::lexical_cast<bool>(_overdue);
	temp.clash = boost::lexical_cast<bool>(_clash);

<<<<<<< HEAD
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

void architectureSaveLoad::changePathName(std:: string newPathName) {
	std:: ofstream file;
	file.open("PathName.txt");
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

bool architectureSaveLoad::isPathNameValid() {
	if (boost::filesystem::exists(_pathName)) { 
		return true;
	} else {
		return false;
	}
}

std:: string architectureSaveLoad::changeSavingDirectoryAndFileName(std:: string directoryName, std:: string fileName) {
	if(directoryName == "" && fileName == "") {
		sprintf_s(transitory, MESSAGE_DEFAULT_SAVE.c_str());
		_pathName = DEFAULT_PATHNAME;
		changePathName(_pathName);
		return transitory;
	}

	initializeDefaultPathAndFileName(directoryName, fileName);
	
	_pathName =  _directoryName + _fileName;

	if (isPathNameValid()) { 
		sprintf_s(transitory, MESSAGE_FAILED_SAVE.c_str());
	} else {
		sprintf_s(transitory, MESSAGE_SUCCESSFUL_SAVE.c_str());
	}

	changePathName(_pathName);
	return transitory;
}

/*
void architectureSaveLoad::writeArchivedFile() {
	TASK temp;
	std:: string buffer;

	std:: ifstream readFile(_pathName);
	std:: ofstream saveFile("ArchivedFile.txt");

	while (std:: getline(readFile,buffer)) {
		saveFile << buffer << std:: endl;
	} 
	saveFile.close();  
}
*/
=======

	
	return temp;
}

void architectureSaveLoad::pushToStorage(TASK task) {
	architectureStorage::pushTaskToMaster(task);
	return;
}
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861
