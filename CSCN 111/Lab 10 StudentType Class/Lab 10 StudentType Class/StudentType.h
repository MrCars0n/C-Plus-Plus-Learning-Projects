#pragma once

#include <string>

class StudentType
{
private:
	// instance or class variables
	std::string studentFName;
	std::string studentLName;
	int testScore;
	char grade;

public:
	// Constructors
	StudentType(std::string f, std::string l, int s, char g);
	StudentType();

	// setters
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setTestScore(int score);
	void setGrade(char gr);

	// getters
	std::string getFirstName() const;
	std::string getLastName() const;
	int getTestScore() const;
	char getGrade() const;
};
