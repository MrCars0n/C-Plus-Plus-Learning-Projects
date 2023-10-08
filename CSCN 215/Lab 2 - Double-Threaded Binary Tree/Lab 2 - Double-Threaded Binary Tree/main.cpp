#include <iostream>
#include "BST.h"

using namespace std;

void wait(); //Used to pause screen output

int main() {
    cout << "Carson Kramer -- CSCN 215 Programming Assignment 2 -- Double-Threaded Binary Tree" << endl << endl;

    BST <int, string> myTree;
    myTree.insert(77, "seventy-seven");
    myTree.insert(70, "seventy");
    myTree.insert(75, "seventy-five");
    myTree.insert(66, "sixty-six");
    myTree.insert(79, "seventy-nine");
    myTree.insert(68, "sixty-eight");
    myTree.insert(67, "sixty-seven");
    myTree.insert(69, "sixty-nine");
    myTree.insert(90, "ninety");
    myTree.insert(85, "eighty-five");
    myTree.insert(83, "eighty-three");
    myTree.insert(87, "eighty-seven");
    myTree.insert(65, "sixty-five");

    myTree.print();
    wait();

    cout << endl << endl;
    cout << "Printing Inorder" << endl;
    myTree.printInorder();

    cout << endl << endl;
    cout << "Printing Reverse" << endl;
    myTree.printReverse();

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