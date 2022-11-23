#include<iostream>
using namespace std;

int main()
{
	double pi = 4;

	double count = 3;
	bool add = false;

	while (true)
	{
		if (not((int)count %2 == 0))
		{
			if (add == true)
			{
				pi += (4 / count);
				add = false;
			}
			else
			{
				pi -= (4 / count);
				add = true;
			}
		}
		if ((int)count % 1000 == 0)
		{
			cout << pi << endl;
		}
		count++;
	}
	return 0;
}