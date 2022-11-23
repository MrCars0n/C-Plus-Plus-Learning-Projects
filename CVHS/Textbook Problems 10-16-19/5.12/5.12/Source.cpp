#include<iostream>
using namespace std;

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int x = 1; x <= i; x++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 10; i >= 1; i--)
	{
		for (int x = 1; x <= i; x++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 10; i >= 1; i--)
	{
		for (int x = 1; x <= 10-i; x++)
		{
			cout << " ";
		}

		for (int x = 1; x <= i; x++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 1; i <= 10; i++)
	{
		for (int x = 1; x <= 10 - i; x++)
		{
			cout << " ";
		}

		for (int x = 1; x <= i; x++)
		{
			cout << "*";
		}
		cout << endl;
	}


	return 0;
}