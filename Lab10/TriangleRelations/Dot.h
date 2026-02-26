/* Dot.h */
#pragma once

// Class representing a point in 2D space
class Dot {
private:
    double x;
    double y;

public:
    // Default constructor: point at origin (0,0)
    Dot();

    // Constructor with coordinates
    Dot(double xCoord, double yCoord);

    // Calculate distance to another point
    double distanceTo(const Dot& otherPoint) const;
};
