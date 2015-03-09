#ifndef ARCHITECTURESTORAGE_H_
#define ARCHITECTURESTORAGE_H_

#include <vector>
#include <string>

using namespace std;

class architectureStorage {
private:
	static vector<string> taskList;
public:
	void addToStorage(string task);
	void deleteFromStorage(int taskID);

};
#endif