#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	cout << "Base 10" << "\t" << "Binary" << "\t" << "Octal" << "\t" << "Hexadecimal" << endl;

	for (int i = 1; i <= 256; i++)
	{
		cout << i << "\t" << bitset<8>(i) << "\t" << oct << i << "\t" << hex << i << endl;
	}
	return 0;
}
