#include<iostream>
using namespace std;

int main()
{
	int num1, num2, sum = 0, smallest = INT_MAX;

	cin >> num1;

	for (int i = 1; i <= num1; i++)
	{
		cin >> num2;

		if (num2 < smallest)
			smallest = num2;
	}

	cout << "Smallest = " << smallest << endl;


	return 0;
}