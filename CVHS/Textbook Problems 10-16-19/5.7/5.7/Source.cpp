#include <iostream>
 using namespace std;

 int main()
 {
	 int x; // declare x
 int y; // declare y
	
		 // prompt user for input
		 cout << "Enter two integers in the range 1-20: ";
	 cin >> x >> y; // read values for x and y
	
		 for (int i = 1; i <= y; ++i) // count from 1 to y
		 {
		 for (int j = 1; j <= x; ++j) // count from 1 to x
			 cout << '@'; // output @
		
			 cout << endl; // begin new line
		 } // end outer for
	 }