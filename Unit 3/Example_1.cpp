//Real-Time Application 1: CAD Shape Drawing System 

#include <iostream>   // Includes the input/output stream library for cout and endl.
#include <memory>     // Includes smart pointers such as unique_ptr and make_unique.
#include <string>     // Includes the string data type.
#include <vector>     // Includes the vector container.
using namespace std;  // Allows us to use cout, string, vector, etc. without writing std::.

// ------------------------------------------------------------
// Base class representing a general vehicle.
// ------------------------------------------------------------
class Vehicle {  // Defines a class named Vehicle.

protected:  // Members under protected can be accessed by this class and its derived classes.
    string vehicleId;          // Stores the unique ID of the vehicle.
    string registrationNumber; // Stores the vehicle's registration number.
    double fuelLevel;          // Stores the current fuel level as a percentage.

public:  // Members under public can be accessed from outside the class.

    // Constructor of Vehicle.
    Vehicle(string vid, string reg)
        : vehicleId(vid),              // Initializes vehicleId with vid.
          registrationNumber(reg),     // Initializes registrationNumber with reg.
          fuelLevel(100.0) {}          // Initializes fuelLevel to 100%.

    // Function to start the vehicle engine.
    void startEngine() const {  // const means this function does not modify object data.
        cout << "Vehicle "        // Prints the text "Vehicle ".
             << vehicleId           // Prints the vehicle ID.
             << " engine started."  // Prints the remaining message.
             << endl;               // Moves the cursor to the next line.
    }

    // Function used to add fuel to the vehicle.
    void refuel(double amount) {  // Takes the amount of fuel to be added.
        fuelLevel += amount;      // Adds amount to the current fuel level.

        // Checks whether the fuel level has gone above 100%.
        if (fuelLevel > 100.0) {  // If fuel level is greater than 100.
            fuelLevel = 100.0;    // Sets fuel level back to the maximum of 100%.
        }
    }

    // Virtual function to display vehicle information.
    virtual void displayInfo() const {  // virtual allows derived classes to override this function.
        cout << "Vehicle ID: "       // Prints the vehicle ID label.
             << vehicleId              // Prints the actual vehicle ID.
             << " | Registration: "    // Prints the registration label.
             << registrationNumber     // Prints the registration number.
             << " | Fuel: "            // Prints the fuel label.
             << fuelLevel              // Prints the current fuel level.
             << "%"                     // Prints the percentage symbol.
             << endl;                   // Moves to the next line.
    }

    // Virtual destructor of the base class.
    virtual ~Vehicle() = default;  // Allows proper destruction of derived objects through a Vehicle pointer.
};


// ------------------------------------------------------------
// Truck class derived from Vehicle.
// ------------------------------------------------------------
class Truck : public Vehicle {  // Truck inherits publicly from Vehicle.

private:  // Private members can only be accessed inside the Truck class.
    double cargoCapacity;  // Stores the cargo capacity of the truck.

public:  // Public members can be accessed from outside the class.

    // Constructor of Truck.
    Truck(string vid, string reg, double capacity)
        : Vehicle(vid, reg),          // Calls the Vehicle constructor with vid and reg.
          cargoCapacity(capacity) {}  // Initializes cargoCapacity with capacity.

    // Overrides the displayInfo function of Vehicle.
    void displayInfo() const override {  // override tells the compiler this function overrides a base-class function.
        cout << "Truck | ";              // Prints the vehicle type.

        Vehicle::displayInfo();          // Calls the displayInfo() function of the Vehicle class.

        cout << "Cargo capacity: "     // Prints the cargo capacity label.
             << cargoCapacity           // Prints the actual cargo capacity.
             << " tonnes"               // Prints the unit.
             << endl;                   // Moves to the next line.
    }
};


// ------------------------------------------------------------
// DeliveryVan class derived from Vehicle.
// ------------------------------------------------------------
class DeliveryVan : public Vehicle {  // DeliveryVan publicly inherits from Vehicle.

private:  // Private members of DeliveryVan.
    int packageCount;  // Stores the number of packages loaded in the van.

public:  // Public members of DeliveryVan.

    // Constructor of DeliveryVan.
    DeliveryVan(string vid, string reg, int packages)
        : Vehicle(vid, reg),          // Calls the Vehicle constructor.
          packageCount(packages) {}    // Initializes packageCount with packages.

    // Overrides Vehicle's displayInfo function.
    void displayInfo() const override {  // Defines the DeliveryVan version of displayInfo().
        cout << "Delivery Van | ";       // Prints the vehicle type.

        Vehicle::displayInfo();          // Calls the base class displayInfo() function.

        cout << "Packages loaded: "  // Prints the package information label.
             << packageCount           // Prints the number of packages.
             << endl;                  // Moves to the next line.
    }
};


// ------------------------------------------------------------
// Bike class derived from Vehicle.
// ------------------------------------------------------------
class Bike : public Vehicle {  // Bike publicly inherits from Vehicle.

private:  // Private members of Bike.
    bool hasDeliveryBox;  // Stores whether the bike has a delivery box.

public:  // Public members of Bike.

    // Constructor of Bike.
    Bike(string vid, string reg, bool hasBox)
        : Vehicle(vid, reg),            // Calls the Vehicle constructor.
          hasDeliveryBox(hasBox) {}     // Initializes hasDeliveryBox with hasBox.

    // Overrides Vehicle's displayInfo function.
    void displayInfo() const override {  // Defines the Bike version of displayInfo().
        cout << "Delivery Bike | ";      // Prints the vehicle type.

        Vehicle::displayInfo();          // Calls the base class displayInfo() function.

        cout << "Delivery box: "   // Prints the delivery box label.

             // ?: is the conditional/ternary operator.
             // If hasDeliveryBox is true, "Available" is printed.
             // If hasDeliveryBox is false, "Not available" is printed.
             << (hasDeliveryBox ? "Available" : "Not available")

             << endl;  // Moves to the next line.
    }
};


// ------------------------------------------------------------
// Main function - program execution starts here.
// ------------------------------------------------------------
int main() {  // Main function where the program starts running.

    // Creates a vector that stores unique_ptr objects pointing to Vehicle objects.
    vector<unique_ptr<Vehicle>> fleet;

    // Creates a Truck object dynamically and stores it inside the fleet vector.
    fleet.push_back(
        make_unique<Truck>(
            "V001",              // Vehicle ID.
            "MH12-AB-1234",      // Registration number.
            10.5                 // Cargo capacity in tonnes.
        )
    );

    // Creates a DeliveryVan object dynamically and stores it in the fleet vector.
    fleet.push_back(
        make_unique<DeliveryVan>(
            "V002",              // Vehicle ID.
            "MH12-CD-5678",      // Registration number.
            50                   // Number of packages.
        )
    );

    // Creates a Bike object dynamically and stores it in the fleet vector.
    fleet.push_back(
        make_unique<Bike>(
            "V003",              // Vehicle ID.
            "MH12-EF-9012",      // Registration number.
            true                 // Indicates that the bike has a delivery box.
        )
    );

    // Prints the heading of the fleet information.
    cout << "=== Fleet Status ===" << endl;

    // Range-based for loop used to go through every vehicle in the fleet.
    for (const auto& vehicle : fleet) {

        // Calls the startEngine() function of the current vehicle.
        vehicle->startEngine();

        // Calls displayInfo() using the Vehicle pointer.
        // Because displayInfo() is virtual, the correct derived-class
        // version (Truck, DeliveryVan, or Bike) is called.
        vehicle->displayInfo();

        // Prints an empty line between vehicle details.
        cout << endl;
    }

    // End of main function.
}