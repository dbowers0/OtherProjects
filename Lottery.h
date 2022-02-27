//Darius Bowers
//Lab 6 Out
#ifndef LOTTERY_H
#define LOTTERY_H

class Lottery
{
private:
	int no_balls;
	int* yourNumbers;
	int* winningNumbers;
	int matches;

public:
	Lottery();
	~Lottery();
	int getNoBalls();
	bool setNoBalls(int no_balls);
	void addNumber();
	void displayYourNumbers();
	void processWinningNumbers();
	void selectionSort();
	void insertionSort();
	int getMatches();
	int binarySearch(int target);
	int computeWinnings();
};
#endif
#pragma once
