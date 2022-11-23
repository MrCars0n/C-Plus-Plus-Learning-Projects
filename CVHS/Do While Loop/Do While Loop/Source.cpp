/*
	Carson Kramer
	9-19-2019
	Period 5
	Penny doubled vs $1 million
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << setprecision(2) << endl;
	cout << setiosflags(ios::fixed | ios::showpoint);
	double money = .01;
	int days = 0;

	do
	{
		days++;
		money *= 2;
		cout << days << "\t$" << money << endl;
	} while (money <= 1000000);

	return 0;
}