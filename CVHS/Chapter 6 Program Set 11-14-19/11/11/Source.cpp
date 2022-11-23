// Program 11

#include<iostream>
using namespace std;

int count5(int);

int main()
{
	int num;
	cin >> num;
	cout << "Number of Fives = " << count5(num) << endl;
	return 0;
}

int count5(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n % 10 == 5)
	{
		return 1 + count5(n / 10);
	}

	return count5(n / 10);
}