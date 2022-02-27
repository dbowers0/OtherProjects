//Darius Bowers
//Lab 5 Out

#include <iostream>
#include "graph1.h"
#include <string>
using namespace std;

class Clock
{
private:
	int hour;
	int min;
	int sec;


public:
	Clock();
	bool setHour(int hour);
	bool setMin(int min);
	bool setSec(int sec);
	int getHour();
	int getMin();
	int getSec();
	void draw();

};

Clock::Clock()
{
	hour = 0;
	min = 0;
	sec = 0;
}

bool Clock::setHour(int hour)
{
	if (hour < 11 && hour > 0)
		return true;
	else
	{
		if (hour > 11)
			hour = 11;
		if (hour < 0)
			hour = 0;
		return false;
	}
}

bool Clock::setMin(int min)
{
	if ( min < 59 && min > 0)
		return true;
	else
	{
		if (min > 59)
			min = 59;
		if (min < 0)
			min = 0;
		return false;
	}
}

bool Clock::setSec(int sec)
{
	if (sec < 59 && sec > 0)
		return true;
	else
	{
		if (sec > 59)
			sec = 59;
		if (sec < 0)
			sec = 0;
		return false;
	}
}

int Clock::getHour()
{
	cout << "Enter the number of Hours: ";
	cin >> hour;
	return hour;
}

int Clock::getMin()
{
	cout << "Enter the number of Minutes: ";
	cin >> min;
	return min;
}

int Clock::getSec()
{
	cout << "Enter the number of Seconds: ";
	cin >> sec;
	return sec;
}

void Clock::draw()
{
	int center_x = 320;
	int center_y = 239;
	int end_x = 0;
	int end_y = 0;
	int alpha = 0;
	int length_of_hand = 0;


	displayPNG("clock_face.png",123,50);
	

	alpha = sec * 6;
	length_of_hand = 150;
	if (alpha > 0 && alpha < 90)
	{
		end_x = center_x + (cos(((double)90 - alpha) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y - (sin(((double)90 - alpha) * 3.14 / 180.0)) * length_of_hand;
	}
	
	if (alpha > 90 && alpha < 180)
	{
		end_x = center_x + (cos(((double)alpha - 90) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y + (sin(((double)alpha - 90) * 3.14 / 180.0)) * length_of_hand;
	}
	if (alpha > 180 && alpha < 270)
	{
		end_x = center_x - (cos(((double)270 - alpha) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y + (sin(((double)270 - alpha) * 3.14 / 180.0)) * length_of_hand;
	}

	if (alpha > 270 && alpha < 360)
	{
		end_x = center_x - (cos(((double)alpha - 270) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y - (sin(((double)alpha - 270) * 3.14 / 180.0)) * length_of_hand;
	}
	int obj_sec = drawLine(center_x, center_y, end_x, end_y,2);
	setColor(obj_sec, 255, 0, 0);
	
	alpha = min * 6 + (sec / 60.0) * 6;
	length_of_hand = 180;
	if (alpha > 0 && alpha < 90)
	{
		end_x = center_x + (cos(((double)90 - alpha) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y - (sin(((double)90 - alpha) * 3.14 / 180.0)) * length_of_hand;
	}

	if (alpha > 90 && alpha < 180)
	{
		end_x = center_x + (cos(((double)alpha - 90) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y + (sin(((double)alpha - 90) * 3.14 / 180.0)) * length_of_hand;
	


	}
	if (alpha > 180 && alpha < 270)
	{
		end_x = center_x - (cos(((double)270 - alpha) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y + (sin(((double)270 - alpha) * 3.14 / 180.0)) * length_of_hand;
	}

	if (alpha > 270 && alpha < 360)
	{
		end_x = center_x - (cos(((double)alpha - 270) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y - (sin(((double)alpha - 270) * 3.14 / 180.0)) * length_of_hand;
	}
	int obj_min = drawLine(center_x, center_y, end_x, end_y, 2);
	setColor(obj_min, 0, 0, 0);

	alpha = hour * 30 + (min / 60.0) * 30;
	length_of_hand = 133;
	if (alpha > 0 && alpha < 90)
	{
		end_x = center_x + (cos(((double)90 - alpha) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y - (sin(((double)90 - alpha) * 3.14 / 180.0)) * length_of_hand;
	}

	if (alpha > 90 && alpha < 180)
	{
		end_x = center_x + (cos(((double)alpha - 90) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y + (sin(((double)alpha - 90) * 3.14 / 180.0)) * length_of_hand;
	}
	if (alpha > 180 && alpha < 270)
	{
		end_x = center_x - (cos(((double)270 - alpha) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y + (sin(((double)270 - alpha) * 3.14 / 180.0)) * length_of_hand;
	}

	if (alpha > 270 && alpha < 360)
	{
		end_x = center_x - (cos(((double)alpha - 270) * 3.14 / 180.0)) * length_of_hand;
		end_y = center_y - (sin(((double)alpha - 270) * 3.14 / 180.0)) * length_of_hand;
	}
	int obj_hour = drawLine(320, 239, end_x, end_y, 2);
	setColor(obj_hour, 0, 0, 0);
	 
	if(min < 10 && sec < 10)
		gout << setPos(280, 440) << "Time: " << hour << ":" << "0" << min << ":" << "0" << sec << endg;
	else if(min < 10)
		gout << setPos(280, 440) << "Time: " << hour << ":" << "0" << min << ":" << sec << endg;
	else if(sec < 10)
		gout << setPos(280, 440) << "Time: " << hour << ":" << min << ":" << "0" << sec << endg;
	else
		gout << setPos(280, 440)  << "Time: " << hour << ":" << min << ":" << sec << endg;

	

}

int main()
{
	int sec = 0;
	int min = 0;
	int hour = 0;
	bool result = false;

	Clock clock1;

	char repeat;
	
	do
	{
		displayGraphics();

		sec = clock1.getSec();
		min = clock1.getMin();
		hour = clock1.getHour();

		result = clock1.setSec(sec);
		if (result == false)
			cout << "Value entered is outside of range";
		result = clock1.setMin(min);
		if (result == false)
			cout << "Value entered is outside of range";

		result = clock1.setHour(hour);
		if (result == false)
			cout << "Value entered is outside of range";

		clock1.draw();
		cout << "Would you like to repeat the program <y/n> ";
		cin >> repeat;
		clearGraphics();
	} while (repeat == 'y' || repeat == 'Y');
}