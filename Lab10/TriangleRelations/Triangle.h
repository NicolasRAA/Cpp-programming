/* Triangle.h */
#pragma once

#include "Dot.h"

/*Triangle using composition
Triangle "owns" its points; they are stored by value
When Triangle dies, its points die with it((( */
class TriangleComposition {
private:
    Dot pointA;
    Dot pointB;
    Dot pointC;

    // Helper methods to get side lengths
    double sideAB() const;
    double sideBC() const;
    double sideCA() const;

public:
    // Consct takes three points and stores copies -> composition
    TriangleComposition(const Dot& a, const Dot& b, const Dot& c);

    // Pritign the lengths of all sides
    void printSideLengths() const;

    // Calc perimeter of triangle
    double calculatePerimeter() const;

    // Calc area using Heron's formula
    double calculateArea() const;
};

/* Triangle using aggregation
Triangle does not own the points; it only keeps pointers to them
Points must exist outside and live longer than the triangle */
class TriangleAggregation {
private:
    const Dot* pointA;
    const Dot* pointB;
    const Dot* pointC;

    double sideAB() const;
    double sideBC() const;
    double sideCA() const;

public:
    // Constructor takes pointers to existing points (aggregation)
    TriangleAggregation(const Dot* a, const Dot* b, const Dot* c);

    void printSideLengths() const;
    double calculatePerimeter() const;
    double calculateArea() const;
};
