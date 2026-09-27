//Real-Time Application 2: Digital Payment Gateway

#include <iostream> 
// #include → Includes a library in the program.
// <iostream> → Provides input/output functions such as cout and cin.

#include <memory> 
// #include → Includes a library in the program.
// <memory> → Provides smart pointers such as unique_ptr and make_unique.

#include <string> 
// #include → Includes a library in the program.
// <string> → Provides the string data type for storing text.

#include <vector> 
// #include → Includes a library in the program.
// <vector> → Provides the vector container for storing multiple elements.

using namespace std; 
// using → Allows direct use of names from a namespace.
// namespace → Groups related identifiers.
// std → Standard C++ namespace.
// ; → Ends the statement.

 
class PaymentMethod { 
// class → Defines a user-defined data type.
// PaymentMethod → Name of the class.
// { → Starts the class body.

protected: 
// protected → Makes members accessible inside this class
// and its derived classes.

    string transactionId; 
    // string → Data type used to store text.
    // transactionId → Stores the unique transaction ID.
    // ; → Ends the declaration.

    double amount; 
    // double → Data type used to store decimal numbers.
    // amount → Stores the payment amount.
    // ; → Ends the declaration.

 
public: 
// public → Makes the following members accessible from outside the class.

    PaymentMethod(string tid, double amt) 
    // PaymentMethod → Constructor of the PaymentMethod class.
    // string tid → Parameter used to receive the transaction ID.
    // double amt → Parameter used to receive the payment amount.
    // ( ) → Contains the constructor parameters.

        : transactionId(tid), amount(amt) {} 
        // : → Starts the member initializer list.
        // transactionId(tid) → Initializes transactionId using tid.
        // amount(amt) → Initializes amount using amt.
        // { } → Empty constructor body.

 
    virtual bool processPayment() const = 0; 
    // virtual → Allows derived classes to provide their own implementation.
    // bool → Function returns true or false.
    // processPayment → Name of the function.
    // ( ) → Function takes no parameters.
    // const → Function cannot modify the object.
    // = 0 → Makes the function a pure virtual function.
    // ; → Ends the function declaration.

    virtual ~PaymentMethod() = default; 
    // virtual → Allows the destructor to work correctly with inheritance.
    // ~PaymentMethod → Destructor of the PaymentMethod class.
    // ( ) → Destructor takes no parameters.
    // = default → Uses the compiler-generated default destructor.
    // ; → Ends the statement.

}; 
// } → Ends the PaymentMethod class.
// ; → Ends the class definition.

 
class CreditCardPayment : public PaymentMethod { 
// class → Defines a new class.
// CreditCardPayment → Name of the derived class.
// : → Indicates inheritance.
// public → Specifies public inheritance.
// PaymentMethod → Base/parent class.
// { → Starts the class body.

private: 
// private → Makes the following member accessible only inside this class.

    string maskedCardNumber; 
    // string → Data type used to store text.
    // maskedCardNumber → Stores the masked credit card number.
    // ; → Ends the declaration.

 
public: 
// public → Makes the following members accessible from outside the class.

    CreditCardPayment(string tid, double amt, string card) 
    // CreditCardPayment → Constructor of the derived class.
    // string tid → Transaction ID parameter.
    // double amt → Payment amount parameter.
    // string card → Masked card number parameter.

        : PaymentMethod(tid, amt), maskedCardNumber(card) {} 
        // : → Starts the member initializer list.
        // PaymentMethod(tid, amt) → Calls the parent class constructor.
        // maskedCardNumber(card) → Initializes maskedCardNumber.
        // { } → Empty constructor body.

 
    bool processPayment() const override { 
    // bool → Function returns true or false.
    // processPayment → Function name.
    // const → Function cannot modify the object.
    // override → Indicates that this function overrides
    // the pure virtual function from PaymentMethod.
    // { → Starts the function body.

        cout << "Credit-card transaction " << transactionId 
        // cout → Displays output on the screen.
        // << → Output/insertion operator.
        // "Credit-card transaction " → Displays transaction text.
        // transactionId → Displays the transaction ID.

             << " for Rs. " << amount 
        // " for Rs. " → Displays the currency label.
        // amount → Displays the payment amount.

             << " using " << maskedCardNumber << " completed." << endl; 
        // " using " → Displays the payment method text.
        // maskedCardNumber → Displays the masked card number.
        // " completed." → Displays the completion message.
        // endl → Moves the cursor to the next line.
        // ; → Ends the statement.

        return true; 
        // return → Sends a value back from the function.
        // true → Indicates that the payment was successful.
        // ; → Ends the statement.

    } 
    // } → Ends the processPayment function.

}; 
// } → Ends the CreditCardPayment class.
// ; → Ends the class definition.

 
class UPIPayment : public PaymentMethod { 
// class → Defines a new class.
// UPIPayment → Name of the derived class.
// : → Indicates inheritance.
// public → Specifies public inheritance.
// PaymentMethod → Base/parent class.
// { → Starts the class body.

private: 
// private → Makes the following member accessible only inside this class.

    string upiId; 
    // string → Data type used to store text.
    // upiId → Stores the UPI ID.
    // ; → Ends the declaration.

 
public: 
// public → Makes the following members accessible from outside the class.

    UPIPayment(string tid, double amt, string upi) 
    // UPIPayment → Constructor of the derived class.
    // string tid → Transaction ID parameter.
    // double amt → Payment amount parameter.
    // string upi → UPI ID parameter.

        : PaymentMethod(tid, amt), upiId(upi) {} 
        // : → Starts the member initializer list.
        // PaymentMethod(tid, amt) → Calls the parent class constructor.
        // upiId(upi) → Initializes upiId.
        // { } → Empty constructor body.

 
    bool processPayment() const override { 
    // bool → Function returns true or false.
    // processPayment → Function name.
    // const → Function cannot modify the object.
    // override → Overrides the function from the parent class.
    // { → Starts the function body.

        cout << "UPI transaction " << transactionId 
        // cout → Displays output.
        // << → Output/insertion operator.
        // "UPI transaction " → Displays transaction text.
        // transactionId → Displays the transaction ID.

             << " for Rs. " << amount 
        // " for Rs. " → Displays the currency label.
        // amount → Displays the payment amount.

             << " from " << upiId << " completed." << endl; 
        // " from " → Displays the source label.
        // upiId → Displays the UPI ID.
        // " completed." → Displays the completion message.
        // endl → Moves the cursor to the next line.
        // ; → Ends the statement.

        return true; 
        // return → Sends a value back from the function.
        // true → Indicates successful payment.
        // ; → Ends the statement.

    } 
    // } → Ends the processPayment function.

}; 
// } → Ends the UPIPayment class.
// ; → Ends the class definition.

 
class NetBankingPayment : public PaymentMethod { 
// class → Defines a new class.
// NetBankingPayment → Name of the derived class.
// : → Indicates inheritance.
// public → Specifies public inheritance.
// PaymentMethod → Base/parent class.
// { → Starts the class body.

private: 
// private → Makes the following member accessible only inside this class.

    string bankName; 
    // string → Data type used to store text.
    // bankName → Stores the name of the bank.
    // ; → Ends the declaration.

 
public: 
// public → Makes the following members accessible from outside the class.

    NetBankingPayment(string tid, double amt, string bank) 
    // NetBankingPayment → Constructor of the derived class.
    // string tid → Transaction ID parameter.
    // double amt → Payment amount parameter.
    // string bank → Bank name parameter.

        : PaymentMethod(tid, amt), bankName(bank) {} 
        // : → Starts the member initializer list.
        // PaymentMethod(tid, amt) → Calls the parent class constructor.
        // bankName(bank) → Initializes bankName.
        // { } → Empty constructor body.

 
    bool processPayment() const override { 
    // bool → Function returns true or false.
    // processPayment → Function name.
    // const → Function cannot modify the object.
    // override → Overrides the function from the parent class.
    // { → Starts the function body.

        cout << "Net-banking transaction " << transactionId 
        // cout → Displays output.
        // << → Output/insertion operator.
        // "Net-banking transaction " → Displays transaction text.
        // transactionId → Displays the transaction ID.

             << " for Rs. " << amount 
        // " for Rs. " → Displays the currency label.
        // amount → Displays the payment amount.

             << " through " << bankName << " completed." << endl; 
        // " through " → Displays the payment source.
        // bankName → Displays the bank name.
        // " completed." → Displays the completion message.
        // endl → Moves the cursor to the next line.
        // ; → Ends the statement.

        return true; 
        // return → Sends a value back from the function.
        // true → Indicates successful payment.
        // ; → Ends the statement.

    } 
    // } → Ends the processPayment function.

}; 
// } → Ends the NetBankingPayment class.
// ; → Ends the class definition.

 
int main() { 
// int → Specifies that main returns an integer.
// main → Starting point of the C++ program.
// ( ) → main takes no parameters.
// { → Starts the main function.

    vector<unique_ptr<PaymentMethod>> payments; 
    // vector → Container used to store multiple elements.
    // < > → Specifies the type stored inside the vector.
    // unique_ptr → Smart pointer that owns one dynamically allocated object.
    // <PaymentMethod> → Smart pointers point to PaymentMethod objects.
    // payments → Name of the vector.
    // ; → Ends the declaration.

    payments.push_back(make_unique<CreditCardPayment>("TXN001", 2500, "XXXX-XXXX-1234")); 
    // payments → Vector storing payment objects.
    // . → Member access operator.
    // push_back → Adds an element to the end of the vector.
    // make_unique → Creates a unique_ptr automatically.
    // <CreditCardPayment> → Creates a CreditCardPayment object.
    // "TXN001" → Transaction ID.
    // 2500 → Payment amount.
    // "XXXX-XXXX-1234" → Masked card number.
    // ; → Ends the statement.

    payments.push_back(make_unique<UPIPayment>("TXN002", 1200, "student@upi")); 
    // payments → Vector of payment smart pointers.
    // . → Member access operator.
    // push_back → Adds an element to the vector.
    // make_unique → Creates a unique_ptr.
    // <UPIPayment> → Creates a UPIPayment object.
    // "TXN002" → Transaction ID.
    // 1200 → Payment amount.
    // "student@upi" → UPI ID.
    // ; → Ends the statement.

    payments.push_back(make_unique<NetBankingPayment>("TXN003", 5000, "Example Bank")); 
    // payments → Vector of payment smart pointers.
    // . → Member access operator.
    // push_back → Adds an element to the vector.
    // make_unique → Creates a unique_ptr.
    // <NetBankingPayment> → Creates a NetBankingPayment object.
    // "TXN003" → Transaction ID.
    // 5000 → Payment amount.
    // "Example Bank" → Bank name.
    // ; → Ends the statement.

 
    cout << "=== Payment Gateway ===" << endl; 
    // cout → Displays output.
    // << → Output/insertion operator.
    // "=== Payment Gateway ===" → Displays the heading.
    // endl → Moves the cursor to the next line.
    // ; → Ends the statement.

    for (const auto& payment : payments) { 
    // for → Starts a loop.
    // const → Prevents modification of the current smart pointer.
    // auto → Automatically determines the data type.
    // & → Creates a reference instead of making a copy.
    // payment → Represents the current payment smart pointer.
    // : → Separates the loop variable from the collection.
    // payments → Vector being traversed.
    // { → Starts the loop body.

        payment->processPayment(); 
        // payment → Current unique_ptr.
        // -> → Accesses a member through a pointer.
        // processPayment → Calls the payment processing function.
        // ( ) → Calls the function without arguments.
        // ; → Ends the statement.

    } 
    // } → Ends the for loop.

} 
// } → Ends the main function.