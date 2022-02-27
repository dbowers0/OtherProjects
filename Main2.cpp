#include <iostream>
#include "graph1.h"
#include "Simulation.h"

using namespace std;

int main()
{
	//Variable Declaration/Initialization
	int height = 0;
	int radius = 0;
	int position = 0;
	int r = 0;
	int b = 0;
	int g = 0;
	char repeat;
	Container container;
	Simulation simulation;
	Color col;
	GenPoint pos;
	//Display the graphics
	displayGraphics();

	//Continually simulate

	do
	{
		//Get the Container's radius/height/color (Add Data Validation)

		cout << "What is the radius? ";
		cin >> radius;

		cout << "What is the height? ";
		cin >> height;

		cout << "What is the color? ";
		cin >> r;
		cin >> g;
		cin >> b;

		//Set the Containers radius/height /color
		container.setRadius(radius);
		container.setHeight(height);

		col.setColor(r, g, b);

		container.setColor(col);

		pos.setPoint(position);

		//Compute the Container upper left coordinate based on the height
		container.setPosition(position);
		//Set the Container’s position
		container.setPosition(pos);
		//Hint: 55, 400 - height

		//Set the Container for the Simulation
		simulation.setContainer(container);
		//Draw the simulation/container (invoke draw on Simulation)
		simulation.draw();


		//Repeat the simulation?
		cout << "Repeat the simulation (y/n)? ";
		cin >> repeat;

		clearGraphics();
		system("cls");

	} while (repeat == 'y');

	return 0;
}
