// Create two-dimensional array and rotate it 90 degrees clockwise.

#include <iostream>
#include <time.h>

using namespace std;

void printArray(int array[][10], int, int);
void rotateArray(int array[][10], int, int);

int main() {
	
	srand (time(NULL)); // initializing random seed
	const int N = 10;
	const int M = 10;
	int array[N][M];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			array[i][j] = rand() % 100;
		}
	}
	
	printArray(array, N, M);
	rotateArray(array, N, M);
	//printArray(array, N, M); // A POINTER SHOULD BE USED HERE IN ORDER TO DESIGNATE THE ARRAY TO ROTATE AND TO PRINT AFTER ROTATION
	
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (array[i][j] < 10) { // if the number is less than 10
				cout << "0" << array[i][j] << " "; // we print additional 0 in front of the number for the array to look nicer
			} else { // if the number is 10 or bigger
				cout << array[i][j] << " "; // we just print out the number and a space after it
			}
		}
		cout << endl;
	}*/
	
	//system("pause");
	return 0;
}

void printArray(int array[][10], int N, int M) {
	cout << "In printArray(): " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (array[i][j] < 10) { // if the number is less than 10
				cout << "0" << array[i][j] << " "; // we print additional 0 in front of the number for the array to look nicer
			} else { // if the number is 10 or bigger
				cout << array[i][j] << " "; // we just print out the number and a space after it
			}
		}
		cout << endl;
	}
}

void rotateArray(int array[][10], int N, int M) {
	/*cout << endl;
	cout << "M is " << M << endl;
	cout << "In rotateArray(): " << endl;
	cout << "arr[0][0] = " << array[0][0] << endl;
	for (int i = 0; i < N; i++) {
		array[i][M] = 999; // N defines COLUMNS, M defines ROWS
	}
	cout << "Now M is " << M << endl;*/
	
	int rotated[N][M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
		rotated[i][j] = array[N - j - 1][i];
		}
	}
	cout << endl;
	cout << "Rotated array: " << endl;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (rotated[i][j] < 10) { // if the number is less than 10
				cout << "0" << rotated[i][j] << " "; // we print additional 0 in front of the number for the array to look nicer
			} else { // if the number is 10 or bigger
				cout << rotated[i][j] << " "; // we just print out the number and a space after it
			}
		}
		cout << endl;
	}
}


/*
 * 1 2 3    7 4 1 
 * 4 5 6 -> 8 5 2 
 * 7 8 9    9 6 3 


01 02 03 04    13 09 05 01 
05 06 07 08 -> 14 10 06 02
09 10 11 12 -> 15 11 07 03
13 14 15 16    16 12 08 04

Basically the first ROW becomes the first COLUMN from DOWN->UP. The first row is 01 05 09 13, and in correct position
it shousd be vice versa - 13 09 05 01.*/
