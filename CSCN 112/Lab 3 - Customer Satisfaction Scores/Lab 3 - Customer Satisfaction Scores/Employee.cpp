// Employee Class Implementation File
#include "Employee.h" // Employee Object
#include <algorithm> // sortScores()
#include <iostream> // cout
#include <iomanip> // setw for printEmployeeinfo()
#include <regex> // removing trailing zeros

// Default Constructor
Employee::Employee()
{
	name = "NULL";
	city = "NULL"; 
	id = "NULL";
}

// 3-argument constructor
Employee::Employee(std::string n, std::string c, std::string i)
{
	name = n;
	city = c;
	id = i;
}

// Set & Get(name, city, ID)
void Employee::setName(std::string n)
{
	name = n;
}

std::string Employee::getName() const
{
	return name;
}

void Employee::setCity(std::string c)
{
	city = c;
}

std::string Employee::getCity() const
{
	return city;
}

void Employee::setID(std::string i)
{
	id = i;
}

std::string Employee::getID() const
{
	return id;
}


void Employee::addScore(float s)
{
	// Redundant error check
	if (s <= 5 && s >= 0)
	{
		scores.push_back(s);
	}
	else
	{
		// Error message
		std::cout << "Value is not within range 0-5" << std::endl;
	}
	sortScores();
}

// Remove Score (location integer)
void Employee::removeScore(int i)
{
	// Removing a score from the vector and error checking within range
	if (i > 0 && i < numScores())
	{
		scores.erase(scores.begin() + i);
	}
	else if (numScores() == 0) // If vector is empty
	{
		std::cout << "Index out of range. Vector is empty" << std::endl;
	}
	else if (numScores() == 1) // If vector only has 1 item
	{
		std::cout << "Index out of range. Only option is value 0" << std::endl;
	}
	else // If vector has two or more items
	{
		std::cout << "Index out of range. Input value between 0-" << numScores() - 1 << std::endl;
	}
}

void Employee::printEmployeeinfo() const
{
	// Check if an employee exists first
	if (getName() != "NULL" && printScores() != "")
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "*****************************************************************" << std::endl;
		std::cout << std::setw(35) << std::right << "Employee Info" << std::endl;
		std::cout << std::setw(35) << std::left << "Employee Name:" << getName() << std::endl;
		std::cout << std::setw(35) << std::left << "City:" << getCity() << std::endl;
		std::cout << std::setw(35) << std::left << "ID:" << getID() << std::endl;
		std::cout << "*****************************************************************" << std::endl;
		std::cout << std::setw(40) << std::right << "Customer Satisfaction Info" << std::endl;
		std::cout << std::setw(35) << std::left << "Average Score:" << averageScore() << std::endl;
		std::cout << std::setw(35) << std::left << "Lowest Score:" << lowestScore() << std::endl;
		std::cout << std::setw(35) << std::left << "Highest Score:" << highestScore() << std::endl;
		std::cout << "List of all recorded scores:" << std::endl;
		std::cout << printScores();
		std::cout << std::setw(35) << std::right << "End of Information for " << getName() << std::endl;
		std::cout << "*****************************************************************" << std::endl << std::endl;
	}
	// If no scores are added, only print out the name, city, and id
	else if (getName() != "NULL" && printScores() == "")
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "*****************************************************************" << std::endl;
		std::cout << std::setw(35) << std::right << "Employee Info" << std::endl;
		std::cout << std::setw(35) << std::left << "Employee Name:" << getName() << std::endl;
		std::cout << std::setw(35) << std::left << "City:" << getCity() << std::endl;
		std::cout << std::setw(35) << std::left << "ID:" << getID() << std::endl;
		std::cout << std::setw(35) << std::right << "End of Information for " << getName() << std::endl;
		std::cout << "*****************************************************************" << std::endl << std::endl;
	}
	// If the employee is set to name "NULL", assume that one has not been created. Don't print
	else
	{
		std::cout << "Employee has not beed created or loaded in. Please create or load an employee first" << std::endl;
	}
}

// Public access to vector
std::string Employee::printScores() const
{
	// Convert each float to a string and remove trailing zeros
	// Create temp vector
	std::vector<std::string> decimalStrings;

	// Go through entire scores vector
	for (auto v : scores) {
		// temp string converting selected vector item to string
		std::string s = std::to_string(v);

		// remove trailing zeros
		s = std::regex_replace(s, std::regex("\\.?0*$"), "");

		// Add altered string to temp string vector
		decimalStrings.push_back(s);
	}

	// Create temp string to be returned after scores added
	std::string tempString = "";
	for (int i = 0; i < numScores(); i++)
	{
		// Only add new line if not on the last score
		// Add tempVector scores to singular temp string
		if (i != numScores())
		{
			tempString += decimalStrings[i] + "\n";
		}
		else
		{
			tempString += decimalStrings[i];
		}
	}

	// Return temp string
	return tempString;
}

// Resets all values of employee to default
void Employee::resetEmployee()
{
	name = "NULL";
	city = "NULL";
	id = "NULL";
	scores.clear();
}

// Sort vector
void Employee::sortScores()
{
	// Sort algorithm (Based on resources in lab guidelines)
	for (const auto& i : scores)
	{
		std::sort(scores.begin(), scores.end());
	}
}

// Calculate vector average
float Employee::averageScore() const
{
	// Temp addition variable
	float temp = 0;

	// Add every element in the vector to the temp variable
	for (auto v : scores)
	{
		temp += v;
	}

	// Typecast to float to prevent truncation
	return temp / (float)numScores();
}

// Find lowest score in vector
float Employee::lowestScore() const
{
	// Temp min variable at max value
	float min = 5;

	// Run through vector
	for (int i = 0; i < numScores(); i++)
	{
		// If current iteration's vector slot is less than min, set min to that value
		if (scores[i] < min)
		{
			min = scores[i];
		}
	}

	return min;
}

// Find highest score in vector
float Employee::highestScore() const
{
	// Temp max variable at min value
	float max = 0;

	// Run through vector
	for (int i = 0; i < numScores(); i++)
	{
		// If current iteration's vector slot is greater than max, set max to that value
		if (scores[i] > max)
		{
			max = scores[i];
		}
	}

	return max;
}

// Return vector size
int Employee::numScores() const
{
	return scores.size();
}
