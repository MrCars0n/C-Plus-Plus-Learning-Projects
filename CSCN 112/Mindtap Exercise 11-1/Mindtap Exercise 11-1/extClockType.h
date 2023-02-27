#pragma once
#ifndef H_extClockType
#define H_extClockType
#include "clockType.h"
#include <iostream>
#include <string>
using namespace std;

class extClockType : public clockType
{
public:
	void setTimeZone(string);
	string getTimeZone() const;
	void printTime() const;
	void setTime(int, int, int, string);

	extClockType(int, int, int, string);
	extClockType();
private:
	string timeZone;
};
#endif