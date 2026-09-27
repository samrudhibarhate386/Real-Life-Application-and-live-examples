//Real-Time Application 1: Student Record File System

#include <fstream>   // Provides file input/output classes such as ifstream and ofstream.
#include <iostream>  // Provides input/output functions such as cout and cerr.
#include <sstream>   // Provides stringstream for processing strings like streams.
#include <string>    // Provides the string data type.
using namespace std; // Allows us to use cout, string, ifstream, etc. without std::.

// Defines a class named Student.
class Student {

private: // Private members can only be accessed inside the Student class.
    int rollNo;       // Stores the student's roll number.
    string name;      // Stores the student's name.
    double marks;     // Stores the student's marks.

public: // Public members can be accessed from outside the class.

    // Default constructor.
    Student()
        : rollNo(0),       // Initializes rollNo to 0.
          marks(0.0) {}     // Initializes marks to 0.0.

    // Parameterized constructor.
    Student(int r, string n, double m)
        : rollNo(r),        // Initializes rollNo with r.
          name(n),           // Initializes name with n.
          marks(m) {}        // Initializes marks with m.

    // Function used to save student information into a file.
    // ofstream is used for writing data to a file.
    // & means out is passed by reference.
    // const means this function does not modify the Student object.
    void saveToFile(ofstream& out) const {

        // Writes roll number, name, and marks into the file.
        // ',' separates the values like a CSV file.
        // '\n' moves to the next line.
        out << rollNo << ','
            << name << ','
            << marks << '\n';
    }

    // Function used to load student information from one line.
    bool loadFromLine(const string& line) {

        // String used to temporarily store the roll number as text.
        string rollText;

        // String used to temporarily store the marks as text.
        string marksText;

        // Creates a stringstream using the given line.
        // This allows us to extract individual values from the string.
        stringstream stream(line);

        // Reads the roll number from the stream until a comma is found.
        // getline() returns false if reading fails.
        if (!getline(stream, rollText, ','))

            // Returns false if the roll number could not be read.
            return false;

        // Reads the name until a comma is found.
        if (!getline(stream, name, ','))

            // Returns false if the name could not be read.
            return false;

        // Reads the remaining part of the line as marks.
        if (!getline(stream, marksText))

            // Returns false if marks could not be read.
            return false;

        // Converts the roll number from string to integer.
        // stoi means "string to integer".
        rollNo = stoi(rollText);

        // Converts the marks from string to double.
        // stod means "string to double".
        marks = stod(marksText);

        // Returns true because all student information was successfully loaded.
        return true;
    }

    // Function used to display student information on the screen.
    void display() const {

        // Prints the roll number.
        cout << "Roll: " << rollNo

             // Prints a separator and the student's name.
             << " | Name: " << name

             // Prints another separator and the student's marks.
             << " | Marks: " << marks

             // Moves the cursor to the next line.
             << endl;
    }
};


// Main function.
// Program execution starts from here.
int main() {

    // Creates an output file stream.
    // Opens or creates students.csv for writing.
    ofstream outFile("students.csv");

    // Checks whether the file was successfully opened.
    if (!outFile) {

        // cerr is used to display an error message.
        cerr << "Unable to open students.csv for writing." << endl;

        // Returns 1 to indicate that an error occurred.
        return 1;
    }

    // Creates the first Student object.
    Student s1(101, "Rahul Patil", 85.5);

    // Creates the second Student object.
    Student s2(102, "Priya Sharma", 92.0);

    // Creates the third Student object.
    Student s3(103, "Amit Kulkarni", 78.5);

    // Saves the first student's information into the file.
    s1.saveToFile(outFile);

    // Saves the second student's information into the file.
    s2.saveToFile(outFile);

    // Saves the third student's information into the file.
    s3.saveToFile(outFile);

    // Closes the output file.
    outFile.close();


    // Creates an input file stream.
    // Opens students.csv for reading.
    ifstream inFile("students.csv");

    // Checks whether the file was successfully opened.
    if (!inFile) {

        // Displays an error message if the file cannot be opened.
        cerr << "Unable to open students.csv for reading." << endl;

        // Returns 1 to indicate an error.
        return 1;
    }

    // Prints the heading of the student report.
    cout << "=== Student Report ===" << endl;

    // String variable used to store one line from the file at a time.
    string line;

    // Reads the file line by line until the end of the file.
    while (getline(inFile, line)) {

        // Creates a temporary Student object.
        Student student;

        // Loads the information from the current line into the Student object.
        if (student.loadFromLine(line)) {

            // Displays the student information if loading was successful.
            student.display();
        }
    }

    // Closes the input file.
    inFile.close();

    // Returns 0 to indicate successful program execution.
    return 0;
}