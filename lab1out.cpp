//Darius Bowers
//
//
#include <iostream>
#include "graph1.h"
#include <string>
using namespace std;

int getNoMonths();
void getSales(int sales[], int no_months);
int getMax(int sales[], int no_months);
int getMin(int sales[], int no_months);
double getAverage(int sales[], int no_months);
void displayResults(int sales[], int no_months, int max, int min, double avg);

int main()
{
	int no_months = 0;
	int sales[10] = { 0 };
	int max = 0;
	int min = 0;
	int average = 0;
	
	displayGraphics();
	
	no_months = getNoMonths();
	getSales(sales, no_months);
	max = getMax(sales, no_months);
	min = getMin(sales, no_months);
	average = getAverage(sales, no_months);
	displayResults(sales, no_months, max, min, average);



}

int getNoMonths()
{
	int no_months = 0;
	cout << "The number of months to process for the sales data. Must be between 3-6 ";
	cin >> no_months; 
	return no_months;
}

void getSales(int sales[], int no_months)
{
	cout << "Enter the sales information ";
	for (int i = 0; i < no_months; i++)
	{
		cout << "Month " << i + 1 << " ";
		cin >> sales[i];
	}
}

int getMax(int sales[], int no_months)
{
	int i = 0;
	int max = 0;
	max = sales[0];
	for (i = 0; i < no_months; i++)
	{
		if (sales[i] > max)
		{
			max = sales[i];
			
		}
	}
		return max;
}
	//cout << max;
	


int getMin(int sales[], int no_months)
{
	int i = 0;
	int min = 0;
	min = sales[0];
	for (i = 0; i < no_months; i++)
	{
		if (sales[i] < min)
		{
			min = sales[i];

		}
	}
	return min;
}

double getAverage(int sales[], int no_months)
{
	int sum = 0;
	int average = 0;
	for (int i = 0; i < no_months; i++)
	{
		sum += sales[i];
	}
	average = sum / no_months;
	return average;
}

void displayResults(int sales[], int no_months, int max, int min, double average)
{
	int line_obj = 0;
	int line2_obj = 0;
	int line3_obj = 0;
	int line4_obj = 0;
	int line5_obj = 0;
	int line6_obj = 0;
	
	int rect_obj = 0;
	int rect2_obj = 0;
	int rect3_obj = 0;
	int rect4_obj = 0;
	int rect5_obj = 0;
	int rect6_obj = 0;
	
	gout << setPos(375, 60) << setColor(0, 255, 0) << "Sales for 6 Months" << endg;
	displayBMP("sales1.bmp", 250, 25);
	line_obj = drawLine(200,280, 200,130,2);
	line2_obj = drawLine(200, 280, 640, 280, 2);
	
	line3_obj = drawLine(200, 345, 425, 345, 2);
	line4_obj = drawLine(200, 345, 200, 445, 2);
	line5_obj = drawLine(425, 345, 425, 445, 2);
	line6_obj = drawLine(200, 445, 425, 445, 2);

	gout << setPos(120, 210) << setColor(0, 255, 0) << "Monthly" << endg;
	gout << setPos(120, 225) << setColor(0, 255, 0) << "Sales" << endg;
	gout << setPos(205, 340) << setColor(0, 255, 0) << "Sales Statistcs" << endg;
	gout << setPos(205, 380) << setColor(0, 255, 0) << "Max Sales: $" << max << endg;
	gout << setPos(205, 400) << setColor(0, 255, 0) << "Min Sales: $" << min << endg;
	gout << setPos(205, 420) << setColor(0, 255, 0) << "Avg Sales: $" << (int)average << endg;
	gout << setPos(325, 300) << setColor(0, 255, 0) << "Months" << endg;

	int x = 0;
	int y = 0;
	
	int height = ((double)sales[0] / max) * 100.0;
	int height2 = ((double)sales[1] / max) * 100.0;
	int height3 = ((double)sales[2] / max) * 100.0;
	int height4 = ((double)sales[3] / max) * 100.0;
	int height5 = ((double)sales[4] / max) * 100.0;
	int height6 = ((double)sales[5] / max) * 100.0;

	gout << setPos(200, -height + 280) << setColor(0, 255, 0) << "Jan" << endg;
	gout << setPos(275, -height2 + 280) << setColor(0, 255, 0) << "Feb" << endg;
	gout << setPos(350, -height3 + 280) << setColor(0, 255, 0) << "Mar" << endg;
	gout << setPos(425, -height4+ 280) << setColor(0, 255, 0) << "Apr" << endg;
	gout << setPos(500, -height5 + 280) << setColor(0, 255, 0) << "May" << endg;
	gout << setPos(575, -height6+ 280) << setColor(0, 255, 0) << "June" << endg;
	
	
	rect_obj = drawRect(200, 280, 50, -height);
	setColor(rect_obj, 255, 0, 0);
	if (height < 1)
	{
		rect_obj = drawRect(200, 280, 25, -1);
		setColor(rect_obj, 255, 0, 0);
	}

	rect2_obj = drawRect(275, 280, 50, -height2);
	setColor(rect2_obj, 0, 255, 0);
	if (height2 < 1)
	{
		rect2_obj = drawRect(200, 280, 25, -1);
		setColor(rect2_obj, 255, 0, 0);
	}

	rect3_obj = drawRect(350, 280, 50, -height3);
	setColor(rect3_obj, 0, 0, 255);
	if (height3 < 1)
	{
		rect3_obj = drawRect(200, 280, 25, -1);
		setColor(rect3_obj, 255, 0, 0);
	}

	rect4_obj = drawRect(425, 280, 50, -height4);
	setColor(rect4_obj, 255, 255, 0);
	if (height4 < 1)
	{
		rect4_obj = drawRect(200, 280, 25, -1);
		setColor(rect4_obj, 255, 0, 0);
	}

	rect5_obj = drawRect(500, 280, 50, -height5);
	setColor(rect5_obj, 255, 0, 255);
	if (height5 < 1)
	{
		rect5_obj = drawRect(200, 280, 25, -1);
		setColor(rect5_obj, 255, 0, 0);
	}

	rect6_obj = drawRect(575, 280, 50, -height6);
	setColor(rect6_obj, 0, 255, 255);
	if (height6 < 1)
	{
		rect6_obj = drawRect(200, 280, 25, -1);
		setColor(rect6_obj, 255, 0, 0);
	}
}