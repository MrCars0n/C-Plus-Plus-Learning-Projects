// Vectors in C++
// 2-27-20

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	// Arrays, and some of their problems

	// An array of characters is a string
	char word[] = "Computer";
	cout << word << endl;

	// what is the size (number of bytes) of a char in C++?
	cout << sizeof(char) << endl;
	cout << sizeof(word) << endl;

	/* Arrays don't know their own size, so we can acces protected memory past the end of the array (which is bad)
	for (int x = 0; x < 90000; x++)
	{
		cout << word[x];// << "\t";
	}
	cout << endl; */

	vector<int> numList(5);

	for (int x = 0; x < numList.size(); x++)
	{
		cin >> numList[x];
	}

	for (int x = 0; x < numList.size(); x++)
	{
		cout << numList[x] << "\t";
	}

	// You may not assign arrays to each other using =
	//char newWord[] = word;

	vector<int> newList;
	newList = numList;

	for (int x = 0; x < numList.size(); x++)
	{
		cout << newList[x] << "\t";
	}

	/*char newWord[] = "Computer";
	if (word == newWord)
	{
		cout << "Word is equal to newWord" << endl;
	}*/

	if (numList == newList)
	{
		cout << "numList is equal to newList" << endl;
	}

	numList.insert(numList.begin() + 2, 10);
	
	for (int x = 0; x < numList.size(); x++)
	{
		cout << numList[x] << "\t";
	}

	cout << numList.max_size() << endl;

	return 0;
}