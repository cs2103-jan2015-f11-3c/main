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

const std:: string architectureStorage::DEFAULT_HOURS = "23";
const std:: string architectureStorage::DEFAULT_MINUTES = "59";
const std:: string architectureStorage::STRING_BLANK = "";

const std:: string architectureStorage::FILTER_UNSUCCESSFUL = "Sorry, no match found!";
const std:: string architectureStorage::FILTER_SUCCESSFUL = "The following task(s) displayed is/are the upcoming task(s) from the dates you keyed";

char architectureStorage::buffer[MAX];

// this function allows the algorithm to execute the find function in our context to compare the respective content of the task struct
bool operator==(const TASK& a, const TASK& b) {
	return (a.taskDescriptionList == b.taskDescriptionList) && (a.startDateTime == b.startDateTime) && (a.endTime == b.endTime);
}

architectureStorage::architectureStorage() {
}

void architectureStorage::updateTaskID(std:: vector<TASK>& input) {
	int counter = 1;
	std:: vector<TASK>::iterator iter;
	
	for(iter = input.begin(); iter != input.end(); iter++, counter++) {
		iter->taskID = counter;
	}
}

bool architectureStorage::loadProgram() {
	
	if (architectureSaveLoad::loadFromTextFile()) {
		masterTaskList.clear();
		floatingTaskList.clear();
		masterTaskList = architectureSaveLoad::passMasterTaskVector();
		floatingTaskList = architectureSaveLoad::passFloatingTaskVector();
		architectureBoost::sortTodayUpcoming(masterTaskList);
		return true;
	} else {
		architectureSaveLoad::initializePathName();
		return false;
	}
}

void architectureStorage::addToMasterStorage(std:: string _contentDescripton, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
											 std:: string _contentStartMinutes, std:: string _contentEndDay, std:: string _contentEndMonth, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	TASK temp;
	updateNewTask();
	architectureBoost::sortTodayUpcoming(masterTaskList);
	
	// not a timed task
	if(_contentEndDay == STRING_BLANK && _contentEndMonth == STRING_BLANK && _contentEndHours == STRING_BLANK && _contentEndMinutes == STRING_BLANK) {
		// not a dateline task -> it is a floating task
		if(_contentStartHours == STRING_BLANK && _contentStartMinutes == STRING_BLANK && _contentStartDay == STRING_BLANK && _contentStartMonth == STRING_BLANK) {
			temp = initializeFloatingTask(_contentDescripton);
			floatingTaskList.push_back(temp);
			architectureHistory::addPreviousState(temp);
			saveProgram();
			return;
		} else {
			// if the task has startday and startmonth but doesn't have a time, it will initialise to default time as all-day task
			if(_contentStartHours == STRING_BLANK && _contentStartMinutes == STRING_BLANK) {
				_contentStartHours = DEFAULT_HOURS;
				_contentStartMinutes = DEFAULT_MINUTES;
				temp = initializeDeadlineTask(_contentDescripton, _contentStartDay, _contentStartMonth, _contentStartHours, _contentStartMinutes);
			} else {
				temp = initializeDeadlineTask(_contentDescripton, _contentStartDay, _contentStartMonth, _contentStartHours, _contentStartMinutes);
			}
		}
	} else {
		temp = initializeTimedTask(_contentDescripton, _contentStartDay, _contentStartMonth, _contentStartHours, _contentStartMinutes, _contentEndDay, _contentEndMonth, _contentEndHours, _contentEndMinutes);
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

TASK architectureStorage::initializeFloatingTask(std:: string _contentDescription) {
	assert(_contentDescription != STRING_BLANK);

	TASK buffer;
	buffer.taskDescriptionList = _contentDescription;
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

TASK architectureStorage::initializeDeadlineTask(std:: string _contentDescription, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, std:: string _contentStartMinutes) {
	assert(_contentDescription != STRING_BLANK);
	assert(_contentStartDay != STRING_BLANK);
	assert(_contentStartMonth != STRING_BLANK);
	assert(_contentStartHours != STRING_BLANK);
	assert(_contentStartMinutes != STRING_BLANK);

	TASK buffer;
	buffer.taskDescriptionList = _contentDescription;
	std::string dateString; 

	dateString = "2015," + _contentStartMonth + "," + _contentStartDay;
	date d(from_string(dateString));
	ptime temp(d, time_duration(hours(stringToInt(_contentStartHours))+minutes(stringToInt(_contentStartMinutes))));
	buffer.startDateTime = temp;
	buffer.startTime = temp.time_of_day();

	ptime temp1;
	buffer.endDateTime = temp1;
	buffer.endTime = time_duration(not_a_date_time);
	
	buffer.taskID = 0;
	buffer.done = false;
	buffer.newTask = true;
	buffer.overdue = false;
	buffer.clash = false;
	return buffer;
}

TASK architectureStorage::initializeTimedTask(std:: string _contentDescription, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
											  std:: string _contentStartMinutes, std:: string _contentEndDay, std:: string _contentEndMonth, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	assert(_contentDescription != STRING_BLANK);
	assert(_contentStartDay != STRING_BLANK);
	assert(_contentStartMonth != STRING_BLANK);
	assert(_contentStartHours != STRING_BLANK);
	assert(_contentStartMinutes != STRING_BLANK);
	assert(_contentEndHours != STRING_BLANK);
	assert(_contentEndMinutes != STRING_BLANK);

	TASK buffer;
	buffer.taskDescriptionList = _contentDescription;
	std::string startDateString; 
	std::string endDateString; 

	startDateString = "2015," +  _contentStartMonth + "," + _contentStartDay;
	date d1(from_string(startDateString));
	ptime temp1(d1, time_duration(hours(stringToInt(_contentStartHours))+minutes(stringToInt(_contentStartMinutes))));
	buffer.startDateTime = temp1;
	buffer.startTime = temp1.time_of_day();

	endDateString = "2015," +  _contentEndMonth + "," + _contentEndDay;
	date d2(from_string(endDateString));
	ptime temp2(d2,time_duration(hours(stringToInt(_contentEndHours))+minutes(stringToInt(_contentEndMinutes))));
	buffer.endDateTime = temp2;
	buffer.endTime = temp2.time_of_day();
	
	buffer.taskID = 0;
	buffer.done = false;
	buffer.newTask = true;
	buffer.overdue = false;
	buffer.clash = false;
	return buffer;
}

int architectureStorage::stringToInt(std:: string input) {
	int value;
	value = atoi(input.c_str());
	return value;
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

void architectureStorage::clearAllFromStorage() {
	architectureHistory::pushPreviousTodayUpcomingTaskList(masterTaskList);
	architectureHistory::pushPreviousFloatingTaskList(floatingTaskList);
	masterTaskList.clear();
	floatingTaskList.clear();
	architectureBoost::sortTodayUpcoming(masterTaskList);
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
	architectureBoost::sortTodayUpcoming(masterTaskList);
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
	architectureBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void architectureStorage::clearFloatingFromStorage() {
	architectureHistory::pushPreviousFloatingTaskList(floatingTaskList);
	floatingTaskList.clear();
	saveProgram();
	return;
}

void architectureStorage::updateToTodayStorage(int taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
											   std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findTodayIterator(taskID);
	architectureHistory::addPreviousState(*iter);
	deleteTask(*iter);
	addToMasterStorage(newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);
	architectureBoost::sortTodayUpcoming(masterTaskList);
}

void architectureStorage::updateToUpcomingStorage(int taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
											   std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findUpcomingIterator(taskID);
	architectureHistory::addPreviousState(*iter);
	deleteTask(*iter);
	addToMasterStorage(newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);	
	architectureBoost::sortTodayUpcoming(masterTaskList);
}

void architectureStorage::updateToFloatingStorage(int taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
											   std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findFloatingIterator(taskID);
	architectureHistory::addPreviousState(*iter);
	floatingTaskList.erase(iter);
	addToMasterStorage(newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);
	architectureBoost::sortTodayUpcoming(masterTaskList);
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

std:: vector<TASK> architectureStorage::retrieveTodayTaskList() {
	return todayTaskList;
}

std:: vector<TASK> architectureStorage::retrieveUpcomingTaskList() {
	return upcomingTaskList;
}

std:: vector<TASK> architectureStorage::retrieveFloatingTaskList() {
	return floatingTaskList;
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


void architectureStorage::storeTodayTask(TASK temp) {
	temp = architectureBoost::checkClashTask(temp, todayTaskList);
	todayTaskList.push_back(temp);
	architectureBoost::sortWithinTodayUpcoming(todayTaskList);
	architectureBoost::checkOverdueTask(todayTaskList);
	saveProgram();
	return;
}

void architectureStorage::storeUpcomingTask(TASK temp) {
	temp = architectureBoost::checkClashTask(temp, upcomingTaskList);
	upcomingTaskList.push_back(temp);
	architectureBoost::sortWithinTodayUpcoming(upcomingTaskList);
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

void architectureStorage::updateClashStatus(TASK& task) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), task);
	position->clash = true;
	architectureBoost::sortWithinTodayUpcoming(todayTaskList);
	saveProgram();
}

void architectureStorage::saveProgram() {
	architectureSaveLoad::saveToTextFile(masterTaskList, floatingTaskList);
}

std:: string architectureStorage::filterTaskInStorage(std:: string day, std:: string month) {
	std:: vector<TASK> tempVector;
	std:: vector<TASK>::iterator iter;
	std:: string dateString;
	std:: string dateString1;
	std:: string dateString2;
	int temp;
	
	dateString = "2015," + month + "," + day;
	date d(from_string(dateString));

	temp = stringToInt(day) + 1;
	day = std:: to_string(temp);
	dateString1 = "2015," + month + "," + day;
	date d1(from_string(dateString1));

	temp = stringToInt(day) + 1;
	day = std:: to_string(temp);
	dateString2 = "2015," + month + "," + day;
	date d2(from_string(dateString2));

	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) {
		if((iter->startDateTime.date() == d) || (iter->endDateTime.date() == d)
		|| (iter->startDateTime.date() == d1) || (iter->endDateTime.date() == d1) 
		|| (iter->startDateTime.date() == d2) || (iter->endDateTime.date() == d2)) {
			tempVector.push_back(*iter);
		}
	}

	ptime today = second_clock::local_time();
	date dateToday = today.date();

	if(tempVector.empty()) {
		sprintf_s(buffer, FILTER_UNSUCCESSFUL.c_str());
		return buffer;
	} else {
		if(dateToday < d) {
			upcomingTaskList = tempVector;
			floatingTaskList.clear();
			todayTaskList.clear();
		}
		if(dateToday > d) {
			todayTaskList = tempVector;
			floatingTaskList.clear();
			upcomingTaskList.clear();
		}
	}
	sprintf_s(buffer, FILTER_SUCCESSFUL.c_str());
	return buffer;
}

void architectureStorage::displayTaskInStorage() {
	architectureBoost::sortTodayUpcoming(masterTaskList);
	return;
}

std:: vector<TASK> architectureStorage::retrieveMasterTaskList(){
	return masterTaskList;
}
