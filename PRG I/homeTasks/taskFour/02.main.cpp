// The game where user has to guess 20 words letter by letter.

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 

using namespace std;

int POINTSCOUNTER = 0; // counter for user points
int WORDSGUESSED = 0; // number of words user have guessed
bool GAMEOVER = false; // boolean to check if the game is over
int RANGE = 20; // number of words is the game dictionary

string dictionary[] = {"alabama", "arkansas", "colorado", "delaware", "georgia", "illinois", "kansas", "louisiana", "maryland", "michigan",
			"montana", "nebraska", "oklahoma", "oregon", "texas", "utah", "vermont", "washington", "virginia", "vyoming"};

string checkMove(char userInput, string openWord, string dottedWord);

string getRandomWord() {
    
    srand (time(NULL)); // initializing random seed
    int selected = (rand() % (RANGE)); // getting random number
    string result = dictionary[selected]; // getting the word from dictionary with that random number
    string temp = dictionary[selected]; 
    dictionary[selected] = dictionary[RANGE - 1]; // and then moving this word to the end of the array
    dictionary[RANGE - 1] = temp;
    RANGE--; // and "shortening" the array so the used words are in the end of array and not used while selecting new random words
    return result;
    
    /* THIS CODE ALSO WORKS, JUST REMOVE 8//8 SIGNS
    //string dictionary[] = {"alpha", "bravo", "charlie", "delta", "echo"};
    //srand(time(0));
    int selected = (rand() % (RANGE));
    while (dictionary[selected] == "$$$") {
        cout << "Inside while" << endl;
        selected = (rand() % (RANGE));
    }
    string result = dictionary[selected];
    
    dictionary[selected] = "$$$";
    
    return result;*/
}

int calculatePoints() {
	cout << "Points at start: " << POINTSCOUNTER << endl;
	POINTSCOUNTER = POINTSCOUNTER - 5; // discarding 5 points from penalty score
	if (POINTSCOUNTER < 0) { // if number of points is less than 0 we use 0 as this number cannot be negative
		POINTSCOUNTER = 0;
	}
	cout << "Points after calculations: " << POINTSCOUNTER << endl;
	return POINTSCOUNTER;
}

string checkMove(char userInput, string openWord, string dottedWord) {
	int result[20]; // here we calculate how many of letters in the word the user have guessed with this try.
	int counter = 0; // at the same time we calculate how many times the letter occurs in the word and record
	int length = openWord.length(); // positions of these occurences. 
	for (int i = 0, j = 0; i  < length; i++) {
		if (openWord[i] == userInput) { // we go letter by letter in the word and if user input matches a letter in the word
			result[j] = i; // we record it 
			counter++; // and increase the counter by one
			j++;
		}
	}
	
	if (counter == 0) { // if counter = 0 this means user guess is not correct
		cout << "No such letter! -1 point" << endl;
		POINTSCOUNTER++; // so we are giving him 1 point
		if (POINTSCOUNTER == 10) { // if the amount of points equals 10 the game is over, 
			cout << "Sorry, you have lost!" << endl;
			cout << "You have guessed " << WORDSGUESSED << "of 20 words." << endl; // and we print the final result
			GAMEOVER = true;
			return 0;
		}
	} else { // but if the user input matches at least one letter in the word
		string line;
		line.replace(0, 1, 1, userInput); // we create a 1 symbol long string (for some reason an easy option of "string line(1, userInput);" failed for me)
		for (int i = 0; i < counter; i++){
			//cout << "Position of letter " << userInput << ": " << result[i] << endl;
			dottedWord.replace(result[i], 1, line); // and put in instead of dots in the correct places
			//output.replace(3, 1, "z");    <- works, note that z is in "" ("z"; a string).
		}
	}
	//cout << "Output line: " << dottedWord << endl;
	
	if (dottedWord.find(".") == string::npos) { // if the are no more . in the word that means the user have guessed the word
		if (WORDSGUESSED == 19) { // if guessed words counter reaches 19 this means all the words are guessed and user has won
			cout << "Congratulations, you have won this game!" << endl;
			GAMEOVER = true;
			return 0;
		} else { // if not, that means we need to calculate user points and continue with the game
			cout << "OK, you have guessed this word!" << endl;
			calculatePoints();
			WORDSGUESSED++; // we increase the amount of guessed words by 1
			cout << "That was word " << WORDSGUESSED << " of 20!" << endl;
		}
	}
	return dottedWord;
}

int main() {
	
	while(!GAMEOVER){ // the game runs while it is not over
		
		cout << "The game is on! Make your guess or press 0 to exit" << endl;
		string openWord = getRandomWord(); // getting the random word from array
		string dottedWord;
		for (int i = 0; i < openWord.length(); i++) { // creating the ... representation of the random word
			dottedWord.append(".");
		}
		
		//cout << "  openWord: " << openWord << endl;
		//cout << "dottedWord: " << dottedWord << endl;
		
		char userInput;
		//while(userInput != 48)
		while (dottedWord.find(".") != string::npos) { // while user has not guessed the word (== while there are . in this word)
			userInput = getch(); // we read his input
			if (userInput == 48) { // if user inputs 0 the game is over
				cout << "OK, see you, bye!" << endl;
				GAMEOVER = true; 
				return 0;
			}
			//cout << userInput << ": " << (int)userInput << endl;
			dottedWord = checkMove(userInput, openWord, dottedWord); // checking if the user has guessed the letter and word 
			cout << "Now -> " << dottedWord << endl;
		}
	}
return 0;
}
