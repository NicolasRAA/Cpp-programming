/* Time.cpp */
#include "Time.h"
#include <iostream>

using std::cout;
using std::endl;

// Default constructor -> everything zero
Time::Time() : hours(0), minutes(0), seconds(0) {}

// Constructor with parameters
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    /* Protection from negative values : nwo for this safe version
    negative components are treated as an error
    */
    if (hours < 0 || minutes < 0 || seconds < 0) {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        throw TimeError("Time::Time(int,int,int) - negative component", totalSeconds);
    }

    // Normalizing to correct format and checking range
    normalize();
}

/* Private helper that fixes minutes / seconds overflow
Also checks that total time is within one day (0..23:59:59) */
void Time::normalize() {
    // Converting to total seconds, then back to h:m:s
    int totalSeconds = hours * 3600 + minutes * 60 + seconds;

    const int secondsPerDay = 24 * 3600;

    // If time outside of one day -> invalid
    if (totalSeconds < 0 || totalSeconds >= secondsPerDay) {
        throw TimeError("Time::normalize() - value out of range", totalSeconds);
    }

    hours = totalSeconds / 3600;
    int remainder = totalSeconds % 3600;
    minutes = remainder / 60;
    seconds = remainder % 60;
}

// New helper tp convert current time to total seconds from start of day
int Time::toTotalSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
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
    // Using constructor with parameters so it will normalize
    // automatically and will throw TimeError if result invalid
    Time result(hours + other.hours,
        minutes + other.minutes,
        seconds + other.seconds);
    return result;
}


/* Operator overloads */

// Time + Time
Time Time::operator+(const Time& other) const
{
    // Using constructor with parameters so it will normalize
    // automatically and throw TimeError if result invalid
    return Time(hours + other.hours,
        minutes + other.minutes,
        seconds + other.seconds);
}

// Time - Time
Time Time::operator-(const Time& other) const
{
    int totalThis = toTotalSeconds();
    int totalOther = other.toTotalSeconds();
    int diffSeconds = totalThis - totalOther;

    // Negative time interval not allowed
    if (diffSeconds < 0) {
        throw TimeError("Time::operator- (result is negative)", diffSeconds);
    }

    int resultHours = diffSeconds / 3600;
    int remainder = diffSeconds % 3600;
    int resultMinutes = remainder / 60;
    int resultSeconds = remainder % 60;

    // Constructor checks that result is inside one day
    return Time(resultHours, resultMinutes, resultSeconds);
}

// Time + double (seconds)
Time Time::operator+(double extraSeconds) const
{
    // Real value as number of seconds
    if (extraSeconds < 0.0) {
        int totalSeconds = toTotalSeconds() + static_cast<int>(extraSeconds);
        throw TimeError("Time::operator+(double) - negative seconds not allowed",
            totalSeconds);
    }

    int secondsToAdd = static_cast<int>(extraSeconds); // ignoring fractional part

    // Reusing constructor + normalize and safety checks
    return Time(hours, minutes, seconds + secondsToAdd);
}

// double + Time (friend free function)
Time operator+(double extraSeconds, const Time& timeObject)
{
    // Reusing Time + double implementation
    return timeObject + extraSeconds;
}

// Equality comparison
bool Time::operator==(const Time& other) const
{
    return hours == other.hours &&
        minutes == other.minutes &&
        seconds == other.seconds;
}

// Less-than comparison (by total seconds)
bool Time::operator<(const Time& other) const
{
    return toTotalSeconds() < other.toTotalSeconds();
}