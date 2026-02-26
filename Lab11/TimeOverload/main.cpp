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

        // Old style using add() from lab9
        totalTime = morningTime.add(eveningTime);
        cout << "\nSum of two times (using add()):\t";
        totalTime.print();
        cout << endl;


        // New operator+ for Time + Time
        Time sumWithOperator = morningTime + eveningTime;
        cout << "Sum of two times (using +):\t";
        sumWithOperator.print();
        cout << endl;

        // New operator- for Time - Time
        Time difference = morningTime - eveningTime;
        cout << "\nDifference (morning - evening):\t";
        difference.print();
        cout << endl;

        // New Time + double (in sec) 
        Time morningPlus30 = morningTime + 30.0; // +30 seconds
        cout << "\nMorning + 30 seconds:\t\t";
        morningPlus30.print();
        cout << endl;

        // New double + Time
        Time fortyFivePlusEvening = 45.0 + eveningTime; // 45 seconds before eveningTime
        cout << "45 seconds + evening time:\t";
        fortyFivePlusEvening.print();
        cout << endl;

        // New comparison operators
        cout << "\nComparing times:\n";
        if (morningTime == eveningTime) {
            cout << "Morning and evening times are equal.\n";
        }
        else if (morningTime < eveningTime) {
            cout << "Morning time is earlier than evening time.\n";
        }
        else {
            cout << "Morning time is later than evening time.\n";
        }


        // Example of dangerous operation:
        // result greater than 24 hours -> exception
        cout << "\nNow trying to create an invalid time (more than 24 hours)...\n";
        Time longTime1(20, 0, 0);
        Time longTime2(10, 0, 0);

        // This call throws Time::TimeError
        Time invalidSum = longTime1 + longTime2;

        // If exception was thrown, still print the result
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
