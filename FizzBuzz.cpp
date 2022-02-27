#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int number = 1;

	for (int i = 0; i < 20; i++)
	{
		if (number % 3 != 0 && number % 5 != 0)
		{
			cout << number << endl;
		}
		if (number % 5 == 0 && number % 3 == 0)
		{
			cout << "FIZZBUZZ" << endl;
		}
		
		else if (number % 3 == 0)
		{
			cout << "FIZZ" << endl;
		}
		else if (number % 5 == 0)
			cout << "BUZZ" << endl;
		
		number++;
	}
}