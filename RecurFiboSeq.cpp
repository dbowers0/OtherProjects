#include <iostream>
#include <cmath>
using namespace std;

int recursion(int n);

int main()
{
	int n = 10;
	for (int i = 0; i < n; i++)
		cout << recursion(i) << endl;
}

int recursion(int n)
{
	if (n <= 1)
		return n;
	else
		return(recursion(n - 1) + recursion(n - 2));
}