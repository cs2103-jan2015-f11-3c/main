#ifndef ARCHITECTURELOGIC_H_
#define ARCHITECTURELOGIC_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class architectureLogic {
private:
	static const string MESSAGE_ADD;

	static const int MAX = 255; 
	static char buffer[MAX];
public:
	architectureLogic();
	enum CommandType { 
		ADD, DELETE, DISPLAY, CLEAR, INVALID, SORT, SEARCH, EXIT 
	};

	void addTask(string task);
	void deleteText(int taskID);

	void showToUser(string task);
};
#endif