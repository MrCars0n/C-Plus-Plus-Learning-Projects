#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << setprecision(2) << setiosflags(ios::fixed | ios::showpoint);

	double balance = 1000;

	for (int i = 1; i <= 30; i++)
	{
		balance *= 1.03;
	}

	cout << "After 30 years, you will have $" << balance << endl;

	return 0;
}