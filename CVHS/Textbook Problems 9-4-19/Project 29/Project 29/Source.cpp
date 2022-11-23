#include<iostream>
using namespace std;

int main()
{
	cout << "integer\tsquare\tcube" << endl;

	for (int i = 0; i <= 10; i++) 
	{
		cout << i << "\t" << pow(i, 2) << "\t" << pow(i, 3) << endl;
	}

	return 0;
}