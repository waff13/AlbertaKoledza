#include <iostream>
#include <fstream>
#include "modules.h"

using namespace std;

struct clientData {
	int accNum;
	char Sur[15];
	char Name[10];
	float balance;
	};
		
void displayMenu() {
	
	bool QUIT = false;
	while (!QUIT) {
		
		cout << "\nSelect an operation:" << endl;
		cout << "1. Add a record" << endl;
		cout << "2. Delete a record" << endl;
		cout << "3. Display all records" << endl;
		cout << "4. Find a record" << endl;
		cout << "5. Change account's balance" << endl;
		cout << "6. Display accounts with negative balance" << endl;
		cout << "7. Count all records" << endl;
		cout << "8. Make a copy of this DB" << endl;
		cout << "0. Exit\n" << endl;
		char userInput;
		cin >> userInput;
		
		switch (userInput) {
			case '1': 
				addRecord();
				break;
			case '2':
				deleteRecord();
				break;
			case '3':
				displayAll();
				break;
			case '4':
				findRecord();
				break;
			case '5':
				changeBalance();
				break;
			case '6':
				displayNegative();
				break;
			case '7':
				countRecords();
				break;
			case '8':
				copyDB();
				break;
			case '0' :
				cout << "Ok, bye!" << endl;
				QUIT = true;
				break;
			default:
				cout << "Please select options from 1 to 8 or 0 to quit.\n" << endl;
		}
	}
}

int main() { // nearly all code in MAIN is taken from example explained in the lecture
	
	clientData blankClient = {0, "", "", 0.0}; // creating empty client
	fstream dbFile; // creating file stream 
	
	dbFile.open("database.dat", ios::out | ios::binary); // opening designated file in read and write mode
	for (int i = 1; i <= 100; i++) {
		dbFile.write((char*)&blankClient, sizeof(clientData)); // writing to file 100 empty clients (stubs)
	}
	dbFile.close(); // closing the opened file 
	
	displayMenu();
}
