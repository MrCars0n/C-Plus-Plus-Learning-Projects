/*
* File:   bagtestmain.cpp
* Author: Prof Sipantzi -- CSIS 215 -- Programming Assignment 1 -- Bag Dictionary
*
* Changes by Prof Sipantzi
*   09/30/2022 -- Updated lines 35-36
*   02/09/2023 -- Added lines 54 and 66 to help identify errors in strData values.
*/

#include <string>
#include <sstream>
#include "ABag.h"
#include "BDictionary.h"

using namespace std;

const size_t DICTIONARY_SIZE = 10;

void wait(); //Used to pause screen output

/*
* Tests BDictionary with int and string objects only.
*/
int main() {

	cout << "Carson Kramer -- CSIS 215 Programming Assignment 1 -- Bag Dictionary" << endl << endl;

	BDictionary<int, string> myIntStrDict(DICTIONARY_SIZE);
	BDictionary<string, int> myStrIntDict(DICTIONARY_SIZE);

	// myIntStrDict tests
	// INSERT: myIntStrDict
	cout << "Testing dictionary with <int, string> KV Pair\n";
	for (int i = 1; i <= DICTIONARY_SIZE; i++) {
		stringstream sn;
		sn << "Beth " << i * 10;
		if (!myIntStrDict.insert(i * 10, sn.str()))
			cout << "insert " << sn.str() << " failed." << endl;

	}
	cout << "INSERT: Size of myIntStrDict is " << myIntStrDict.size() << endl;

	// REMOVEANY: myIntStrDict
	string strData = "ERROR!!!";
	if (myIntStrDict.removeAny(strData) == true) {
		cout << "REMOVEANY: My string data is " << strData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";

	// FIND: test for myIntStrDict.find
	int intKey = 40;
	strData = "ERROR!!!";
	if (myIntStrDict.find(intKey, strData) == true) {
		cout << "FIND: My data at key==" << intKey << " is: " << strData << "\n";
		cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << intKey << "\n";
	}

	// REMOVE: myIntStrDict
	intKey = 60;
	strData = "ERROR!!!";
	if (myIntStrDict.remove(intKey, strData) == true) {
		cout << "REMOVE: Removed key " << intKey << " which was " << strData << "\n";
	}
	else {
		cout << "Could not find key " << intKey << "\n";
	}
	cout << "Size of my dictionary is " << myIntStrDict.size() << "\n";

	// CLEAR: myIntStrDict
	myIntStrDict.clear();
	cout << "CLEAR: Size of myIntStrDict is " << myIntStrDict.size() << "\n\n";

	/* end myIntStrDict tests ---------------------------------------------*/

	// myStrIntDict tests
	// INSERT: myStrIntDict
	cout << "Testing dictionary with <string, int> KV Pair\n";
	myStrIntDict.insert("Terri", 57);
	myStrIntDict.insert("Beth", 53);
	myStrIntDict.insert("Jeremy", 19);
	myStrIntDict.insert("Nathan", 17);
	myStrIntDict.insert("Zipper", 2);
	myStrIntDict.insert("Button", 1);
	myStrIntDict.insert("Kiwi", 7);
	myStrIntDict.insert("Masoala", 10);

	cout << "INSERT: Size of myStrIntDict is " << myStrIntDict.size() << endl;

	// REMOVEANY: myStrIntDict
	int intData;
	if (myStrIntDict.removeAny(intData) == true) {
		cout << "REMOVEANY: My int data is " << intData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myStrIntDict.size() << "\n";

	// FIND: myStrIntDict.find
	string strKey = "Kiwi";
	if (myStrIntDict.find(strKey, intData) == true) {
		cout << "FIND: " << strKey << "\'s age is " << intData << endl;
		cout << "Size of myStrIntDict is " << myStrIntDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << strKey << "\n";
	}

	// REMOVE: myStrIntDict
	strKey = "Button";
	if (myStrIntDict.remove(strKey, intData) == true) {
		cout << "REMOVE: Removed key " << strKey << " which was " << intData << "\n";
	}
	else {
		cout << "Could not find key " << strKey << "\n";
	}
	cout << "Size of my dictionary is " << myStrIntDict.size() << "\n";

	// CLEAR: myStrIntDict
	myStrIntDict.clear();
	cout << "CLEAR: Size of myStrIntDict is " << myStrIntDict.size() << "\n\n";

	/* end myStrIntDict tests ---------------------------------------------*/

	/* Demonstrate any Bag functions that were not used/demonstrated in the implemention
	of your BDictionary and ABag using a Bag of KVpairs<int, string>. */

	// Added size constant for constructor implementation
	ABag<KVpair<int, string>> myBag; //Used to test bag functions not previously demonstrated

	// += operator test
	KVpair<int, string> kvPair1(1, "One");

	// Bag Capacity
	cout << "Capacity of myBag: " << myBag.bagCapacity() << endl;
	
	// Insert (+=) test
	if (myBag += kvPair1)
	{
		cout << "INSERT (+=): KVpair1 added to bag" << endl;
	}
	else
	{
		cout << "INSERT (+=): KVpair1 not added to bag" << endl;
	}

	// Inspect Top - use kvPair1 as temp because it resets
	// If bag is not empty
	if (myBag.inspectTop(kvPair1))
	{
		cout << "INSPECT TOP: Top element is <" << kvPair1.key() << ", " << kvPair1.value() << ">" << endl;
	}
	else // If bag is empty
	{
		cout << "INSPECT TOP: The bag is empty" << endl;
	}

	wait();

	return 0;
}

//Used to pause the screen wherever desired
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(256, '\n'); //Clear the input buffer 
	}
	char ch;
	cout << "Press the Enter key to continue ... ";
	cin.get(ch);
}