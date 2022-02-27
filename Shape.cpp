#include <iostream>
#include "graph1.h"
#include <cmath>
#include "Color.h"
#include "Shape.h"
using namespace std;

Shape::Shape()
{
	color.setColor(0, 0, 0);
}

Color Shape::getColor()
{
	return color;
}

void Shape::setCol(Color color)
{
	this->color = color;
}

double Shape::getPerimeter() 
{
	double perimeter = 0.0;
	return perimeter;
}


void Shape::print()
{
	
}
void Shape::draw()
{

}