// Employee Class Declaration File
#pragma once

#include "Person.h" // Person inheritence
#include <vector> // Jobs vector

class Employee : public Person
{
	// Overload the insertion operator to be able to print out a room object using <<
	friend std::ostream& operator<<(std::ostream&, const Employee&);

public:
	// Default constructor
	Employee();

	// Multiargument constructor
	Employee(int, Date, int, float);

	// Destructor
	~Employee();

	// Get and set
	void setID(int);
	int getID() const;

	void setDateHired(Date);
	Date getDateHired() const;

	void setMilesTraveled(int);
	int getMilesTraveled() const;

	void setEmployeeRating(float);
	float getEmployeeRating() const;

	// Vector manipulation
	void addJob(float);
	void removeJob(int);

	// Calculated total of revenue vector
	float completedJobRevenue() const;

	// < operator overload
	bool operator<(const Employee& other) const;

	// Assignment operator
	const Employee& operator=(const Employee&);

private:
	int ID;
	Date dateHired;
	int milesTraveled;
	float employeeRating;
	std::vector<float> jobs;
};