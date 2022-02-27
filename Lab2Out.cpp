//Darius Bowers
//a basic 2-player card game. One player represents you while the 2nd player represents the dealer

#include <iostream>
#include <ctime>
#include "graph1.h"
using namespace std;

void getWager(int* wager);
void deal(int* pc1_no, int* pc2_no, int* deal1_no, int* deal2_no);
int computeScore(int* pc1_no, int* pc2_no, int card1_no, int card2_no);
int computeScore1(int* deal1_no, int* deal2_no, int card1_no, int card2_no);
void displayResults(int pc1_no, int pc2_no, int deal1_no, int deal2_no, int player_score, int dealer_score);

int main()
{
	int wager, pc1_no, pc2_no, deal1_no, deal2_no;
	int card1_no = 0, card2_no = 0;
	int player_score;
	int dealer_score;
	char repeat = ' ';
	do
	{
		displayGraphics();
		getWager(&wager);
		deal(&pc1_no, &pc2_no, &deal1_no, &deal2_no);
		player_score = computeScore(&pc1_no, &pc2_no, card1_no, card2_no);
		dealer_score = computeScore1(&deal1_no, &deal2_no, card1_no, card2_no);
		displayResults(pc1_no, pc2_no, deal1_no, deal2_no, player_score, dealer_score);
		cout << "Would you like to repeat the program <Press y for yes and N for no> ";
		cin >> repeat;
		clearGraphics();
	} while (repeat == 'y' || repeat == 'Y');

}

void getWager(int* wager)
{
	do
	{
		cout << "Enter your wager: <$5 minimum>: ";
		cin >> *wager;
			if (*wager < 5)
				cout << "\nMust be at least $5 ";
	} while (*wager < 5);
}

void deal(int* pc1_no, int* pc2_no, int* deal1_no, int* deal2_no)
{
	srand(time(0));

	*pc1_no = rand() % 13 + 2;
	*pc2_no = rand() % 13 + 2;
	*deal1_no = rand() % 13 + 2; 
	*deal2_no = rand() % 13 + 2; 

	
	
}

int computeScore(int* pc1_no, int* pc2_no, int card1_no, int card2_no)
{
	int score = 0;
	card1_no = *pc1_no;
	card2_no = *pc2_no;
	int card1_value = *pc1_no;
	int card2_value = *pc2_no;



	if (card1_no >= 11 && card1_no < 14)
	{
		card1_value = 10;
	}
	if (card1_no == 14)
	{
		card1_value = 11;
	}
	if (card2_no >= 11 && card2_no < 14)
	{
		card2_value = 10;
	}
	if (card2_no == 14)
	{
		card2_value = 11;
	}
	 
	score = card1_value + card2_value;
	return score;
}

int computeScore1(int* deal1_no, int* deal2_no, int card1_no, int card2_no)
{
	int score1 = 0;
	card1_no = *deal1_no;
	card2_no = *deal2_no;
	int card1_value = card1_no;
	int card2_value = card2_no;



	if (card1_no >= 11 && card1_no < 14)
	{
		card1_value = 10;
	}
	if (card1_no == 14)
	{
		card1_value = 11;
	}
	if (card2_no >= 11 && card2_no < 14)
	{
		card2_value = 10;
	}
	if (card2_no == 14)
	{
		card2_value = 11;
	}

	score1 = card1_value + card2_value;
	return score1;
	
}

void displayResults(int pc1_no, int pc2_no, int deal1_no, int deal2_no, int player_score, int dealer_score)
{
	string fn = "";
	string fn1 = "";
	string fn2 = "";
	string fn3 = "";

	int a = 2;
	displayBMP("back.bmp", 75, 100);
	displayBMP("back.bmp", 400, 100);
	fn = "h" + to_string(pc1_no) + ".bmp";
	fn1 = "d" + to_string(pc2_no) + ".bmp";
	fn2 = "c" + to_string(deal1_no) + ".bmp";
	fn3 = "s" + to_string(deal2_no) + ".bmp";
	displayBMP(fn, 150, 100);
	displayBMP(fn1, 225, 100);
	displayBMP(fn2, 475, 100);
	displayBMP(fn3, 550, 100);
	gout << setPos(75, 90) << "Your Cards " << endg;
	gout << setPos(400, 90) << "Dealer Cards " << endg;
	gout << setPos(75, 220) << "Your Total: " << player_score << endg;
	gout << setPos(400, 220) << "Dealer Total: " << dealer_score << endg;
	if (player_score > dealer_score)
		gout << setPos(290, 300) << "You Win!" << endg;
	if (dealer_score > player_score)
		gout << setPos(290, 300) << "You Lose!" << endg;
	if (player_score == dealer_score)
		gout << setPos(290, 300) << "Tie" << endg;
}
