#include <iostream>
#include <cmath>
#include <string>
#include "Bank.h"
#include <iomanip>

using namespace std;

void Bank::addUser()
{
	string input = "";
	for(int i = 0; i < 100; i++)
	{
		//searches for avaliable spot
		if (names[i].length() < 1)
		{
			accountNumber[i] = i + 1;
			cout << accountNumber[i] << endl << endl;
			numberofAccounts++;

			//Allows to enter data
			cout << "Name: ";
			getline(cin, names[i]);
			cout << endl << endl;

			cout << "Address: ";
			getline(cin, address[i]);
			cout << endl << endl;

			
			cout << "Phone Number: ";
			getline(cin, phoneNumbers[i]);
			cout << endl << endl;

			cout << "Deposit Amount: $";
			getline(cin, balance[i]);
			cout << endl << endl;


			/*cout << "add another User?";
			getline(cin,input);*/

			if (input == "n" || "N")
			{
				break;
			}
		}
		
		
		
	}

}

void Bank::removeUser(int account)
{
	bool found = false;
	for (int i = 0; i < 100; i++)
	{
		if(accountNumber[i] == account)
		{
			cout << "Account Number found" << endl;
			found = true;
		}
	}

	if (found == true)
	{
		//removes data from arrays

		names[account-1] = "";
		address[account - 1] = "";
		phoneNumbers[account - 1] = "";
		balance[account - 1] = "";

		numberofAccounts--;
	}
}

void Bank::editUser(int account)
{
	bool found = false;
	for (int i = 0; i < 100; i++)
	{
		if (accountNumber[i] == account)
		{
			cout << "Account Number found" << endl;
			found = true;
		}

	}

	cout << "Edit 1. Address or 2. Phone Number? ";
	string decision = "";
	cout << endl << endl;

	getline(cin, decision);

	if (decision == "1")
	{
		string newAddress = " ";
		cout << "New Address: ";
		getline(cin, newAddress);
		address[account-1] = newAddress;
	}
	
	if (decision == "2")
	{
		string newNumber = "";
		cout << "New Phone Number: ";
		getline(cin, newNumber);
		phoneNumbers[account-1] = newNumber;
	}

	/*for (int i = 0; i < 100; i++)
	{
		cout << names[i] << " ";
		cout << address[i] << " ";
		cout << phoneNumbers[i] << " ";
	}*/

}

void Bank::transactions(int account1)
{
	bool again = false;
	int withdrawl = 0;
	int withdrawl2 = 0;
	cout << "1. Deposit 2. Withdrawl ";
	string choice = " ";
	getline(cin, choice);
	
	bool found = false;
	for (int i = 0; i < 100; i++)
	{
		if (accountNumber[i] == account1)
		{
			cout << "Account Number found" << endl;
			found = true;
		}

	}
	 
	cout << endl << endl;
	if (found == true)
	{

		if (choice == "1")
		{
			cout << "Deposit Amount: ";
			getline(cin, transaction1);

			int deposit = stoi(transaction1);
			int deposit1 = stoi(balance[account1-1]);

			int finalBalance = deposit + deposit1;

			balance[account1 - 1] = to_string(finalBalance);

			cout << "Balance: " << balance[account1 - 1];
		}

		if (choice == "2")
		{

			do
			{
				again = false;
				cout << "Withdrawl Amount: ";
				getline(cin, transaction1);
				withdrawl = stoi(transaction1);
				withdrawl2 = stoi(balance[account1 - 1]);
				if (withdrawl > withdrawl2)
				{
					cout << "Can't Withdrawl more than what is Avaliable in Balance " << endl << endl;
					again = true;
				}
			} while (again == true);

			int withdrawl3 = withdrawl2 - withdrawl;

			balance[account1 - 1] = to_string(withdrawl3);
			cout << "Balance: " << balance[account1 - 1];
		}
	}
}

void Bank::printInfo()
{
	cout << endl << endl;
	cout << "Names             Addresses                Phone Numbers         Balance" << endl;
	cout << "___________________________________________________________________________________________" << endl;
	
	for (int i = 0; i < numberofAccounts; i++)
	{
		cout << setprecision(0) << fixed << showpoint;
		cout << setw(18) << left << names[i];
		cout << setw(25) << address[i];
		cout << setw(22) << phoneNumbers[i];
		cout << "$" << balance[i];
		cout << endl;

	}
}