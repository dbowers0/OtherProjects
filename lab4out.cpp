//Darius Bowers
//Lab Out 4

#include <iostream>
#include <string>
#include "graph1.h"
#include <iomanip>
using namespace std;

void getString(string& fn, string& ln, string& ddress, string& city, string& state, string& zip);
int getWeight(int weight);
bool validateName(string name);
bool validateAddress(string address);
bool validateCity(string city);
bool validateState(string state);
bool validateZip(string zip);
string convertToUpper(string input);
void displayLetter(string fn, string ln, string address, string city, string state, string zip, int weight);

int main()
{
	string prompt = " ";
	string name = " ";
	string address = " ";
	string city = " ";
	string state = " ";
	string zip = " ";
	string input = " ";
	string fn = " ";
	string ln = " ";
	int weight = 0;
	string repeat = " ";

	do
	{
		displayGraphics();
		getString(fn, ln, address, city, state, zip);
		weight = getWeight(weight);
		bool dum;
		dum = validateName(fn);
			do
			{
			if (dum == 0)
			{
				cout << "Enter a valid first name: ";
				cin >> fn;
				validateName(fn);
			}
		} while (validateName == 0);
		
		
		dum = validateName(ln);
		do
		{
			if (dum == 0)
			{
				cout << "Enter a valid last name: ";
				cin >> ln;
				validateName(ln);
			}
		} while (validateName == 0);
		string dummy = " ";
		getline(cin, dummy);

		dum = validateAddress(address);
		do
		{
			if (dum == 0)
			{
				cout << "Enter a valid address: ";
				getline(cin, address);
				validateAddress(address);
			}
		} while (validateAddress == 0);
		
		
		dum = validateCity(city);
		do
		{
			if (dum == 0)
			{
				cout << "Enter a valid city: ";
				getline(cin, city);
				validateCity(city);
			}
		} while (validateCity == 0);
		
		dum = validateState(state);
		do
		{
			if (dum == 0)
			{
				cout << "Enter a valid State: ";
				cin >> state;
				validateState(state);
			}
		} while (validateState == 0);
		
		
		dum = validateZip(zip);
		do
		{
			
			if (dum == 0)
			{
				cout << "Enter a valid zip code: ";
				cin >> zip;
				validateZip(zip);
			}
		} while (validateZip == 0);
		gout << setPos(0, 0) << "Hello" << endg;
		state = convertToUpper(state);
		displayLetter(fn, ln, address, city, state, zip, weight);
		cout << "Repeat program (y/n): ";
		getline(cin, repeat);
		if (repeat == "y" || repeat == "Y")
			clearGraphics();
	} while (repeat == "y" || repeat == "Y");

}

void getString(string& fn, string& ln, string& address, string& city, string& state, string& zip)
{
	cout << "Enter First Name: ";
	getline(cin, fn);
	cout << "Enter Last Name: ";
	getline(cin, ln);
	cout << "Enter Address: ";
	getline(cin, address);
	cout << "Enter City: ";
	getline(cin, city);
	cout << "Enter State: ";
	getline(cin, state);
	cout << "Enter Zip: ";
	getline(cin, zip);
	
		
}

int getWeight(int weight)
{
	do
	{
		cout << "Enter Weight: ";
		cin >> weight;
	} while (weight > 6 || weight < 1);
	return weight;
}

bool validateName(string name)
{
	int score = 0;

	for (int i = 0; i < name.length(); i++)
	{
		
		if (isalpha(name[i]) == 0)
			score += 1;
		
	}
	
	if (score > 0)
		return false;
	else
		return true;

	

}

bool validateAddress(string address)
{
	int score = 0;
	for (int i = 0; i < address.length(); i++)
	{
		if (isalpha(address[i]) == 0)
		{
			if (isdigit(address[i]) == 0)
			{
				if (isspace(address[i]) == 0)
					score += 1;
			}
		}

	}
	if (score > 0)
	{
		return false;
	}
	else
		return true;
}

bool validateCity(string city)
{
	int wrong = 0;
	if (isupper(city[0]) == 0)
			return false;
			
	for (int i = 0; i < city.length(); i++)
	{
		if (isalpha(city[i]) == 0)
		{
			wrong += 1;
			
		}
			
	
	}
	if (wrong > 0)
	{
		return false;
	}
	else
		return true;
}

bool validateState(string state)
{
	int score = 0;
	int wrong = 0;
	for (int i = 0; i < state.length(); i++)
	{
		wrong += 1;
		if (isalpha(state[i]) == 0)
			score += 1;
		
	}
	if (wrong > 2)
	{
		return false;
	}
	else if (score > 0)
	{
		return false;
	}
	else
		return true;
}

bool validateZip(string zip)
{
	int score = 0;
	int wrong = 0;
	for (int i = 0; i < zip.length(); i++)
	{
		wrong += 1;
		if (isdigit(zip[i]) == 0)
			score += 1;

	}
	if (wrong > 5 || wrong < 5)
	{
		return false;
	}
	else if (score > 0)
	{
		return false;
	}
	else
		return true;
}

string convertToUpper(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		input = toupper(input[i]);
	}
	return input;
}

void displayLetter(string fn, string ln, string address, string city, string state, string zip, int weight) 
{
	double cost = 0;
	displayBMP("envelope.bmp", 0, 0);
	string fullName = fn + " " + ln;
	displayBMP("returnAddress.bmp", 43, 26);
	gout << setPos(315, 210) << fullName << endg;
	gout << setPos(315, 230) << address << endg;
	string area = city + ", " + state + " " + zip;

	cost = weight * .47; 
	
	drawRect(200, 385, 290, 85);
	gout << setPos(315, 250) << area << endg;
	gout << setPos(200, 385) << "Weight: " << weight << " ounces" << endg;
	gout << setPos(200, 405) << "Cost of First Class Stamp: 47 cents" << endg;
	
	gout << setPos(200, 425) << "Total Mailing Cost: " << cost << endg;

	if(weight == 1)
	displayBMP("stamp.bmp", 525, 20);

	if (weight == 2)
	{
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 450, 20);
	}
	if (weight == 3)
	{
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 375, 20);
	}
	if (weight == 4)
	{
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 375, 20);
		displayBMP("stamp.bmp", 525, 99);
	}
	if (weight == 5)
	{
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 375, 20);
		displayBMP("stamp.bmp", 525, 99);
		displayBMP("stamp.bmp", 450, 99);
	}
	if (weight == 6)
	{
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 375, 20);
		displayBMP("stamp.bmp", 525, 99);
		displayBMP("stamp.bmp", 450, 99);
		displayBMP("stamp.bmp", 375, 99);
	}
}
