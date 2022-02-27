//Darius Bowers
//Lab 6 Out
#include <iostream>
#include <ctime>
#include "graph1.h"
#include "Lottery.h"
using namespace std;

Lottery::Lottery()
{
	no_balls = 0;
	yourNumbers = NULL;
	winningNumbers = NULL;

}
Lottery::~Lottery()
{
	delete[] yourNumbers;
	delete[] winningNumbers;
}
int Lottery::getNoBalls()
{
	return no_balls;
}

bool Lottery::setNoBalls(int no_balls)
{
	yourNumbers = new int[no_balls];
	winningNumbers = new int[no_balls];
	if (no_balls > 10)
	{
		no_balls = 10;
		return false;
	}
	else if (no_balls < 3)
	{
		no_balls = 3;
		return false;
	}
	else
		return true;
}

void Lottery::addNumber()
{
	bool duplicate;
	for (int i = 0; i < no_balls - 1; i++)
	{
		do
		{
			cout << "Enter Lottery #" << i + 1 << ": ";
			cin >> yourNumbers[i];
			do
			{
				duplicate = false;
				for (int j = 0; j < i; j++)
				{
					if (yourNumbers[i] == yourNumbers[j])
					{
						cout << "Enter Lottery #" << i + 1 << ": ";
						cin >> yourNumbers[i];
						duplicate = true;
						break;
					}
				}
			} while (duplicate);

			if (yourNumbers[i] > 40 || yourNumbers[i] < 1)
				cout << "Must be between 1 and 40";
		} while (yourNumbers[i] > 40 || yourNumbers[i] < 1);
	}
}

void Lottery::displayYourNumbers()
{
	for (int i = 0; i < no_balls; i++)
	{
		string fn = to_string(yourNumbers[i]) + ".bmp";
		displayBMP(fn, 40 + 20*i, 320);

	}
	gout << setPos(40, 340) << "Your Numbers" << endg;
}

void Lottery::processWinningNumbers()
{
	for(int i = 0; i < no_balls; i++)
	winningNumbers[i] = rand() % 40 + 1;

	for (int i = 0; i < no_balls; i++)
	{
		string fn = to_string(winningNumbers[i]) + ".bmp";
		displayBMP(fn, 40 + 20 * i, 220);

	}
	gout << setPos(40, 200) << "Winning Numbers" << endg;

}

void Lottery::selectionSort()
{
	int i, j, min_idx;

	
	for (i = 0; i < no_balls - 1; i++)
	{
		 
		min_idx = i;
		for (j = i + 1; j < no_balls; j++)
		{
			if (yourNumbers[j] < yourNumbers[min_idx])
				min_idx = j;
		}
	}

}

void Lottery::insertionSort()
{
	int i, key, j;
	for (i = 1; i < no_balls; i++)
	{
		key = yourNumbers[i];
		j = i - 1;

		while (j >= 0 && yourNumbers[j] > key)
		{
			yourNumbers[j + 1] = yourNumbers[j];
			j = j - 1;
		}
		yourNumbers[j + 1] = key;
	}
}

int Lottery::getMatches()
{
	return 0;
}

int Lottery::binarySearch(int target)
{
	return 0;
}
int Lottery::computeWinnings()
{
	return 0;
}