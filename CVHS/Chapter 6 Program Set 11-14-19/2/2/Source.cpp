#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int functionA(), functionB(), functionC();

int main()
{
	srand(time(0));

	cout << "A: " << functionA() << endl;
	cout << "B: " << functionB() << endl;
	cout << "C: " << functionC() << endl;

	return 0;
}

int functionA() 
{
	//return 2 * (rand() % 5 + 1);

	int numbers[5] = { 2, 4, 6, 8, 10 };
	return numbers[rand() % 5];
}

int functionB()
{
	//return a() + 1;
	int numbers[5] = { 3, 5, 7, 9, 11 };
	return numbers[rand() % 5];
}

int functionC() 
{
	//return 2 * b();
	int numbers[5] = { 6, 10, 14, 18, 22 };
	return numbers[rand() % 5];
}