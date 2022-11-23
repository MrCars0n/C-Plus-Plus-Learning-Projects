#include<iostream>
using namespace std;

int main()
{
	int num;
	cout << "Enter a number: ";
	cin >> num;

	for (int x = 0; x < num; x++)
	{
		for (int i = 1; i <= x; i++)
		{
			cout << " ";
		}

		for (int i = 1; i <= num; i++)
		{
			cout << "*";
		}

		cout << endl;
	}
	return 0;
}