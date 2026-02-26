/* Time.cpp */
#include "Time.h"
#include <iostream>

using std::cout;
using std::endl;

// Default constructor -> everything zero
Time::Time() : hours(0), minutes(0), seconds(0) {}

// Constructor with parameters
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    // protection from negative values
    if (hours < 0) hours = 0;
    if (minutes < 0) minutes = 0;
    if (seconds < 0) seconds = 0;

    // Normalizing to correct format
    normalize();
}

// Private helper that fixes minutes/seconds overflow
void Time::normalize() {
    // Convertign to total seconds, then back to h:m:s
    int totalSeconds = hours * 3600 + minutes * 60 + seconds;

    if (totalSeconds < 0) {
        totalSeconds = 0;
    }

    hours = totalSeconds / 3600;
    int remainder = totalSeconds % 3600;
    minutes = remainder / 60;
    seconds = remainder % 60;
}

// Getters
int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }

// Print time as hh:mm:ss with leading zeros
void Time::print() const
{
    // Small helper to print 2 digits
    auto printTwoDigits = [](int value) {
        if (value < 10) {
            cout << '0';
        }
        cout << value;
        };

    printTwoDigits(hours);
    cout << ':';
    printTwoDigits(minutes);
    cout << ':';
    printTwoDigits(seconds);
}

// Sum of two Time objects
Time Time::add(const Time& other) const
{
    // Using constructor with parameters so it will normalize automatically
    Time result(hours + other.hours,
        minutes + other.minutes,
        seconds + other.seconds);
    return result;
}