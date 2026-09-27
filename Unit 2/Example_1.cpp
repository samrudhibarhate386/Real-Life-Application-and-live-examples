//Real-Time Application 1: Employee Payroll System

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

 
class Employee { 
// class → Defines a user-defined data type.
// Employee → Name of the class.
// { → Starts the class body.

protected: 
// protected → Members can be accessed inside this class and its derived classes.

    int empId; 
    // int → Integer data type.
    // empId → Stores the employee ID.
    // ; → Ends the declaration.

    string name; 
    // string → Data type used to store text.
    // name → Stores the employee name.
    // ; → Ends the declaration.

    string department; 
    // string → Data type used to store text.
    // department → Stores the employee's department.
    // ; → Ends the declaration.

 
public: 
// public → Makes the following members accessible from outside the class.

    Employee(int id, string n, string dept) 
    // Employee → Constructor with the same name as the class.
    // int id → Parameter used to receive employee ID.
    // string n → Parameter used to receive employee name.
    // string dept → Parameter used to receive department name.
    // ( ) → Contains constructor parameters.

        : empId(id), name(n), department(dept) {} 
        // : → Starts the member initializer list.
        // empId(id) → Initializes empId using id.
        // name(n) → Initializes name using n.
        // department(dept) → Initializes department using dept.
        // { } → Empty constructor body.

 
    void displayBasicInfo() const { 
    // void → Function does not return a value.
    // displayBasicInfo → Name of the function.
    // ( ) → Function takes no parameters.
    // const → Function cannot modify the object.
    // { → Starts the function body.

        cout << "ID: " << empId 
        // cout → Displays output on the screen.
        // << → Output/insertion operator.
        // "ID: " → Displays the ID label.
        // empId → Displays the employee ID.

             << " | Name: " << name 
        // " | Name: " → Displays the name label.
        // name → Displays the employee name.

             << " | Department: " << department; 
        // " | Department: " → Displays the department label.
        // department → Displays the department name.
        // ; → Ends the statement.

    } 
    // } → Ends the displayBasicInfo function.

 
    virtual double calculateSalary() const = 0; 
    // virtual → Allows derived classes to provide their own version of the function.
    // double → Function returns a decimal value.
    // calculateSalary → Name of the function.
    // ( ) → Function takes no parameters.
    // const → Function cannot modify the object.
    // = 0 → Makes this a pure virtual function.
    // ; → Ends the function declaration.

    virtual ~Employee() = default; 
    // virtual → Allows the destructor to work correctly with inheritance.
    // ~Employee → Destructor of the Employee class.
    // ( ) → Destructor takes no parameters.
    // = default → Tells the compiler to generate the default destructor.
    // ; → Ends the statement.

}; 
// } → Ends the Employee class.
// ; → Ends the class definition.

 
class FullTimeEmployee : public Employee { 
// class → Defines a new class.
// FullTimeEmployee → Name of the derived class.
// : → Indicates inheritance.
// public → Specifies public inheritance.
// Employee → Base/parent class.
// { → Starts the class body.

private: 
// private → Makes the following member accessible only inside FullTimeEmployee.

    double monthlySalary; 
    // double → Data type for decimal numbers.
    // monthlySalary → Stores the monthly salary.
    // ; → Ends the declaration.

 
public: 
// public → Makes the following members accessible from outside the class.

    FullTimeEmployee(int id, string n, string dept, double salary) 
    // FullTimeEmployee → Constructor of the derived class.
    // int id → Employee ID parameter.
    // string n → Employee name parameter.
    // string dept → Department parameter.
    // double salary → Monthly salary parameter.

        : Employee(id, n, dept), monthlySalary(salary) {} 
        // : → Starts the member initializer list.
        // Employee(id, n, dept) → Calls the constructor of the parent class.
        // monthlySalary(salary) → Initializes monthlySalary.
        // { } → Empty constructor body.

 
    double calculateSalary() const override { 
    // double → Function returns a decimal value.
    // calculateSalary → Name of the function.
    // const → Function cannot modify the object.
    // override → Confirms that this function overrides the virtual
    // function from the Employee class.
    // { → Starts the function body.

        return monthlySalary; 
        // return → Sends a value back from the function.
        // monthlySalary → Returns the monthly salary.
        // ; → Ends the statement.

    } 
    // } → Ends calculateSalary.

 
    void display() const { 
    // void → Function does not return a value.
    // display → Name of the function.
    // const → Function cannot modify the object.
    // { → Starts the function body.

        displayBasicInfo(); 
        // Calls the inherited displayBasicInfo function.
        // ( ) → Calls the function without arguments.
        // ; → Ends the statement.

        cout << " | Type: Full-Time | Salary: Rs. " 
        // cout → Displays output.
        // << → Output/insertion operator.
        // " | Type: Full-Time | Salary: Rs. " → Displays employee type and salary label.

             << calculateSalary() << endl; 
        // calculateSalary() → Calls the salary calculation function.
        // << → Displays the returned salary.
        // endl → Moves the cursor to the next line.
        // ; → Ends the statement.

    } 
    // } → Ends the display function.

}; 
// } → Ends the FullTimeEmployee class.
// ; → Ends the class definition.

 
class PartTimeEmployee : public Employee { 
// class → Defines a new class.
// PartTimeEmployee → Name of the derived class.
// : → Indicates inheritance.
// public → Specifies public inheritance.
// Employee → Base/parent class.
// { → Starts the class body.

private: 
// private → Makes the following members accessible only inside this class.

    double hourlyRate; 
    // double → Decimal data type.
    // hourlyRate → Stores the employee's hourly pay rate.
    // ; → Ends the declaration.

    int hoursWorked; 
    // int → Integer data type.
    // hoursWorked → Stores the number of hours worked.
    // ; → Ends the declaration.

 
public: 
// public → Makes the following members accessible from outside the class.

    PartTimeEmployee(int id, string n, string dept, double rate, int hours) 
    // PartTimeEmployee → Constructor of the derived class.
    // int id → Employee ID parameter.
    // string n → Employee name parameter.
    // string dept → Department parameter.
    // double rate → Hourly rate parameter.
    // int hours → Hours worked parameter.

        : Employee(id, n, dept), hourlyRate(rate), hoursWorked(hours) {} 
        // : → Starts the member initializer list.
        // Employee(id, n, dept) → Calls the parent class constructor.
        // hourlyRate(rate) → Initializes hourlyRate.
        // hoursWorked(hours) → Initializes hoursWorked.
        // { } → Empty constructor body.

 
    double calculateSalary() const override { 
    // double → Function returns a decimal value.
    // calculateSalary → Function name.
    // const → Function cannot modify the object.
    // override → Overrides the virtual function from Employee.
    // { → Starts the function body.

        return hourlyRate * hoursWorked; 
        // return → Sends the calculated value back.
        // hourlyRate → Employee's hourly pay rate.
        // * → Multiplication operator.
        // hoursWorked → Number of hours worked.
        // ; → Ends the statement.

    } 
    // } → Ends calculateSalary.

 
    void display() const { 
    // void → Function does not return a value.
    // display → Function name.
    // const → Function cannot modify the object.
    // { → Starts the function body.

        displayBasicInfo(); 
        // Calls the inherited displayBasicInfo function.
        // ( ) → Calls the function without arguments.
        // ; → Ends the statement.

        cout << " | Type: Part-Time | Salary: Rs. " 
        // cout → Displays output.
        // << → Output/insertion operator.
        // " | Type: Part-Time | Salary: Rs. " → Displays employee type and salary label.

             << calculateSalary() << endl; 
        // calculateSalary() → Calls the salary calculation function.
        // << → Displays the returned salary.
        // endl → Moves the cursor to the next line.
        // ; → Ends the statement.

    } 
    // } → Ends the display function.

}; 
// } → Ends the PartTimeEmployee class.
// ; → Ends the class definition.

 
class Intern : public Employee { 
// class → Defines a new class.
// Intern → Name of the derived class.
// : → Indicates inheritance.
// public → Specifies public inheritance.
// Employee → Base/parent class.
// { → Starts the class body.

private: 
// private → Makes the following member accessible only inside the Intern class.

    double stipend; 
    // double → Decimal data type.
    // stipend → Stores the intern's stipend.
    // ; → Ends the declaration.

 
public: 
// public → Makes the following members accessible from outside the class.

    Intern(int id, string n, string dept, double stipendAmount) 
    // Intern → Constructor of the Intern class.
    // int id → Employee ID parameter.
    // string n → Employee name parameter.
    // string dept → Department parameter.
    // double stipendAmount → Stipend parameter.

        : Employee(id, n, dept), stipend(stipendAmount) {} 
        // : → Starts the member initializer list.
        // Employee(id, n, dept) → Calls the parent class constructor.
        // stipend(stipendAmount) → Initializes stipend.
        // { } → Empty constructor body.

 
    double calculateSalary() const override { 
    // double → Function returns a decimal value.
    // calculateSalary → Function name.
    // const → Function cannot modify the object.
    // override → Overrides the virtual function from Employee.
    // { → Starts the function body.

        return stipend; 
        // return → Sends a value back from the function.
        // stipend → Returns the intern's stipend.
        // ; → Ends the statement.

    } 
    // } → Ends calculateSalary.

 
    void display() const { 
    // void → Function does not return a value.
    // display → Function name.
    // const → Function cannot modify the object.
    // { → Starts the function body.

        displayBasicInfo(); 
        // Calls the inherited displayBasicInfo function.
        // ( ) → Calls the function without arguments.
        // ; → Ends the statement.

        cout << " | Type: Intern | Stipend: Rs. " 
        // cout → Displays output.
        // << → Output/insertion operator.
        // " | Type: Intern | Stipend: Rs. " → Displays intern type and stipend label.

             << calculateSalary() << endl; 
        // calculateSalary() → Calls the salary calculation function.
        // << → Displays the returned stipend.
        // endl → Moves the cursor to the next line.
        // ; → Ends the statement.

    } 
    // } → Ends the display function.

}; 
// } → Ends the Intern class.
// ; → Ends the class definition.

 
int main() { 
// int → Specifies that main returns an integer.
// main → Starting point of the C++ program.
// ( ) → main takes no parameters.
// { → Starts the main function.

    FullTimeEmployee f1(101, "Amit", "IT", 65000); 
    // FullTimeEmployee → Derived class name.
    // f1 → Name of the FullTimeEmployee object.
    // 101 → Employee ID.
    // "Amit" → Employee name.
    // "IT" → Department.
    // 65000 → Monthly salary.
    // ; → Ends the statement.

    PartTimeEmployee p1(102, "Sneha", "HR", 250, 120); 
    // PartTimeEmployee → Derived class name.
    // p1 → Name of the PartTimeEmployee object.
    // 102 → Employee ID.
    // "Sneha" → Employee name.
    // "HR" → Department.
    // 250 → Hourly rate.
    // 120 → Hours worked.
    // ; → Ends the statement.

    Intern i1(103, "Rohan", "Marketing", 15000); 
    // Intern → Derived class name.
    // i1 → Name of the Intern object.
    // 103 → Employee ID.
    // "Rohan" → Employee name.
    // "Marketing" → Department.
    // 15000 → Stipend amount.
    // ; → Ends the statement.

 
    cout << "=== Employee Payroll ===" << endl; 
    // cout → Displays output.
    // << → Output/insertion operator.
    // "=== Employee Payroll ===" → Displays the payroll heading.
    // endl → Moves the cursor to the next line.
    // ; → Ends the statement.

    f1.display(); 
    // f1 → Full-time employee object.
    // . → Member access operator.
    // display → Calls the display function.
    // ( ) → Calls the function without arguments.
    // ; → Ends the statement.

    p1.display(); 
    // p1 → Part-time employee object.
    // . → Member access operator.
    // display → Calls the display function.
    // ( ) → Calls the function without arguments.
    // ; → Ends the statement.

    i1.display(); 
    // i1 → Intern object.
    // . → Member access operator.
    // display → Calls the display function.
    // ( ) → Calls the function without arguments.
    // ; → Ends the statement.

} 
// } → Ends the main function.