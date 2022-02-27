//Darius Bowers
//Lab 3 Out
//Display Bugs and Guess coordinates to win
#include <iostream>
#include <ctime>
#include "graph1.h"
using namespace std;

void initDisplay();
int getNoBugs();
int* getXCoords(int no_bugs);
int* getYCoords(int no_bugs);
int* displayObjects(int* x_coords, int* y_coords, int no_objects, int no_bugs, int obj_bug[]);
int zapBugs(int* x_coords, int* y_coords, int* objects, int no_bugs, int obj_bug[]);


int main()
{
	
	int no_bugs = 0;
	int* x = NULL;
	int* y = NULL;
	int* x_coords = NULL;
	int* y_coords = NULL;
	int* objects = NULL;
	int no_objects = 0;
	int score = 0;
	int obj_bug[20] = { };

	char repeat = ' ';
	do
	{
	displayGraphics();
	
	    initDisplay();
		no_bugs = getNoBugs();
		x_coords = getXCoords(no_bugs);
		y_coords = getYCoords(no_bugs);
		objects = displayObjects(x_coords, y_coords, no_objects, no_bugs, obj_bug);
		score = zapBugs(x_coords, y_coords, objects, no_bugs, obj_bug);
		cout << "Play Again? <Enter y for yes and n for no> ";
		cin >> repeat;
		clearGraphics();
		delete[] x_coords;
		delete[] y_coords;
	} while (repeat == 'y' || repeat == 'Y');
}

void initDisplay()
{
	displayPNG("Grass.png",0,0);
	drawRect(250, 0, 200, 40);
	gout << setPos(285, 20) << setColor(0, 0, 0)  << "Score: " << "  Shots: " << endg;
}

int getNoBugs()
{
	int no_bugs = 0;
	do
	{
		cout << "Enter # of bugs to display <Between 5 and 20> ";
		cin >> no_bugs;
		if (no_bugs < 5 || no_bugs > 20)
		{
			cout << "Please enter valid amount" << endl;
		}
	} while (no_bugs < 5 || no_bugs > 20);
	return no_bugs;
}

int* getXCoords(int no_bugs)
{
	srand(time(0));
	int* x = NULL;
	x = new int[no_bugs];
	for (int i = 0; i < no_bugs; i++)
	{
		//Set x/y coordinates
		x[i] = (rand() % 576);
	}
	return x;
}

int* getYCoords(int no_bugs)
{
	srand(time(0));
	int* y = NULL;
	y = new int[no_bugs];
	for (int i = 0; i < no_bugs; i++)
	{
		//Set x/y coordinates
		y[i] = (rand() % 376);
	}
	return y;
}

int* displayObjects(int* x_coords, int* y_coords, int no_objects, int no_bugs, int obj_bug[])
{
	no_objects = no_bugs;
	//obj_bug = new int[no_bugs];
	//int *no_objects = new int[];
	
	//no_objects = new int[no_bugs];
	 
	for (int i = 0; i < no_bugs; i++)
	{
		obj_bug[i] = displayPNG("Bugs.png", x_coords[i], y_coords[i]);
		
	}
	
	return obj_bug;
}

int zapBugs(int* x_coords, int* y_coords, int* objects, int no_bugs, int obj_bug[])
{
	int shots = 0;
	int score = 0;
	int userX = 0;
	int userY = 0;
	int obj_circle = 0;

	for (int i = 0; i < no_bugs * 2; i++)
	{
		//cout << x_coords;
		cout << "Enter x/y coordinate ";
		cin >> userX >> userY;
		int x = 0;
		obj_circle = drawCircle(10, userX, userY);
		setColor(obj_circle, 0, 0, 0);
	
		for (int i = 0; i < no_bugs; i++)
		{
			if ((userX > x_coords[i]) && (userX < x_coords[i] + 64) && (userY > y_coords[i]) && (userY < y_coords[i] + 64))
			{
				score += 1;
				gout << setPos(340, 20) << setColor(0, 0, 0) << score << endg;
				removeObject(obj_bug[i]);

			}
				
			
		}
		shots += 1;
		gout << setPos(410, 20) << setColor(0, 0, 0) << shots << endg;
		if (score >= no_bugs)
			break;
		
	}
	if (score >= no_bugs)
	{
		gout << setPos(315, 50) << setColor(0, 0, 0) << "WINNER" << endg;
	}
	else
	{
		gout << setPos(315, 50) << setColor(0, 0, 0) << "You Lose" << endg;
	}
	
	return score;
}

