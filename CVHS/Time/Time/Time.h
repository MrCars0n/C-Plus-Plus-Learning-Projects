// Time Header File
// 1-21-20

#pragma once
#include<iostream>
using namespace std;

#ifndef TIME_H
#define TIME_H

class Time
{
private:
	int hour;
	int minute;
public:
	Time();
	Time(int, int);

	void setHour(int);
	void setMinute(int);
	void setTime(int, int);
	int getHour();
	int getMinute();

	void printTime();
};

int Time::getHour()
{
	return hour;
}

int Time::getMinute()
{
	return minute;
}

// Default constructor - sets variable values to defaults choosen (in context of what you're doing)
Time::Time()
{
	setTime(0, 0);
}

// Specific constructor - sets vales to what's sent in (still check to see if values ok)
Time::Time(int h, int m)
{
	setTime(h, m);
}

void Time::printTime()
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
		<< (minute < 10 ? "0" : "") << minute
		<< (hour < 12 ? "AM" : "PM") << endl;
}

void Time::setHour(int h)
{
	if (h >= 0 && h < 24)
	{
		hour = h;
	}
	else
	{
		cout << "Invalid hour - setting the hour to 0 (midnight)" << endl;
		hour = 0;
	}
}

void Time::setMinute(int m)
{
	if (m >= 0 && m < 60)
	{
		minute = m;
	}
	else
	{
		cout << "Invalid minute - setting the minute to 0" << endl;
		minute = 0;
	}
}

void Time::setTime(int h, int m)
{
	setHour(h);
	setMinute(m);
}

#endif
