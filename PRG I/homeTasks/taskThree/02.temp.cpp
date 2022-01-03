// Tic-tac-toe game

#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

bool GAMEOVER = false;
bool QUIT = false;

int whoStarts() {
	srand(time(NULL)); // initializing random seed
	int move = rand() % 2;
	cout << "random 0 or 1: " << move << endl;
	//return rand() % 1;
	return move;
}

void onePlayerGame() {
	if (whoStarts() == 0) {
		cout << "Please wait for your turn..." << endl;
	} else {
		cout << "It's your turn now!" << endl;
	}
}

void twoPlayersGame() {
	if (whoStarts() == 0) {
		cout << "Player 1, it is your move" << endl;
	} else {
		cout << "Player 2, it is your turn" << endl;
	}
}

void displayField() {
	int array[4][4];
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			array[i][j] = 8;
		}
	}
	
	for (int i = 0; i < 4; i++) {
		array[0][i] = i;
		array[i][0] = i;
	}
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void displayMenu() {
	cout << "Welcome to the game of Tic Tac Toe!" << endl;
	cout << "Press 1 to play against the computer and 2 for a 2-player game" << endl;
	
	char userInput;
	cin >> userInput;
	switch (userInput) {
		case '1': 
			cout << "vs. computer" << endl;
			onePlayerGame();
			break;
		case '2':
			cout << "vs. human" << endl;
			twoPlayersGame();
			break;
		default:
			cout << "Only 1 or 2, please!" << endl;
			break;
	}
}

int main() {
	while (!GAMEOVER) {
		displayMenu();
		//displayField();
		cout << "...and someone has won!" << endl;
		
		while (!QUIT) {
			cout << "Press Y to play again or N to quit" << endl;
			char userInput;
			cin >> userInput;
			switch (userInput) {
				case 'Y':
				case 'y':
					cout << "Great, lets play again!" << endl;
					main();
					break;
				case 'N':
				case 'n':
					cout << "Ok bye!" << endl;
					QUIT = true;
					break;
				default:
					cout << "Only Y(es) or N(o), please! " << endl;
					break;
			}
		}
		GAMEOVER = true;
	}
	return 0;
}
