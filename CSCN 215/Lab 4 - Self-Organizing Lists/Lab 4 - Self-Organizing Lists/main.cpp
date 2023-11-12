#include <iostream>
#include <fstream>
#include "SOLMTF.h"
#include "SOLCount.h"
#include "SOLTranspose.h"
#include <vector>

using namespace std;

// This is the basic input for every test1 on each SOL
const char test1_input[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
// length of the input array
const int test1_input_length = sizeof(test1_input) / sizeof(test1_input[0]);

// These are the characters which we call the find() function for every test1 on each SOL
const char test1_find[] = { 'F', 'D', 'F', 'G', 'E', 'G', 'F', 'A', 'D', 'F', 'G', 'E', 'H', 'I' };
// Length of the find array
const int test1_find_length = sizeof(test1_find) / sizeof(test1_find[0]);


void input_test1_data(SelfOrderedListADT<char>& sol);

void execute_test_1(SelfOrderedListADT<char>& sol, string list_type);
void execute_test_2(SelfOrderedListADT<string>& sol, vector<string>& words, string list_type);

int main() {

    cout << "Carson Kramer -- Lab 4 Programming Assignment CSCN 215 -- Self-Organizing Lists" << endl << endl;
    fstream file;
    // // Do we need fstream::binary?
    file.open("test.txt", fstream::in);

    // Store every word in string vector
    vector<string> words;
    string word;

    while (file >> word) {
        words.push_back(word);
    }

    file.close();

    // Count Heuristic
    // Test 1
    SOLCount<char> solCountChar;
    execute_test_1(solCountChar, "Count");
    cout << endl;

    // Test 2
    SOLCount<string> solCountString;
    execute_test_2(solCountString, words, "Count");

    cout << endl << endl << endl;

    // Move to Front Heuristic
    // Test 1
    SOLMTF<char> solMTFChar;
    execute_test_1(solMTFChar, "Move to Front");
    cout << endl;

    // Test 2
    SOLMTF<string> solMTFString;
    execute_test_2(solMTFString, words, "Move to Front");

    cout << endl << endl << endl;

    // Transpose Heuristic
    // Test 1
    SOLTranspose<char> solTransposeChar;
    execute_test_1(solTransposeChar, "Transpose");
    cout << endl;

    // Test 2
    SOLTranspose<string> solTransposeString;
    execute_test_2(solTransposeString, words, "Transpose");

    return 0;
}

void input_test1_data(SelfOrderedListADT<char>& sol) {
    // input (calling add function)
    for (int i = 0; i < test1_input_length; i++) {
        sol.add(test1_input[i]);
    }

    // calling find function for test1
    for (int i = 0; i < test1_find_length; i++) {
        sol.find(test1_find[i]);
    }
}

void execute_test_1(SelfOrderedListADT<char>& sol, string list_type) {
    input_test1_data(sol);
    cout << list_type << " - Test 1" << endl;
    cout << "Number of compares: " << sol.getCompares() << endl;
    cout << "Final list with frequencies" << endl;
    sol.printlist();
    cout << "List size: " << sol.size() << endl;
}

void execute_test_2(SelfOrderedListADT<string>& sol, vector<string>& words, string list_type) {
    // execute the find function for test2
    for (string word : words) {
        sol.find(word);
    }

    cout << list_type << " - Test 2" << endl;
    cout << "Number of compares: " << sol.getCompares() << endl;
    cout << "Top 10 words with with frequencies" << endl;
    // print the top 10 elements
    sol.printlist(10);
    cout << "List size: " << sol.size() << endl;
}