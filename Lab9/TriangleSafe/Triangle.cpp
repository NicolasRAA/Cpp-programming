/* Triangle.cpp */
#include "Triangle.h"
#include <cmath>

// Default constructor: 3-4-5 triangle
Triangle::Triangle() : sideA(3.0), sideB(4.0), sideC(5.0) {
    // 3-4-5 is a valid right triangle, no checks needed here
}

// Constructor with validation
Triangle::Triangle(double a, double b, double c) {
    // Checking for positive sides
    if (a <= 0.0 || b <= 0.0 || c <= 0.0) {
        throw TriangleError("Triangle sides must be positive.");
    }

    // Checking triangle inequality
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw TriangleError("Triangle inequality is violated. "
            "Each side must be less than sum of the other two.");
    }

    // If vsyo jorosho, store sides
    sideA = a;
    sideB = b;
    sideC = c;
}

// Getters
double Triangle::getSideA() const {
    return sideA;
}

double Triangle::getSideB() const {
    return sideB;
}

double Triangle::getSideC() const {
    return sideC;
}

// Computing area using Heron's formula
double Triangle::area() const {
    // poluPerimetr = (a + b + c) / 2
    double poluPerimetr = (sideA + sideB + sideC) / 2.0;

    // Heron's formula: S = sqrt(p * (p-a) * (p-b) * (p-c))
    double valueUnderRoot = poluPerimetr * (poluPerimetr - sideA) * (poluPerimetr - sideB) * (poluPerimetr - sideC);

    // For a valid triangle valueUnderRoot should be >= 0
    if (valueUnderRoot < 0.0) {
        // This should not normally happen, but na vsyaki protection from possible floating-point rounding errors
        throw TriangleError("Cannot compute area: negative value under square root.");
    }

    return std::sqrt(valueUnderRoot);
}

// Print sides and area
void Triangle::printInfo() const {
    std::cout << "\nTriangle sides: "
        << sideA << ", " << sideB << ", " << sideC << std::endl;

    std::cout << "Triangle area: " << area() << std::endl;
}
