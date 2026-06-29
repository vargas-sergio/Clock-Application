// CS210 Module 3.3
// 
// Author: Sergio J. Vargas
// Date: 05/20/2026
// 
// Purpose: Purpose: Create clock module for Chada Tech 

// required headers
#include <iostream>
#include <string>

// use std namespace
using namespace std;

// get user input time
int initialTime() {
	// declare constants
	int userHour, userMinute, userSecond;
	int totalSeconds;

	// declare initial inputs
	int hourFormat = 0;
	int hourPeriod = 0;

	// declare string value
	string border(27, '*');

	// bordered time format selection
	cout << border << endl;
	cout << "* Select time format:     *" << endl;
	cout << "* 1 - 12 Hour Format      *" << endl;
	cout << "* 2 - 24 Hour Format      *" << endl;
	cout << border << endl;

	// get user input
	cin >> hourFormat;

	// get hour conditionally
	if (hourFormat == 1) {
		// 12 hour format input
		cout << border << endl;
		cout << "* Enter Hours (1-12):     *" << endl;
		cout << border << endl;

		// get user input
		cin >> userHour;

		// error condition
		if (userHour < 1 || userHour > 12) {
			return -1; // exit program; todo: loop retry/exit
		}
	}
	else if (hourFormat == 2) {
		// 24 hour format input
		cout << border << endl;
		cout << "* Enter Hours (0-23):     *" << endl;
		cout << border << endl;

		// get user input
		cin >> userHour;

		// error condition
		if (userHour < 0 || userHour > 23) {
			return -1; // exit program; todo: loop retry/exit
		}
	}
	else {
		// error condition
		return -1; // exit program; todo: loop retry/exit
	}
	// bordered minute input
	cout << border << endl;
	cout << "* Enter Minutes (0-59):   *" << endl;
	cout << border << endl;

	// get user input
	cin >> userMinute;

	// error conidtion
	if (userMinute < 0 || userMinute > 59) {
		return -1; // exit program; todo: loop retry/exit
	}
	// bordered second input
	cout << border << endl;
	cout << "* Enter Seconds (0-59):   *" << endl;
	cout << border << endl;

	// get user second
	cin >> userSecond;

	// error condition
	if (userSecond < 0 || userSecond > 59) {
		return -1; // exit program; todo: loop retry/exit
	}

	// get AM/PM from user
	if (hourFormat == 1) {
		// bordered AM/PM selection menu
		cout << border << endl;
		cout << "* Select Period AM/PM:    *" << endl;
		cout << "* 1 - AM                  *" << endl;
		cout << "* 2 - PM                  *" << endl;
		cout << border << endl;
		// get user input
		cin >> hourPeriod;

		// 12 to 24 hour conversion
		if (hourPeriod == 1) {
			if (userHour == 12) {
				userHour = 0;
			}
		}
		else if (hourPeriod == 2) {
			if (userHour != 12) {
				userHour += 12;
			}
		}
		else {
			// catch errors
			return -1;
		}
	}
	// convert usertime to seconds for processing
	totalSeconds = userSecond;
	totalSeconds += 60 * userMinute;
	totalSeconds += 3600 * userHour;

	// return user time in seconds
	return totalSeconds;
}

// stringify time inputs to ISO 8601 parts
string stringTime(int timeValue) {
	// declare variables
	string returnString;
	// if less than 10 add leading 0
	if (timeValue < 10) {
		returnString = "0" + to_string(timeValue);
	}
	else {
		returnString = to_string(timeValue);
	}
	// return string
	return returnString;
}

// display user menu
void displayMenu() {
	// border
	string border(27, '*');

	// display bordered user input
	cout << border << endl;
	cout << "* 1 - Add One Hour        *" << endl;
	cout << "* 2 - Add One Minute      *" << endl;
	cout << "* 3 - Add One Second      *" << endl;
	cout << "* 4 - Exit Program        *" << endl;
	cout << border << endl;

	// no output only visible console output
	return;
}

void displayClock(int userSeconds) {
	// border
	string star(27, '*');
	string space(6, ' ');

	// define variables
	int timeHour;
	int timeMinute;
	int timeSecond;

	// define string variables
	string timeMeridian;
	string timeOutput;

	// store AM/PM
	timeMeridian = (userSeconds > 43199) ? " PM" : " AM";

	// get component parts hour, minute, second
	timeHour = userSeconds / 3600;
	userSeconds = userSeconds % 3600;

	timeMinute = userSeconds / 60;
	userSeconds %= 60;

	timeSecond = userSeconds;

	// display clock to console
	cout << star << space << star << endl;
	cout << "*" << space << "12-Hour Clock" << space << "*";
	cout << space;
	cout << "*" << space << "24-Hour Clock" << space << "*";
	cout << endl;
	// 12 hour clock
	timeOutput = stringTime((timeHour % 12 == 0) ? 12 : timeHour % 12) + ":" +
		stringTime(timeMinute) + ":" + stringTime(timeSecond) + timeMeridian;
	cout << "* " << space << timeOutput << space << " *";
	cout << space;
	// 24 hour clock
	timeOutput = stringTime(timeHour) + ":" + stringTime(timeMinute) + ":" + stringTime(timeSecond);
	cout << "*   " << space << timeOutput << space << "  *";
	cout << endl;
	cout << star << space << star << endl << endl;
	// no output only visible console output
	return;
}

// execute program
int main() {
	// define variables
	char userInput = 0;
	int userTime;

	// get initial time from user
	userTime = initialTime();

	// display error and exit if invalid time inputs
	if (userTime == -1) {
		// todo: instead of exiting should loop through inputs or allow exit
		cout << "There was a problem with1 your inputs." << endl;
		cout << "Please restart the program and try again!" << endl << endl;
		// create a no run condition to exit
		userInput = '4';
	}

	// allow looping of user menu selection
	while (userInput != '4') {
		// commented to match flowchart, but this is the most logical
		// place to display time
		// displayClock(userTime);

		// display selection menu
		displayMenu();

		// get user input
		cin >> userInput;

		switch (userInput) {
			// add an hour in seconds
		case '1':
			userTime += 3600;
			break;
			// add a minute in seconds
		case '2':
			userTime += 60;
			break;
			// add a second in seconds
		case '3':
			userTime += 1;
			break;
			// loopback invalid selection
		default:
			cout << "Invalid selection: Try again!" << endl << endl;
			break;
		}
		// hotfix to not display clock on exit
		if (userInput != '4') {
			// get max value of time in seconds
			userTime %= 86400;
			// display clock
			displayClock(userTime);
		}
	}
	// display exit message
	cout << "Program Finished!" << endl;

	// close main
	return 0;
}
