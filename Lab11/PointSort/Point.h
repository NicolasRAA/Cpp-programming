/* Point.h (declaration de la clase) */
#pragma once

#include <iostream>

// Class that represents a point in a 2D space
class Point {
private:
    double x;   // x-coord
    double y;   // y-coord

public:
    // Default constructor: point at the origin (0, 0)
    Point();

    // Constructor with coordinates
    Point(double xValue, double yValue);

    // Getters
    double getX() const;
    double getY() const;

    // Distance from this point to the origin (0, 0)
    double distanceToOrigin() const;

    // Comparison operator for sorting
    // Points compared by distance to the origin
    bool operator<(const Point& other) const;

    // Output operator for printing a Point with std::cout
    friend std::ostream& operator<<(std::ostream& out, const Point& p);
};
