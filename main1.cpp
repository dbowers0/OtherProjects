//Darius Bowers
#include <iostream>
#include "graph1.h"
#include "Lottery.h"
#include <ctime>

using namespace std;

int main()
{
	int no_balls = 0;
	int* yourNumbers = NULL;
	int* winningNumbers = NULL;
	int matches = 0;

	Lottery player;

	srand(time(0));
	
	displayGraphics();
	cout << "How many lottery balls would you like to play? ";
	cin >> no_balls;

	no_balls = player.getNoBalls();
	bool res = player.setNoBalls(no_balls);
	if (no_balls > 10)
	{
		no_balls = 10;
	}
	
	if (no_balls < 3)
	{
		no_balls = 3;
	}
	player.addNumber();
	player.displayYourNumbers();
}