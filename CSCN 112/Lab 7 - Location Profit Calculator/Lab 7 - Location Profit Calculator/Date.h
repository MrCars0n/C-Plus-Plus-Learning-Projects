// Date Class Declaration File
#pragma once

#include <iostream>
#include <cstdlib>
#include <cctype>

class Date
{
	friend std::ostream& operator<<(std::ostream& output, Date d)
	{
		output << d.month << "/" << d.day << "/" << d.year;
		return output;
	}

public:
	Date(int d = 0, int m = 0, int yyyy = 0)
	{
		setDate(d, m, yyyy);
	}

	~Date() {}

	void setDate(int d, int m, int yyyy)
	{
		day = d;
		month = m;
		year = yyyy;
	}

	// Assignment operator
	const Date& operator=(const Date& rightSideDate)
	{
		if (this != &rightSideDate) // avoid self-assignment
		{
			// Set value stored in address that length points to equal to value
			//  stored in the address that rightSideRoom's length points to
			//  By default, = operator takes length = rightSideRoom.length; resulting in shallow copy
			day = rightSideDate.day;
			month = rightSideDate.month;
			year = rightSideDate.year;
		}
		return *this;
	}

private:
	int day;
	int month;
	int year;
};
