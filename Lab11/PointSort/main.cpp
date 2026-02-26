/* main.cpp */
#include <iostream>
#include <vector>
#include <algorithm>   // for std::sort
#include "Point.h"

int main() {
    // Creating vector with several points
    std::vector<Point> points;
    points.push_back(Point(1, 2));
    points.push_back(Point(10, 12));
    points.push_back(Point(21, 7));
    points.push_back(Point(4, 8));

    std::cout << "Original points:\n";
    for (const auto& point : points) {
        std::cout << point << '\n';
    }

    // Sorting points by distance to the origin (using Point::operator<)
    std::sort(points.begin(), points.end());

    std::cout << "\nPoints sorted by distance to origin:\n";
    for (const auto& point : points) {
        std::cout << point << '\n';  // using operator<<
    }

    return 0;
}
