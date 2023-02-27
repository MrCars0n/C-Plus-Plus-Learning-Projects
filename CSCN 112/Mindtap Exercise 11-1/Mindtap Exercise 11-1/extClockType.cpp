#include "extClockType.h"

void extClockType::setTimeZone(string tz)
{
	timeZone = tz;
}

string extClockType::getTimeZone() const
{
	return timeZone;
}

void extClockType::printTime() const
{
	clockType::printTime();

	cout << " " << timeZone << endl;
}

void extClockType::setTime(int hours, int minutes, int seconds, string tz)
{
	timeZone = tz;
	clockType::setTime(hours, minutes, seconds);
}

extClockType::extClockType(int hours, int minutes, int seconds, 
	string timeZone) : clockType(hours, minutes, seconds)
{
	timeZone = timeZone;
}

extClockType::extClockType() : clockType()
{
	timeZone = "";
}
