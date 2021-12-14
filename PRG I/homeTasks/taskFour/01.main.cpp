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

/* This programm asks user for time and checks if the time is entered correctly (correctly = hh:mm:ss). It returns OK status
 * if time is correct, "Incorrect format" error if the format is wrong, and "Incorrect time" if the time itself is invalid.
 * 
 * The format is correct only if the third and sixth symbols in user input are semicolons (:). If not, we can immediately
 * throw the "Incorrect format" error.
 * 
 * If format is OK, we should check if time is ok. For that we can cut the user input into hours, minutes and seconds, and 
 * check them. We can convert each of two symbols to integer and check against ASCII table if this symbol is a digit or not.
 * If it is a digit, we can check if the digit is correct in terms of time, for example, for hours the first digit can be 
 * 0,1,2 but the second can be 0,1,2,3 (because the time goes from 00:00:00 to 23:59:59). Other digits means the time is 
 * incorrect, and we should notify the user about it.
 */


#include <iostream>
#include <conio.h>
//#include <stdlib.h> I don't think I really need this lib on Windows

using namespace std;

int main() {
	
	cout << "Please input time: " << endl; // asking user for input
	string userInput = "";
	cin >> userInput; // getting user input
	
	if ((userInput[2] != ':') || (userInput[5] != ':')) { // time should be in format hh:mm:ss, so we check if the semicolons (:)
		cout << "Incorrect format (:)" << endl; // are located where they should be, and throwing an error if they are not
		return 0;
	}
	
	/*int i = 0;
	string test = "";
	while (userInput[i] != ':') {
		test = test + userInput[i];
		i++;
	}
	
	cout << "Test string for: -> "<< test << endl;*/
	
	string hours = userInput.substr(0,2); // getting first two symbols from user input, these are hours
	string minutes = userInput.substr(3,2); // getting the 4th and 5th symbols, these are minutes
	string seconds = userInput.substr(6,2); // getting the 7th and 8th symbols, these are seconds
	
	//cout << "Part 0: " << hours << endl;
	//cout << "Part 1: " << minutes << endl;
	//cout << "Part 2: " << seconds << endl;
	
	// 0 = 48 | 2 = 50 | 3 = 51 | 5 = 53 | 9 = 57
	
	//cout << "pair0[0] = " << hours[0] << ", pair0[1] = " << hours[1] << endl;
	//cout << "(int) pair0[0] = " << (int) hours[0] << ", (int) pair0[1] = " << (int) hours[1] << endl;
	
	/* We check each symbol for correctness, converting it to integer and checking against ASCII table where 0 = 48 and 9 = 57.
	Since hours can be from 00 to 23 we should check the first symbol is between 0 (48 in ASCII) and 2 (50), and the second 
	is between 0 (48) and 3 (51). For minutes and seconds it is from 00 to 59, so the first symbol is > 0 and < 6, the 
	second -- > 0 and < 9. THAT APPROACH IS NOT ENTIRELY CORRECT!!1
	
	if ( (((int)hours[0]) < 48 || ((int)hours[0] > 50)) || (((int)hours[1] < 48) || ((int)hours[1] > 51)) )
	{
		cout << "Incorrect time (hours)" << endl;
	} else if ((((int)minutes[0]) < 48 || ((int)minutes[0] > 53)) || (((int)minutes[1] < 48) || ((int)minutes[1] > 57))) {
		cout << "Incorrect time (minutes)" << endl;
	} else if ((((int)seconds[0]) < 48 || ((int)seconds[0] > 53)) || (((int)minutes[1] < 48) || ((int)minutes[1] > 57))) {
        cout << "Incorrect time (seconds)" << endl;
    } else {
        cout << "This time is OK!" << endl;
    }*/
	
	// We check each of strings for hours, minutes and seconds for correctness, converting it to integer with stoi() function.
	// Since hours can be from 00 to 23 we should check that hours are > 0 and < 23. For minutes and seconds it is from 
	// 00 to 59, so we should check that these are > 0 and < 59. 
	
	if ((stoi(hours) < 0) || (stoi(hours) > 23)) {
		cout << "Incorrect time (hours)" << endl;
	} else if ((stoi(minutes) < 0) || (stoi(minutes) > 59)) {
		cout << "Incorrect time (minutes)" << endl;
	} else if ((stoi(seconds) < 0) || (stoi(seconds) > 59)) {
		cout << "Incorrect time (seconds)" << endl;
	} else {
		cout << "This time is OK!" << endl;
	}
	
	
	/*if ( (((int)hours[0]) < 48 || ((int)hours[0] > 50)) || (((int)hours[1] < 48) || ((int)hours[1] > 51)) )
	{
		cout << "Incorrect time (hours)" << endl;
	} else if ((((int)minutes[0]) < 48 || ((int)minutes[0] > 53)) || (((int)minutes[1] < 48) || ((int)minutes[1] > 57))) {
		cout << "Incorrect time (minutes)" << endl;
	} else if ((((int)seconds[0]) < 48 || ((int)seconds[0] > 53)) || (((int)minutes[1] < 48) || ((int)minutes[1] > 57))) {
		cout << "Incorrect time (seconds)" << endl;
	} else {
		cout << "This time is OK!" << endl;
	}*/
	
	return 0;
}
	
	/*int hours = stoi(pair0);
    cout << "hours as int: " << hours << endl;
    int minutes = stoi(pair1);
    cout << "minutes as int: " << minutes << endl;
    int seconds = stoi(pair2);
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
    }*/
	return 0;
}
