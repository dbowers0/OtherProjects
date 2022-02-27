#include <iostream>
#include <string>
#include "Bank.h"
#include <string>
using namespace std;

int main()
{
	Bank* t = new Bank();
	string choice = " ";
	string again = " ";
	string redo = " ";

	do {
		cout << "MENU" << endl << endl;
		cout << "1. addUser " << endl << "2. removeUser " << endl << "3. editUser " << endl << "4. Transaction " << endl << 
			"5. Print Information ";
		getline(cin, choice);
		
		if (choice == "1")
			t->addUser();
		if (choice == "2")
		{
			cout << "What account Number would you like to remove";
			string account = " ";
			getline(cin, account);;
			stoi(account);
			int account1 = stoi(account);
			t->removeUser(account1);
		}
		if (choice == "3")
		{
			cout << "What account Number would you like to edit";
			string account2 = " ";
			getline(cin, account2);;
			stoi(account2);
			int account3 = stoi(account2);
			t->editUser(account3);
		}
		if (choice == "4")
		{
			cout << "What account Number would you like to perform a transaction ";
			string account3 = " ";
			getline(cin, account3);;
			stoi(account3);
			int account4 = stoi(account3);
			t->transactions(account4);
		}
		
		if (choice == "5")
		{
			t->printInfo();
		}
		cout << "Would you like to perform another task? ";
		getline(cin, again);
		if (again == "n")
			break;
		/*cin >> again;
		cin.get();*/
	} while (again == "y" || "Y");
}
