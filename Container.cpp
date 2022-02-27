#include <iostream>
#include <cmath>
#include "graph1.h"
#include "Container.h"

Container::Container()
{
	pos.setPoint(0, 0);
	radius = 0;
	height = 0;
	color.setColor(0, 0, 0);
}

void Container::setPosition(GenPoint pos)
{
	this->pos.setPoint(pos.getX(), pos.getY());
}

void Container::setRadius(int radius)
{
	this->radius = radius;
}

void Container::setHeight(int height)
{
	this->height = height;
}

void Container::setColor(Color color)
{
	this->color = color;
}

GenPoint Container::getPosition()
{
	return pos;
}

int Container::getRadius()
{
	return radius;
}

int Container::getHeight()
{
	return height;
}

Color Container::getColor()
{
	return color;
}

void Container::draw()
{
	//draw the walls
	drawLine(pos);
	int ground = 0;

	wall = drawRect(0, 0, 55, 400);
	ground = drawRect(0, 400, 640, 80);


}

