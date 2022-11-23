/*
	Carson Kramer
	9-20-2019
	Period 5
	Gas Mileage
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << setprecision(6) << setiosflags(ios::fixed | ios::showpoint);

	int miles, gallons, totalMiles = 0, totalGallons = 0;
	double mpg, totalMPG;

	cout << "Enter miles driven (-1 to quit): ";
	cin >> miles;

	while (miles != -1)
	{
		cout << "Enter gallons used: ";
		cin >> gallons;

		mpg = (double)miles / gallons;

		totalMiles += miles;
		totalGallons += gallons;

		totalMPG = (double)totalMiles / totalGallons;

		cout << "MPG this trip: " << mpg << endl;
		cout << "Total MPG: " << totalMPG << endl;

		cout << "Enter miles driven (-1 to quit): ";
		cin >> miles;
	}

	return 0;
}