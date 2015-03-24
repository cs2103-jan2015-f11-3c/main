#ifndef ARCHITECTURELOGIC_H_
#define ARCHITECTURELOGIC_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <boost/date_time.hpp>

using namespace boost::posix_time;
using namespace boost::gregorian;
using boost::local_time::local_time_input_facet;
using boost::posix_time::ptime;

class sortBoost {
private:
		static std::string _startHour;
		static std::string _startMin;
		static std::string _endHour;
        static std::string _endMin;
        static std::string _dayOfTheWeek;
		static std::string _dateDay;
		static std::string _dateMonth;
		static int startHour;
		static int startMin;
		static int endHour;
        static int endMin;
        static int dayOfTheWeek;
		static int dateDay;
		static int dateMonth;

public:

	static void getDayOfTheWeek(std::string input);
	static void getDateDay(std::string input);
	static void getDateMonth(std::string input);
	static void getStartHour(std::string input);
	static void getStartMin(std::string input);
	static void getEndHour(std::string input);
	static void getEndMin(std::string input);
	static void sortTodayUpcoming();
	static date retrieveDateToday();
};

#endif
