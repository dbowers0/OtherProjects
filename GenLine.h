#ifndef GENLINE_H
#define GENLINE_H
#include "GenLine.h"

class GenLine
{
	private:
		GenPoint p1;
		GenPoint p2;
	
	public: 
		GenLine();
		void setLine(GenPoint p1, GenPoint p2);
		GenPoint getPoint1();
		GenPoint getPoint2();
		double getLength();
		void draw();
		GenPoint getMidPoint();
		string getType();





};

#endif
