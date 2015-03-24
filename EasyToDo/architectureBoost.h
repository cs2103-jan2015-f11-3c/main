#ifndef ARCHITECTUREBOOST_H_
#define ARCHITECTUREBOOST_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <boost/date_time.hpp>

using namespace boost::posix_time;
using namespace boost::gregorian;
using boost::local_time::local_time_input_facet;
using boost::posix_time::ptime;

class architectureBoost {
public:
	static void getDayOfTheWeek(std::string input);
	static void getDateDay(std::string input);
	static void getDateMonth(std::string input);
	static void getStartHour(std::string input);
	static void getStartMin(std::string input);
	static void getEndHour(std::string input);
	static void getEndMin(std::string input);
	static void sortTodayUpcoming(std:: vector<TASK>& masterTaskList);
	static date retrieveDateToday();
};
#endif
