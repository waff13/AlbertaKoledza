/* Task 3. A game where user makes the number between 0 and 100 inclusive, and computer tries to guess it.
 * 
 * We ask user to thing of any number within range (0 to 100) and try to guess it. In order to guess the 
 * number we cut the range in half (range is 0 to 100, so the half is 50) and ask user if his number is 
 * higher or lower. If the number is lower, it means the number is between 0 and 50, so we change the 
 * range to (0 - (50 - 1)) from the original (0 - 100). If user says the number is higher, it means it is
 * between 50 and 100, so we change the range to ((50 + 1) - 100) from the original (0 - 100). Than we again 
 * select the middle number in a new range ((0 - 49) or (51 - 100)) and ask user if it is his number. 
 * And again we cut the range according to user's reaction. And by cutting the range we are getting 
 * closer and closer to guessing the number. 
 * 
 * These actions we will put in the loop, and the loop will be broken when the user signals that the 
 * number is guessed. We also use a counter to count moves that is initialised to 1 at the beginning 
 * (because we right from the beginning are asking user if his number is 50, and that is 1st move) 
 * and we increase it in the loop.  
 * 
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Think of a number between 0 and 100 inclusive, and I will guess it." << endl;
	cout << "Let's go!" << endl;
	
	bool gameOver = false;  // setting boolean gameOver to false. We will change it to true when the game is over.
	int movesCount = 1; // setting moves counter to 1
	int high = 100; // setting the highest possible number to 100
	int low = 0; // setting the lowest possible number to 0
	
	while (!gameOver) { // starting a loop with condition that boolean gameOver is false. When it changes to true,
						// the loop ends.
		
		int temp = ((high + low) / 2); // setting a temporary number that is in the middle of the range
		cout << "Is your number " << temp << "?" << endl; // asking the user if that is the correct number 
		cout << "Press 1 if your number is lower, 3 if your number is higher," <<
			" and 0 if this is your number!" << endl;
		
		int result; // creating an integer to read user input
		cin >> result; // putting user input in "result"
		if (result == 1) { // if user inputs 1 that means his number is lower, 
			high = temp - 1; // and because of that we change the range of numbers, making the middle number the highest 
		} else if (result == 3) { // or if the user inputs 3 that means the number is higher
			low = temp + 1; // and because of that we change the range, making the middle number the lowest
		} else if (result == 0) { // if the user inputs 0 that means the user had guessed the number
			cout << "Ha, that was easy! It took me just " << movesCount << " attempts." << endl; // printing the message with number of moves
			gameOver = true; // breaking the loop
		}

		movesCount ++; // increasing the moves count by one
	}
    return 0;
}
