// Printed Date Function

#include<iostream>
#include<string>
using namespace std;

void printDate(int, int, int);

int main()
{
	int month, day, year;

	cout << "Month: ";
	cin >> month;

	cout << "Day: ";
	cin >> day;

	cout << "Year: ";
	cin >> year;

	printDate(month, day, year);

	for (int i = 1; i <= 30; i++)
		printDate(11, i, 2019);

	return 0;
}

void printDate(int month, int day, int year)
{
	int ending = 4;
	string monthList[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	string dayEnding[4] = { "st", "nd", "rd", "th" };

	for (int i = 1; i <= 4; i++)
		if (day % 10 == i && day % 100 != (i + 10)) //if number ends in 1, 2, or 3 and its not 11, 12, or 13
			ending = i;

	cout << endl << monthList[month - 1] << " " << day << dayEnding[ending - 1] << ", " << year << endl;
}