// Implementation file for our basketballGame class
#include "basketballGame.h"
#include <iostream> // cin & cout in print

// Default Constructor
basketballGame::basketballGame()
{
	opponent = "";
	teamName = "";
	our_score = 0;
	opponent_score = 0;
}

// Two - Argument constructor - Know teams, but not score
basketballGame::basketballGame(std::string tName, std::string oName)
{
	opponent = oName;
	teamName = tName;
	our_score = 0;
	opponent_score = 0;
}

// Four-argument - game finished, all details known
basketballGame::basketballGame(std::string tName, std::string oName, int tScore, int oScore)
{
	opponent = oName;
	teamName = tName;
	our_score = tScore;
	opponent_score = oScore;
}

void basketballGame::setOpponentName(std::string oName)
{
	// Bring in the opponent's name as oName
	// Set the private member variable to the oName passed in
	opponent = oName;
}

std::string basketballGame::getOpponentName() const
{
	// Function should return the value of the private member variable
	return opponent;
}

void basketballGame::setTeamName(std::string tName)
{
	teamName = tName;
}

std::string basketballGame::getTeamName() const
{
	return teamName;
}

void basketballGame::setOurScore(int oScore)
{
	our_score = oScore;
}

int basketballGame::getOurScore() const
{
	return our_score;
}

void basketballGame::setOppScore(int oppScore)
{
	opponent_score = oppScore;
}

int basketballGame::getOppScore() const
{
	return opponent_score;
}

// Print function
void basketballGame::print() const
{
	std::cout << "Our opponent is " << opponent << " and the final score is " <<
		opponent << ": " << opponent_score << " " << teamName << ": " << our_score << std::endl
		<< std::endl;
	if (our_score > opponent_score)
		std::cout << "We win!" << std::endl;
	else
		std::cout << opponent << " wins the game." << std::endl;
}