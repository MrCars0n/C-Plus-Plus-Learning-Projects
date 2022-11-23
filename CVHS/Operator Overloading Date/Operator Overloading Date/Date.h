/*
	Date Class 2.0

	GOALS:
		1) Overload << to print the date
		2) Overload ++ to add a day to the date with proper rollover
		3) Overload += to add a certain number of days, also with proper rollover
*/

#ifndef DATE_H
#define DATE_H
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Date
{
	friend ostream &operator<<(ostream&, Date&);

public:
	Date(int m = 1, int d = 1, int y = 2020);
	void setDate(int, int, int);
	bool leapYear(int);
	bool endOfMonth(int);

	Date operator++(int);
	Date &operator+=(int);
	Date operator--(int);
	Date &operator-=(int);

private:
	int month;
	int day;
	int year;

	static const int days[];
	void helpIncrement();
	void helpDecrement();
};

const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int m, int d, int y)
{
	setDate(m, d, y);
}

void Date::setDate(int m, int d, int y)
{
	month = (m >= 1 && m <= 12 ? m : 1);

	year = (y >= 1753 ? y : 2020);

	if ((month == 2 && leapYear(year) == true && d >= 1 && d <= 29) ||
		(d >= 1 && d <= days[month]))
	{
		day = d;
	}
	else
	{
		day = 1;
	}
}

bool Date::leapYear(int y)
{
	return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}

bool Date::endOfMonth(int d)
{
	if (month == 2 && leapYear(year))
	{
		return d == 29;
	}
	else
	{
		return d == days[month];
	}
}

void Date::helpIncrement()
{
	if (!endOfMonth(day))
	{
		day++;
	}
	else if (month < 12)
	{
		month++;
		day = 1;
	}
	else
	{
		year++;
		month = 1;
		day = 1;
	}
}

void Date::helpDecrement()
{
	if (day != 1)
	{
		day--;
	}
	else if (month > 1)
	{
		month--;

		if (month == 2 && leapYear(year))
		{
			day = 29;
		}
		else
		{
			day = days[month];
		}
	}
	else
	{
		year--;
		month = 12;
		day = 31;
	}
}

ostream &operator<<(ostream &output, Date &d)
{
	string monthName[13] = { "", "Janurary", "Febuary", "March", "April", "May", 
		"June", "July", "August", "September", "October", "November", "December" };

	output << monthName[d.month] << " " << d.day << ", " << d.year;
	return output;
}

Date Date::operator++(int)
{
	Date temp = *this;
	helpIncrement();
	return temp;
}

Date &Date::operator+=(int days)
{
	for (int x = 0; x < days; x++)
	{
		helpIncrement();
	}

	return *this;
}

Date Date::operator--(int)
{
	Date temp = *this;
	helpDecrement();
	return temp;
}

Date &Date::operator-=(int days)
{
	for (int x = 0; x < days; x++)
	{
		helpDecrement();
	}

	return *this;
}

#endif

