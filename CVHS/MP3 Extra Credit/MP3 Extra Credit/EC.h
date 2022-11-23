#pragma once
#include<iostream>
#include<array>
#include<string>
using namespace std;

void bubbleSort(int arr[], int SIZE)
{
	int temp;
	for (int i = 0; i<SIZE; i++)
	{
		for (int v = 1; v<SIZE; v++)
		{
			if (arr[v - 1]< arr[v])
			{
				temp = arr[v - 1];
				arr[v - 1] = arr[v];
				arr[v] = temp;
			}
		}
	}
}

void printArray(int arr[], int SIZE)
{
	for (int x = 0; x < SIZE; x++)
		cout << arr[x] << " ";
	cout << endl;
}

int largestMultiply(int arr[], int SIZE)
{
	int num1 = 0;

	for (int i = 0; i < SIZE - 1; i++)
	{
		num1 += arr[i] * pow(10, SIZE - 2 - i);
	}
	return num1;
}

void stringToArray(string str, int arr[])
{
	for (int x = 0; x < 10; x++)
	{
		arr[x] = 0;
	}

	// get number of digits in string
	int length = str.size();

	for (int x = 10 - length, y = 0; x < 10; x++, y++)
	{
		if (isdigit(str[y]))
		{
			arr[x] = str[y] - '0';
		}
	}
}

int removeZeros(int arr[])
{
	int temp = 0;
	for (int x = 0; x < 9; x++)
	{
		if (arr[x] != 0)
		{
			temp += 1;
		}
		else
		{
			return temp;
		}
	}
}