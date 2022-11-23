#include<iostream>
using namespace std;

int time(int, int, int);

int main()
{
	int hr1, min1, sec1, hr2, min2, sec2;

	cout << "Hour 1: ";
	cin >> hr1;

	cout << "Minute 1: ";
	cin >> min1;

	cout << "Seconds 1: ";
	cin >> sec1;

	cout << endl << "Hour 2: ";
	cin >> hr2;

	cout << "Minute 2: ";
	cin >> min2;

	cout << "Seconds 2: ";
	cin >> sec2;

	cout << endl << "There are " << abs(time(hr1, min1, sec1) - time(hr2, min2, sec2)) << " seconds between these times." << endl;

	return 0;
}

int time(int hours, int minutes, int seconds)
{
	return (hours * 3600) + (minutes * 60) + seconds;
}