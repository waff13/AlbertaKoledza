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
	//cout << "\n[DONE] Adding a record...\n" << endl;
	
	clientData client;
	fstream dbFile;
	
	//dbFile.open("database.dat", ios::out | ios::binary);
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
	cout << "\nChanging a balance...\n" << endl;
	
}

void copyDB() {
	cout << "\nCopying a database...\n" << endl;
}

void countRecords() {
	//cout << "\n[DONE] Counting records...\n" << endl;
	
	clientData client;
	fstream dbFile;
	int counter = 0;
	
	dbFile.open("database.dat", ios::in | ios::binary);
	dbFile.read((char*)&client, sizeof(clientData));
	
	while(dbFile) {
		if (client.accNum != 0) {
			counter++;
		}
		dbFile.read((char*)&client, sizeof(clientData));
	}
	
	cout << setw(10) << "\nThere are " << counter << " record(s) in this database!\n" << endl;
	
	dbFile.close();
}

void deleteRecord() {
	//cout << "\n[DONE] Deleting a record...\n" << endl;
	
	clientData client;
	fstream dbFile;
	int zero = 0;
	int userInput;
	bool isFound = false;
	
	cout << "Please input account number to delete: ";
	cin >> userInput;
	
	dbFile.open("database.dat", ios::in | ios::out);
	dbFile.read((char*)&client, sizeof(clientData));
	
	while(dbFile) {
		if (client.accNum == userInput) {
			dbFile.seekp((client.accNum-1) * sizeof(clientData));
			//cout << setw(10) << "Deleting this:" << setw(10) << client.accNum << setw(10) << client.Sur << setw(10) << client.Name << setw(10) << client.balance << endl;
			dbFile.write((char*)&zero, sizeof(int));
			isFound = true;
			break;
		} 
		dbFile.read((char*)&client, sizeof(clientData));
	}
	
	if (!isFound) {
		cout << setw(10) << "\nThere are no records with this account number in this database!\n" << endl;
	}
	
	dbFile.close();
}

void displayAll() {
	//cout << "\n[DONE] Displaying all records...\n" << endl;
	
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
		cout << "\n   There are no records in this database!\n" << endl; 
	}
	
	dbFile.close();
	
}

void displayNegative () {
	//cout << "\n[DONE] Showing accounts with negative balance...\n" << endl;
	
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
		cout << setw(10) << "\nThere are no accounts with negative balance!\n" << endl;
	}
	
	dbFile.close();
}

void findRecord() {
	//cout << "\n[DONE] Searching for a record...\n" << endl;
	
	clientData client;
	fstream dbFile;
	int userInput;
	bool isFound = false;
	
	cout << "Please input account number to search for: ";
	cin >> userInput;
	
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
		cout << setw(10) << "\nNo such account number!\n" << endl;
	}

	dbFile.close();
}
