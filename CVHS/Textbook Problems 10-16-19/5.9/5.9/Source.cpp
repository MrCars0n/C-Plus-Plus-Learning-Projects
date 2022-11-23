#include<iostream>
using namespace std;

int main()
{
	int sum = 1;
	for (int i = 1; i <= 15; i++)
	{
		if (not (i % 2 == 0))
			sum *= i;
	}

	cout << "Product of odd numbers = " << sum << endl;

	return 0;
}