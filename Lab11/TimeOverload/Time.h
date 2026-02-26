/* Time.h */
#pragma once

#include <string>

// Class for representing time as hours:minutes:seconds
class Time {

public:

    // Exception class for invalid time values or operations
    class TimeError {
    public:
        std::string origin; // where the error at
        int wrongTotalSeconds; // invalid total number of seconds

        TimeError(const std::string& org, int seconds)
            : origin(org), wrongTotalSeconds(seconds) {
        }
    };

private:
    int hours;
    int minutes;
    int seconds;

    // Helper: fix values | napr 1:70:90 into a correct form ( -> 02:11:30)
    // Now also checks for invalid ranges and may throw TimeError
    void normalize();

    // Helper: covert current time to total seconds from start of day
    int toTotalSeconds() const;

public:
    // Default constructor - 00:00:00
    Time();

    /* Constructor with parameters
    May throw TimeError if parameters are negative
    or result is outside allowed range (0 .. 23:59:59)
    */
    Time(int h, int m, int s);

    // Getters
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    // Print time as hh:mm:ss
    void print() const;

    /*Return sum of this time and another time
    Old helper from lab9
    Now using operator+ 
    */
    Time add(const Time& other) const;
    // If result outside allowed range -> TimeError


    /*Overloaded functions*/

    // Adding two Time objects: t1 + t2)
    Time operator+(const Time& other) const;

    // Subtracting two Time objects: result = this - other
    // Throws TimeError if result negative
    Time operator-(const Time& other) const;

    // Adding a number of seconds to this time (Time + double)
    // extraSeconds is interpreted as seconds; negative values arn't allowed
    Time operator+(double extraSeconds) const;

    // Adding seconds and Time object (double + Time)
    // Implemented as a friend free function
    friend Time operator+(double extraSeconds, const Time& timeObject);

    // Comparing two Time objects (by total seconds from start of day)
    bool operator==(const Time& other) const;
    bool operator<(const Time& other) const;
};
