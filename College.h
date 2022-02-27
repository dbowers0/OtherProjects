#pragma once
#include <iostream>
#include <string>
using namespace std; 

const int CAPACITY = 400;

class College
{
public:
	string assign();
	string assignState();
	string assignInstitution();
	double assignCost();
	double assignRate();
	string Hello(string);
private:
	string name[CAPACITY];
	string state[CAPACITY];
	string typeofInstitution[CAPACITY];
	int cost[CAPACITY];
	double Rate[CAPACITY];
};
