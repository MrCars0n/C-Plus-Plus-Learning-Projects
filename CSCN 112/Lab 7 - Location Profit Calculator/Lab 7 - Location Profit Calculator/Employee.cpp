// Employee Class Implementation File

#include "Employee.h"
#include <iomanip> // setprecision

// Overload the insertion operator to be able to print out a room object using <<
std::ostream& operator<<(std::ostream& out, const Employee& inputEmployee)
{
	out << std::setprecision(2) << std::fixed;
	out << "Name: " << inputEmployee.getFirstName() << " " << inputEmployee.getLastName() << std::endl;
	out << "Employee ID: " << inputEmployee.getID() << std::endl;
	out << "Birth Date: " << inputEmployee.getBirthDate() << std::endl;
	out << "Date Hired: " << inputEmployee.getDateHired() << std::endl;
	out << "Employee Rating: " << inputEmployee.getEmployeeRating() << std::endl;
	out << "Completed Job Revenue: " << std::endl;
	// Run through whole vector and add to temp total
	for (const auto& j : inputEmployee.jobs)
	{
		out << "$" << j << std::endl;
	}

	return out;
}

// Default constructor
Employee::Employee()
{
	Date d(0, 0, 0);

	setID(0);
	setDateHired(d);
	setMilesTraveled(0);
	setEmployeeRating(0);
}

// Multiargument constructor
Employee::Employee(int id, Date dH, int miles, float rating)
{
	setID(id);
	setDateHired(dH);
	setMilesTraveled(miles);
	setEmployeeRating(rating);
}

// Destructor
Employee::~Employee()
{
}

// Get and set
void Employee::setID(int i)
{
	ID = i;
}
int Employee::getID() const
{
	return ID;
}

void Employee::setDateHired(Date d)
{
	dateHired = d;
}
Date Employee::getDateHired() const
{
	return dateHired;
}

void Employee::setMilesTraveled(int m)
{
	milesTraveled = m;
}
int Employee::getMilesTraveled() const
{
	return milesTraveled;
}

void Employee::setEmployeeRating(float r)
{
	employeeRating = r;
}
float Employee::getEmployeeRating() const
{
	return employeeRating;
}

// Vector manipulation
void Employee::addJob(float j) // append job to end of vector
{
	jobs.push_back(j);
}
void Employee::removeJob(int i) // remove item at index i
{
	jobs.erase(jobs.begin() + i);
}

// Calculated total of revenue vector
float Employee::completedJobRevenue() const
{
	float temp = 0;

	// Run through whole vector and add to temp total
	for (const auto &j : jobs)
	{
		temp += j;
	}

	return temp;
}

// < operator overload
bool Employee::operator<(const Employee& other) const
{
	return getID() < other.getID();
}

// Assignment operator
const Employee& Employee::operator=(const Employee& rightSideEmployee)
{
	if (this != &rightSideEmployee) // avoid self-assignment
	{
		// Set value stored in address that length points to equal to value
		//  stored in the address that rightSideRoom's length points to]
		//  By default, = operator takes length = rightSideRoom.length; resulting in shallow copy
		setFirstName(rightSideEmployee.getFirstName());
		setLastName(rightSideEmployee.getLastName());
		setID(rightSideEmployee.getID());
		setBirthDate(rightSideEmployee.getBirthDate());
		setDateHired(rightSideEmployee.getDateHired());
		setMilesTraveled(rightSideEmployee.getMilesTraveled());
		setEmployeeRating(rightSideEmployee.getEmployeeRating());

		for (const auto& j : rightSideEmployee.jobs)
		{
			jobs.push_back(j);
		}
	}

	return *this;
}