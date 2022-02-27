#include "PointList.h"
#include "graph1.h"
#include <iostream>

using namespace std;
PointList::PointList()
{
	color.setColor(0, 0, 0);
}

void PointList::addNode(GenPoint point)
{
	points.push_back(point);



}

void PointList::draw()
{
	//display bmp
	displayBMP("arkansas1.bmp", 0, 0);
	//variables
	int x = 0;
	int y = 0;
	int r = 0;
	int g = 0;
	int b = 0;

	r = color.getRed();
	g = color.getGreen();
	b = color.getBlue();
	//creating a circle
	int circle = 0;

	int i = 0;
	for (i = 0; i < (int)points.size(); i++)
	{
		x = points[i].getX();
		y = points[i].getY();

		//draw a circle at a given point
		for (int i = 0; i <= 10; i++)
		{
			circle = drawCircle(i, x, y);
			::setColor(circle, r, g, b);
		}
	}




}

Color PointList::getColor()
{
	return color;
}

void PointList::setColor(Color color)
{
	this->color = color;
}
