// Program Problem 1
// 11-13-19

#include<iostream>
using namespace std;

double roundToInteger(double), roundToTenths(double), roundToHundredths(double), roundToThousandths(double);

int main()
{
	double num;
	cin >> num;

	cout << "Int: " << roundToInteger(num) << endl;
	cout << "Tenth: " << roundToTenths(num) << endl;
	cout << "Hundreth: " << roundToHundredths(num) << endl;
	cout << "Thousandth: " << roundToThousandths(num) << endl;

	return 0;
}

double roundToInteger(double num)
{
	return floor(num + 0.5);
}

double roundToTenths(double num)
{
	return floor(num * 10 + 0.5) / 10;
}

double roundToHundredths(double num)
{
	return floor(num * 100 + 0.5) / 100;
}

double roundToThousandths(double num)
{
	return floor(num * 1000 + 0.5) / 1000;
}