#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << setprecision(2) << setiosflags(ios::fixed | ios::showpoint);

	double p5 = 24, p6 = 24, p7 = 24, p8 = 24, p9 = 24, p10 = 24;

	for (int i = 1; i <= 393; i++)
	{
		p5 *= 1.05;
		p6 *= 1.06;
		p7 *= 1.07;
		p8 *= 1.08;
		p9 *= 1.09;
		p10 *= 1.1;
	}

	cout << "5% = $" << p5 << endl;
	cout << "6% = $" << p6 << endl;
	cout << "7% = $" << p7 << endl;
	cout << "8% = $" << p8 << endl;
	cout << "9% = $" << p9 << endl;
	cout << "10% = $" << p10 << endl;
	return 0;
}