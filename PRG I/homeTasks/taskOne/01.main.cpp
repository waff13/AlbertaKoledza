/* Task 1(a). Programm checks if given number is a palindrome.
 * 
 * It receives user input, than constructs the reversed version of the received number
 * by cutting the last digit of the number and putting it in front of the reversed number.
 * For example, with 123 in order to construct reversed number we need to cut the last digit (3)
 * and add it to the reversed number (now it is 3), than from remaining 12 again cut the last 
 * digit (now it is 2) and add it to the reversed number (now it is 32), than from remainig 1 take
 * this 1 and add it to the reversed number (now it is 321). 
 * 
 * That cutting and adding can be done in the loop, that ends when the number we process has no digits 
 * left. 
 * 
 * Than we have to check if initiall number
 * (123) is equal to the reversed number (321). If yes, the number is a palindrome, if not, 
 * the number is not a palindrome.
*/ 

#include <iostream>

using namespace std;

int main()
{
    int userInput = 0;	// number that user will enter
	int temp = 0;		// temporary number we need to operate on
	int reversedNumber = 0;	// reversed number, i.e. user enters 123, reversed number is 321 
	
	cout << "Please enter a number" << endl; // invite user to enter a number
	cin >> userInput; // reading user input
	temp = userInput; // assigning user input to temporary number
	
	while (temp != 0) { // loop that operates until temporary number is not equal to zero
		int lastDigit = (temp %  10); // extracting last digit
		reversedNumber = (reversedNumber * 10) + lastDigit; // building reversed number by taking last digit
															// from the temporary number and putting it in front
															// of the reversed number
		temp = (temp / 10); // cutting off the last digit from the temporary number
	}
	
	if (userInput == reversedNumber) { // checking if number entered by user is equal to the reversed number
		cout << "Yes, " << userInput << " is a palindrome!" << endl; // if yes, printing a message
	} else { // in other case
		cout << "No, " << userInput << " is NOT a palindrome!" << endl; // printing another message
	}
	
    return 0;
}
