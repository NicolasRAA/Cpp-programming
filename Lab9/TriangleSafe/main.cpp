/* main.cpp */
#include <iostream>
#include "Triangle.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Safe Triangle (with exceptions)\n";

    // E.q. 1: creating triangle from user input
    double inputA, inputB, inputC;

    cout << "\nEnter three sides for the triangle:\n";
    cout << "Side a: ";
    cin >> inputA;
    cout << "Side b: ";
    cin >> inputB;
    cout << "Side c: ";
    cin >> inputC;

    try {
        // Mozhet throw TriangleError if sides are not valid
        Triangle userTriangle(inputA, inputB, inputC);

        cout << "\nTriangle created successfully!\n";
        userTriangle.printInfo();
    }
    catch (const TriangleError& error) {
        cout << "\nError while creating triangle: ";
        error.printMessage();
    }

    // E.q. 2: show default 3-4-5 triangle (no exceptions)
    cout << "\n=================================================";
    cout << "\nNow showing default 3-4-5 triangle:\n";
    Triangle defaultTriangle;  // using default constructor
    defaultTriangle.printInfo();

    // E.q. 3: invalid triangle -> exception
    cout << "\n=================================================";
    cout << "\nCreating an invalid triangle (1, 2, 10) to test error handling...\n";
    try {
        Triangle badTriangle(1.0, 2.0, 10.0);  // must fail
        badTriangle.printInfo();               // this line should not be reached
    }
    catch (const TriangleError& error) {
        cout << "Caught exception for invalid triangle: ";
        error.printMessage();
    }

    return 0;
}
