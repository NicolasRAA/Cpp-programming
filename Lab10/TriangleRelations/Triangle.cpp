/* Triangle.cpp */
#include "Triangle.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

// TriangleComposition implementacion

TriangleComposition::TriangleComposition(const Dot& a,
    const Dot& b,
    const Dot& c)
    : pointA(a), pointB(b), pointC(c) {
}

// Private helpers – side lengths
double TriangleComposition::sideAB() const {
    return pointA.distanceTo(pointB);
}

double TriangleComposition::sideBC() const {
    return pointB.distanceTo(pointC);
}

double TriangleComposition::sideCA() const {
    return pointC.distanceTo(pointA);
}

void TriangleComposition::printSideLengths() const {
    double ab = sideAB();
    double bc = sideBC();
    double ca = sideCA();

    cout << "Sides (composition):\n";
    cout << "  AB = " << ab << endl;
    cout << "  BC = " << bc << endl;
    cout << "  CA = " << ca << endl;
}

double TriangleComposition::calculatePerimeter() const {
    return sideAB() + sideBC() + sideCA();
}

double TriangleComposition::calculateArea() const {
    double ab = sideAB();
    double bc = sideBC();
    double ca = sideCA();

    double poluPerimetr = (ab + bc + ca) / 2.0;  // Heron's formula
    double area = std::sqrt(
        poluPerimetr *
        (poluPerimetr - ab) *
        (poluPerimetr - bc) *
        (poluPerimetr - ca)
    );

    return area;
}


// TriangleAggregation implementacion

TriangleAggregation::TriangleAggregation(const Dot* a,
    const Dot* b,
    const Dot* c)
    : pointA(a), pointB(b), pointC(c) {
}

// Side helpers – workin with pointers
double TriangleAggregation::sideAB() const {
    return pointA->distanceTo(*pointB);
}

double TriangleAggregation::sideBC() const {
    return pointB->distanceTo(*pointC);
}

double TriangleAggregation::sideCA() const {
    return pointC->distanceTo(*pointA);
}

void TriangleAggregation::printSideLengths() const {
    double ab = sideAB();
    double bc = sideBC();
    double ca = sideCA();

    cout << "Sides (aggregation):\n";
    cout << "  AB = " << ab << endl;
    cout << "  BC = " << bc << endl;
    cout << "  CA = " << ca << endl;
}

double TriangleAggregation::calculatePerimeter() const {
    return sideAB() + sideBC() + sideCA();
}

double TriangleAggregation::calculateArea() const {
    double ab = sideAB();
    double bc = sideBC();
    double ca = sideCA();

    double poluPerimetr = (ab + bc + ca) / 2.0;
    double area = std::sqrt(
        poluPerimetr *
        (poluPerimetr - ab) *
        (poluPerimetr - bc) *
        (poluPerimetr - ca)
    );

    return area;
}
