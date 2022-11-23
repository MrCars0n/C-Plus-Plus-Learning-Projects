/*	Factorial with Recursion
	11-8-19

	What is Recursion?
		Recursion is when a function calls itself either directly or indirectly.
		in a recurvise problem, we need to find the "base case" - simplest example of a problem.

	In factorial, 1! = 1;	<-- base case of factorial
	"Recursive Cases" are all of the subsequent steps
		In other words, 2! = 2 * base case
		3! = 3 * 2!, 4! = 4 * 3!
*/

#include<iostream>
using namespace std;

unsigned long long factorial(unsigned long long);

int main()
{
	for (int i = 1; i <= 100; i++)
	{
		cout << i << "! =\t" << factorial(i) << endl;
	}

	return 0;
}

unsigned long long factorial(unsigned long long n)
{
	// base case - returns the final value (1! = 1)
	// recursive case - calls the function again
	if (n == 1)
	{
		return 1;
	}
	//recursive case - calls the function again
	else
	{
		return n * factorial(n - 1);
	}
}