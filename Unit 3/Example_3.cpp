//Real-Time Application 3: Input Validation Service

#include <cctype>   // Includes character checking functions such as isalpha().
#include <iostream> // Includes input/output functions such as cout and endl.
#include <string>   // Includes the string data type.
using namespace std; // Allows us to use cout, string, endl, etc. without writing std::.

// Defines a class named Validator.
class Validator {

public: // Makes the following functions accessible outside the class.

    // Validates an integer value representing marks.
    bool validate(int marks) const {

        // Checks whether marks are greater than or equal to 0
        // AND less than or equal to 100.
        // Returns true if both conditions are satisfied.
        return marks >= 0 && marks <= 100;
    }

    // Validates a double value representing an amount.
    // This is function overloading because validate() already exists
    // with a different parameter type.
    bool validate(double amount) const {

        // Checks whether amount is greater than 0
        // AND less than or equal to 1,000,000.
        return amount > 0.0 && amount <= 1000000.0;
    }

    // Validates a string representing a person's name.
    // This is another overloaded version of validate().
    bool validate(const string& name) const {

        // Checks whether the name contains no characters.
        if (name.empty()) {

            // Returns false because an empty name is invalid.
            return false;
        }

        // Range-based for loop.
        // Goes through every character stored in the name string.
        for (char ch : name) {

            // isalpha() checks whether ch is an alphabetic character.
            // static_cast<unsigned char>(ch) safely converts ch to unsigned char.
            // ! means NOT.
            // Therefore, !isalpha(...) means the character is NOT a letter.
            // ch != ' ' checks that the character is not a space.
            // && means both conditions must be true.
            if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ') {

                // If the character is neither a letter nor a space,
                // the name is invalid.
                return false;
            }
        }

        // If every character is valid, return true.
        return true;
    }
};


// Main function.
// Program execution starts from here.
int main() {

    // Creates an object named validator
    // from the Validator class.
    Validator validator;

    // boolalpha makes boolean values display as
    // "true" and "false" instead of 1 and 0.
    cout << boolalpha;

    // Calls validate(int) because 88 is an integer.
    // 88 is between 0 and 100, so the result is true.
    cout << "Marks 88 valid: "
         << validator.validate(88)
         << endl;

    // Calls validate(int) because 120 is an integer.
    // 120 is greater than 100, so the result is false.
    cout << "Marks 120 valid: "
         << validator.validate(120)
         << endl;

    // Calls validate(double) because 4500.50 is a double value.
    // The amount is within the valid range, so the result is true.
    cout << "Amount 4500.50 valid: "
         << validator.validate(4500.50)
         << endl;

    // Prints the label for Priya Sharma validation.
    cout << "Name Priya Sharma valid: "

         // Creates a string containing "Priya Sharma".
         // Calls validate(const string&) because the argument is a string.
         << validator.validate(string("Priya Sharma"))

         // Moves the cursor to the next line.
         << endl;

    // Prints the label for Priya123 validation.
    cout << "Name Priya123 valid: "

         // Creates a string containing "Priya123".
         // The numbers 1, 2, and 3 are not alphabetic characters,
         // so the validation returns false.
         << validator.validate(string("Priya123"))

         // Moves the cursor to the next line.
         << endl;

    // Returns 0 to indicate successful program execution.
    return 0;
}