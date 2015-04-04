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
std:: string architectureSaveLoad::_newTask;
std:: string architectureSaveLoad::_overdue;
std:: string architectureSaveLoad::_clash;
std:: vector<TASK> architectureSaveLoad::_tempVector;

architectureSaveLoad::architectureSaveLoad() {
}

void architectureSaveLoad::saveToTextFile(std:: vector<TASK>& taskList) {
	std:: vector<TASK>::iterator iter;
	std:: string textFileName;
	textFileName = "task.txt";
	std:: ofstream saveFile(textFileName);

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

bool architectureSaveLoad::loadFromTextFile() {
	std:: string textFileName = "task.txt";
	TASK temp;
	std:: string buffer;
	std:: vector<std:: string> tempStringVector;

	std:: ifstream readFile(textFileName);
	
	if (!readFile.is_open()) { // if file doesn't exists
		std:: ofstream writeFile(textFileName);
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

		
		readFile.close();
		return true;
	}
	
}

std:: vector<TASK> architectureSaveLoad::passTaskVector() {
	return _tempVector;
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
//	time_duration stringTimeDuration;
//	boost::posix_time::time_input_facet *timeFacetEnd = new boost::posix_time::time_input_facet;
//   timeFacetEnd->format("%H:%M");
//	std::istringstream iss(_endTime);
//	iss.imbue(std::locale(std::locale::classic(), timeFacet));
//	iss >> stringTimeDuration;
//	temp.endTime = stringTimeDuration;
//	temp.endTime = boost::posix_time::duration_from_string(_endTime);

	temp.taskID =  atoi(_taskID.c_str());
	temp.done = boost::lexical_cast<bool>(_done);
	temp.newTask = boost::lexical_cast<bool>(_newTask);
	temp.overdue = boost::lexical_cast<bool>(_overdue);
	temp.clash = boost::lexical_cast<bool>(_clash);


	
	return temp;
}

void architectureSaveLoad::pushToStorage(TASK task) {
	architectureStorage::pushTaskToMaster(task);
	return;
}