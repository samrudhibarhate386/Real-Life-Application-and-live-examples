#include <iostream> 
// #include → Includes a required library in the program.
// <iostream> → Provides input/output functions like cout and cin.

#include <string> 
// #include → Includes the required library.
// <string> → Provides the string data type for storing text.

#include <vector> 
// #include → Includes the required library.
// <vector> → Provides the vector container for storing multiple objects.

using namespace std; 
// using → Allows us to use a namespace.
// namespace → A container for related identifiers.
// std → Standard C++ namespace.
// :: is not needed here because using namespace std makes standard names directly accessible.


// Class for storing and managing soil sensor information.
class SoilSensor { 
// class → Defines a user-defined class.
// SoilSensor → Name of the class.
// { → Starts the class body.

private: 
// private → Makes the following data members accessible only inside the class.

    string sensorId; 
    // string → Data type used to store text.
    // sensorId → Variable used to store the sensor ID.

    double moistureLevel; 
    // double → Data type used to store decimal numbers.
    // moistureLevel → Variable used to store the soil moisture percentage.

    string timestamp; 
    // string → Data type used to store text.
    // timestamp → Variable used to store the time of the sensor reading.

public: 
// public → Makes the following class members accessible from outside the class.

    SoilSensor(string id, double moisture, string time) 
    // SoilSensor → Constructor with the same name as the class.
    // string id → Parameter used to receive the sensor ID.
    // double moisture → Parameter used to receive the moisture value.
    // string time → Parameter used to receive the timestamp.
    // () → Contains the constructor parameters.

        : sensorId(id), moistureLevel(moisture), timestamp(time) {} 
        // : → Starts the member initializer list.
        // sensorId(id) → Initializes sensorId using id.
        // moistureLevel(moisture) → Initializes moistureLevel using moisture.
        // timestamp(time) → Initializes timestamp using time.
        // {} → Empty constructor body.

    void readSensor(double newMoisture, string newTime) { 
    // void → Specifies that the function does not return a value.
    // readSensor → Name of the function.
    // double newMoisture → Parameter that stores the new moisture value.
    // string newTime → Parameter that stores the new timestamp.
    // { → Starts the function body.

        moistureLevel = newMoisture; 
        // moistureLevel → Existing moisture variable.
        // = → Assignment operator.
        // newMoisture → New moisture value.
        // Updates moistureLevel with the new moisture value.

        timestamp = newTime; 
        // timestamp → Existing time variable.
        // = → Assignment operator.
        // newTime → New time value.
        // Updates timestamp with the new time.

    } 
    // } → Ends the readSensor function.

    void displayData() const { 
    // void → Function does not return a value.
    // displayData → Name of the function.
    // () → Function takes no parameters.
    // const → Prevents the function from modifying object data.
    // { → Starts the function body.

        cout << "Sensor: " << sensorId 
        // cout → Displays output on the screen.
        // << → Insertion/output operator.
        // "Sensor: " → Text displayed before the sensor ID.
        // sensorId → Displays the sensor ID.

             << " | Moisture: " << moistureLevel << "%" 
        // << → Sends the next value to cout.
        // " | Moisture: " → Displays the moisture label.
        // moistureLevel → Displays the moisture value.
        // "%" → Displays the percentage symbol.

             << " | Time: " << timestamp << endl; 
        // " | Time: " → Displays the time label.
        // timestamp → Displays the timestamp.
        // endl → Moves the cursor to the next line.
        // ; → Ends the statement.

    } 
    // } → Ends the displayData function.

}; 
// } → Ends the SoilSensor class.
// ; → Semicolon required after a class definition.


// Main function where program execution begins.
int main() { 
// int → Specifies that main returns an integer value.
// main → Special function where execution of the program starts.
// () → main takes no parameters.
// { → Starts the main function.

    vector<SoilSensor> farmSensors; 
    // vector → Container used to store multiple elements.
    // <SoilSensor> → Specifies that the vector stores SoilSensor objects.
    // farmSensors → Name of the vector.
    // ; → Ends the statement.

    farmSensors.emplace_back("S001", 45.2, "08:00"); 
    // farmSensors → Vector containing SoilSensor objects.
    // . → Member access operator.
    // emplace_back → Creates and adds an object at the end of the vector.
    // ("S001", 45.2, "08:00") → Values passed to the SoilSensor constructor.
    // "S001" → Sensor ID.
    // 45.2 → Initial moisture level.
    // "08:00" → Initial timestamp.
    // ; → Ends the statement.

    farmSensors.emplace_back("S002", 52.8, "08:00"); 
    // farmSensors → Vector of SoilSensor objects.
    // . → Member access operator.
    // emplace_back → Adds a new SoilSensor object.
    // "S002" → Sensor ID.
    // 52.8 → Initial moisture level.
    // "08:00" → Initial timestamp.
    // ; → Ends the statement.

    farmSensors.emplace_back("S003", 38.5, "08:00"); 
    // farmSensors → Vector of SoilSensor objects.
    // . → Member access operator.
    // emplace_back → Adds a new SoilSensor object.
    // "S003" → Sensor ID.
    // 38.5 → Initial moisture level.
    // "08:00" → Initial timestamp.
    // ; → Ends the statement.

    cout << "=== Morning Sensor Readings ===" << endl; 
    // cout → Displays output.
    // << → Output/insertion operator.
    // "=== Morning Sensor Readings ===" → Heading displayed on the screen.
    // endl → Moves to the next line.
    // ; → Ends the statement.

    for (const auto& sensor : farmSensors) { 
    // for → Starts a loop.
    // ( ) → Contains the loop information.
    // const → Prevents modification of the current object.
    // auto → Automatically determines the data type.
    // & → Creates a reference to the existing object instead of copying it.
    // sensor → Variable representing the current SoilSensor object.
    // : → Separates the loop variable from the collection.
    // farmSensors → Vector being traversed by the loop.
    // { → Starts the loop body.

        sensor.displayData(); 
        // sensor → Current SoilSensor object.
        // . → Member access operator.
        // displayData → Function that displays sensor information.
        // () → Calls the function without arguments.
        // ; → Ends the statement.

    } 
    // } → Ends the for loop.

    farmSensors[0].readSensor(47.5, "09:00"); 
    // farmSensors → Vector containing the sensor objects.
    // [0] → Accesses the first object because vector indexing starts from 0.
    // . → Member access operator.
    // readSensor → Function used to update sensor information.
    // 47.5 → New moisture level.
    // "09:00" → New timestamp.
    // ; → Ends the statement.

    cout << "\n=== Updated Reading ===" << endl; 
    // cout → Displays output.
    // << → Output/insertion operator.
    // \n → Moves the output to a new line.
    // "=== Updated Reading ===" → Heading displayed on the screen.
    // endl → Moves the cursor to the next line.
    // ; → Ends the statement.

    farmSensors[0].displayData(); 
    // farmSensors → Vector containing sensor objects.
    // [0] → Accesses the first sensor object.
    // . → Member access operator.
    // displayData → Function used to display sensor information.
    // () → Calls the function without arguments.
    // ; → Ends the statement.

} 
// } → Ends the main function.