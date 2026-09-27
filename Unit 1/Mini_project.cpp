#include <iostream>  // Includes input/output functions such as cout and endl.
#include <string>    // Includes the string data type.
#include <vector>    // Includes the vector container.
using namespace std; // Allows us to use cout, string, vector, etc. without std::.

// Base class representing a general smart home device.
class SmartDevice {

protected: // Protected members can be accessed by this class and its derived classes.
    string deviceId;        // Stores the unique ID of the device.
    string location;        // Stores the location of the device.
    string status;          // Stores the current status of the device.
    string lastUpdated;     // Stores the last updated time.

public: // Public members can be accessed from outside the class.

    // Constructor of SmartDevice.
    SmartDevice(string id, string loc)
        : deviceId(id),              // Initializes deviceId with id.
          location(loc),              // Initializes location with loc.
          status("OFF"),              // Initially sets the device status to OFF.
          lastUpdated("Not updated")  // Initially sets the update time.
    {
    }

    // Virtual function used to switch the device ON.
    virtual void turnOn(string time) {

        status = "ON";          // Changes the device status to ON.
        lastUpdated = time;     // Updates the last-updated time.
    }

    // Virtual function used to switch the device OFF.
    virtual void turnOff(string time) {

        status = "OFF";         // Changes the device status to OFF.
        lastUpdated = time;     // Updates the last-updated time.
    }

    // Function used to change the device status.
    void changeStatus(string newStatus, string time) {

        status = newStatus;     // Stores the new status.
        lastUpdated = time;     // Updates the last-updated time.
    }

    // Virtual function used to display device information.
    virtual void displayInfo() const {

        cout << "Device ID: " << deviceId       // Displays the device ID.
             << " | Location: " << location      // Displays the location.
             << " | Status: " << status          // Displays the current status.
             << " | Last Updated: " << lastUpdated // Displays update time.
             << endl;                            // Moves to the next line.
    }

    // Virtual destructor.
    virtual ~SmartDevice() = default; // Allows proper destruction of derived objects.
};


// Derived class representing a smart light.
class Light : public SmartDevice {

private: // Private members can only be accessed inside the Light class.
    int brightness; // Stores the brightness percentage of the light.

public: // Public members can be accessed from outside the class.

    // Constructor of Light.
    Light(string id, string loc, int b)
        : SmartDevice(id, loc), // Calls the SmartDevice constructor.
          brightness(b)          // Initializes brightness with b.
    {
    }

    // Overrides the turnOn function.
    void turnOn(string time) override {

        SmartDevice::turnOn(time); // Calls the base class turnOn function.
        status = "ON - Brightness " + to_string(brightness) + "%"; // Adds brightness to the status.
    }

    // Overrides the displayInfo function.
    void displayInfo() const override {

        cout << "Light | ";       // Displays the device type.
        SmartDevice::displayInfo(); // Displays common device information.
    }
};


// Derived class representing a smart thermostat.
class Thermostat : public SmartDevice {

private: // Private members of Thermostat.
    double temperature; // Stores the current temperature setting.

public: // Public members of Thermostat.

    // Constructor of Thermostat.
    Thermostat(string id, string loc, double temp)
        : SmartDevice(id, loc), // Calls the SmartDevice constructor.
          temperature(temp)      // Initializes temperature.
    {
    }

    // Overrides the turnOn function.
    void turnOn(string time) override {

        SmartDevice::turnOn(time); // Calls the base class turnOn function.
        status = "ON - Temperature " + to_string(temperature) + " C"; // Adds temperature to status.
    }

    // Overrides the displayInfo function.
    void displayInfo() const override {

        cout << "Thermostat | ";       // Displays the device type.
        SmartDevice::displayInfo();    // Displays common device information.
    }
};


// Derived class representing a smart camera.
class Camera : public SmartDevice {

private: // Private members of Camera.
    bool recording; // Stores whether the camera is recording.

public: // Public members of Camera.

    // Constructor of Camera.
    Camera(string id, string loc)
        : SmartDevice(id, loc), // Calls the SmartDevice constructor.
          recording(false)       // Initially sets recording to false.
    {
    }

    // Overrides the turnOn function.
    void turnOn(string time) override {

        SmartDevice::turnOn(time); // Calls the base class turnOn function.
        recording = true;          // Starts camera recording.
        status = "ON - Recording"; // Updates the camera status.
    }

    // Overrides the turnOff function.
    void turnOff(string time) override {

        SmartDevice::turnOff(time); // Calls the base class turnOff function.
        recording = false;           // Stops camera recording.
    }

    // Overrides the displayInfo function.
    void displayInfo() const override {

        cout << "Camera | ";          // Displays the device type.
        SmartDevice::displayInfo();  // Displays common device information.
    }
};


// Derived class representing a smart door lock.
class DoorLock : public SmartDevice {

private: // Private members of DoorLock.
    bool locked; // Stores whether the door is locked.

public: // Public members of DoorLock.

    // Constructor of DoorLock.
    DoorLock(string id, string loc)
        : SmartDevice(id, loc), // Calls the SmartDevice constructor.
          locked(true)           // Initially locks the door.
    {
    }

    // Overrides the turnOn function.
    void turnOn(string time) override {

        SmartDevice::turnOn(time); // Calls the base class turnOn function.
        locked = false;            // Unlocks the door.
        status = "ON - Unlocked";  // Updates the status.
    }

    // Overrides the turnOff function.
    void turnOff(string time) override {

        SmartDevice::turnOff(time); // Calls the base class turnOff function.
        locked = true;              // Locks the door.
        status = "OFF - Locked";    // Updates the status.
    }

    // Overrides the displayInfo function.
    void displayInfo() const override {

        cout << "Door Lock | ";        // Displays the device type.
        SmartDevice::displayInfo();   // Displays common device information.
    }
};


// Main function.
// Program execution starts from here.
int main() {

    // Creates a vector of pointers to the base SmartDevice class.
    // It can store objects of Light, Thermostat, Camera, and DoorLock.
    vector<SmartDevice*> devices;

    // Creates a smart light dynamically.
    devices.push_back(
        new Light("L001", "Living Room", 80)
    );

    // Creates a smart thermostat dynamically.
    devices.push_back(
        new Thermostat("T001", "Bedroom", 24.5)
    );

    // Creates a smart camera dynamically.
    devices.push_back(
        new Camera("C001", "Main Door")
    );

    // Creates a smart door lock dynamically.
    devices.push_back(
        new DoorLock("D001", "Main Door")
    );


    // Switches the first device ON.
    devices[0]->turnOn("10:00 AM");

    // Switches the second device ON.
    devices[1]->turnOn("10:05 AM");

    // Switches the third device ON.
    devices[2]->turnOn("10:10 AM");

    // Switches the fourth device ON.
    devices[3]->turnOn("10:15 AM");


    // Prints the overall home dashboard heading.
    cout << "========== SMART HOME DASHBOARD ==========" << endl;

    // Range-based for loop goes through every device.
    for (const auto& device : devices) {

        // Displays information about the current device.
        // Because displayInfo() is virtual, the correct derived class function is called.
        device->displayInfo();
    }

    // Prints a heading before changing a device status.
    cout << "\nChanging device status..." << endl;

    // Turns the camera OFF.
    devices[2]->turnOff("10:30 AM");

    // Changes the thermostat status.
    devices[1]->changeStatus("ON - Temperature 26 C", "10:35 AM");


    // Prints the updated dashboard.
    cout << "\n========== UPDATED DASHBOARD ==========" << endl;

    // Displays all devices again after the changes.
    for (const auto& device : devices) {

        // Displays the updated information.
        device->displayInfo();
    }


    // Deletes every dynamically created device.
    // This releases the memory allocated using new.
    for (auto device : devices) {

        // Frees the memory occupied by the current device.
        delete device;
    }

    // Clears the vector after deleting the objects.
    devices.clear();

    // Returns 0 to indicate successful program execution.
    return 0;
}