// Extra Credit Program (MP 2)
// 11-19-19
// Carson Kramer

#include<iostream>
using namespace std;

int main()
{
	int e, m, count = 0;

	cin >> e >> m;

	while (e != 0 || m != 0)
	{
		count += 1;
		e = (e + 1) % 365;
		m = (m + 1) % 687;
	}

	cout << "The shortest number of days is " << count << endl;

	return 0;
}