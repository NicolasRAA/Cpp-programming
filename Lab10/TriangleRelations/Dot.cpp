/* Dot.cpp */
#include "Dot.h"
#include <cmath>

// Default constructor
Dot::Dot() : x(0.0), y(0.0) {}

// Constructor with coordinates
Dot::Dot(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

// Euclidean distance between two points
double Dot::distanceTo(const Dot& otherPoint) const {
    double deltaX = otherPoint.x - x;
    double deltaY = otherPoint.y - y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}
