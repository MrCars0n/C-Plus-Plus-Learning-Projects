// Fibonacci Sequence (Recursion)
// 11-11-19

#include<iostream>
using namespace std;

// Send in the term number in the sequence
// f(0) = 0, f(1) = 1, f(2) = 1, f(3) = 2, f(4) = 3
int fib(int);

int main()
{
	for (int n = 1; n <= 50; n++)
		cout << n << "\t" << fib(n) << "\t" << (double)fib(n) / fib(n-1) << endl;

	return 0;
}

int fib(int n)
{
	// Base Case
	if (n == 0 || n == 1)
		return n;
	// Recursive Case
	else
		return fib(n - 1) + fib(n-2);
}