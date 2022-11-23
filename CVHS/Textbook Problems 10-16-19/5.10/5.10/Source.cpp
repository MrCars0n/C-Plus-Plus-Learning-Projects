#include<iostream>
using namespace std;

int main()
{
	int factorial = 1;
	for (int i = 1; i <= 5; i++)
	{
		factorial *= i;
		cout << factorial << endl;
	}
	return 0;
}