#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Enter Number";
	int x = 0;
	cin >> x;
	string palindrome = to_string(x);
	string palindrome1 = " ";
	int length = palindrome.length();
	int j = 2;
	for (int i = 0; i < length; i++)
	{
		palindrome1[j] = palindrome[i];
		//cout << palindrome1[j] << endl;
		//cout << j << endl;
		j--;
	}
	
	x = stoi(palindrome);
	int y = stoi(palindrome1);

	if (x == y)
	{
		cout << "true";

	}
	else
		cout << "false";
}

