// Person Class Implementation File

#include <string> // String
#include "Date.h" // Date object
#include "Person.h"

// Default constructor
Person::Person()
{
	Date d(0, 0, 0);
	setFirstName("");
	setLastName("");
	setBirthDate(d);
}

// Multiargument constructor
Person::Person(std::string f, std::string l, Date b)
{
	setFirstName(f);
	setLastName(l);
	setBirthDate(b);
}

// Destructor
Person::~Person()
{
}

// Get and set
void Person::setFirstName(std::string f)
{
	fName = f;
}
std::string Person::getFirstName() const
{
	return fName;
}

void Person::setLastName(std::string l)
{
	lName = l;
}
std::string Person::getLastName() const
{
	return lName;
}

void Person::setBirthDate(Date b)
{
	bDate = b;
}
Date Person::getBirthDate() const
{
	return bDate;
}