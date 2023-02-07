#pragma once

#include<string>

// Define a struct object for a single game
class basketballGame
{
public:
	// Constructors
	// Default Constructor
	basketballGame();

	// Two - Argument constructor - Know teams, but not score
	basketballGame(std::string tName, std::string oName);

	// Four-argument - game finished, all details known
	basketballGame(std::string tName, std::string oName, int tScore, int oScore);

	// Get and Set functions
	void setOpponentName(std::string oName);
	std::string getOpponentName() const;

	void setTeamName(std::string tName);
	std::string getTeamName() const;

	void setOurScore(int oScore);
	int getOurScore() const;

	void setOppScore(int oppScore);
	int getOppScore() const;

	// Print function
	void print() const;

private:
	std::string opponent;
	std::string teamName;
	int our_score;
	int opponent_score;
};