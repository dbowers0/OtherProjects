#include <iostream>
#include "graph1.h"
#include <cmath>
#include "Color.h"
#include "Shape.h"
#include "Triangle.h"
using namespace std;

Triangle::Triangle()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
}

Triangle::Triangle(GenPoint a, GenPoint b, GenPoint c, Color color)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->color = color;
}

void Triangle::setPoints(GenPoint a, GenPoint b, GenPoint c)
{
	if (a.getX() < 0)
	{
		this->a.setPoint(0, a.getY());

	}
	else if (a.getX() > 639)
		this->a.setPoint(639, a.getY());

	else if (a.getY() > 0)
		this->a.setPoint(a.getX(), 0);

	else if (a.getY() > 399)
		this->a.setPoint(a.getX(), 399);
	else
		this->a = a;

	if (b.getX() < 0)
	{
		this->b.setPoint(0, b.getY());

	}
	else if (b.getX() > 639)
		this->b.setPoint(639, b.getY());

	else if (b.getY() > 0)
		this->b.setPoint(b.getX(), 0);

	else if (b.getY() > 399)
		this->b.setPoint(b.getX(), 399);
	else
		this->b = b;

	if (c.getX() < 0)
	{
		this->c.setPoint(0, c.getY());

	}
	else if (c.getX() > 639)
		this->c.setPoint(639, c.getY());

	else if (c.getY() > 0)
		this->c.setPoint(c.getX(), 0);

	else if (c.getY() > 399)
		this->c.setPoint(c.getX(), 399);
	else
		this->c = c;
}

double Triangle::getArea()
{
	double side1 = a.getX() - b.getX();
	double side2 = 0;
	double side3 = 0;
	double s = (side1 + side2 + side3) / 2.0;
	double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

	return area;
}

double Triangle::getPerimeter()
{
	double perimeter = 0;
	return perimeter;

}

void Triangle::print()
{
	gout << setPos(200, 405) << "Shape Info Follows for: " << endg;
	gout << setPos(200, 420) << "Point A: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point B (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point C (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(200, 465) << "Perimeter: " << getPerimeter() << "Area: " << getArea() << endg;
}


void Triangle::draw()
{
	
}