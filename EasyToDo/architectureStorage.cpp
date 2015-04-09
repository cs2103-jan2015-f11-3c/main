#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"
#include "architectureBoost.h"
#include "architectureHistory.h"
#include "architectureSaveLoad.h"

std:: vector<TASK> architectureStorage::masterTaskList;
std:: vector<TASK> architectureStorage::todayTaskList;
std:: vector<TASK> architectureStorage::upcomingTaskList;
std:: vector<TASK> architectureStorage::floatingTaskList;

bool operator==(const TASK& a, const TASK& b) {
		return (a.taskDescriptionList == b.taskDescriptionList) && (a.startDateTime == b.startDateTime) && (a.endTime == b.endTime);
	}

architectureStorage::architectureStorage() {
}

bool architectureStorage::loadProgram() {
	
	if (architectureSaveLoad::loadFromTextFile()) {
		masterTaskList.clear();
<<<<<<< HEAD
		floatingTaskList.clear();
		masterTaskList = architectureSaveLoad::passMasterTaskVector();
		floatingTaskList = architectureSaveLoad::passFloatingTaskVector();
=======
		masterTaskList = architectureSaveLoad::passTaskVector();
>>>>>>> 117c7a87c41ca2fbfbcd365f13f372c21afd5861
		architectureBoost::sortTodayUpcoming(masterTaskList);
		return true;
	} else {
		return false;
	}
}
void architectureStorage::updateTaskID(std:: vector<TASK>& input) {
	int counter = 1;
	std:: vector<TASK>::iterator iter;
	
	for(iter = input.begin(); iter != input.end(); iter++, counter++) {
		iter->taskID = counter;
	}
}

int architectureStorage::stringToInt(std:: string input) {
	int value;
	value = atoi(input.c_str());
	return value;
}

TASK architectureStorage::initializeTimedTask(std:: string _contentDescripton, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	TASK buffer;
	buffer.taskDescriptionList = _contentDescripton;
	std::string dateString; // ("2002/1/25");
	dateString = "2015," +  _contentMonth + "," + _contentDay;
	date d(from_string(dateString));
	ptime temp(d, time_duration(hours(stringToInt(_contentStartHours))+minutes(stringToInt(_contentStartMinutes))));
	buffer.startDateTime = temp;
	buffer.endTime = time_duration(hours(stringToInt(_contentEndHours))+minutes(stringToInt(_contentEndMinutes)));
	ptime temp2(d,time_duration(hours(stringToInt(_contentEndHours))+minutes(stringToInt(_contentEndMinutes))));
	buffer.endDateTime = temp2;
	buffer.taskID = 0;
	buffer.done = false;
	buffer.newTask = true;
	buffer.overdue = false;
	buffer.clash = false;
	return buffer;
}

TASK architectureStorage::initializeDeadlineTask(std:: string _contentDescripton, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes) {
	TASK buffer;
	buffer.taskDescriptionList = _contentDescripton;
	std::string dateString; // ("2002/1/25");
	dateString = "2015," + _contentMonth + "," + _contentDay;
	date d(from_string(dateString));
	ptime temp(d, time_duration(hours(stringToInt(_contentStartHours))+minutes(stringToInt(_contentStartMinutes))));
	buffer.startDateTime = temp;
	buffer.endTime = time_duration(not_a_date_time);
	ptime temp1;
	buffer.endDateTime = temp1;
	buffer.taskID = 0;
	buffer.done = false;
	buffer.newTask = true;
	buffer.overdue = false;
	buffer.clash = false;
	return buffer;
}

TASK architectureStorage::initializeFloatingTask(std:: string _contentDescripton) {
	TASK buffer;
	buffer.taskDescriptionList = _contentDescripton;
	ptime temp; //temp => not_a_date_time
	buffer.startDateTime = temp;
	buffer.endTime = time_duration(not_a_date_time);
	buffer.endDateTime = temp;
	buffer.taskID = 0;
	buffer.done = false;
	buffer.newTask = true;
	buffer.overdue = false;
	buffer.clash = false;
	return buffer;
}

void architectureStorage::addToMasterStorage(std:: string _contentDescripton, std:: string _contentDay, std:: string _contentMonth, std:: string _contentStartHours, std:: string _contentStartMinutes, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	TASK temp;
	updateNewTask();
	architectureBoost::sortTodayUpcoming(masterTaskList);
	if(_contentEndHours == "" && _contentEndMinutes == "") {
		if(_contentStartHours == "" && _contentStartMinutes == "") {
			temp = initializeFloatingTask(_contentDescripton);
			floatingTaskList.push_back(temp);
			architectureHistory::addPreviousState(temp);
			saveProgram();
			return;
		} else {
			temp = initializeDeadlineTask(_contentDescripton, _contentDay, _contentMonth, _contentStartHours, _contentStartMinutes);
		}
	} else {
		temp = initializeTimedTask(_contentDescripton, _contentDay, _contentMonth, _contentStartHours, _contentStartMinutes, _contentEndHours, _contentEndMinutes);
	}
	architectureHistory::addPreviousState(temp);
	masterTaskList.push_back(temp);
	architectureBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void architectureStorage::updateNewTask() {
	std:: vector<TASK>::iterator iter;
	for(iter = floatingTaskList.begin(); iter != floatingTaskList.end(); iter++) {
		iter->newTask = false;
	}

	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) {
		iter->newTask = false;
	}
}

std:: vector<TASK> architectureStorage::retrieveTodayTaskList() {
	return todayTaskList;
}

std:: vector<TASK> architectureStorage::retrieveUpcomingTaskList() {
	return upcomingTaskList;
}

std:: vector<TASK> architectureStorage::retrieveFloatingTaskList() {
	return floatingTaskList;
}

void architectureStorage::deleteTodayFromStorage(std:: vector<TASK>::iterator iter) {
	deleteTask(*iter);
	architectureBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void architectureStorage::deleteUpcomingFromStorage(std:: vector<TASK>::iterator iter) {
	deleteTask(*iter);
	architectureBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void architectureStorage::deleteFloatingFromStorage(std:: vector<TASK>::iterator iter) {
	architectureHistory::addPreviousState(*iter);
	floatingTaskList.erase(iter);
	saveProgram();
	return;
}

int architectureStorage::findTotalNumberofTodayTask() {
	return todayTaskList.size();
}

int architectureStorage::findTotalNumberofUpcomingTask() {
	return upcomingTaskList.size();
}

int architectureStorage::findTotalNumberofFloatingTask() {
	return floatingTaskList.size();
}


bool architectureStorage::isMasterTaskListEmpty() {
	if(masterTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

bool architectureStorage::isTodayTaskListEmpty() {
	if(todayTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

bool architectureStorage::isUpcomingTaskListEmpty() {
	if(upcomingTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

bool architectureStorage::isFloatingTaskListEmpty() {
	if(floatingTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

std:: vector<TASK>::iterator architectureStorage::findTodayIterator(int taskID) {
	std:: vector<TASK>::iterator iter; 
	iter = todayTaskList.begin() + taskID - 1;
	return iter;
}

std:: vector<TASK>::iterator architectureStorage::findUpcomingIterator(int taskID) {
	std:: vector<TASK>::iterator iter; 
	iter = upcomingTaskList.begin() + taskID - 1;
	return iter;
}

std:: vector<TASK>::iterator architectureStorage::findFloatingIterator(int taskID) {
	std:: vector<TASK>::iterator iter; 
	iter = floatingTaskList.begin() + taskID - 1;
	return iter;
}

// for update function, i will store two previous states instead of one[add, delete] 
// thus the first one you pop from the stack "previousStateStack" would be the one you need to delete
// and the second one would be the one you need to add back cause of LIFO
void architectureStorage::updateToTodayStorage(int taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findTodayIterator(taskID);
	architectureHistory::addPreviousState(*iter);
	deleteTask(*iter);
	addToMasterStorage(newTask, newDay, newMonth, newStartHours, newStartMinutes, newEndHours, newEndMinutes);
	architectureBoost::sortTodayUpcoming(masterTaskList);
}

void architectureStorage::updateToUpcomingStorage(int taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findUpcomingIterator(taskID);
	architectureHistory::addPreviousState(*iter);
	deleteTask(*iter);
	addToMasterStorage(newTask, newDay, newMonth, newStartHours, newStartMinutes, newEndHours, newEndMinutes);	
	architectureBoost::sortTodayUpcoming(masterTaskList);
}

void architectureStorage::updateToFloatingStorage(int taskID, std:: string newTask, std:: string newDay, std:: string newMonth, std:: string newStartHours, std:: string newStartMinutes, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findFloatingIterator(taskID);
	architectureHistory::addPreviousState(*iter);
	floatingTaskList.erase(iter);
	addToMasterStorage(newTask, newDay, newMonth, newStartHours, newStartMinutes, newEndHours, newEndMinutes);
	architectureBoost::sortTodayUpcoming(masterTaskList);
}

void architectureStorage::storeTodayTask(TASK temp) {
	temp = architectureBoost::checkClashTask(temp, todayTaskList);
	todayTaskList.push_back(temp);
	architectureBoost::sortWithinTodayUpcoming(todayTaskList);
	architectureBoost::checkOverdueTask(todayTaskList);
	saveProgram();
	return;
}

void architectureStorage::updateClashStatus(TASK& task) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), task);
	position->clash = true;
	architectureBoost::sortWithinTodayUpcoming(todayTaskList);
	saveProgram();
}

void architectureStorage::storeUpcomingTask(TASK temp) {
	temp = architectureBoost::checkClashTask(temp, upcomingTaskList);
	upcomingTaskList.push_back(temp);
	architectureBoost::sortWithinTodayUpcoming(upcomingTaskList);
	saveProgram();
	return;
}

void architectureStorage::clearAllFromStorage() {
	architectureHistory::pushPreviousTodayUpcomingTaskList(masterTaskList);
	architectureHistory::pushPreviousFloatingTaskList(floatingTaskList);
	masterTaskList.clear();
	todayTaskList.clear();
	upcomingTaskList.clear();
	floatingTaskList.clear();
	saveProgram();
	return;
}

void architectureStorage::clearTodayFromStorage() {
	architectureHistory::pushPreviousTodayUpcomingTaskList(masterTaskList);
	assert(!masterTaskList.empty());
	masterTaskList.clear();
	std:: vector<TASK>::iterator iter;
	for(iter = upcomingTaskList.begin(); iter != upcomingTaskList.end(); iter++) {
		masterTaskList.push_back(*iter);
	}
	todayTaskList.clear();
	upcomingTaskList.clear();
	saveProgram();
	return;
}

void architectureStorage::clearUpcomingFromStorage() {
	architectureHistory::pushPreviousTodayUpcomingTaskList(masterTaskList);
	masterTaskList.clear();
	std:: vector<TASK>::iterator iter;
	for(iter = todayTaskList.begin(); iter != todayTaskList.end(); iter++) {
		masterTaskList.push_back(*iter);
	}
	todayTaskList.clear();
	upcomingTaskList.clear();
	saveProgram();
	return;
}

void architectureStorage::clearFloatingFromStorage() {
	architectureHistory::pushPreviousFloatingTaskList(floatingTaskList);
	floatingTaskList.clear();
	saveProgram();
	return;
}

/**************for undo function ******************/
void architectureStorage::undoDelete(TASK& input) {
	if (input.startDateTime == not_a_date_time) {
		floatingTaskList.push_back(input);
	}
	else {
		masterTaskList.push_back(input);
		architectureBoost::sortTodayUpcoming(masterTaskList);
	}
	saveProgram();
	return;
}

void architectureStorage::deleteTask(TASK& input) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), input);
	if (position == masterTaskList.end()) {
		position = std::find(floatingTaskList.begin(), floatingTaskList.end(), input);
		floatingTaskList.erase(position);
	}
	else {
		masterTaskList.erase(position);
		architectureBoost::sortTodayUpcoming(masterTaskList);
	}
	saveProgram();
	return;
}

void architectureStorage::undoAdd(TASK& input) {
	deleteTask(input);
	architectureBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void architectureStorage::undoClear(std:: vector<TASK>& previousTodayUpcomingTaskList, 
						  std:: vector<TASK>& previousFloatingTaskList) {
	masterTaskList.clear(); 
	std:: vector<TASK>::iterator iter;
	for(iter = previousTodayUpcomingTaskList.begin(); iter != previousTodayUpcomingTaskList.end(); iter++) {
		masterTaskList.push_back(*iter);
	}

	for(iter = previousFloatingTaskList.begin(); iter != previousFloatingTaskList.end(); iter++) {
		floatingTaskList.push_back(*iter);
	}
	architectureBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void architectureStorage::undoDone(TASK& input) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), input);

	if (position == masterTaskList.end()) {
		position = std::find(floatingTaskList.begin(), floatingTaskList.end(), input);
		position->done = false;
	}
	else {
		position->done = false;
		architectureBoost::sortTodayUpcoming(masterTaskList);
	}
	saveProgram();
	return;
}

void architectureStorage::doneTodayTask(std:: vector<TASK>::iterator iter) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), *iter);
	position->done = true;
	architectureBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void architectureStorage::doneUpcomingTask(std:: vector<TASK>::iterator iter) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), *iter);
	position->done = true;
	architectureBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void architectureStorage::doneFloatingTask(std:: vector<TASK>::iterator iter) {
	iter->done = true;
	saveProgram();
	return;
}

void architectureStorage::clearTodayTaskList() {
	todayTaskList.clear();
	return;
}

void architectureStorage::clearUpcomingTaskList() {
	upcomingTaskList.clear();
	return;
}

/**** integration testing ****/

std:: vector<TASK> architectureStorage::retrieveMasterTaskList(){
	return masterTaskList;
}

/**** saveLoad function ****/


void architectureStorage::saveProgram() {
	architectureSaveLoad::saveToTextFile(masterTaskList, floatingTaskList);
}