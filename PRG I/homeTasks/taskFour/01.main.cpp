// This is the code copied from the lecture

/*
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	char c;
	while(c!=27)
	{
		c=getch();
		cout << c << ": " << (int)c << endl;
	}
	
    return 0;
}
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h> // Do I really need this lib?

using namespace std;

int main() {
	
	cout << "Please input time: " << endl;
	string userInput = "";
	cin >> userInput;
	
	if ((userInput[2] != ':') || (userInput[2] != ':')) {
		cout << "Incorrect format (:)" << endl;
		return 0;
	}
	
	/*int i = 0;
	string test = "";
	while (userInput[i] != ':') {
		test = test + userInput[i];
		i++;
	}
	
	cout << "Test string for: -> "<< test << endl;*/
	
	string pair0 = userInput.substr(0,2);
	string pair1 = userInput.substr(3,2);
	string pair2 = userInput.substr(6,2);
	
	cout << "Part 0: " << pair0 << endl;
	cout << "Part 1: " << pair1 << endl;
	cout << "Part 2: " << pair2 << endl;
	
	int hours = atoi(pair0);
    cout << "hours as int: " << hours << endl;
    int minutes = atoi(pair1);
    cout << "minutes as int: " << minutes << endl;
    int seconds = atoi(pair2);
    cout << "seconds as int: " << seconds << endl;
    
    if ((hours < 0) || (hours > 23)) {
        cout << "Incorrect time (hours)" << endl;
        return 0;
    } else if ((minutes < 0) || (minutes > 59)) {
        cout << "Incorrect time (minutes)" << endl;
        return 0;
    } else if ((seconds < 0) || (seconds > 59)) {
        cout << "Incorrect time (seconds)" << endl;
        return 0;
    } else {
        cout << "Oll Korrect" << endl;
    }
	
	
	return 0;
