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

    // Return sum of this time and another time
    Time add(const Time& other) const;
    // If result outside allowed range -> TimeError
};
