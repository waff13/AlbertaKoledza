#include <iostream>
#include <fstream>
#include <iomanip>
#include "modules.h"

using namespace std;

struct clientData {
	int accNum;
	char Sur[15];
	char Name[10];
	float balance;
	};

void addRecord() {
	
	clientData client;
	fstream dbFile;
	
	dbFile.open("database.dat", ios::out | ios::in | ios::binary);
	cout << "Enter account number (1 to 100, 0 to end input)" << endl;
	cin >> client.accNum;
	
	while (client.accNum != 0) {
		cout << "Enter lastname, firstname, balance" << endl;
		cin >> client.Sur >> client.Name >> client.balance;
		dbFile.seekp((client.accNum-1) * sizeof(clientData), ios::beg);
		dbFile.write((char*)&client, sizeof(clientData));
		cout << "Enter account number" << endl;
		cin >> client.accNum;
	}
	
	dbFile.close();
}

void changeBalance() {
	
	clientData client;
	fstream dbFile;
	int userInput;
	float newBalance;
	bool isFound = false;
	
	cout << "Please input account number to change balance: ";
	cin >> userInput;
	
	if (userInput != 0) {
		dbFile.open("database.dat", ios::in | ios::out | ios::binary); // opening binary file in read and write mode
		dbFile.read((char*)&client, sizeof(clientData)); // read the first chunk of data from the file
		
		while(dbFile) { // while the end of original file is not reached
			if (client.accNum == userInput) { // if user inputs the existing account number
				cout << "Please input balance change for this account: ";
				cin >> newBalance; // user inputs the amount to add to the current balance
				dbFile.seekp((client.accNum-1) * sizeof(client)); // finding the correct position to write new balance data
				client.balance = client.balance + newBalance; // changing the balance
				cout << "New balance for account " << userInput << " is " << client.balance << endl;
				dbFile.write((char*)&client, sizeof(clientData)); // updating the record in database with the new balance
				isFound = true; // setting the isFound flag to true
				break;
			}
			
			dbFile.read((char*)&client, sizeof(clientData));
		}
	}
	
	if (!isFound) { // if user inputs non-existent account we print the error message
		cout << "\nThere are no records with this account number in this database!" << endl;
	}
	
	dbFile.close(); // closing the opened file
}

void copyDB() { // code is taken from the lecture example
	
	fstream copyFrom ("database.dat", ios::in); // opening file stream for the file, in read mode
	fstream copyTo ("database_copy.dat", ios::out); // opening file stream for tht file copy, in write mode
	char symbol;
	copyFrom.get(symbol);
	
	while (copyFrom) { // while the end of original file is not reached symbol is taken from original file and put into copy of the file
		copyTo.put(symbol);
		copyFrom.get(symbol);
	}
	
	copyTo.close(); // closing both files
	copyFrom.close();
	
	cout << "Database copied to database_copy.dat" << endl;
	/*cout << "And now lets check that everything is copied right\n" << endl;
	
	clientData client;
	fstream dbFile;
	bool isFound = false;
	
	dbFile.open("database_copy.dat", ios::in | ios::binary);
	cout << setw(10) << "Account" << setw(10) << "Surname" << setw(10) << "Name" << setw(10) << "Balance" << endl;
	dbFile.read((char*)&client, sizeof(clientData));
	
	while(dbFile) {
		if (client.accNum != 0) {
			cout << setw(10) << client.accNum << setw(10) << client.Sur << setw(10) << client.Name << setw(10) << client.balance << endl;
			isFound = true;
		}
		dbFile.read((char*)&client, sizeof(clientData));
	}
	
	if (!isFound) {
		cout << "\n   There are no records in this database!\n" << endl; 
	}
	
	dbFile.close();*/
}

void countRecords() {
	
	clientData client;
	fstream dbFile;
	int counter = 0;
	
	dbFile.open("database.dat", ios::in | ios::binary); 
	dbFile.read((char*)&client, sizeof(clientData));
	
	while(dbFile) {
		if (client.accNum != 0) { // counting every account number that is not 0
			counter++;
		}
		dbFile.read((char*)&client, sizeof(clientData));
	}
	
	cout << "\nThere are " << counter << " record(s) in this database!" << endl;
	
	dbFile.close();
}

void deleteRecord() {
	
	clientData client;
	fstream dbFile;
	int zero = 0;
	int userInput;
	bool isFound = false;
	
	cout << "Please input account number to delete: ";
	cin >> userInput;
	
	if (userInput != 0) {
		dbFile.open("database.dat", ios::in | ios::out);
		dbFile.read((char*)&client, sizeof(clientData));
		
		while(dbFile) {
			if (client.accNum == userInput) { // if user inputs existing account number
				dbFile.seekp((client.accNum-1) * sizeof(clientData)); // finding the correct position to change data
				dbFile.write((char*)&zero, sizeof(int)); // writing 0 as an account number, thus making this record "invisible"
				isFound = true;
				cout << "Account " << userInput << " successfully deleted." << endl;
				break;
			} 
			dbFile.read((char*)&client, sizeof(clientData));
		}
	}
	
	if (!isFound) {
		cout << "\nThere are no records with this account number in this database!" << endl;
	}
	
	dbFile.close();
}

void displayAll() {
	
	clientData client;
	fstream dbFile;
	bool isFound = false;
	
	dbFile.open("database.dat", ios::in | ios::binary);
	cout << setw(10) << "Account" << setw(10) << "Surname" << setw(10) << "Name" << setw(10) << "Balance" << endl;
	dbFile.read((char*)&client, sizeof(clientData));
	
	while(dbFile) {
		if (client.accNum != 0) {
			cout << setw(10) << client.accNum << setw(10) << client.Sur << setw(10) << client.Name << setw(10) << client.balance << endl;
			isFound = true;
		}
		dbFile.read((char*)&client, sizeof(clientData));
	}
	
	if (!isFound) {
		cout << "\n   There are no records in this database!" << endl; 
	}
	
	dbFile.close();
}

void displayNegative () {
	
	clientData client;
	fstream dbFile;
	bool isFound = false;
	
	dbFile.open("database.dat", ios::in | ios::binary);
	dbFile.read((char*)&client, sizeof(clientData));
	cout << setw(10) << "Account" << setw(10) << "Surname" << setw(10) << "Name" << setw(10) << "Balance" << endl;
	
	while(dbFile) {
		if (client.balance < 0) {
			cout << setw(10) << client.accNum << setw(10) << client.Sur << setw(10) << client.Name << setw(10) << client.balance << endl;
			isFound = true;
		}
		dbFile.read((char*)&client, sizeof(clientData));
	}
	
	if (!isFound) {
		cout << "\n   There are no accounts with negative balance!" << endl;
	}
	
	dbFile.close();
}

void findRecord() {
	
	clientData client;
	fstream dbFile;
	int userInput;
	bool isFound = false;
	
	cout << "Please input account number to search for: ";
	cin >> userInput;
	
	if (userInput > 0) {
		dbFile.open("database.dat", ios::in | ios::binary);
		dbFile.read((char*)&client, sizeof(clientData));
		
		while(dbFile) {
			if (client.accNum == userInput) {
				cout << setw(10) << "Account" << setw(10) << "Surname" << setw(10) << "Name" << setw(10) << "Balance" << endl;
				cout << setw(10) << client.accNum << setw(10) << client.Sur << setw(10) << client.Name << setw(10) << client.balance << endl;
				isFound = true;
			}
			dbFile.read((char*)&client, sizeof(clientData));
		}
		
		if (!isFound) {
			cout << setw(10) << "\nNo such account number!" << endl;
		}
		
		dbFile.close();
		
	} else {
		cout << setw(10) << "\nNo such account number!" << endl;
	}
}
