/* Triangle.h */
#pragma once

#include <string>
#include <iostream>

// Simple exception class for invalid triangles
class TriangleError {
public:
    explicit TriangleError(const std::string& msg) : message(msg) {}

    // Printing stored error message
    void printMessage() const {
        std::cout << message << std::endl;
    }

private:
    std::string message;  // text describing the error
};

// Triangle defined by three sides
class Triangle {
public:
    // Default constructor: creates a 3-4-5 triangle (always valid)
    Triangle();

    /* Constructor with three sides
    Throws TriangleError if sides are not positive
    or triangle inequality is violated
    */
    Triangle(double sideA, double sideB, double sideC);

    // Getters (na vsyaki)
    double getSideA() const;
    double getSideB() const;
    double getSideC() const;

    // To compute area of triangle using Heron's formula
    double area() const;

    // Print sides and area
    void printInfo() const;

private:
    double sideA;
    double sideB;
    double sideC;
};
