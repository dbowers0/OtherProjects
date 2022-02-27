#include <iostream>
#include "graph1.h"
#include "PointList.h"
#include "Color.h"

using namespace std;

int main()
{
	//Variable Declaration/Initialization
	int i = 0;
	int x = 0;
	int y = 0;
	int r = 0;
	int g = 0;
	int b = 0;
	char repeat = 'y';
	GenPoint point;
	PointList list;
	Color color;

	//Display graphics
	displayGraphics();

	//Repeat program as many times as desired
	do
	{
		//Prompt for as many points as desired
		cout << "Enter r/g/b color for all Points" << (i + 1) << ": ";
		cin >> r >> g >> b;

		//Set the Color
		color.setColor(r, g, b);
		list.setColor(color);


		do
		{
			//Get x/y coordinates for a point
			cout << "Enter x/y coordinates for Point #" << (i + 1) << ": ";
			cin >> x >> y;

			//Set the GenPoint
			point.setPoint(x, y);

			//Add the point to the list
			list.addNode(point);




			//Increment the counter
			i++;

			cout << "Add another point? (y/n): ";
			cin >> repeat;

		} while ((repeat == 'y') || (repeat == 'Y'));


		//Draw the map/route
		list.draw();




	} while ((repeat == 'y') || (repeat == 'Y'));

	return 0;

}
