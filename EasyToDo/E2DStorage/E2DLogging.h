// @author A0111378J
#ifndef E2DLOGGING_H_
#define E2DLOGGING_H_

#include <string>
#include <fstream>
#include <boost/date_time.hpp>

using namespace boost::posix_time;
using namespace boost::gregorian;

// this class allows the users to log the information into an external file which is standardised to the logFile in 
// the UI folder
// the information being logged will be the severity level, filename, line number, time, message
// to serve as black box for the developer to trace the errors and warnings
class E2DLogging {
private:
	static const std:: string LOG_FILENAME;
	static const std:: string MESSAGE_LINENUMBER;
public:
	E2DLogging(void);
	~E2DLogging(void);

	// this function allow the developer and user to keep track of the errors
	// Pre: the error or assertion or exception must be violated for this function to be called
	// Post: log into the file
	static void logToFile(std:: string severity, std:: string fileName, std:: string lineNumber, std:: string message);
	static date retrieveDateToday();
	static time_duration retrieveTimeNow();

};
#endif