#include<iostream>
using namespace std;

int main()
{
	int side1, side2, side3;

	for (int a = 1; a <= 500; a++)
	{
		for (int b = 1; b <= 500; b++)
		{
			for (int c = 1; c <= 500; c++)
			{
				if ((pow(a, 2) + pow(b, 2)) == pow(c, 2))
				{
					cout << a << " ^ 2 \t\t+\t\t" << b << " ^ 2\t\t=\t" << c << " ^ 2" << endl;
				}
			}
		}
	}
	return 0;
}