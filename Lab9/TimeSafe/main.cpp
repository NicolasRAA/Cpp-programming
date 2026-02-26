/* main.cpp */
#include <iostream>
#include "Time.h"

using std::cout;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian");

    try {
        // Example values (these are valid)
        Time morningTime(1, 70, 30); // -> 02:10:30
        Time eveningTime(0, 55, 50);
        Time totalTime; // default 00:00:00

        cout << "First time (normalized):\t";
        morningTime.print();
        cout << endl;

        cout << "Second time (normalized):\t";
        eveningTime.print();
        cout << endl;

        cout << "Third time (by default):\t";
        totalTime.print();
        cout << endl;

        // Sum of the two times (still within one day)
        totalTime = morningTime.add(eveningTime);

        cout << "\nSum of two times:\t\t";
        totalTime.print();
        cout << endl;

        // Example of dangerous operation:
        // result will be greater than 24 hours, so exception is expected
        cout << "\nNow trying to create an invalid time (more than 24 hours)...\n";
        Time longTime1(20, 0, 0);
        Time longTime2(10, 0, 0);

        // This call -> Time::TimeError
        Time invalidSum = longTime1.add(longTime2);

        // If for some reason no exception was thrown, still print the result
        cout << "Sum of long times:\t\t";
        invalidSum.print();
        cout << endl;
    }
    catch (const Time::TimeError& error) {
        cout << "\nException in Time class!\n";
        cout << "Where: " << error.origin << endl;
        cout << "Wrong total seconds value: " << error.wrongTotalSeconds << endl;
    }

    return 0;
}
