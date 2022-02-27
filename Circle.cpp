#include <iostream>
#include "graph1.h"
#include <cmath>
#include "Color.h"
#include "Shape.h"
#include "Circle.h"
using namespace std;

Circle::Circle()
{
	this->radius = 0;
	center.setPoint(0, 0);
}

Circle::Circle(GenPoint center, int radius, Color c)
{
	this->center = center;
	this->radius = radius;
	this->color = c;
}

void Circle::setCenter(GenPoint center)
{
	if (center.getX() < 0)
	{
		this->center.setPoint(0, center.getY());

	}
	else if (center.getX() > 639)
		this->center.setPoint(639, center.getY());

	else if (center.getY() > 0)
		this->center.setPoint(center.getX(), 0);

	else if (center.getY() > 399)
		this->center.setPoint(center.getX(), 399);
	else
		this->center = center;
}

void Circle::setRadius(int radius)
{
	if (radius < 0)
	{
		radius = 0;
	}
	else if (radius > 639)
	{
		radius = 639;
	}
	else
		this->radius = radius;

}

double Circle::getPerimeter()
{
	double perimeter = 0.0;
	perimeter = 2 * PI * radius;
	return perimeter;
}

double Circle::getArea()
{
	double area = 0.0;
	area = PI * pow(radius, 2);
	return area;
}

void Circle::print()
{
	gout << setPos(200, 405) << "Shape Info Follows for: Circle" << endg;
	gout << setPos(200, 420) << "Center Point: (" << center.getX() << "," << center.getY() << ")" << endg;
	gout << setPos(200, 435) << "Radius: " << radius << endg;
	gout << setPos(200, 450) << "Perimeter: " << getPerimeter() << endg;
}

void Circle::draw()
{
	drawCircle(radius, center.getX(), center.getY());
}