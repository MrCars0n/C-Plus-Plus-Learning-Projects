// Employee Class Declaration File
#pragma once

#include <string> // name, city, id & function arguments
#include <vector> // scores vector

class Employee
{
public:
	// Default Constructor
	Employee();

	// 3-argument constructor
	Employee(std::string, std::string, std::string);

	// Set & Get(name, city, ID)
	void setName(std::string);
	std::string getName() const;

	void setCity(std::string);
	std::string getCity() const;

	void setID(std::string);
	std::string getID() const;

	// addScore(float) (Positive values between 1 & 5)
	void addScore(float);

	// Remove Score (location integer)
	void removeScore(int);

	// Print employee information
	void printEmployeeinfo() const;

	// Public access to vector
	std::string printScores() const;

	// Resets all values of employee to default
	void resetEmployee();

	// Return vector size
	int numScores() const;
private:
	// Private variables
	std::vector<float> scores;
	std::string name;
	std::string city;
	std::string id;
	
	// Sort Vector (Sorting algorithm library - private helper function)
	void sortScores();

	// Calculate vector average
	float averageScore() const;

	// Find lowest and highest score in vector (search algorithm)
	float lowestScore() const;
	float highestScore() const;
};