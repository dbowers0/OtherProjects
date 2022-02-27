#include <iostream>
#include "graph1.h"
#include <cmath>
#include "GenPoint.h"
#include "GenRectangle.h"
#include "Quadrilateral.h"
#include "Color.h"
using namespace std;

GenRectangle::GenRectangle()
{
	cout << "GenRectangle Constructor";
}

void GenRectangle::setPoints(GenPoint ul, GenPoint lr)
{
	//set the private data fields for upper left x,y coords
	a.setPoint(ul.getX(), ul.getY());
	b.setPoint(ul.getX(), ul.getY());
	c.setPoint(ul.getX(), ul.getY());
	d.setPoint(ul.getX(), ul.getY());
	//repeat for b,c,d

	Quadrilateral::setPoints(a, b, c, d);
}

double GenRectangle::getArea()
{
	double area = 0.0;
	double width = 0.0;
	double height = 0.0;

	//compute points between a and b
	width = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));

	//repeat for height, height is distance between b and c
	height = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
	area = width * height;

	return area;
}

void GenRectangle::print()
{
	//display the same infor print(); displays
	Quadrilateral::print();

	gout << setPos(a.getX(), a.getY() - 30) << "Rectangle Info " << endg;



}