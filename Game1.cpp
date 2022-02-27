#include <iostream>
#include <cstring>
#include <fstream>
#include "graph1.h"
#include "Game.h"

using namespace std;


Game::Game()
{
	fileName = " ";
	word = " ";
}


string Game::getFileName()
{
	return fileName;

}
void Game::setFileName(string fn)
{
	fileName = fn;

}
void Game::setWord(int rand_no)
{
	int word_count = 0;
	int total_words = 1149;
	string temp_word;
	//open file for input


	fstream in_file(fileName, ios::in);

	//test file for opening

	if (!in_file)
	{
		cout << "ERROR READING FILE";
	}
	while (true)
	{
		
		//read word one at a time
		in_file >> temp_word;
		
		//test for end of file
		if (word_count == 1149)
		{
			in_file.close();
			break;
		}
			
		//test for words
		if (word_count == rand_no)
		{
			this->word = temp_word;
			break;
		}
		temp_word = "";
		word_count++;
		
		
	}

}
string Game::getWord()
{
	return word;

}
void Game::draw()
{
	int length_of_word = word.length();
	int x = 100;
	int y = 250;

	string fn = "";

	//display the letters

	//words1.txt

	for (int i = 0; i < length_of_word; i++)
	{
		drawRect(x, y, 32, 32);
		/*fn = "";
		fn += word[i];
		//cout << word[i];
		fn += ".bmp";
		displayBMP(fn, x, y);*/
		x += 33;

	}

}

int Game::play()
{
	int score = 0;
	int length_of_word = word.length();
	int x = 100;
	int y = 250;
	string fn = "";
	string fw = "";
	char guessword[] = "";
	int vowels = 0;
	int guesses = 0;

	fw += word[0];
	fw += ".bmp";
	displayBMP(fw, x, y);
	int a = 1;
	string guess;
	int totalScore = 0;
	
	for (int i = 1; i < length_of_word; i++)
	{
		if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
		{
			
			int b = 33 * a;
			fn = "";
			fn += word[i];
			fn += ".bmp";
			displayBMP(fn, x + b, y);
			vowels++;
			//x += 33;
		}
		a++;
	
	}
	score = length_of_word - vowels - 1;
	int trails = score;
	
	a = 1;

	for (int i = 0; i < trails; i++)
	{
		guess = "";
		gout << setPos(100, 120) << "Guess Number: " << guesses + 1 << endg;
		cout << "What is the word? ";
		cin >> guess;
		if (guess == word)
		{
			
			for (int i = 1; i < length_of_word; i++)
			{
				if (word[i] == 'b' || word[i] == 'c' || word[i] == 'd' || word[i] == 'f' || word[i] == 'g' || word[i] == 'h' || word[i] == 'j' || word[i] == 'k' || word[i] == 'l' || word[i] == 'm' || word[i] == 'n' || word[i] == 'p'
					|| word[i] == 'q' || word[i] == 'r' || word[i] == 's' || word[i] == 't' || word[i] == 'v' || word[i] == 'w' || word[i] == 'x' || word[i] == 'y' || word[i] == 'z')
				{
					int b = 33 * a;
					fn = "";
					fn += word[i];
					fn += ".bmp";
					displayBMP(fn, x + b, y);
					//x += 33;
					
				}
				a++;
			}
			gout << setPos(100, 110) << "!!!CORRECT!!!" << endg;
			break;
		}
		if (guess != word)
		{
			gout << setPos(100, 90) << "!!!INCORRECT!!!" << endg;
			score -= 2;
			guess += 1;
		}
	}
	cout << score;
	score *= 10;
	totalScore += score;
	gout << setPos(100, 80) << "Total Score: " << totalScore;
	gout << setPos(100, 130) << "Score: " << score;
	cout << score;
	return score;
}




