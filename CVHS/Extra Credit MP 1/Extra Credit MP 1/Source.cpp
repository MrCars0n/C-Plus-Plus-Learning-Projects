/*
Carson Kramer
Period 6
10/3/19
Extra Credit MP 1
*/

#include<iostream>
using namespace std;

int main()
{
	int digNumber, digNumberCopy, maxDig = 1, count = 1;

	cout << "Enter number of terms: ";
	cin >> digNumber;

	digNumberCopy = digNumber;

	while (maxDig < digNumberCopy)
	{
		digNumberCopy -= maxDig;
		maxDig++;
		//cout << digNumberCopy << endl;
	}


	for (int a = 1; a < maxDig; a++)
	{
		for (int i = 1; i <= a; i++)
		{
			cout << i << " ";
		}
		cout << endl;

	}

	for (int i = 1; i <= digNumberCopy; i++)
	{
		cout << i << " ";
	}

	cout << endl << endl;

	for (int a = 1; a <= maxDig; a++)
	{
		for (int i = 1; i <= a; i++)
		{
			cout << i << " ";
			digNumber--;
		}
	}


	for (int i = 1; i <= digNumberCopy; i++)
	{
		cout << i << " ";
	}



	cout << endl;

	return 0;
}