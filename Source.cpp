#include <iostream>
#include <string>
#include "College.h"
#include <cstring>
using namespace std;
int main()
{
	College *t1 = new College();
	string userState = " ";
	
	cout << "Names of College in Arkansas" << endl << endl;
	t1->assign();

	cout << "What state do you want to search?";
	cin >> userState;
	//t1->Hello(userState);

	
}