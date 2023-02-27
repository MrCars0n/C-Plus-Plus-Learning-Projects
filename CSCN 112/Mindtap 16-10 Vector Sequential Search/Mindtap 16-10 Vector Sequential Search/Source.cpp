#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool inVector(vector<string> v, string i)
{
    for (int x = 0; x < v.size(); x++)
    {
        if (v[x] == i)
        {
            //cout << "\t" << v[x] << "|\t" << i;
            return true;
        }
    }
    return false;
}

int main() {
    vector<string> vector1;

    string input = "";

    while (input != "zzz")
    {
        cin >> input;
        vector1.push_back(input);
    }

    cin >> input;

    if (inVector(vector1, input))
    {
        cout << input << " is found in the list" << endl;
    }
    else
    {
        cout << input << " is not in the list" << endl;
    }
    return 0;
}
