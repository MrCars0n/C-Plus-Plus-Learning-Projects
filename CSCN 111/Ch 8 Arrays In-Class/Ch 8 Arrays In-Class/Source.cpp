#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


int AvgAge(int ages[], int n);
int TwoDimensions(const int a[][10], int r, int c); // Dont need to enter number for first dimension

int main()
{
	float temps[5];
	int m;

	cout << "Lab 1" << endl;
	for (m = 0; m < 5; m++)
		temps[m] = 100.0 + m * 0.2;

	for (m = 4; m >= 0; m--)
		cout << "temps[" << m << "] is " << temps[m] << endl;
	cout << endl;

	// Lab 2
	cout << endl << "Lab 2" << endl;
	const int SIZE = 5;
	int ages[SIZE] = { 40, 13, 20, 19, 36 };
	for (int i = 0; i < SIZE; i++)
	{
		cout << ages[i] << ' ';
	}
	cout << endl << endl;

	// Lab 3
	cout << endl << "Lab 3" << endl;
	cout << "The average age is " << AvgAge(ages, 5) << endl << endl;

	// Lab 4 - array for loops
	cout << endl << "Lab 4" << endl;
	double list[25] = { 0 };

	double sum = 0;
	int i = 0;
	for (auto& num : list)
		num += i++; // This is the same as list[i] = list[i] + i

	for (auto num : list)
		cout << num << ' ';
	cout << endl;

	// Lab 5 - character arrays (C strings)
	cout << endl << "Lab 5" << endl;
	char name[] = "Frank";
	cout << name << endl;
	cout << "The first letter is " << name[0] << endl;
	char yourName[15];
	strcpy_s(yourName, name); // strcpy_s is newer, more secure version of strcpy
	cout << "name = " << name << " and consists of " << strlen(name) << " characters." << endl;
	cout << "yourName = " << yourName << " and consists of " << strlen(yourName) << " characters." << endl;
	cout << "The size of the name array is " << sizeof(name) << endl;
	cout << "The size of the yourName array is " << sizeof(yourName) << endl;


}

int AvgAge(int ages[], int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += ages[i];
	}
	return static_cast<float>(total / 5 + 0.5);
}