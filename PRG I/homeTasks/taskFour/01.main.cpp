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
	
	string part0 = userInput.substr(0,2);
	string part1 = userInput.substr(3,2);
	string part2 = userInput.substr(6,2);
	
	cout << "Part 0: " << part0 << endl;
	cout << "Part 1: " << part1 << endl;
	cout << "Part 2: " << part2 << endl;
	
	
	cout << "Here: " << userInput << endl;
	
	return 0;
}
