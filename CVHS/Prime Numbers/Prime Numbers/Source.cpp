// Prime Numbers (only factors are 1 and itself)

#include<iostream>
using namespace std;

int main()
{
	for(int num=100000000; num<= 500000000; num++)
	{

		// Assume the number IS prime
		bool isPrime = true;

		for(int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime == true)
		{
			cout << num << endl;
		}

	}

	return 0;
}