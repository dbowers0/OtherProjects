#include <iostream>
#include "graph1.h"
#include <cmath>
#include "Color.h"
#include "Shape.h"
#include "Trapezoid.h"
using namespace std;

Trapezoid::Trapezoid()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
	d.setPoint(0, 0);
}

Trapezoid::Trapezoid(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;

}

void Trapezoid::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
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

	if (d.getX() < 0)
	{
		this->d.setPoint(0, d.getY());

	}
	else if (d.getX() > 639)
		this->d.setPoint(639, d.getY());

	else if (d.getY() > 0)
		this->d.setPoint(d.getX(), 0);

	else if (d.getY() > 399)
		this->d.setPoint(d.getX(), 399);
	else
		this->d = d;
}

double Trapezoid::getArea()
{
	double area = 0.0;
	double length1 = a.getX() - b.getX();
	double length2 = c.getX() - d.getX();
	double height = a.getY() - c.getY();
	area = ((length1 + length2) / 2) * height;
	return area;
}

void Trapezoid::print()
{
	gout << setPos(200, 405) << "Shape Info Follows for: " << endg;
	gout << setPos(200, 420) << "Point A: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point B (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point C (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(200, 465) << "Point D: " << d.getX() << "," << d.getY() << endg;
	gout << setPos(200, 480) << "Perimeter: " << getPerimeter() << endg;
}