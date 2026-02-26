/* main.cpp */
#include <iostream>
#include "Time.h"

using std::cout;
using std::endl;

int main()
{
    // Example values
    Time morningTime(1, 70, 30); // -> 2:10:30
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

    // Sum of the two times
    totalTime = morningTime.add(eveningTime);

    cout << "\nSum of two times:\t\t";
    totalTime.print();
    cout << endl;

    return 0;
}
