//Real-Time Application 2: Server Log Analyzer 

#include <fstream>   // Includes file handling classes such as ifstream and ofstream.
#include <iostream>  // Includes input/output functions such as cout, cerr, and endl.
#include <string>    // Includes the string data type.
#include <vector>    // Includes the vector container.
using namespace std; // Allows us to use cout, string, vector, etc. without writing std::.

// Structure used to represent one log entry.
struct LogEntry {

    // Stores one complete line of the log file.
    string line;
};


// Main function.
// Program execution starts from here.
int main() {

    // Creates an output file stream named sampleLog.
    // "server.log" is the file that will be created/opened for writing.
    ofstream sampleLog("server.log");

    // Checks whether the log file was successfully created/opened.
    if (!sampleLog) {

        // Displays an error message if the file could not be created.
        cerr << "Unable to create log file." << endl;

        // Returns 1 to indicate that an error occurred.
        return 1;
    }

    // Writes the first log entry into the server.log file.
    // \n moves the cursor to the next line.
    sampleLog << "2026-09-09 08:00:00 INFO Server started\n";

    // Writes the second log entry into the file.
    sampleLog << "2026-09-09 08:10:00 WARNING High memory usage\n";

    // Writes an ERROR log entry into the file.
    sampleLog << "2026-09-09 08:20:00 ERROR Database connection failed\n";

    // Writes another INFO log entry into the file.
    sampleLog << "2026-09-09 08:30:00 INFO Backup completed\n";

    // Writes a CRITICAL log entry into the file.
    sampleLog << "2026-09-09 08:40:00 CRITICAL Disk space low\n";

    // Closes the output file after writing all log entries.
    sampleLog.close();


    // Creates an input file stream to read the server.log file.
    ifstream logFile("server.log");

    // Checks whether the log file was successfully opened for reading.
    if (!logFile) {

        // Displays an error message if the file could not be opened.
        cerr << "Unable to open server.log." << endl;

        // Returns 1 to indicate that an error occurred.
        return 1;
    }

    // Creates a vector named errors.
    // It stores LogEntry objects containing ERROR or CRITICAL messages.
    vector<LogEntry> errors;

    // String variable used to store one line from the log file at a time.
    string line;

    // Reads the log file line by line until the end of the file.
    while (getline(logFile, line)) {

        // Checks whether the current line contains "ERROR"
        // OR contains "CRITICAL".
        if (line.find("ERROR") != string::npos ||

            // find() searches for "CRITICAL" in the current line.
            // string::npos means the text was not found.
            line.find("CRITICAL") != string::npos) {

            // Adds the current log line to the errors vector.
            // {line} creates a LogEntry object using the current line.
            errors.push_back({line});
        }
    }

    // Closes the log file after reading all entries.
    logFile.close();


    // Prints the heading for critical log events.
    cout << "=== Critical Log Events ===" << endl;

    // Range-based for loop goes through every LogEntry stored in errors.
    // const means the entry cannot be modified.
    // auto automatically determines the type of entry.
    // & means entry is accessed by reference.
    for (const auto& entry : errors) {

        // Prints the complete log line stored in the entry.
        cout << entry.line << endl;
    }

    // Prints the total number of ERROR and CRITICAL events.
    // errors.size() returns the number of elements in the vector.
    cout << "Total critical events: " << errors.size() << endl;

    // Returns 0 to indicate successful program execution.
    return 0;
}