#ifndef ARCHITECTURESTORAGE_H_
#define ARCHITECTURESTORAGE_H_

#include <vector>
#include <string>

using namespace std;

class architectureStorage {
private:
	static vector<string> taskDescriptionList;
	static vector<string> taskTimeList;
	static const string MESSAGE_ADD;
	static const string MESSAGE_EMPTY;
	
public:
	architectureStorage();
	static void addToStorage(string task, string time);
	static void deleteFromStorage(int taskID);
	static void clearFromStorage();
	static void displayFromStorage();

	static void showToUser(string task);
	static int sizeOfStorage();
};
#endif