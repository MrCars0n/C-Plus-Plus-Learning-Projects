#include<iostream>
using namespace std;

double celcius(double), fahrenheit(double);

int main()
{
	cout << "F\tC\tC->F" << endl;
	for (int i = 32; i <= 212; i++)
	{
		cout << i << "\t" << celcius(i) << "\t\t" << fahrenheit(celcius(i)) << endl;
	}

	return 0;
}

double celcius(double fahrenheit)
{
	return (fahrenheit - 32) * 5.0 / 9;
}

double fahrenheit(double celcius)
{
	return (celcius * (9.0 / 5)) + 32;
}