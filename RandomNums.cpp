#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int equal = 0;
	int notEqual = 0;
	float a;
	float b;
	float c;
	
	//creates random float numbers 
	//test associative property for different random float numbers 100 times
	srand((unsigned)time(0));
	for (int i = 0; i < 100; i++)
	{
		a = static_cast <float> ((unsigned)rand()) / static_cast <float> (RAND_MAX);
		b = static_cast <float> ((unsigned)rand()) / static_cast <float> (RAND_MAX);
		c = static_cast <float> ((unsigned)rand()) / static_cast <float> (RAND_MAX);

		
		//adds the three random float numbers to test associative property

		if (a + (b + c) == (a+b) + c)
		{

			equal++;
		}

		else
			notEqual++;
	}

	cout << "EQUAL: " << equal << endl << "NOT EQUAL: " << notEqual << endl << endl;

	//calculates the percent of where associative property works
	double percentEqual = (double)equal / 100;

	percentEqual = percentEqual * 100;


	//displays the amount of times and percentage associative property is equal
	cout << "It is equal " << (double)percentEqual << "% of the time";
	
	
}