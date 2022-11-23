#include<iostream>
using namespace std;

int main()
{

	for (int i = 12; i >= 1; i--) 
	{
		switch (i)
		{
		case 12:
			cout << "On the first day of Christmas my true love sent to me" << endl;
			break;
		case 11:
			cout << "On the second day of Christmas my true love sent to me" << endl;
			break;
		case 10:
			cout << "On the third day of Christmas my true love sent to me" << endl;
			break;
		case 9:
			cout << "On the fourth day of Christmas my true love sent to me" << endl;
			break;
		case 8:
			cout << "On the fifth day of Christmas my true love sent to me" << endl;
			break;
		case 7:
			cout << "On the sixth day of Christmas my true love sent to me" << endl;
			break;
		case 6:
			cout << "On the seventh day of Christmas my true love sent to me" << endl;
			break;
		case 5:
			cout << "On the eight day of Christmas my true love sent to me" << endl;
			break;
		case 4:
			cout << "On the ninth day of Christmas my true love sent to me" << endl;
			break;
		case 3:
			cout << "On the 10th day of Christmas my true love sent to me" << endl;
			break;
		case 2:
			cout << "On the 11th day of Christmas my true love sent to me" << endl;
			break;
		case 1:
			cout << "On the 12th day of Christmas my true love sent to me" << endl;
			break;
		}

		switch (i)
		{
		case 1:
			cout << "12 drummers drumming" << endl;
		case 2:
			cout << "11 pipers piping" << endl;
		case 3:
			cout << "10 lords a - leaping" << endl;
		case 4:
			cout << "Nine ladies dancing" << endl;
		case 5:
			cout << "Eight maids a - milking" << endl;
		case 6:
			cout << "Seven swans a - swimming" << endl;
		case 7:
			cout << "Six geese a - laying" << endl;
		case 8:
			cout << "Five golden rings" << endl;
		case 9:
			cout << "Four calling birds" << endl;
		case 10:
			cout << "Three french hens" << endl;
		case 11:
			cout << "Two turtle doves" << endl;
		case 12:
			if (i == 12)
				cout << "A partridge in a pear tree" << endl;
			else
				cout << "and A partridge in a pear tree" << endl;
		}

		cout << endl;
	}
	
	return 0;
}