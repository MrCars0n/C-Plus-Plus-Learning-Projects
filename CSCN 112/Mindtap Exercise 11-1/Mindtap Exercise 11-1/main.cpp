#include <iostream>
#include "extClockType.h"

using namespace std;

int main() {
    extClockType ext1(23, 59, 00, "UTC");
    extClockType ext2(11, 22, 33, "EST");
    extClockType ext3;
    ext3.setTimeZone("IST");

    cout << "Times at initially..." << endl;
    cout << "Time #1: ";
    ext1.printTime();
    cout << "Time #2: ";
    ext2.printTime();
    cout << "Time #3: ";
    ext3.printTime();

    ext1.incrementMinutes();
    ext2.incrementMinutes();
    ext3.incrementMinutes();
    ext3.setTime(5, 10, 34, "CST");
    ext3.incrementHours();

    cout << "\nTimes after 1 minute..." << endl;
    cout << "Time #1: ";
    ext1.printTime();
    cout << "Time #2: ";
    ext2.printTime();
    cout << "Time #3: ";
    ext3.printTime();

    return 0;
}
