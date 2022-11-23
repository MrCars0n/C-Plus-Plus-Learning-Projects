// Program 7

#include<iostream>
using namespace std;

int GCD(int, int);

int main()
{
	int int1, int2;

	cin >> int1 >> int2;

	cout << "GCD = " << GCD(int1, int2) << endl;

	return 0;
}

int GCD(int int1, int int2)
{
	int GCD = INT_MIN, smallerInt;

	if (int1 < int2)
		smallerInt = int1;
	else
		smallerInt = int2;

	for (int i = 1; i <= smallerInt; i++)
	{
		if ((int1 % i == 0) && (int2 % i == 0))
		{
			GCD = i;
		}
	}

	return GCD;
}