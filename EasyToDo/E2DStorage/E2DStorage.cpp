// @author A0111378J
#include "E2DStorage.h"
#include "E2DBoost.h"
#include "E2DSaveLoad.h"
#include "E2DHistory.h"
#include "E2DLogging.h"

std:: vector<TASK> E2DStorage::masterTaskList; 
std:: vector<TASK> E2DStorage::todayTaskList;
std:: vector<TASK> E2DStorage::upcomingTaskList;
std:: vector<TASK> E2DStorage::floatingTaskList;
std:: vector<TASK> E2DStorage::tempFloatingTaskList;

const std:: string E2DStorage::DEFAULT_HOURS = "23";
const std:: string E2DStorage::DEFAULT_MINUTES = "59";
const std:: string E2DStorage::STRING_BLANK = "";

const std:: string E2DStorage::MESSAGE_FILTER_UNSUCCESSFUL = "Sorry, no match found!";
const std:: string E2DStorage::MESSAGE_FILTER_DATE_SUCCESSFUL = "The following task(s) displayed is/are the upcoming task(s) from the date you keyed";
const std:: string E2DStorage::MESSAGE_FILTER_TIME_SUCCESSFUL = "The following task(s) displayed is/are the upcoming task(s) from the time you keyed";

const std:: string E2DStorage::MESSAGE_SEARCH_UNSUCCESSFUL = "Sorry, no match found!";
const std:: string E2DStorage::MESSAGE_SEARCH_SUCCESSFUL = "The following task(s) displayed is/are the task(s) that contain(s) your intended search input";

const std:: string E2DStorage::DEFAULT_YEAR = "2015,";

const std:: string E2DStorage::SEVERITY_LEVEL_WARNING = "Warning";
const std:: string E2DStorage::MESSAGE_LOG_INVALID = "Invalid User Input";


char E2DStorage::buffer[MAX];

// this function allows the algorithm to execute the find function in our context to compare the respective content of the task struct
bool operator==(const TASK& a, const TASK& b) {
	return (a.taskDescriptionList == b.taskDescriptionList) && (a.startDateTime == b.startDateTime) && (a.endTime == b.endTime);
}

E2DStorage::E2DStorage(void) {
}


E2DStorage::~E2DStorage(void) {
}


void E2DStorage::updateTaskID(std:: vector<TASK>& input) {
	int counter = 1;
	std:: vector<TASK>::iterator iter;
	
	for(iter = input.begin(); iter != input.end(); iter++, counter++) {
		iter->taskID = counter;
	}
}

bool E2DStorage::loadProgram() {
	
	if (E2DSaveLoad::loadFromTextFile()) {
		masterTaskList.clear();
		floatingTaskList.clear();
		masterTaskList = E2DSaveLoad::passMasterTaskVector();
		floatingTaskList = E2DSaveLoad::passFloatingTaskVector();
		E2DBoost::sortTodayUpcoming(masterTaskList);
		return true;
	} else {
		E2DSaveLoad::initializePathName();
		return false;
	}
}

void E2DStorage::addToMasterStorage(std:: string _contentDescripton, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
											 std:: string _contentStartMinutes, std:: string _contentEndDay, std:: string _contentEndMonth, std:: string _contentEndHours, std:: string _contentEndMinutes) {
	TASK temp;
	updateNewTask();
	E2DBoost::sortTodayUpcoming(masterTaskList);

	
	// not a timed task
	if(_contentEndHours == STRING_BLANK && _contentEndMinutes == STRING_BLANK) {
		// not a dateline task -> it is a floating task
		if(_contentStartHours == STRING_BLANK && _contentStartMinutes == STRING_BLANK && _contentStartDay == STRING_BLANK && _contentStartMonth == STRING_BLANK) {
			temp = initializeFloatingTask(_contentDescripton);
			floatingTaskList.push_back(temp);
			E2DHistory::addPreviousState(temp);
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

	E2DHistory::addPreviousState(temp);
	masterTaskList.push_back(temp);
	E2DBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void E2DStorage::updateNewTask() {
	std:: vector<TASK>::iterator iter;
	for(iter = floatingTaskList.begin(); iter != floatingTaskList.end(); iter++) {
		iter->newTask = false;
	}

	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) {
		iter->newTask = false;
	}
}

TASK E2DStorage::initializeFloatingTask(std:: string _contentDescription) {
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

TASK E2DStorage::initializeDeadlineTask(std:: string _contentDescription, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, std:: string _contentStartMinutes) {
	assert(_contentDescription != STRING_BLANK);
	assert(_contentStartDay != STRING_BLANK);
	assert(_contentStartMonth != STRING_BLANK);
	assert(_contentStartHours != STRING_BLANK);
	assert(_contentStartMinutes != STRING_BLANK);

	TASK buffer;
	buffer.taskDescriptionList = _contentDescription;
	std::string dateString; 

	dateString = DEFAULT_YEAR + _contentStartMonth + "," + _contentStartDay;
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

TASK E2DStorage::initializeTimedTask(std:: string _contentDescription, std:: string _contentStartDay, std:: string _contentStartMonth, std:: string _contentStartHours, 
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

	startDateString = DEFAULT_YEAR +  _contentStartMonth + "," + _contentStartDay;
	date d1(from_string(startDateString));
	ptime temp1(d1, time_duration(hours(stringToInt(_contentStartHours))+minutes(stringToInt(_contentStartMinutes))));
	buffer.startDateTime = temp1;
	buffer.startTime = temp1.time_of_day();

	// if the user did not specify the endDay and endMonth, it will be assumed that they are the same as the startday and month
	if(_contentEndDay == STRING_BLANK && _contentEndMonth == STRING_BLANK) {
		_contentEndDay = _contentStartDay;
		_contentEndMonth = _contentStartMonth;
	}

	endDateString = DEFAULT_YEAR +  _contentEndMonth + "," + _contentEndDay;
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

int E2DStorage::stringToInt(std:: string input) {
	int value;
	value = atoi(input.c_str());
	return value;
}

void E2DStorage::deleteTodayFromStorage(std:: vector<TASK>::iterator iter) {
	deleteTask(*iter);
	E2DBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void E2DStorage::deleteUpcomingFromStorage(std:: vector<TASK>::iterator iter) {
	deleteTask(*iter);
	E2DBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void E2DStorage::deleteFloatingFromStorage(std:: vector<TASK>::iterator iter) {
	E2DHistory::addPreviousState(*iter);
	floatingTaskList.erase(iter);
	saveProgram();
	return;
}

void E2DStorage::deleteTask(TASK& input) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), input);
	if (position == masterTaskList.end()) {
		position = std::find(floatingTaskList.begin(), floatingTaskList.end(), input);
		floatingTaskList.erase(position);
	}
	else {
		masterTaskList.erase(position);
		E2DBoost::sortTodayUpcoming(masterTaskList);
	}
	saveProgram();
	return;
}

void E2DStorage::clearAllFromStorage() {
	E2DHistory::pushPreviousTodayUpcomingTaskList(masterTaskList);
	E2DHistory::pushPreviousFloatingTaskList(floatingTaskList);
	masterTaskList.clear();
	floatingTaskList.clear();
	E2DBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void E2DStorage::clearTodayFromStorage() {
	E2DHistory::pushPreviousTodayUpcomingTaskList(masterTaskList);
	masterTaskList.clear();
	std:: vector<TASK>::iterator iter;
	for(iter = upcomingTaskList.begin(); iter != upcomingTaskList.end(); iter++) {
		masterTaskList.push_back(*iter);
	}
	E2DBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void E2DStorage::clearUpcomingFromStorage() {
	E2DHistory::pushPreviousTodayUpcomingTaskList(masterTaskList);
	masterTaskList.clear();
	std:: vector<TASK>::iterator iter;
	for(iter = todayTaskList.begin(); iter != todayTaskList.end(); iter++) {
		masterTaskList.push_back(*iter);
	}
	E2DBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void E2DStorage::clearFloatingFromStorage() {
	E2DHistory::pushPreviousTodayUpcomingTaskList(masterTaskList);
	E2DHistory::pushPreviousFloatingTaskList(floatingTaskList);
	floatingTaskList.clear();
	saveProgram();
	return;
}

void E2DStorage::updateToTodayStorage(int taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
											   std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findTodayIterator(taskID);
	E2DHistory::addPreviousState(*iter);
	deleteTask(*iter);
	addToMasterStorage(newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);
	E2DBoost::sortTodayUpcoming(masterTaskList);
}

void E2DStorage::updateToUpcomingStorage(int taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
											   std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findUpcomingIterator(taskID);
	E2DHistory::addPreviousState(*iter);
	deleteTask(*iter);
	addToMasterStorage(newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);	
	E2DBoost::sortTodayUpcoming(masterTaskList);
}

void E2DStorage::updateToFloatingStorage(int taskID, std:: string newTask, std:: string newStartDay, std:: string newStartMonth, std:: string newStartHours, 
											   std:: string newStartMinutes, std:: string newEndDay, std:: string newEndMonth, std:: string newEndHours, std:: string newEndMinutes) {
	std:: vector<TASK>::iterator iter = findFloatingIterator(taskID);
	E2DHistory::addPreviousState(*iter);
	floatingTaskList.erase(iter);
	addToMasterStorage(newTask, newStartDay, newStartMonth, newStartHours, newStartMinutes, newEndDay, newEndMonth, newEndHours, newEndMinutes);
	E2DBoost::sortTodayUpcoming(masterTaskList);
}

std:: vector<TASK>::iterator E2DStorage::findTodayIterator(int taskID) {
	std:: vector<TASK>::iterator iter; 
	iter = todayTaskList.begin() + taskID - 1;
	return iter;
}

std:: vector<TASK>::iterator E2DStorage::findUpcomingIterator(int taskID) {
	std:: vector<TASK>::iterator iter; 
	iter = upcomingTaskList.begin() + taskID - 1;
	return iter;
}

std:: vector<TASK>::iterator E2DStorage::findFloatingIterator(int taskID) {
	std:: vector<TASK>::iterator iter; 
	iter = floatingTaskList.begin() + taskID - 1;
	return iter;
}

void E2DStorage::undoDelete(TASK& input) {
	if (input.startDateTime == not_a_date_time) {
		floatingTaskList.push_back(input);
	}
	else {
		masterTaskList.push_back(input);
		E2DBoost::sortTodayUpcoming(masterTaskList);
	}
	saveProgram();
	return;
}

void E2DStorage::undoAdd(TASK& input) {
	deleteTask(input);
	E2DBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void E2DStorage::undoClear(std:: vector<TASK>& previousTodayUpcomingTaskList, 
						  std:: vector<TASK>& previousFloatingTaskList) {
	masterTaskList.clear(); 
	std:: vector<TASK>::iterator iter;
	for(iter = previousTodayUpcomingTaskList.begin(); iter != previousTodayUpcomingTaskList.end(); iter++) {
		masterTaskList.push_back(*iter);
	}

	for(iter = previousFloatingTaskList.begin(); iter != previousFloatingTaskList.end(); iter++) {
		floatingTaskList.push_back(*iter);
	}
	E2DBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void E2DStorage::undoDone(TASK& input) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), input);

	if (position == masterTaskList.end()) {
		position = std::find(floatingTaskList.begin(), floatingTaskList.end(), input);
		position->done = false;
	}
	else {
		position->done = false;
		E2DBoost::sortTodayUpcoming(masterTaskList);
	}
	saveProgram();
	return;
}

void E2DStorage::doneTodayTask(std:: vector<TASK>::iterator iter) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), *iter);
	position->done = true;
	E2DBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void E2DStorage::doneUpcomingTask(std:: vector<TASK>::iterator iter) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), *iter);
	position->done = true;
	E2DBoost::sortTodayUpcoming(masterTaskList);
	saveProgram();
	return;
}

void E2DStorage::doneFloatingTask(std:: vector<TASK>::iterator iter) {
	iter->done = true;
	saveProgram();
	return;
}

std:: vector<TASK> E2DStorage::retrieveTodayTaskList() {
	return todayTaskList;
}

std:: vector<TASK> E2DStorage::retrieveUpcomingTaskList() {
	return upcomingTaskList;
}

std:: vector<TASK> E2DStorage::retrieveFloatingTaskList() {
	return floatingTaskList;
}

int E2DStorage::findTotalNumberofTodayTask() {
	return todayTaskList.size();
}

int E2DStorage::findTotalNumberofUpcomingTask() {
	return upcomingTaskList.size();
}

int E2DStorage::findTotalNumberofFloatingTask() {
	return floatingTaskList.size();
}

bool E2DStorage::isMasterTaskListEmpty() {
	if(masterTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

bool E2DStorage::isTodayTaskListEmpty() {
	if(todayTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

bool E2DStorage::isUpcomingTaskListEmpty() {
	if(upcomingTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

bool E2DStorage::isFloatingTaskListEmpty() {
	if(floatingTaskList.size() == 0) {
		return true;
	} else {
		return false;
	}
}


void E2DStorage::storeTodayTask(TASK temp) {
	temp = E2DBoost::checkClashTask(temp, todayTaskList);
	todayTaskList.push_back(temp);
	E2DBoost::sortWithinTodayUpcoming(todayTaskList);
	E2DBoost::checkOverdueTask(todayTaskList);
	saveProgram();
	return;
}

void E2DStorage::storeUpcomingTask(TASK temp) {
	temp = E2DBoost::checkClashTask(temp, upcomingTaskList);
	upcomingTaskList.push_back(temp);
	E2DBoost::sortWithinTodayUpcoming(upcomingTaskList);
	saveProgram();
	return;
}

void E2DStorage::clearTodayTaskList() {
	todayTaskList.clear();
	return;
}

void E2DStorage::clearUpcomingTaskList() {
	upcomingTaskList.clear();
	return;
}

void E2DStorage::updateClashStatus(TASK& task) {
	std::vector<TASK>::iterator position = std::find(masterTaskList.begin(), masterTaskList.end(), task);
	position->clash = true;
	E2DBoost::sortWithinTodayUpcoming(todayTaskList);
	saveProgram();
}

void E2DStorage::saveProgram() {
	E2DSaveLoad::saveToTextFile(masterTaskList, floatingTaskList);
}

std:: string E2DStorage::filterTaskByDayAndMonth(std:: string day, std:: string month) {
	std:: vector<TASK> tempTodayVector;
	std:: vector<TASK> tempUpcomingVector;
	
	
	date d = initializeDate(day, month);

	day = incrementDay(day);
	date d1 = initializeDate(day, month);

	day = incrementDay(day);
	date d2 = initializeDate(day, month);

	tempTodayVector = filteredTaskFromToday(d, d1, d2);
	tempUpcomingVector = filteredTaskFromUpcoming(d, d1, d2);
	
	try {
		if(tempTodayVector.empty() && tempUpcomingVector.empty()) {
			E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found");
			throw MESSAGE_FILTER_UNSUCCESSFUL;
		} else {
			if(tempFloatingTaskList.empty()) {
				tempFloatingTaskList = floatingTaskList;
			}

			todayTaskList = tempTodayVector;
			upcomingTaskList = tempUpcomingVector;

			floatingTaskList.clear();
			throw MESSAGE_FILTER_DATE_SUCCESSFUL;
		}
		
	} catch (std:: string& exceptionMessage) {
		sprintf_s(buffer, exceptionMessage.c_str());
		saveProgram();
		return buffer;
	}
}

std:: string E2DStorage::filterTaskByHrAndMin(std:: string hour, std:: string min) {
	std:: vector<TASK> tempTodayVector;
	std:: vector<TASK> tempUpcomingVector;
	std:: vector<TASK>::iterator iter;

	time_duration td = hours(stringToInt(hour)) + seconds(stringToInt(min)); 

	for(iter = todayTaskList.begin(); iter != todayTaskList.end(); iter++) {
		if(isTimeFound(td, *iter)) {
			tempTodayVector.push_back(*iter);
		}
	}

	for(iter = upcomingTaskList.begin(); iter != upcomingTaskList.end(); iter++) {
		if(isTimeFound(td, *iter)) {
			tempUpcomingVector.push_back(*iter);
		}
	}

	try {
		if(tempTodayVector.empty() && tempUpcomingVector.empty()) {
			E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found");
			throw MESSAGE_FILTER_UNSUCCESSFUL;
		} else {
			if(tempFloatingTaskList.empty()) {
				tempFloatingTaskList = floatingTaskList;
			}

			todayTaskList = tempTodayVector;
			upcomingTaskList = tempUpcomingVector;

			floatingTaskList.clear();
			throw MESSAGE_FILTER_TIME_SUCCESSFUL;
		}
	} catch (std:: string& exceptionMessage) {
		sprintf_s(buffer, exceptionMessage.c_str());
		saveProgram();
		return buffer;
	}
}

std:: string E2DStorage::incrementDay(std:: string day) {
	int temp;
	temp = stringToInt(day) + 1;
	day = std:: to_string(temp);
	return day;
}

date E2DStorage::initializeDate(std:: string day, std:: string month) {
	std:: string dateString;
	dateString = DEFAULT_YEAR + month + "," + day;
	date d(from_string(dateString));
	return d;
}

std:: vector<TASK> E2DStorage::filteredTaskFromToday(date d, date d1, date d2) {
	std:: vector<TASK>::iterator iter;
	std:: vector<TASK> temp;

	for(iter = todayTaskList.begin(); iter != todayTaskList.end(); iter++) {
		if(areDatesFound(d, d1, d2, *iter)) {
			temp.push_back(*iter);
		}
	}
	return temp;
}

std:: vector<TASK> E2DStorage::filteredTaskFromUpcoming(date d, date d1, date d2) {
	std:: vector<TASK>::iterator iter;
	std:: vector<TASK> temp;

	for(iter = upcomingTaskList.begin(); iter != upcomingTaskList.end(); iter++) {
		if(areDatesFound(d, d1, d2, *iter)) {
			temp.push_back(*iter);
		}
	}
	return temp;
}

bool E2DStorage::areDatesFound(date d, date d1, date d2, TASK& task) {
	if((task.startDateTime.date() == d) || (task.endDateTime.date() == d)
		|| (task.startDateTime.date() == d1) || (task.endDateTime.date() == d1) 
		|| (task.startDateTime.date() == d2) || (task.endDateTime.date() == d2)) {
			return true;
	} else {
		return false;
	}
}

bool E2DStorage::isTimeFound(time_duration td, TASK& task) {
	// if it contains a endTime -> timed task
	if(!task.endTime.is_not_a_date_time()) {
		time_period tp1(task.startDateTime, task.endDateTime);
		time_period tp2(task.startDateTime, ptime(task.startDateTime.date(), td));
		if(tp2.intersects(tp1)) {
			return true;
		} else {
			return false;
		}
	} else { // it does not contain a endTime -> deadline Task
		if(task.startTime == td) {
			return true;
		} else {
			return false;
		}
	}
}

void E2DStorage::displayTaskInStorage() {
	E2DBoost::sortTodayUpcoming(masterTaskList);
	floatingTaskList = tempFloatingTaskList;
	tempFloatingTaskList.clear();
	saveProgram();
	return;
}

std:: string E2DStorage::searchContentInStorage(std:: string& searchContent) {
	std:: vector<TASK> tempTodayVector;
	std:: vector<TASK> tempUpcomingVector;
	std:: vector<TASK> tempFloatingVector;
	
	tempTodayVector = searchInTodayTaskList(searchContent);
	tempUpcomingVector = searchInUpcomingTaskList(searchContent);
	tempFloatingVector = searchInFloatingTaskList(searchContent);

	try {
		if(tempTodayVector.empty() && tempUpcomingVector.empty() && tempFloatingVector.empty()) {
			E2DLogging::logToFile(SEVERITY_LEVEL_WARNING, __FILE__, std:: to_string(__LINE__), MESSAGE_LOG_INVALID + ": " + "taskID is not found");
			throw MESSAGE_SEARCH_UNSUCCESSFUL;
		} else {
			if(tempFloatingTaskList.empty()) {
				tempFloatingTaskList = floatingTaskList;
			}
			todayTaskList = tempTodayVector;
			upcomingTaskList = tempUpcomingVector;
			floatingTaskList = tempFloatingVector;
		}
		throw MESSAGE_SEARCH_SUCCESSFUL;
	} catch (std:: string& exceptionMessage) {
		sprintf_s(buffer, exceptionMessage.c_str());
		saveProgram();
		return buffer;
	}
}

std:: vector<TASK> E2DStorage::searchInTodayTaskList(std::string& searchContent) {
	std:: vector<TASK>::iterator iter;
	std::size_t found;
	std:: vector<TASK> temp;

	for(iter = todayTaskList.begin(); iter != todayTaskList.end(); iter++) {
		found = iter->taskDescriptionList.find(searchContent);
		if(found != std:: string::npos) {
			temp.push_back(*iter);
		}
	}
	return temp;
}

std:: vector<TASK> E2DStorage::searchInUpcomingTaskList(std::string& searchContent) {
	std:: vector<TASK>::iterator iter;
	std::size_t found;
	std:: vector<TASK> temp;

	for(iter = upcomingTaskList.begin(); iter != upcomingTaskList.end(); iter++) {
		found = iter->taskDescriptionList.find(searchContent);
		if(found != std:: string::npos) {
			temp.push_back(*iter);
		}
	}
	return temp;
}

std:: vector<TASK> E2DStorage::searchInFloatingTaskList(std::string& searchContent) {
	std:: vector<TASK>::iterator iter;
	std::size_t found;
	std:: vector<TASK> temp;

	for(iter = floatingTaskList.begin(); iter != floatingTaskList.end(); iter++) {
		found = iter->taskDescriptionList.find(searchContent);
		if(found != std:: string::npos) {
			temp.push_back(*iter);
		}
	}
	return temp;
}

std:: vector<TASK> E2DStorage::retrieveMasterTaskList(){
	return masterTaskList;
}