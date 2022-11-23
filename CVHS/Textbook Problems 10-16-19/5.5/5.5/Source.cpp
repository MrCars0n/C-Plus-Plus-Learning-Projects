#include<iostream>
using namespace std;

int main()
{
	int num1, num2, sum = 0;

	cin >> num1;

	for (int i = 1; i <= num1; i++)
	{
		cin >> num2;
		sum += num2;
	}

	cout << "Sum = " << sum << endl;

	return 0;
}