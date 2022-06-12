/*
 * Author: Nikolas George
 * Purpose: Project 1
 */

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <time.h>
#include <algorithm>
#include <iterator>
#include "Scoreboard.h"
#include "Printing.h"

 //User Libraries

using namespace std;

void bubbleSortHighScores(Score* arr, int size);

// Read a Score from an istream
istream& operator>> (istream& is, Score& score) {
	is >> score.name >> score.score;
	return is;
}

// Print a Score to a ostream
ostream& operator<<(ostream& os, const Score& score) {
	os << score.name << " " << score.score;
	return os;
}


Scoreboard::Scoreboard()
{
	// load scores from file-
	// and display in a specific order
	ifstream reader("scoreBoard.txt");
	if (reader.is_open())
	{
		string name;
		int score;

		istream_iterator<Score> scoreItr(reader);

		while (scoreItr != istream_iterator<Score>())
		{
			scores.push_back(*scoreItr);
			scoreItr++;
		}

		// Close reader when we are done
		reader.close();

	}

	// Code for the computer to pick from and taunt the player
	gameOverMessages.addString("Try again!");
	gameOverMessages.addString("Wow you lost?");
	gameOverMessages.addString("Wasn't the word obvious?");
	gameOverMessages.addString("Losing? That's cringe bro.");
	gameOverMessages.addString("Who's keeping score anyway?");
	gameOverMessages.addString("Don't quit your day job.");
	gameOverMessages.addString("Cringe.");
	gameOverMessages.addString("HAHAHAHAHAH!");
	gameOverMessages.addString("IQ lower than the room temperature in Alaska.");
	gameOverMessages.addString("Your rent or mortgage is going up for that.");
	gameOverMessages.addString("I should have just Segfaulted from watching you.");
	gameOverMessages.addString("I hope your code gets linker errors.");
	gameOverMessages.addString("You're a third rate player with a fourth rate vocabulary");
	gameOverMessages.addString("Don't play again. Just don't.");
	gameOverMessages.addString("According to all known laws of aviation, there is no way a bee should be able to fly.");
	gameOverMessages.addString("AHHHHHHHHHHHHHHHHH");
	gameOverMessages.addString("We need to see the compiler as the enemy.");
	gameOverMessages.addString("Did better than the average Valorant player.");
	gameOverMessages.addString("Stop");
	gameOverMessages.addString("Go eat a can of beans.");

}

Scoreboard::~Scoreboard()
{
	// Save scores to a text file
	ofstream outfile("scoreBoard.txt");
	if (outfile.is_open())
	{
		ostream_iterator<Score> outfileItr(outfile, "\n");

		// We use another itr for displaying the scores
		for (auto itr = scores.begin(); itr != scores.end(); itr++)
		{
			*outfileItr = *itr;
		}

		// When the leader-board has exited we go back to the main menu
		outfile.close();
	}

}

void Scoreboard::recordNewScore(int score)
{
	system("cls");

	// This code prints a game over message
	string gameOverMessage = gameOverMessages.randomString();
	printMessage(gameOverMessage);


	// Logic for storing player Score
	Score nameAndScore;

	nameAndScore.score = score;

	// Logic for storing player name
	string playerName;

	// Record user name for storing score
	printMessage("Enter your first name: ");
	cin >> playerName;
	// Record score for game over
	nameAndScore.name = playerName;
	scores.push_back(nameAndScore);	

	printScores();
	system("pause");
}

void Scoreboard::printScores()
{
	// Sort all scores-
	// With a specific pattern
	bubbleSortHighScores(scores.data(), scores.size());

	// Print all scores when user-
	// Presses L at main menu
	system("cls");
	// Display message High Scores:
	printMessage("High Scores:");
	for (auto itr = scores.begin(); itr != scores.end(); itr++)
	{
		printMessage(itr->name + ": " + to_string(itr->score));
	}
}

void bubbleSortHighScores(Score* arr, int size)
{
	if (size == 1)
		return;

	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i].score < arr[i + 1].score)
		{
			Score temp;

			temp = arr[i];

			arr[i] = arr[i + 1];

			arr[i + 1] = temp;
		}
	}

	bubbleSortHighScores(arr, size - 1);

}