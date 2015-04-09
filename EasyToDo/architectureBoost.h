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
	architectureBoost();
	static void sortTodayUpcoming(std:: vector<TASK>& masterTaskList);
	static date retrieveDateToday();
	static bool isValidTodayTask(days dayDifference);
	static void sortWithinTodayUpcoming(std:: vector<TASK>& todayUpcomingTASKList);
	static void checkOverdueTask(std:: vector<TASK>& todayTaskList);
	static bool isTaskOverdue(days dayDifference);
	static TASK checkClashTask(TASK temp, std:: vector<TASK>& taskList);
};
#endif
