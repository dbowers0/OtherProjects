#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "graph1.h"
#include "Game.h"

using namespace std;

class Game
{
private:
	string fileName;
	string word;


public:
	Game();
	string getFileName();
	void setFileName(string fn);
	void setWord(int rand_no);
	string getWord();
	void draw();
	int play();
};

#endif

