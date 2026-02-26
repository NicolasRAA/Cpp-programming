/* main.cpp */
#include <iostream>
#include "Dot.h"
#include "Triangle.h"

using std::cout;
using std::endl;

int main() {
    setlocale(LC_ALL, "Russian");

    // Creating three points for a 3-4-5 right triangle
    Dot pointA(0.0, 0.0);
    Dot pointB(3.0, 0.0);
    Dot pointC(0.0, 4.0);

    // Triangle composition (owns its points)
    TriangleComposition triangleComp(pointA, pointB, pointC);

    cout << "=== Triangle using COMPOSITION ===\n";
    triangleComp.printSideLengths();
    cout << "Perimeter (composition): " << triangleComp.calculatePerimeter() << endl;
    cout << "Area (composition):       " << triangleComp.calculateArea() << endl;

    cout << "\n";

    // Triangle aggregation (uses external points)
    TriangleAggregation triangleAgg(&pointA, &pointB, &pointC);

    cout << "=== Triangle using AGGREGATION ===\n";
    triangleAgg.printSideLengths();
    cout << "Perimeter (aggregation): " << triangleAgg.calculatePerimeter() << endl;
    cout << "Area (aggregation):       " << triangleAgg.calculateArea() << endl;

    return 0;
}

