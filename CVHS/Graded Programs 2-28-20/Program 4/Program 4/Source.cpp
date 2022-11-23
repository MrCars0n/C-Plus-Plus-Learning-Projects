#include<iostream>
using namespace std;

int main()
{
	bool lockers[1000];

	// Opens all lockers
	for (int x = 0; x < 1000; x++)
	{
		lockers[x] = true;
	}

	// Inverts state of lockers multiples of 3
	for (int y = 2; y <= 1000; y++)
	{
		for (int x = 0; x < 1000; x++)
		{
			if (x % y == 0)
			{
				if (lockers[x] == true)
				{
					lockers[x] = false;
				}
				else
				{
					lockers[x] = true;
				}
			}
		}
	}

	for (int x = 0; x < 1000; x++)
	{
		if (lockers[x] == true)
		{
			cout << x << endl;
		}
	}

	return 0;
}