// Fig. 10.11: Employee.cpp
// Employee class member-function definitions.
#include <iostream>
#include "Employee.h" // Employee class definition
#include "Date.h" // Date class definition
using namespace std;

// constructor uses member initializer list to pass initializer
// values to constructors of member objects
Employee::Employee(const string &first, const string &last,
	const Date &dateOfBirth, const Date &dateOfHire)
	: firstName(first), lastName(last), birthDate(dateOfBirth), hireDate(dateOfHire)
	{
	// output Employee object to show when constructor is called
		cout << "Employee object constructor: "
		<< firstName << ' ' << lastName << endl;
} // end Employee constructor

// print Employee object
void Employee::print() const
{
	cout << lastName << ", " << firstName << " Hired: ";
	hireDate.print();
	cout << " Birthday: ";
	birthDate.print();
	cout << endl;
	} // end function print

// output Employee object to show when its destructor is called
Employee::~Employee()
{
	cout << "Employee object destructor: "
		<< lastName << ", " << firstName << endl;
} // end ~Employee destructor