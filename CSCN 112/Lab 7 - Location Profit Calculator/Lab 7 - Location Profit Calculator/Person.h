// Person Class Declaration File
#pragma once

#include <string> // String
#include "Date.h" // Date object

class Person
{
public:
	// Default constructor
	Person();

	// Multiargument constructor
	Person(std::string, std::string, Date);

	// Destructor
	~Person();

	// Get and set
	void setFirstName(std::string);
	std::string getFirstName() const;

	void setLastName(std::string);
	std::string getLastName() const;

	void setBirthDate(Date);
	Date getBirthDate() const;
private:
	// Design decision: Only include First Name, Last Name, and Birthday because person may 
	//  not be an employee so even though manager and employee share hire date and ID,
	//  they are inheriting qualities that all people share
	std::string fName;
	std::string lName;
	Date bDate;

};