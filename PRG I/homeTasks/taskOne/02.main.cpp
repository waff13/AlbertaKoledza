/* Task 1(b). Print out all 6-digit palindromes.
 * 
 * In order to print out all 6-digit palindrome numbers we can loop througth all 6 digit numbers 
 * (that is from 100 000 to 999 999 inclusive) and check if that particulat number is a palindrome.
 * Checking if the number is palindrome is taken from the previous task and is described in details there.
 *  
*/

#include <iostream>

using namespace std;

int main()
{
	int temp = 0; // temporaty number, we need it to operate on
	
	for (int number = 100000; number < 1000000; number++) { // loop from 100000 till 999999 inclusive
		temp = number; // assign current number in the loop to temporary number
		int reversedNumber = 0; // reversed number we will check against the number 
		while (temp != 0) {  // loop that operates until temporary number is not equal to zero
			int lastDigit = (temp % 10); // extracting last digit
			reversedNumber = (reversedNumber * 10) + lastDigit; // constructing reversed number
			temp = (temp / 10);  // cutting off the last digit from the temporary number
		}
		if (number == reversedNumber) { // if number equals reversed number the number is palindrome
		cout << number << endl;	// in that case it gets printed out
		}
	}
    
    return 0;
}
