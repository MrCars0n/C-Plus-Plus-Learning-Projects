// Program Set 6

#include<iostream>
using namespace std;

bool isPerfect(int);

int main()
{
	for (int i = 1; i <= 10000; i++)
		if (isPerfect(i))
			cout << i << endl;

	return 0;
}

bool isPerfect(int num)
{
	int numTotal = 0;

	for (int i = 1; i < num; i++)
		if (num % i == 0)
			numTotal += i;

	return numTotal == num;
}