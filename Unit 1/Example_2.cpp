//Real-Time Application 2: Student Attendance Management System

#include <iostream> 
// #include → Includes a library in the program.
// <iostream> → Provides input/output functions such as cout and cin.

#include <string> 
// #include → Includes a library in the program.
// <string> → Provides the string data type for storing text.

using namespace std; 
// using → Allows direct use of names from a namespace.
// namespace → Groups related identifiers.
// std → Standard C++ namespace.
// ; → Ends the statement.

 
class Student { 
// class → Defines a user-defined data type.
// Student → Name of the class.
// { → Starts the class body.

private: 
// private → Makes the following data members accessible only inside the class.

    int rollNo; 
    // int → Integer data type.
// rollNo → Stores the student's roll number.
// ; → Ends the declaration.

    string name; 
    // string → Data type used to store text.
// name → Stores the student's name.
// ; → Ends the declaration.

    int totalDays; 
    // int → Integer data type.
// totalDays → Stores the total number of attendance days.
// ; → Ends the declaration.

    int presentDays; 
    // int → Integer data type.
// presentDays → Stores the number of days the student was present.
// ; → Ends the declaration.

 
public: 
// public → Makes the following members accessible from outside the class.

    Student(int r, string n) 
    // Student → Constructor with the same name as the class.
// int r → Parameter used to receive the roll number.
// string n → Parameter used to receive the student's name.
// ( ) → Contains the constructor parameters.

        : rollNo(r), name(n), totalDays(0), presentDays(0) {} 
        // : → Starts the member initializer list.
        // rollNo(r) → Initializes rollNo with r.
        // name(n) → Initializes name with n.
        // totalDays(0) → Initializes totalDays to 0.
        // presentDays(0) → Initializes presentDays to 0.
        // { } → Empty constructor body.

 
    void markAttendance(bool isPresent) { 
    // void → Function does not return a value.
    // markAttendance → Name of the function.
    // bool → Boolean data type that stores true or false.
    // isPresent → Stores whether the student is present.
    // ( ) → Contains the function parameter.
    // { → Starts the function body.

        totalDays++; 
        // totalDays → Stores the total attendance days.
        // ++ → Increment operator; increases the value by 1.
        // ; → Ends the statement.

        if (isPresent) { 
        // if → Checks a condition.
        // (isPresent) → Checks whether isPresent is true.
        // { → Starts the if block.

            presentDays++; 
            // presentDays → Stores the number of days the student was present.
            // ++ → Increases presentDays by 1.
            // ; → Ends the statement.

        } 
        // } → Ends the if block.

    } 
    // } → Ends the markAttendance function.

 
    double getAttendancePercentage() const { 
    // double → Function returns a decimal value.
    // getAttendancePercentage → Name of the function.
    // ( ) → Function takes no parameters.
    // const → Function cannot modify the object's data.
    // { → Starts the function body.

        if (totalDays == 0) { 
        // if → Checks a condition.
        // totalDays → Stores the total number of days.
        // == → Comparison operator used to check equality.
        // 0 → Checks whether totalDays is zero.
        // { → Starts the if block.

            return 0.0; 
            // return → Sends a value back from the function.
            // 0.0 → Decimal value returned when there are no attendance days.
            // ; → Ends the statement.

        } 
        // } → Ends the if block.

        return (presentDays * 100.0) / totalDays; 
        // return → Returns the calculated attendance percentage.
        // ( ) → Groups the calculation.
        // presentDays → Number of days the student was present.
        // * → Multiplication operator.
        // 100.0 → Multiplies the attendance by 100.
        // / → Division operator.
        // totalDays → Divides by the total number of days.
        // ; → Ends the statement.

    } 
    // } → Ends the getAttendancePercentage function.

 
    void display() const { 
    // void → Function does not return a value.
    // display → Name of the function.
    // ( ) → Function takes no parameters.
    // const → Function cannot modify the object.
    // { → Starts the function body.

        cout << "Roll: " << rollNo 
        // cout → Displays output on the screen.
        // << → Output/insertion operator.
        // "Roll: " → Displays the text "Roll: ".
        // rollNo → Displays the student's roll number.

             << " | Name: " << name 
        // << → Sends the next value to cout.
        // " | Name: " → Displays the name label.
        // name → Displays the student's name.

             << " | Attendance: " << getAttendancePercentage() << "%" << endl; 
        // " | Attendance: " → Displays the attendance label.
        // getAttendancePercentage() → Calls the function that calculates attendance.
        // "%" → Displays the percentage symbol.
        // endl → Moves the cursor to the next line.
        // ; → Ends the statement.

    } 
    // } → Ends the display function.

}; 
// } → Ends the Student class.
// ; → Ends the class definition.

 
int main() { 
// int → Specifies that the function returns an integer.
// main → Starting point of the C++ program.
// ( ) → main function takes no parameters.
// { → Starts the main function.

    Student s1(101, "Rahul"); 
    // Student → Class name.
    // s1 → Name of the first Student object.
    // (101, "Rahul") → Values passed to the constructor.
    // 101 → Roll number.
    // "Rahul" → Student name.
    // ; → Ends the statement.

    Student s2(102, "Priya"); 
    // Student → Class name.
    // s2 → Name of the second Student object.
    // 102 → Roll number.
    // "Priya" → Student name.
    // ; → Ends the statement.

 
    s1.markAttendance(true); 
    // s1 → First Student object.
    // . → Member access operator.
    // markAttendance → Calls the attendance function.
    // true → Indicates that Rahul is present.
    // ; → Ends the statement.

    s1.markAttendance(true); 
    // s1 → First Student object.
    // . → Member access operator.
    // markAttendance → Calls the attendance function.
    // true → Indicates that Rahul is present.
    // ; → Ends the statement.

    s1.markAttendance(false); 
    // s1 → First Student object.
    // . → Member access operator.
    // markAttendance → Calls the attendance function.
    // false → Indicates that Rahul is absent.
    // ; → Ends the statement.

 
    s2.markAttendance(true); 
    // s2 → Second Student object.
    // . → Member access operator.
    // markAttendance → Calls the attendance function.
    // true → Indicates that Priya is present.
    // ; → Ends the statement.

    s2.markAttendance(true); 
    // s2 → Second Student object.
    // . → Member access operator.
    // markAttendance → Calls the attendance function.
    // true → Indicates that Priya is present.
    // ; → Ends the statement.

    s2.markAttendance(true); 
    // s2 → Second Student object.
    // . → Member access operator.
    // markAttendance → Calls the attendance function.
    // true → Indicates that Priya is present.
    // ; → Ends the statement.

 
    cout << "=== Attendance Report ===" << endl; 
    // cout → Displays output on the screen.
    // << → Output/insertion operator.
    // "=== Attendance Report ===" → Displays the report heading.
    // endl → Moves the cursor to the next line.
    // ; → Ends the statement.

    s1.display(); 
    // s1 → First Student object.
    // . → Member access operator.
    // display → Calls the display function.
    // ( ) → Calls the function without arguments.
    // ; → Ends the statement.

    s2.display(); 
    // s2 → Second Student object.
    // . → Member access operator.
    // display → Calls the display function.
    // ( ) → Calls the function without arguments.
    // ; → Ends the statement.

} 
// } → Ends the main function.