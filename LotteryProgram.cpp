//Darius Bowers
//Lottery program that takes 7 numbers and compares them to people in a list. Sorts by alphabetical order the names
//and show the id, matches, and numbers picked
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Lottery
{
	int id;
	string name;
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
	int num6;
	int num7;
	int lotteryNums;
	int match;
	double money;
};

const int COUNT = 50;
void getInfo(Lottery[], int&);
void compare(Lottery[], int);
void display(Lottery[], int);

int main()
{
	Lottery lottery[50];
	int numel = 0;
	getInfo(lottery, numel);
	compare(lottery, numel);
	display(lottery, numel);
}

void getInfo(Lottery lottery[], int& numel) //gets the info from the text file and 7 numbers
{
	ifstream inFile;
	inFile.open("guesses1.txt");

	int i = 0;

	while (!inFile.eof())
	{
		inFile >> lottery[i].id;

		numel += 1;
		getline(inFile, lottery[i].name);


		inFile >> lottery[i].num1;


		inFile >> lottery[i].num2;


		inFile >> lottery[i].num3;


		inFile >> lottery[i].num4;


		inFile >> lottery[i].num5;


		inFile >> lottery[i].num6;


		inFile >> lottery[i].num7;


		i++;
	}


	cout << "Enter 7 numbers " << endl;

	for (int i = 0; i < 7; i++)
	{
		cout << "Num " << i + 1 << ": ";
		cin >> lottery[i].lotteryNums;

	}
}

void compare(Lottery lottery[], int numel) //gets the number of matches and amount of money earned
{
	for (int i = 0; i < numel; i++)
		lottery[i].match = 0;

	for (int i = 0; i < numel; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (lottery[j].lotteryNums == lottery[i].num1)
			{
				lottery[i].match += 1;
			}
			if (lottery[j].lotteryNums == lottery[i].num2)
			{
				lottery[i].match += 1;
			}
			if (lottery[j].lotteryNums == lottery[i].num3)
			{
				lottery[i].match += 1;
			}
			if (lottery[j].lotteryNums == lottery[i].num4)
			{
				lottery[i].match += 1;
			}
			if (lottery[j].lotteryNums == lottery[i].num5)
			{
				lottery[i].match += 1;
			}
			if (lottery[j].lotteryNums == lottery[i].num6)
			{
				lottery[i].match += 1;
			}
			if (lottery[j].lotteryNums == lottery[i].num7)
			{
				lottery[i].match += 1;
			}
		}
	}
	for (int i = 0; i < numel; i++)
	{
		lottery[i].money = 0;
	}
	for (int i = 0; i < numel; i++)
	{
		if (lottery[i].match == 7)
		{
			lottery[i].money = 20;
		}
		if (lottery[i].match == 6)
		{
			lottery[i].money = 10;
		}
		if (lottery[i].match == 5)
		{
			lottery[i].money = 5;
		}
		if (lottery[i].match == 4)
		{
			lottery[i].money = 0;
		}
		if (lottery[i].match == 3)
		{
			lottery[i].money = 0;
		}
		if (lottery[i].match == 2)
		{
			lottery[i].money = 0;
		}
		if (lottery[i].match == 1)
		{
			lottery[i].money = 0;
		}
		if (lottery[i].match == 0)
		{
			lottery[i].money = 0;
		}
	}

}

void display(Lottery lottery[], int numel)//sorts structure and displays the information
{
	string min, temp;
	int minidx, i, j, tempMatch, tempID, temp1, temp2, temp3, temp4, temp5, temp6, temp7;
	int minMatch, minID, min1, min2, min3, min4, min5, min6, min7;
	double tempMoney, minMoney;
	numel -= 1;

	for (i = 0; i < (numel - 1); i++)
	{
		min = lottery[i].name;
		minMatch = lottery[i].match;
		minID = lottery[i].id;
		min1 = lottery[i].num1;
		min2 = lottery[i].num2;
		min3 = lottery[i].num3;
		min4 = lottery[i].num4;
		min5 = lottery[i].num5;
		min6 = lottery[i].num6;
		min7 = lottery[i].num7;
		minMoney = lottery[i].money;

		//assume minimum is the first array element
		minidx = i;
		//index(position) of minimum element

		for (j = i + 1; j < numel; j++)
		{
			if (lottery[j].name < min)
			{
				min = lottery[j].name;
				minMatch = lottery[j].match;
				minID = lottery[j].id;
				min1 = lottery[j].num1;
				min2 = lottery[j].num2;
				min3 = lottery[j].num3;
				min4 = lottery[j].num4;
				min5 = lottery[j].num5;
				min6 = lottery[j].num6;
				min7 = lottery[j].num7;
				minMoney = lottery[j].money;
				minidx = j;
			}
		}
		if (min < lottery[i].name)
		{
			temp = lottery[i].name;
			tempMatch = lottery[i].match;
			tempID = lottery[i].id;
			temp1 = lottery[i].num1;
			temp2 = lottery[i].num2;
			temp3 = lottery[i].num3;
			temp4 = lottery[i].num4;
			temp5 = lottery[i].num5;
			temp6 = lottery[i].num6;
			temp7 = lottery[i].num7;
			tempMoney = lottery[i].money;

			lottery[i].name = min;
			lottery[i].match = minMatch;
			lottery[i].id = minID;
			lottery[i].num1 = min1;
			lottery[i].num2 = min2;
			lottery[i].num3 = min3;
			lottery[i].num4 = min4;
			lottery[i].num5 = min5;
			lottery[i].num6 = min6;
			lottery[i].num7 = min7;
			lottery[i].money = minMoney;

			lottery[minidx].name = temp;
			lottery[minidx].match = tempMatch;
			lottery[minidx].id = tempID;
			lottery[minidx].num1 = temp1;
			lottery[minidx].num2 = temp2;
			lottery[minidx].num3 = temp3;
			lottery[minidx].num4 = temp4;
			lottery[minidx].num5 = temp5;
			lottery[minidx].num6 = temp6;
			lottery[minidx].num7 = temp7;
			lottery[minidx].money = tempMoney;
		}
	}


	cout << "*************************************RESULTS REPORT***********************************************************" << endl << endl;
	cout << "STUDENT ID       STUDENT NAME       CHOSEN NUMBERS                  Matches          MONEY" << endl;
	cout << "___________________________________________________________________________________________" << endl;
	for (int i = 0; i < numel; i++)
	{
		cout << setprecision(0) << fixed << showpoint;
		cout << setw(18) << left << lottery[i].id;
		cout << setw(18) << lottery[i].name;
		cout << setw(2) << " " << lottery[i].num1 << " " << lottery[i].num2 << " " << lottery[i].num3 << " "
			<< lottery[i].num4 << " "
			<< lottery[i].num5 << " " << lottery[i].num6 << " " << lottery[i].num7;
		cout << setw(18) << " " << lottery[i].match;
		cout << setprecision(2) << fixed << showpoint;
		cout << setw(18) << lottery[i].money << endl;

	}
	cout << endl << endl;
	cout << "* * * * * * * * * Winnings Report * * * * * * * * *" << endl << endl;
	cout << "*********Students Who Matched All 7*********" << endl;
	cout << "Student ID        Student Name    Matches            Prize $" << endl;
	cout << "_____________________________________________________________" << endl;

	for (int i = 0; i < numel; i++)
	{
		if (lottery[i].match == 7)
		{
			cout << setw(18) << left << lottery[i].id;
			cout << setw(18) << lottery[i].name;
			cout << setw(20) << lottery[i].match;
			cout << setw(20) << lottery[i].money << endl;
		}
	}
	cout << endl;
	cout << "*********Students Who Matched All 6*********" << endl;
	cout << "Student ID        Student Name    Matches            Prize $" << endl;
	cout << "_____________________________________________________________" << endl;
	for (int i = 0; i < numel; i++)
	{
		if (lottery[i].match == 6)
		{
			cout << setw(18) << left << lottery[i].id;
			cout << setw(18) << lottery[i].name;
			cout << setw(20) << lottery[i].match;
			cout << setw(20) << lottery[i].money << endl;
		}
	}
	cout << endl;
	cout << "*********Students Who Matched All 5*********" << endl;
	cout << "Student ID        Student Name    Matches            Prize $" << endl;
	cout << "_____________________________________________________________" << endl;
	for (int i = 0; i < numel; i++)
	{
		if (lottery[i].match == 5)
		{
			cout << setw(18) << left << lottery[i].id;
			cout << setw(18) << lottery[i].name;
			cout << setw(20) << lottery[i].match;
			cout << setw(20) << lottery[i].money << endl;
		}
	}
}

