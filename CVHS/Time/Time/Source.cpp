// Time Test
// 1-21-20

#include<iostream>
#include"Time.h"
using namespace std;

int main()
{
	/* 
	We can no longer set the members (variables) of a class like this:
		period5end.hour = 11;
		period5end.minute = 56;

	In struct, everything is public. In class, data (variables) = private. Means to access it (functions) = public
	Again, VARIABLES = PRIVATE, FUNCTIONS = PUBLIC
	*/

	Time period5end;

	period5end.setTime(11, 56);
	period5end.printTime();

	Time period6start;
	period6start.setTime(12, 1);
	period6start.printTime();

	Time now(11, 38);		// Declaration (give object name & title)
	now.printTime();

	/*
	int x;		Also declaration
	x = 10;			Initialize (set value)

	int num = 5;	Both declaration & initialization
	*/

	return 0;
}