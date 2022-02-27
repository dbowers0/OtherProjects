#include <iostream>
#include "GenLine.h"
#include "GenPoint.h"
#include "graph1.h"
using namespace std;

GenLine::GenLine()
{
	p1.setPoint(0, 0);
	p2.setPoint(0, 0);
}

void GenLine::setLine(GenPoint p1, GenPoint p2)
{
	this->p1 = p1;
	this->p2 = p2;
}

GenPoint GenLine::getPoint1()
{
	return p1;
}

GenPoint GenLine::getPoint2()
{
	return p2;
}

double GenLine::getLength()
{
	double length = 0;
	length = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
	return length;
}

void GenLine::draw()
{
	int mid1 = (p2.getX() - p1.getX()) / 2;
	int mid2 = (p2.getY() - p1.getY()) / 2;
	int line = drawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY(),getLength());
	int circle1 = drawCircle(5, p1.getX(), p1.getY());
	int circle2 = drawCircle(5, mid1, mid2);
	int circle3 = drawCircle(5, p2.getX(), p2.getY());
	setColor(circle1, 255, 0, 255);
	setColor(circle2, 255, 0, 255);
	setColor(circle3, 255, 0, 255);

	if (getType() == "SMALL_LINE")
	{
		setColor(line, 255, 0, 0);
	}

	if (getType() == "MEDIUM_LINE")
	{
		setColor(line, 0, 255, 0);
	}

	if (getType() == "LARGE_LINE")
	{
		setColor(line, 0, 0, 255);
	}

}

GenPoint GenLine::getMidPoint()
{
	GenPoint midpoint;
	int mid1 = 0;
	int mid2 = 0;

	mid1 = (p2.getX() - p1.getX()) / 2;
	mid2 = (p2.getY() - p1.getY()) / 2;

	midpoint.setPoint(mid1, mid2);
	this->getMidPoint = midpoint;
	return midpoint;
}

string GenLine::getType()
{
	string size = " ";
	if (getLength() > 0 && getLength() < 100)
	{
		size = "SMALL_LINE";
	}
	else if (getLength() >= 100 && getLength() <= 300)
	{
		size = "MEDIUM_LINE";
	}
	else if (getLength() >= 300)
	{
		size = "LARGE_LINE";
	}
	this->getType = size;
	return size;
}