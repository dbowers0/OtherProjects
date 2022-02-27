#include <iostream>
#include "College.h"
#include <fstream>
#include <cstring>

using namespace std;

string College::assign()
{
	string* ptrName = name;
	string* type = typeofInstitution;
	string* ptrState = state;

	int turn = 0;
	//fstream in_file;

	//Open file for input
	fstream in_file("collegeNames.txt", ios::in);
	
	//Test for file opening
	if (!in_file)
	{
		cout << "Cannot open words1.txt for reading" << endl;
	}

	//Open file for output
	fstream out_file("out.txt", ios::out);

	//Test for opening
	if (!out_file)
	{
		cout << "Cannot open out.txt for writing" << endl;
	}
	int i = 0;
	while (true)
	{
		//Read one word at a time
		//getline(in_file, name[i], '|');
		in_file >> name[i];
		getline(in_file, name[i], '|');
		
		//Test for eof
		if (in_file.eof())
			break;
		i++;
	}

	for (int i = 0; i < 100; i++)
	{
		cout << name[i] << endl;
	}
	//cout << name[0];
	return name[CAPACITY];
}

/*string College::assignState()
{
	string state[CAPACITY];
}

string College::assignInstitution()
{
	string typeofInstitution[CAPACITY];
	int cost[CAPACITY];
	double Rate[CAPACITY];
}

double College::assignCost()
{
	int cost[CAPACITY];
}

double College::assignRate()
{
	double Rate[CAPACITY];
}*/

/*string College::Hello(string userState)
{
	for (int i = 0; i < CAPACITY; i++)
	{
		if (userState == state[i])
		{

		}
	}
}*/
