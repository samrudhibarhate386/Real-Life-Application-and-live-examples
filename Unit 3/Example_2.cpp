//Real-Time Application 2: Complex Number Calculator 

#include <iostream>  // Includes the input/output stream library for cout and endl.
using namespace std; // Allows us to use cout and endl without writing std::.

// Class representing a complex number.
class Complex {  // Defines a class named Complex.

private:  // Private members can only be accessed inside the Complex class.

    double real;  // Stores the real part of the complex number.
    double imag;  // Stores the imaginary part of the complex number.

public:  // Public members can be accessed from outside the class.

    // Constructor of the Complex class.
    // r and i have default values of 0.0.
    Complex(double r = 0.0, double i = 0.0)
        : real(r), imag(i) {}  // Initializes real with r and imag with i.

    // Overloads the + operator for addition of two Complex objects.
    Complex operator+(const Complex& other) const {

        // Adds the real parts and imaginary parts separately.
        // Returns a new Complex object containing the result.
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloads the - operator for subtraction of two Complex objects.
    Complex operator-(const Complex& other) const {

        // Subtracts the real parts and imaginary parts separately.
        // Returns a new Complex object containing the result.
        return Complex(real - other.real, imag - other.imag);
    }

    // Overloads the * operator for multiplication of two Complex objects.
    Complex operator*(const Complex& other) const {

        // Formula for multiplication of complex numbers:
        // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
        return Complex(

            // Calculates the real part of the product.
            real * other.real - imag * other.imag,

            // Calculates the imaginary part of the product.
            real * other.imag + imag * other.real
        );
    }

    // Overloads the == operator to compare two Complex objects.
    bool operator==(const Complex& other) const {

        // Checks whether both real parts AND both imaginary parts are equal.
        // && means logical AND.
        return real == other.real && imag == other.imag;
    }

    // Function used to display a complex number.
    void display() const {

        // Prints the real part, plus sign, imaginary part, and i.
        cout << real << " + " << imag << "i" << endl;
    }
};


// Main function - program execution starts here.
int main() {

    // Creates the first Complex object.
    // real = 3.0 and imaginary = 4.0.
    Complex c1(3.0, 4.0);

    // Creates the second Complex object.
    // real = 1.0 and imaginary = 2.0.
    Complex c2(1.0, 2.0);

    // Prints the label "C1: ".
    cout << "C1: ";

    // Displays the first complex number.
    c1.display();

    // Prints the label "C2: ".
    cout << "C2: ";

    // Displays the second complex number.
    c2.display();

    // Prints the label "Sum: ".
    cout << "Sum: ";

    // + operator is overloaded.
    // Adds c1 and c2 and displays the resulting Complex object.
    (c1 + c2).display();

    // Prints the label "Difference: ".
    cout << "Difference: ";

    // - operator is overloaded.
    // Subtracts c2 from c1 and displays the result.
    (c1 - c2).display();

    // Prints the label "Product: ".
    cout << "Product: ";

    // * operator is overloaded.
    // Multiplies c1 and c2 and displays the result.
    (c1 * c2).display();

    // Returns 0 to indicate successful program execution.
    return 0;
}