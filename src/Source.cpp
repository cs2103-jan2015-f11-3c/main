#include "Header.h"

const string TextBuddy::MESSAGE_WELCOME = "Welcome to TextBuddy. %s is ready for use";
const string TextBuddy::MESSAGE_COMMAND = "command: ";
const string TextBuddy::MESSAGE_ADD = "added to %s: \"%s\"";
const string TextBuddy::MESSAGE_DELETE = "deleted from %s: \"%s\"";
const string TextBuddy::MESSAGE_EMPTY = "%s is empty. ";
const string TextBuddy::MESSAGE_CLEAR = "all content cleared from %s";
const string TextBuddy::MESSAGE_INVALID = "Error! Invalid Command : %s";
const string TextBuddy::MESSAGE_SORT = "all content sorted";
const string TextBuddy::MESSAGE_NOTFOUND = "Text Input is not found";
const string TextBuddy::MESSAGE_ERROR = "Invalid command type";

bool isProgramValid = true;
char TextBuddy::buffer[MAX];
vector<string> TextBuddy::textList;

TextBuddy::TextBuddy(){
}

void TextBuddy::showToUser(string text) {
	cout << text << endl;
}

void TextBuddy::saveFile(string outputFile) {
	ifstream inputFile;
	ofstream myFile;
	inputFile.open("tempfile.txt");
	inputFile.close();
	remove(outputFile.c_str());
	rename("tempfile.txt", outputFile.c_str());

	if(textList.begin() != textList.end()) {
		for(std::vector<std::string>::iterator iter = textList.begin(); iter != textList.end(); iter++) {
			myFile.open(outputFile);
			myFile << *iter << endl;
			myFile.close();
		}
	}
}

// this method ignores any possible typing errors there is in the commandline and standardise the return commandType for executeCommand
TextBuddy::CommandType TextBuddy::determineCommandType(string commandAction) {
	if(isValidCommand(commandAction, "add")) {
		return CommandType::ADD;
	} else if (isValidCommand(commandAction,"display")) {
		return CommandType::DISPLAY;
	} else if(isValidCommand(commandAction, "clear")) {
		return CommandType::CLEAR;
	} else if(isValidCommand(commandAction, "delete")) {
		return CommandType::DELETE;
	} else if(isValidCommand(commandAction, "sort")) {
		return CommandType::SORT;
	} else if(isValidCommand(commandAction, "search")) {
		return CommandType::SEARCH;
	} else if(isValidCommand(commandAction, "exit")) {
			return CommandType::EXIT;
	} else {
		return CommandType::INVALID;

	}
}

// this method check if the two strings are identical regardless of the capitalization of words
bool TextBuddy::isValidCommand(const string& str1, const string& str2) {
	if (str1.size() != str2.size()) {
        return false;
    }
	for (string::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2) {
        if (tolower(*c1) != tolower(*c2)) {
            return false;
        }
    }
    return true;
}
string TextBuddy::getFirstWord(string commandAction) {
	string command = commandAction.substr(0, commandAction.find_first_of(" "));
	return command;
}

string TextBuddy::removeFirstWord(string commandAction) {
	string userInput = commandAction.substr(commandAction.find_first_of(" ") + 1);
	return userInput;
}

string TextBuddy::executeCommand(string commandAction, string outputFile) { 
	string command = getFirstWord(commandAction);
	CommandType commandTypeAction = determineCommandType(command);
	string userInput = removeFirstWord(commandAction);

	switch(commandTypeAction) {
	case ADD:
		return addText(userInput, outputFile);
	case DISPLAY:
		return displayText(outputFile);
	case DELETE: 
		return deleteText(userInput, outputFile);
	case CLEAR: 
		return clearText(outputFile);
	case SORT:
		sortText();
		return MESSAGE_SORT;
	case SEARCH:
		searchText(userInput);
		return "";
	case INVALID:{
		sprintf_s(buffer, MESSAGE_INVALID.c_str(), commandAction.c_str());
		return buffer;
		}
	case EXIT:{
		isProgramValid = false;
		exit(0);
		}
	default:
		showToUser(MESSAGE_ERROR);
		getchar();
		exit(EXIT_FAILURE);
	}
}

string TextBuddy::addText(string text, string outputFile) {
	textList.push_back(text);
	sprintf_s(buffer, MESSAGE_ADD.c_str(), outputFile.c_str(), text.c_str());

	return buffer;
}


string TextBuddy::deleteText(string text, string outputFile) {
	vector<string>::iterator iter = locateText(text, outputFile);
	sprintf_s(buffer, MESSAGE_DELETE.c_str(), outputFile.c_str(), iter->c_str());
	textList.erase(iter);
	return buffer;
}

vector<string>::iterator TextBuddy::locateText(string text, string outputFile) {
	int temp = 1;
	for(vector<string>::iterator iter = textList.begin(); iter != textList.end(); iter++) {
		if(temp == stoi(text)) {
			return iter;
		}
		else {
			temp++;
		}
	}
	sprintf_s(buffer, MESSAGE_NOTFOUND.c_str(), outputFile.c_str());
	showToUser(buffer);
	return textList.end();
}

string TextBuddy::displayText(string outputFile) {
	int counter = 1;

	if(textList[0].empty()) {
		sprintf_s(buffer, MESSAGE_EMPTY.c_str(), outputFile.c_str());
	}
	else {
		for(vector<string>::iterator iter = textList.begin(); iter != textList.end(); iter++) {
			cout << counter+1;
			showToUser(". " + *iter + "\n");
		}
	}
	return "";
}

string TextBuddy::clearText(string outputFile) {
	textList.clear();
	sprintf_s(buffer, MESSAGE_CLEAR.c_str(), outputFile.c_str());

	return buffer;
}

/************************CE2**************************/
void TextBuddy::sortText() {
	sort(textList.begin(), textList.end());
	return;
}

vector<string> TextBuddy::searchText(string input) {
	vector<string> containInput;
	for(std::vector<std::string>::iterator iter = textList.begin(); iter != textList.end(); iter++) {
		size_t found = iter->find(input);
		if(found != string::npos) {
			containInput.push_back(*iter);
		}
	}

	if(isSearchSuccess(containInput)) {
		printSearchResult(containInput);
	}
	else {
		showToUser(MESSAGE_NOTFOUND);
	}

	return containInput;
}

bool TextBuddy::isSearchSuccess(vector<string>& containInput) {
	return !(containInput.empty());
}
void TextBuddy::printSearchResult(vector<string>& containInput) {
	if(!containInput.empty()) {
		for(unsigned int counter = 1; counter <= containInput.size(); counter++) {
			cout << counter;
			showToUser(". " + containInput[counter-1] + "\n");
		}
	}
}

/***************Unit Testing Functions**************/
string TextBuddy::retrieveText(int i) {
	vector<string>::iterator iter = textList.begin();
	string text;
	text = *(iter+i);

	return text;
}

int main(int argc, char* argv[]) {

	TextBuddy::main(argc, argv);
	return 0;
}

void TextBuddy::main(int argc, char* argv[]) {
	string command;
	string outputFile = argv[1];
	string programFeedback;

	sprintf_s(buffer, MESSAGE_WELCOME.c_str(), outputFile.c_str());
	showToUser(buffer);

	while(isProgramValid) {
		showToUser(MESSAGE_COMMAND + "\n");
		getline(cin, command);
		programFeedback = executeCommand(command, outputFile);
		saveFile(outputFile);
		showToUser(programFeedback);
	}
}
