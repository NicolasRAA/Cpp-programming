/* Vehicle.h */
#pragma once

#include <iostream>
#include <string>

// abstract base class for all vehicles
class Vehicle {
public:
    // (dopolnitelno) static counter of created vehicles
    static int vehicleCount;

    // Constructor increases the counter
    Vehicle() {
        ++vehicleCount;
    }

    // Virtual destructor to delete through base pointer safely
    virtual ~Vehicle() {}

    // Pure virtual function: how this vehicle moves
    virtual void move() const = 0;

    // Pure virtual function: returns type name of vehicle
    virtual std::string type() const = 0;

    // (dopolnitelno) virtual function for saving to a stream
    // Format: <type>;<behavior text>
    virtual void saveToStream(std::ostream& out) const = 0;
};


/* Car */
class Car : public Vehicle {
public:
    // How car moves
    void move() const override {
        std::cout << "Car is driving on the road." << std::endl;
    }

    std::string type() const override {
        return "Car";
    }

    // (dopolnitelno) save description to text stream
    void saveToStream(std::ostream& out) const override {
        out << type() << ";Car is driving on the road.\n";
    }
};


/* Boat */
class Boat : public Vehicle {
public:
    void move() const override {
        std::cout << "Boat is sailing on water." << std::endl;
    }

    std::string type() const override {
        return "Boat";
    }

    // (dop)
    void saveToStream(std::ostream& out) const override {
        out << type() << ";Boat is sailing on water.\n";
    }
};


/* Plane */
class Plane : public Vehicle {
public:
    void move() const override {
        std::cout << "Plane is flying in the sky." << std::endl;
    }

    std::string type() const override {
        return "Plane";
    }

    // (dop)
    void saveToStream(std::ostream& out) const override {
        out << type() << ";Plane is flying in the sky.\n";
    }
};


/* (dop) AmphibiousVehicle */
/* combines car and boat behavior */
class AmphibiousVehicle : public Vehicle {
public:
    void move() const override {
        std::cout << "Amphibious vehicle can drive on the road and sail on water." << std::endl;
    }

    std::string type() const override {
        return "AmphibiousVehicle";
    }

    // (dop)
    void saveToStream(std::ostream& out) const override {
        out << type()
            << ";Amphibious vehicle can drive on the road and sail on water.\n";
    }
};
