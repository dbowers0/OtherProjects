#include <iostream>
#include "graph1.h"
#include <cmath>
#include "Color.h"
#include "Shape.h"
#include "RightTriangle.h"
#include "GenPoint.h"
#include "GenRectangle.h"
using namespace std;

RightTriangle::RightTriangle()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
}

RightTriangle::RightTriangle(GenPoint vertex, int height, int base, Color color)
{
	height = 0;
	vertex = vertex;
	base = 0;
	this->color = color;
}

void RightTriangle::print()
{
	gout << setPos(200, 405) << "Shape Info Follows for: " << endg;
	gout << setPos(200, 420) << "Point A: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point B (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point C (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(200, 465) << "Perimeter: " << getPerimeter() << "Area: " << getArea() << endg;
}

