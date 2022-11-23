// MP3 Extra Credit
#include<iostream>
#include"EC.h"
using namespace std;

int main()
{
	string str;
	cin >> str;
	int arr[10];
	stringToArray(str, arr);
	int size = sizeof(arr) / sizeof(arr[0]);
	//cout << sizeof(input) / sizeof(input[0]);
	printArray(arr, size);
	cout << removeZeros(arr) << endl;
	bubbleSort(arr, size);
	printArray(arr, size);
	cout << largestMultiply(arr, size) << endl;
	cout << arr[size - 1] << endl;

	cout << largestMultiply(arr, size) + arr[size - 1] << endl;
	return 0;
}