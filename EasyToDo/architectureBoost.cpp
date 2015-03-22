#include "architectureStorage.h"
#include "architectureLogic.h"
#include "architectureParser.h"
#include "architectureBoost.h"

void sortBoost::getDayOfTheWeek(std::string input){

	_dayOfTheWeek = input;
	dayOfTheWeek = atoi(_dayOfTheWeek.c_str());

}

void sortBoost::getDateDay(std::string input){

	_dateDay = input;
	dateDay = atoi(_dateDay.c_str());

}

void sortBoost::getDateMonth(std::string input){

	_dateMonth = input;
	dateMonth = atoi(_dateMonth.c_str());
}

void sortBoost::getStartHour(std::string input){

	_startHour = input;
	startHour = atoi(_startHour.c_str());
}

void sortBoost::getStartMin(std::string input){

	_startMin = input;
	startMin = atoi(_startMin.c_str());

}

void sortBoost::getEndHour(std::string input){

	_endHour = input;
	endHour = atoi(_endHour.c_str());

}

void sortBoost::getEndMin(std::string input){

	_endMin = input;
	endMin = atoi(_endMin.c_str());

}

void sortBoost::sortTodayUpcoming(){
	
	ptime inputData(date(2015,dateMonth,dateDay),time_duration(hours(startHour)+minutes(+startMin)));
	ptime today = second_clock::local_time();
	date dateToday = today.date();
	date inputDate = inputData.date();
	days dayDifference = inputDate - dateToday;
	days day(1);

	if (dayDifference >= day)
		architectureStorage::storeToday();
	else
		architectureStorage::storeUpcoming();

}
