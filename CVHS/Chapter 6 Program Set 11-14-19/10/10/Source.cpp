// Program 10

#include<iostream>
using namespace std;

bool hasTwinPrime(int);
bool prime(int);

int main()
{
	int num;
	cin >> num;

	if (hasTwinPrime(num))
		cout << num << " has a twin prime" << endl;
	else
		cout << num << " does not have a twin prime" << endl;
	return 0;
}

bool hasTwinPrime(int num)
{
	return prime(num) && (prime(num - 2) ||  prime(num + 2));
}

bool prime(int num)
{
	for (int i = 2; i < num; i++)
		if (num % i == 0)
			return false;

	return true;
}