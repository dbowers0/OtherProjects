#include <iostream>
#include "graph1.h"
#include <cmath>
#include "GenRectangle.h"
#include "Quadrilateral.h"
#include "Color.h"
using namespace std;

Quadrilateral::Quadrilateral()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
	d.setPoint(0, 0);

	color.setColor(0,0,0);
}
//set private data fields to corresponding parameters
// new max is 639
void Quadrilateral::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
{
	//repeat for b,c,d Replace a with letter
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

double Quadrilateral::getPerimeter()
{
	double perimeter = 0.0;
	double length[4] = { 0,0 };
	int i = 0;
	//to compute the distance for line i (a to b)
	length[0] = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
	//repeat the computation for line c-b, d-c, a-d
	length[1] = sqrt(pow(b.getX() - c.getX(), 2) + pow(b.getY() - c.getY(), 2));
	length[2] = sqrt(pow(c.getX() - d.getX(), 2) + pow(c.getY() - d.getY(), 2));
	length[3] = sqrt(pow(d.getX() - a.getX(), 2) + pow(d.getY() - a.getY(), 2));
	for (i = 0; i < 4; i++)
	{
		perimeter += length[i];
	}

	return perimeter;
}

void Quadrilateral::print()
{
	gout << setPos(200, 405) << "Shape Info for Quadrilateral" << endg;
	gout << setPos(200, 420) << "Point A " << a.getX() << " , " << a.getY() << endg;
	gout << setPos(200, 435) << "Point B " << b.getX() << " , " << b.getY() << endg;
	gout << setPos(200, 450) << "Point C " << c.getX() << " , " << c.getY() << endg;
	gout << setPos(200, 465) << "Point D " << d.getX() << " , " << d.getY() << endg;
	//repeat for b,c,d and perimeter


}

void Quadrilateral::draw()
{
	int line = 0;

	line = drawLine(a.getX(), a.getY(), b.getX(), b.getY(),5);
	setColor(line, color.getRed(), color.getGreen(), color.getBlue());
}
