/* Task 2. A game where user has 10 attempts to guess a number between 0 and 100 inclusive.
 * 
 * We need to create a random number that user should guess. Than we create a loop inside which user 
 * inputs his guess, we check his guess against the number that should be guessed, and inform user if 
 * his number is lower or higher. In this loop we also count user' moves. 
 * 
 * When user guessed the number correctly or user has used out his 10 moves we break the loop and end 
 * the game.
 * 
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Can you guess my number? It is between 0 and 100. Can you guess it in 10 attempts or less?" << endl;
	
	bool gameOver = false; // setting boolean gameOver to false. We will change it to true when the game is over. 
	int numberToGuess = (rand() % 101); // creating random number that user should guess, it is between 0 and 100 inclusive
	int userInput; // the number that user will enter
	int movesCount = 0; // counter of moves
	
	while (!gameOver) { // starting a loop with condition that boolean gameOver is false. When it changes to true,
						// the loop ends.
		
		cout << "Make your guess: " << endl; // invite user to make a guess
		cin >> userInput; // reading user input and assigning it to userInput
		movesCount++; // after user inputs his number we increase the counter of user moves
		if (userInput == numberToGuess) { // if user number equals the number that he should guess
			cout << "Yup, " << numberToGuess << " was my number! You guessed it in " << movesCount << " attempts!" << endl; 
			// printing message with the number user guessed and how many moves it took to guess
			gameOver = true; // setting gameOver to true and thus braking the loop because the game is over
		} else if (userInput > numberToGuess) { // if the users number is bigger than the number to guess
			cout << "No, my number is lower" << endl; // print a corresponding message
		} else if (userInput < numberToGuess) { // in case users number is lower than the number to guess
			cout << "No, my number is higher" << endl; // print another corresponding message
		}
		
		if ((!gameOver) && (movesCount == 10)) { // if the game is not over and counter of moves reaches 10
			cout << "Oh no, you did not make it in 10 attempts!" << endl; // we inform user that he did not guessed the number in 10 attempts,
			cout << "My number was " << numberToGuess << ". Game over!" << endl; // and display the number, 
			gameOver = true; // and break the loop
		}
	}
    return 0;
}
