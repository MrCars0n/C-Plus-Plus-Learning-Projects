#include "StudentType.h"
#include <string>

//Your class implementation functions go below
// setters
void StudentType::setFirstName(std::string firstName)
{
	studentFName = firstName;
}

void StudentType::setLastName(std::string lastName)
{
	studentLName = lastName;
}

void StudentType::setTestScore(int score)
{
	if (score > 0 && score < 100)
	{
		testScore = score;
	}
	else
	{
		testScore = 0;
	}
}

void StudentType::setGrade(char gr)
{
	if ((int)gr >= (int)'A' && (int)gr <= (int)'F' && gr != 'E')
	{
		grade = gr;
	}
	else
	{
		grade = 'F';
	}
}

// Constructors
StudentType::StudentType(std::string f, std::string l, int s, char g)
{
	setFirstName(f);
	setLastName(l);
	setTestScore(s);
	setGrade(g);
}

StudentType::StudentType()
{
	setFirstName("");
	setLastName("");
	setTestScore(0);
	setGrade('F');
}

// getters
std::string StudentType::getFirstName() const
{
	return studentFName;
}

std::string StudentType::getLastName() const
{
	return studentLName;
}

int StudentType::getTestScore() const
{
	return testScore;
}

char StudentType::getGrade() const
{
	return grade;
}