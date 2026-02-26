/* Point.cpp (implementation de la case) */
#include "Point.h"
#include <cmath>   // for std::sqrt

// Default constructor: point at (0, 0)
Point::Point() : x(0.0), y(0.0) {}

// Constructor with coordinates
Point::Point(double xValue, double yValue)
    : x(xValue), y(yValue) {
}

// Getters
double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

// Distance to the origin (0, 0)
double Point::distanceToOrigin() const {
    // sqrt(x^2 + y^2)
    return std::sqrt(x * x + y * y);
}

// Comparison operator: comparing distances to origin
bool Point::operator<(const Point& other) const {
    return distanceToOrigin() < other.distanceToOrigin();
}

// Output operator: printing point as (x, y)
std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
