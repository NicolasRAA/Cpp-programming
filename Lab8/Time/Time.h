/* Time.h */
#pragma once

// Class for representing time as hours:minutes:seconds
class Time {
private:
    int hours;
    int minutes;
    int seconds;

    // Helper: fix values | napr 1:70:90 into a correct form ( -> 02:11:30)
    void normalize();

public:
    // Default constructor - 00:00:00
    Time();

    // Constructor with parameters
    Time(int h, int m, int s);

    // Getters
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    // Print time as hh:mm:ss
    void print() const;

    // Return sum of this time and another time
    Time add(const Time& other) const;
};
