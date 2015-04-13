// @author A0111378J
#include "E2DLogging.h"

const std:: string E2DLogging::LOG_FILENAME = "logFile.txt";
const std:: string E2DLogging::MESSAGE_LINENUMBER = "line number: ";
int counter = 1; 

E2DLogging::E2DLogging(void) {
}


E2DLogging::~E2DLogging(void) {
}


void E2DLogging::logToFile(std:: string severity, std:: string fileName, std:: string lineNumber, std:: string message) {
	date dateToday;
	time_duration time;
	std:: ofstream LOG;
	LOG.open(LOG_FILENAME, std:: ios::out | std:: ios::app);

	dateToday = retrieveDateToday();
	time = retrieveTimeNow();

	LOG << to_simple_string(dateToday) << ", " << to_simple_string(time) << ", " << fileName + " @ " << MESSAGE_LINENUMBER << lineNumber << std:: endl;
	LOG << std:: to_string(counter) << ". " << severity << ", " << message << std:: endl << std:: endl;
	counter++;
	LOG.close();
	return;
}

date E2DLogging::retrieveDateToday() {
	ptime today = second_clock::local_time();
	date dateToday = today.date();
	return dateToday;
}

time_duration E2DLogging::retrieveTimeNow() {
	ptime today = second_clock::local_time();
	time_duration time = today.time_of_day();
	return time;
}
