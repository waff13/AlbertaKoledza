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
	// cout << "\n[DONE] Changing a balance...\n" << endl;
	
	clientData client;
	fstream dbFile;
	//int zero = 0;
	int userInput;
	float newBalance;
	bool isFound = false;
	
	cout << "Please input account number to change balance: ";
	cin >> userInput;
	
	dbFile.open("database.dat", ios::in | ios::out | ios::binary);
	dbFile.read((char*)&client, sizeof(clientData));
	
	while(dbFile) {
		if (client.accNum == userInput) {
			cout << "Please input balance change for this account: ";
			cin >> newBalance;
			
			//cout << "Ok, we will set " << newBalance << " as a new balance for account " << userInput << endl;
			dbFile.seekp((client.accNum-1) * sizeof(client));
			//cout << setw(10) << "Deleting this:" << setw(10) << client.accNum << setw(10) << client.Sur << setw(10) << client.Name << setw(10) << client.balance << endl;
			client.balance = client.balance + newBalance;
			dbFile.write((char*)&client, sizeof(clientData));
			isFound = true;
			break;
		} 
		dbFile.read((char*)&client, sizeof(clientData));
	}
	
	if (!isFound) {
		cout << "\nThere are no records with this account number in this database!" << endl;
	}
	
	dbFile.close();
}

void copyDB() {
	//cout << "\n[DONE] Copying a database...\n" << endl;
	
	fstream fails_no ("database.dat", ios::in);
	fstream fails_uz ("database_copy.dat", ios::out);
	char symbol;
	fails_no.get(symbol);
	
	while (fails_no) {
		fails_uz.put(symbol);
		fails_no.get(symbol);
	}
	
	fails_uz.close();
	fails_no.close();
	
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
	
	cout << "\nThere are " << counter << " record(s) in this database!" << endl;
	
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
		cout << "\nThere are no records with this account number in this database!" << endl;
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
		cout << "\n   There are no records in this database!" << endl; 
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
		cout << "\n   There are no accounts with negative balance!" << endl;
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
	
	/*dbFile.open("database.dat", ios::in | ios::binary);
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

	dbFile.close();*/
}
