// Program 12
#include<iostream>
using namespace std;

int numBlocks(int);

int main()
{
	int num;

	cin >> num;
	cout << "Number of Blocks = " << numBlocks(num) << endl;

	return 0;
}

int numBlocks(int blocks)
{
	if (blocks == 1)
	{
		return 1;
	}
	else
	{
		return blocks + numBlocks(blocks - 1);
	}
}