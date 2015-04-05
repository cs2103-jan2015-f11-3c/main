#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureParser.h"
#include "architectureHistory.h"
#include "architectureSaveLoad.h"
#include "architectureBoost.h"

std:: string architectureSaveLoad::_taskDescription;
std:: string architectureSaveLoad::_startDateTime;
std:: string architectureSaveLoad::_endTime;
std:: string architectureSaveLoad::_taskID;
std:: string architectureSaveLoad::_done;

architectureSaveLoad::architectureSaveLoad() {
}

void architectureSaveLoad::saveToTextFile(std:: vector<TASK>& taskList) {
	std:: vector<TASK>::iterator iter;
	std:: string textFileName;
	textFileName = "EasyToDo.txt";
	std:: ofstream saveFile (textFileName);

	for(iter = taskList.begin(); iter != taskList.end(); iter++) {
		saveFile << iter->taskDescriptionList;
		saveFile << std:: endl;

		saveFile << boost::posix_time::to_simple_string(iter->startDateTime).c_str();
		saveFile << std:: endl;

		saveFile << boost::posix_time::to_simple_string(iter->endTime).c_str();
		saveFile << std:: endl;

		saveFile << std:: to_string(iter->taskID);
		saveFile << std:: endl;

		saveFile << boost::lexical_cast<std::string>(iter->done);
		saveFile << std:: endl;
	}
	 saveFile.close();  
}

std:: vector<TASK> architectureSaveLoad::loadFromTextFile() {
	std:: string textFileName;
	std:: vector<TASK> tempVector;
	TASK temp;
	std:: string buffer;
	textFileName = "task.txt";

	std:: ifstream readFile(textFileName);
	if(!readFile.is_open()) { // if file does not exist
		std:: ofstream writeFile(textFileName);
		writeFile.close();
		std:: ifstream readFile(textFileName);
	} else { // if file already exists
		do {
			std:: getline(readFile, _taskDescription);
			std:: getline(readFile, buffer);

			std:: getline(readFile, _startDateTime);
			std:: getline(readFile, buffer);

			std:: getline(readFile, _endTime);
			std:: getline(readFile, buffer);

			std:: getline(readFile, _taskID);
			std:: getline(readFile, buffer);

			std:: getline(readFile, _done);
			std:: getline(readFile, buffer);

			temp = initializeTaskFromString(_taskDescription, _startDateTime, _endTime, _taskID, _done);
			tempVector.push_back(temp);
		} while (std:: getline(readFile, _taskDescription));
	}
	return tempVector;
}

TASK architectureSaveLoad::initializeTaskFromString(std:: string _taskDescription, std:: string _startDateTime, std:: string _endTime, std:: string _taskID, std:: string _done) {
	TASK temp;
	temp.taskDescriptionList = _taskDescription;
	temp.startDateTime = boost::posix_time::time_from_string(_startDateTime);
	temp.endTime = boost::posix_time::duration_from_string(_endTime);
	temp.taskID =  atoi(_taskID.c_str());
	temp.done = boost::lexical_cast<bool>(_done);
	return temp;
}

void architectureSaveLoad::pushToStorage(TASK task) {
	architectureStorage::pushTaskToMaster(task);
	return;
}