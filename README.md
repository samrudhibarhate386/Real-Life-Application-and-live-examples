# Real Life Application and Live Examples

## Student Information

- **Student Name:** Samrudhi Barhate
- **PRN:** ___125UAD1223_______________
- **Class / Division:** _____SY , E_____________
- **Course Name:** Artificial Intelligence and Data science
- **Programming Language:** C++

---

## Course Overview

| Unit | Program 1 | Program 2 | Program 3 | Mini Project |
|---|---|---|---|---|
| **Unit 1 – Fundamentals of Object Oriented Programming** | Smart Agriculture Sensor Monitor | Student Attendance Tracker | E-Commerce Product Catalog | **Smart Home Device Manager** |
| **Unit 2 – Inheritance** | Employee Payroll System | Payment Gateway | Vehicle Fleet Management | **Banking System with Account Hierarchy** |
| **Unit 3 – Polymorphism** | CAD Shape Drawing System | Complex Number Calculator | Input Validation Service | **Media Player with Polymorphic Controls** |
| **Unit 4 – Files and Streams** | Student Record File System | Log Analyzer | Binary File for Fixed-Size Records | **Library Book Management System** |

---

# Unit 1 – Fundamentals of Object Oriented Programming

## Programs

### 1. Smart Agriculture Sensor Monitor

**Description:**  
A smart farm sensor monitoring application that represents soil-moisture, temperature, and humidity sensors as objects. It stores sensor IDs, readings, and timestamps and allows sensor readings to be updated and displayed.

**Concepts Used:**
- Classes and objects
- Encapsulation
- Parameterized constructors
- Member functions
- Vector of objects
- Range-based loops

### 2. Student Attendance Tracker

**Description:**  
A student attendance application that stores student names and attendance details and generates an attendance report.

**Concepts Used:**
- Classes and objects
- Constructors
- Member functions
- Encapsulation
- Object-based data management

### 3. E-Commerce Product Catalog

**Description:**  
An online store product catalog that maintains product ID, product name, price, and stock quantity. A static member keeps track of the number of active product objects.

**Concepts Used:**
- Classes and objects
- Static data members
- Static member functions
- Inline accessor functions
- Constructors and destructors
- Encapsulation

## Mini Project – Smart Home Device Manager

**Description:**  
A smart home application that models devices such as lights, thermostats, cameras, and door locks. Each device contains a device ID, location, status, and last-updated time. The system supports switching devices on or off, changing status, and displaying an overall home dashboard.

---

# Unit 2 – Inheritance

## Programs

### 1. Employee Payroll System

**Description:**  
A payroll system for full-time employees, part-time employees, and interns. Common employee information is maintained in a base class while salary calculation varies according to the employee type.

**Concepts Used:**
- Base and derived classes
- Protected members
- Hierarchical inheritance
- Constructor chaining
- Function overriding
- Abstract base class

### 2. Payment Gateway

**Description:**  
A payment gateway that supports different payment methods such as credit cards, UPI, and net banking. All payment methods share a common interface while implementing their own payment processing behavior.

**Concepts Used:**
- Abstract classes
- Hierarchical inheritance
- Pure virtual functions
- Virtual destructors
- Runtime polymorphism

### 3. Vehicle Fleet Management

**Description:**  
A logistics fleet management system for trucks, delivery vans, and delivery bikes. Common vehicle information is maintained in a base class while each vehicle type has specialized properties.

**Concepts Used:**
- Inheritance
- Base and derived classes
- Protected members
- Function overriding
- Runtime polymorphism
- Smart pointers

## Mini Project – Banking System with Account Hierarchy

**Description:**  
A banking system with a base `Account` class and derived classes `SavingsAccount`, `CurrentAccount`, and `FixedDepositAccount`. The system includes account number, holder name, balance, deposit, withdrawal, and interest-calculation features using virtual functions for account-specific behavior.

---

# Unit 3 – Polymorphism

## Programs

### 1. CAD Shape Drawing System

**Description:**  
A computer-aided design system that handles circles, rectangles, and triangles. Each shape can be drawn and its area can be calculated through a common base-class interface.

**Concepts Used:**
- Abstract base classes
- Pure virtual functions
- Runtime polymorphism
- Vector of smart pointers
- Virtual destructors

### 2. Complex Number Calculator

**Description:**  
A calculator for performing arithmetic operations on complex numbers. Operator overloading allows addition, subtraction, multiplication, and comparison of complex number objects using natural operators.

**Concepts Used:**
- Binary operator overloading
- Constructor with default arguments
- Constant member functions
- Encapsulation

### 3. Input Validation Service

**Description:**  
A business application that validates different types of user data such as marks, names, and payment amounts using a common `validate()` interface.

**Concepts Used:**
- Function overloading
- Encapsulation
- Input validation
- Multiple function signatures

## Mini Project – Media Player with Polymorphic Controls

**Description:**  
A media player system with a base `Media` class and derived classes `Audio`, `Video`, and `Image`. It provides operations such as `play()`, `pause()`, `stop()`, and `showDetails()` and manages media items using a collection of base-class pointers.

---

# Unit 4 – Files and Streams

## Programs

### 1. Student Record File System

**Description:**  
A college student record system that stores student data in a CSV-like text file. The application writes student records to a file and reads them back to generate a report.

**Concepts Used:**
- `ofstream`
- `ifstream`
- Text-file writing and reading
- File-open validation
- Class methods
- `getline()` parsing

### 2. Log Analyzer

**Description:**  
A server log analysis application that reads log entries from a text file and identifies important events such as errors and critical events. It then generates a report of the critical log events.

**Concepts Used:**
- File reading
- Text-file processing
- String searching
- `find()`
- Vectors
- Log analysis

### 3. Binary File for Fixed-Size Records

**Description:**  
A multimedia or embedded application that stores fixed-size image metadata records in a binary file for compact storage and sequential retrieval.

**Concepts Used:**
- Binary file mode
- `write()` and `read()`
- Fixed-size structures
- Binary data storage
- Sequential record retrieval

## Mini Project – Library Book Management System

**Description:**  
A library management system that stores book details such as ISBN, title, author, category, and availability in a text file. The system supports adding, searching, issuing, returning, updating, and generating an availability report.

---

# Technologies Used

- **Programming Language:** C++
- **Compiler:** C++17 or newer
- **IDE:** Visual Studio Code
- **Version Control:** Git
- **Repository Hosting:** GitHub

---

# Repository Structure

```text
Real Life Application and live examples/
│
├── Unit 1/
│   ├── Smart Agriculture Sensor Monitor
│   ├── Student Attendance Tracker
│   ├── E-Commerce Product Catalog
│   └── Smart Home Device Manager
│
├── Unit 2/
│   ├── Employee Payroll System
│   ├── Payment Gateway
│   ├── Vehicle Fleet Management
│   └── Banking System with Account Hierarchy
│
├── Unit 3/
│   ├── CAD Shape Drawing System
│   ├── Complex Number Calculator
│   ├── Input Validation Service
│   └── Media Player with Polymorphic Controls
│
└── Unit 4/
    ├── Student Record File System
    ├── Log Analyzer
    ├── Binary File for Fixed-Size Records
    └── Library Book Management System
