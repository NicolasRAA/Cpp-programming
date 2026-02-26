/* main.cpp */
#include <iostream>
#include <vector>
#include <fstream>
#include <typeinfo>

#include "Vehicle.h"

using std::cout;
using std::endl;

// Definition of static member of Vehicle
int Vehicle::vehicleCount = 0;

int main()
{
    // Collection of different vehicles (polymorphism demo)
    std::vector<Vehicle*> vehicles;

    // Creating some vehicles and adding them to the collection
    vehicles.push_back(new Car());
    vehicles.push_back(new Boat());
    vehicles.push_back(new Plane());

    // (dop) adding amphibious vehicle
    vehicles.push_back(new AmphibiousVehicle());

    cout << "Vehicle types and their behavior:\n\n";

    // Polymorphic calls: same code, different behavior
    for (const Vehicle* v : vehicles) {
        cout << v->type() << ": ";
        v->move();   // virtual function call
    }

    // (dop) showing how many vehicles were created
    cout << "\nTotal number of created vehicles: "
        << Vehicle::vehicleCount << endl;

    // (dop) saving data to a text file
    {
        std::ofstream outFile("vehicles.txt");
        if (outFile.is_open()) {
            for (const Vehicle* v : vehicles) {
                v->saveToStream(outFile);
            }
            cout << "\nData was written to file 'vehicles.txt'.\n";
        }
        else {
            cout << "\nCould not open 'vehicles.txt' for writing.\n";
        }
    }

    // (dop) RTTI demo: showing dynamic type names
    cout << "\nRTTI demo (typeid(*v).name()):\n";
    for (const Vehicle* v : vehicles) {
        cout << "  " << typeid(*v).name() << endl;
    }

    // Cleaning up dynamic memory
    for (Vehicle* v : vehicles) {
        delete v;  // calls correct destructor because it is virtual
    }

    return 0;
}
