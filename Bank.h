#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Bank
{
public:
	void addUser();
	void removeUser(int);
	void editUser(int);
	void transactions(int);
	void printInfo();

private:
	string names[100] = { };
	string address[100] = {  };
	int accountNumber[100] = { };
	double amount[100] = {  };
	string phoneNumbers[100] = { };
	string transaction1 = " ";
	string balance[100] = { };
	int numberofAccounts = 0;
};
#pragma once
