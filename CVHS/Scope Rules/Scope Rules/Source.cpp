// Scope Rules
// 11-7-19

#include<iostream>
using namespace std;

void useLocal(), useStatic(), useGlobal();

// Global Variable
int x = 1;

int main()
{
	const double PI = 3.14159;
	//PI = 3;

	cout << "X at the top of main = " << x << endl; // 1

	int x = 5;
	cout << "X inside main = " << x << endl; // 5

	{
		cout << "X at the top of inner block = " << x << endl; // 5
		int x = 10;
		cout << "X at the bottom of inner block = " << x << endl; // 10
	}

	cout << "X after the block = " << x << endl; // 5

	useLocal();
	useLocal();

	useStatic();
	useStatic();

	useGlobal();
	useGlobal();

	return 0;
}

void useLocal()
{
	int x = 20;
	cout << "useLocal = " << x << endl; // 20
	x++; // Resets each time function is called
}

void useStatic()
{
	static int x = 50;
	cout << "useStatic = " << x << endl; // 50 1st run, 51 2nd run
	x++; // x only shown when function called
}

void useGlobal()
{
	cout << "useGlobal = " << x << endl; // 1, 2
	x++; // x called when used anywhere in program
}
