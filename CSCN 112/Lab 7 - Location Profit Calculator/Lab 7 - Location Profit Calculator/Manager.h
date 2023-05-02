// Manager Class Declaration File
#pragma once

#include "Person.h" // Person inheritence
#include <string> // String

class Manager : public Person
{
	// Overload the insertion operator to be able to print out a room object using <<
	friend std::ostream& operator<<(std::ostream&, const Manager&);

public:
	// Default constructor
	Manager();

	// Multiargument constructor
	Manager(std::string, int, Date, Date, float);

	// Destructor
	~Manager();

	// Get and set
	void setTitle(std::string);
	std::string getTitle() const;

	void setID(int);
	int getID() const;

	void setDateHired(Date);
	Date getDateHired() const;

	void setPromotionDate(Date);
	Date getPromotionDate() const;

	void setSalary(float);
	float getSalary() const;

	// Assignment operator
	const Manager& operator=(const Manager&);

private:
	std::string title;
	int ID;
	Date dateHired;
	Date promotionDate;
	float salary;
};