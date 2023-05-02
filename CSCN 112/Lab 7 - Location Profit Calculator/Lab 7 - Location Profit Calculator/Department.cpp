// Department Class Implementation File

#include "Department.h"
#include <string> // String
#include <vector> // Employee vector

const float BASE_RATE = 2880;

// Overload the insertion operator to be able to print out a room object using <<
std::ostream& operator<<(std::ostream& out, const Department& inputDepartment)
{
	out << "----------------------------------------------------------------" << std::endl;
	out << "Department Information for " << inputDepartment.getName() << std::endl;
	out << "----------------------------------------------------------------" << std::endl;
	out << "Capacity: " << inputDepartment.getCapacity() << std::endl;
	out << "Product Cost: $" << inputDepartment.getProductCost() << std::endl;

	// Print out manager if they exist
	if (inputDepartment.getManager().getID() != 0)
	{
		out << std::endl << "Manager" << std::endl;
		out << "----------------------------------------------------------------" << std::endl;
		out << inputDepartment.getManager() << std::endl;
	}

	// Print out employees if at least 1 exists
	if (inputDepartment.numOfEmployees() > 0)
	{
		out << "Current Employees: " << std::endl;
		out << "----------------------------------------------------------------" << std::endl;
		for (const auto& e : inputDepartment.employees)
		{
			out << e << std::endl;
			out << "----------------------------------------------------------------" << std::endl;
		}
	}

	return out;
}

// Default constructor
Department::Department()
{
	Manager m;

	setName("");
	setCapacity(0);
	setManager(m);
}

// Multiargument constructor
Department::Department(std::string n, int c, float p, Manager m)
{
	setName(n);
	setCapacity(c);
	setProductCost(p);
	setManager(m);
}

// Destructor
Department::~Department()
{
}

// Get and set
void Department::setName(std::string n)
{
	name = n;
}
std::string Department::getName() const
{
	return name;
}

void Department::setCapacity(int c)
{
	capacity = c;
}
int Department::getCapacity() const
{
	return capacity;
}

void Department::setProductCost(float c)
{
	productCost = c;
}
float Department::getProductCost() const
{
	return productCost;
}

void Department::setManager(Manager m)
{
	manager = m;
}
Manager Department::getManager() const
{
	return manager;
}

// Vector manipulation
void Department::addEmployee(Employee e) // append job to end of vector
{
	employees.push_back(e);
}
void Department::removeEmployee(int id)
{
	int index = -1, count = 0;

	// Search through employees vector
	for (const auto& e : employees)
	{
		// If current elements ID matches prompted ID for removal
		if (e.getID() == id)
		{
			index = count;
		}
		count++;
	}

	if (index != -1) // If employee is found
	{
		employees.erase(employees.begin() + index); // remove item at index i
	}
	else // If employee not found
	{
		std::cout << "Employee with ID " << id << " cannot be found." << std::endl;
	}
}
int Department::numOfEmployees() const
{
	return employees.size();
}

// Total Revenue for department
float Department::totalRevenue() const
{
	float temp = 0;

	// Run through whole vector and add revenue to temp total
	for (const auto &e : employees)
	{
		temp += e.completedJobRevenue();
	}

	return temp;
}

// Cost of labor for department
//  number of employees in the department multiplied by the base pay rate 
//  (all painters are currently paid at the same rate) then adding the salary 
//  of the manager for that department
float Department::costOfLabor() const
{
	return (employees.size() * BASE_RATE) + manager.getSalary();
}

// Cost of travel
//  adding up all employees’ miles and multiplying by the standard rate of ($0.87/mile)
float Department::costOfTravel() const
{
	float temp = 0;

	// Run through whole vector and add miles to temp total
	for (const auto &e : employees)
	{
		temp += e.getMilesTraveled();
	}

	return temp * 0.87;
}

// Checks if inputted ID is already taken
bool Department::idTaken(int i) const
{
	// Check if manager has id
	if (getManager().getID() == i)
	{
		return true;
	}

	// Run through whole vector and check for id
	for (const auto& e : employees)
	{
		if (e.getID() == i)
		{
			return true;
		}
	}

	// If no one with same ID is found, return false
	return false;
}

// Average Employee Rating
float Department::avgEmployeeRating() const
{
	float temp = 0, counter = 0;

	// Run through whole vector and add revenue to temp total
	for (const auto& e : employees)
	{
		temp += e.getEmployeeRating();
		counter++;
	}

	return temp / counter;
}