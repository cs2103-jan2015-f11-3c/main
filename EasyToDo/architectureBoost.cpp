#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"
#include "architectureBoost.h"


 void architectureBoost::getDayOfTheWeek(std::string input){
 }

 void architectureBoost::getDateDay(std::string input){
 }
 
 void architectureBoost::getDateMonth(std::string input){
 }

 void architectureBoost::getStartHour(std::string input){
 }

 void architectureBoost::getStartMin(std::string input){
 }

 void architectureBoost::getEndHour(std::string input){
 }

 void architectureBoost::getEndMin(std::string input){
 }


void architectureBoost::sortTodayUpcoming(std:: vector<TASK>& masterTaskList) {
	/*std:: vector<TASK>::iterator iter;
	date dateToday = retrieveDateToday();
	date temp; 
	days dayDifference;
	days day(1);

	for(iter = masterTaskList.begin(); iter != masterTaskList.end(); iter++) {
		temp = (iter->startDateTime).date();
		dayDifference = temp - dateToday;
		if (dayDifference >= day) {
			architectureStorage::storeTodayTask(*iter);
		} else {
			architectureStorage::storeUpcomingTask(*iter);
		}
	}*/

}
/*
date architectureBoost::retrieveDateToday() {
	ptime today = second_clock::local_time();
	date dateToday = today.date();
	return dateToday;
}
*/