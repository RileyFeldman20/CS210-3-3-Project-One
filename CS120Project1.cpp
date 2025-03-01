/*
Riley Feldman
1/20/2025
CS210 Project One
*/

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

//Displays the menu options for the user.
void ShowMenu() {
	cout << "**************************" << endl;
	cout << "* 1 - Add One Hour       *" << endl;
	cout << "* 2 - Add One Minute     *" << endl;
	cout << "* 3 - Add One Second     *" << endl;
	cout << "* 4 - Exit Program       *" << endl;
	cout << "**************************" << endl;
}

//Displays the clocks for the user.
void ShowClock(int& hours, int& minutes, int& seconds) {
	if (hours > 12) {
		int hoursstd = hours - 12;
		cout << "\n**************************     *************************" << endl;
		cout << "*      12-Hour Clock     *     *     24-Hour Clock     *" << endl;
		cout << "*       " << setfill('0') << setw(2) << hoursstd << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << " pm      *" 
			 << "     *       " << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << "        *" << endl;
		cout << "**************************     *************************" << endl << endl;
	}
	else if (hours == 12) {
		int hoursstd = 12;
		cout << "\n**************************     *************************" << endl;
		cout << "*      12-Hour Clock     *     *     24-Hour Clock     *" << endl;
		cout << "*       " << setfill('0') << setw(2) << hoursstd << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << " pm      *"
			<< "     *       " << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << "        *" << endl;
		cout << "**************************     *************************" << endl << endl;
	}
	else if (hours == 0) {
		int hoursstd = 12;
		cout << "\n**************************     *************************" << endl;
		cout << "*      12-Hour Clock     *     *     24-Hour Clock     *" << endl;
		cout << "*       " << setfill('0') << setw(2) << hoursstd << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << " am      *"
			<< "     *       " << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << "        *" << endl;
		cout << "**************************     *************************" << endl << endl;
	}
	else {
		cout << "\n**************************     *************************" << endl;
		cout << "*      12-Hour Clock     *     *     24-Hour Clock     *" << endl;
		cout << "*       " << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << " am      *"
			<< "     *       " << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << "        *" << endl;
		cout << "**************************     *************************" << endl << endl;
	}
}

//Handles time inputs to ensure values cannot exceed possible values on a clock.
void TimeHandling(int& hours, int& minutes, int& seconds) {
	if (seconds == 60) {
		seconds = 0;
		minutes += 1;
	}

	if (minutes == 60) {
		minutes = 0;
		hours += 1;
	}

	if (hours > 23) {
		hours = 0;
	}
	ShowClock(hours, minutes, seconds);
}

int main() {
	string input;
	bool terminateProgram = false;
	bool exception = false;
	int hours, minutes, seconds;
	char delimiter;

	cout << "Hello, please enter your current time! Example HH:MM:SS in 24 HR FORMAT" << endl;
	
	//Error handling for inputting anything other than the specific time format asked for processing.
	do {
		getline(cin, input);
		stringstream userTime(input);

		if (userTime >> hours >> delimiter >> minutes >> delimiter >> seconds && delimiter == ':') {
			if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59) {
				cout << "\nValid time: "
					<< setfill('0') << setw(2) << hours << ":"
					<< setfill('0') << setw(2) << minutes << ":"
					<< setfill('0') << setw(2) << seconds << endl;
				
				ShowClock(hours, minutes, seconds);
				exception = true;
			}
			else {
				cout << "Invalid time format.\nPlease input a valid time! Example HH:MM:SS in 24 HR FORMAT" << endl;
			}
		}
		else {
			cout << "Invalid time format.\nPlease input a valid time! Example HH:MM:SS in 24 HR FORMAT" << endl;
		}
	} while (exception != true);

	//Main program loop.
	int userInput = 1;
	while (terminateProgram != true) {
		ShowMenu();
		cin >> userInput;
		//Error handling built in for inputting anything outside of the provided 1-4 inputs of the menu.
		if (userInput >= 1 && userInput <= 4) {
			switch (userInput) {
				//Case adds one hour and pushes all values to TimeHandling() to correct for values exceeding possible values.
			case 1:
				hours += 1;
				TimeHandling(hours, minutes, seconds);
				break;
				//Case adds one minute and pushes all values to TimeHandling() to correct for values exceeding possible values.
			case 2:
				minutes += 1;
				TimeHandling(hours, minutes, seconds);
				break;
				//Case adds one second and pushes all values to TimeHandling() to correct for values exceeding possible values.
			case 3:
				seconds += 1;
				TimeHandling(hours, minutes, seconds);
				break;
				//Case breaks the loop, thus ending the program.
			case 4:
				cout << "Exiting Program..." << endl;
				terminateProgram = true;
				break;
			}
		}
		else {
			cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
			continue;
		}
	}
		
	cout << "Program terminated successfully :)" << endl;
	return 0;
}