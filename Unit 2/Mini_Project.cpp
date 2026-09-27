#include <iostream>                         // Includes the input/output stream library for cout and endl.
#include <string>                           // Includes the string data type.
#include <vector>                           // Includes the vector container.
#include <memory>                           // Includes smart pointers such as unique_ptr.
#include <iomanip>                          // Includes formatting tools such as fixed and setprecision.

using namespace std;                        // Allows us to use standard library names without writing std::.

// Base class representing a general bank account.
class Account {
protected:
    string accountNumber;                   // Stores the unique account number.
    string holderName;                      // Stores the name of the account holder.
    double balance;                          // Stores the current account balance.

public:
    // Constructor used to initialize the account details.
    Account(string accNo, string name, double initialBalance)
        : accountNumber(accNo),             // Initializes accountNumber with accNo.
          holderName(name),                 // Initializes holderName with name.
          balance(initialBalance) {}        // Initializes balance with initialBalance.

    // Virtual destructor allows proper destruction of derived-class objects.
    virtual ~Account() = default;

    // Virtual function for depositing money into the account.
    virtual void deposit(double amount) {
        if (amount > 0) {                    // Checks whether the deposit amount is positive.
            balance += amount;               // Adds the deposit amount to the balance.
            cout << "Deposited: Rs. "       // Displays the deposited amount.
                 << fixed << setprecision(2)
                 << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl; // Displays an error for invalid amount.
        }
    }

    // Virtual function for withdrawing money from the account.
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) { // Checks amount and available balance.
            balance -= amount;               // Subtracts the withdrawal amount.
            cout << "Withdrawn: Rs. "
                 << fixed << setprecision(2)
                 << amount << endl;
        } else {
            cout << "Invalid withdrawal or insufficient balance." << endl;
        }
    }

    // Pure virtual function for calculating account-specific interest.
    // Different account types will implement this differently.
    virtual double calculateInterest() const = 0;

    // Virtual function for displaying account information.
    virtual void displayAccount() const {
        cout << "\nAccount Number: " << accountNumber // Displays account number.
             << "\nHolder Name: " << holderName       // Displays holder name.
             << "\nBalance: Rs. "                     // Displays balance label.
             << fixed << setprecision(2)
             << balance << endl;                     // Displays balance with 2 decimal places.
    }

    // Returns the account number.
    string getAccountNumber() const {
        return accountNumber;                  // Sends the account number back to the caller.
    }

    // Returns the current balance.
    double getBalance() const {
        return balance;                       // Sends the balance back to the caller.
    }
};


// Derived class representing a Savings Account.
class SavingsAccount : public Account {
private:
    double interestRate;                     // Stores the annual interest rate.

public:
    // Constructor for SavingsAccount.
    SavingsAccount(string accNo, string name, double initialBalance, double rate)
        : Account(accNo, name, initialBalance), // Calls the base-class constructor.
          interestRate(rate) {}                 // Initializes the interest rate.

    // Overrides the interest calculation for a savings account.
    double calculateInterest() const override {
        return balance * interestRate / 100;  // Calculates interest using simple percentage.
    }

    // Overrides the display function.
    void displayAccount() const override {
        cout << "\n===== Savings Account =====" << endl;

        Account::displayAccount();            // Calls the base-class display function.

        cout << "Interest Rate: "
             << interestRate << "%" << endl;

        cout << "Calculated Interest: Rs. "
             << fixed << setprecision(2)
             << calculateInterest() << endl;
    }
};


// Derived class representing a Current Account.
class CurrentAccount : public Account {
private:
    double overdraftLimit;                   // Stores the maximum allowed overdraft amount.

public:
    // Constructor for CurrentAccount.
    CurrentAccount(string accNo, string name, double initialBalance, double limit)
        : Account(accNo, name, initialBalance), // Calls the base-class constructor.
          overdraftLimit(limit) {}              // Initializes overdraft limit.

    // Overrides withdrawal because current accounts may allow overdrafts.
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance + overdraftLimit) {
            balance -= amount;                // Deducts the amount from the balance.
            cout << "Withdrawn: Rs. "
                 << fixed << setprecision(2)
                 << amount << endl;

            // Checks whether the account is using overdraft.
            if (balance < 0) {
                cout << "Overdraft used: Rs. "
                     << fixed << setprecision(2)
                     << -balance << endl;
            }
        } else {
            cout << "Withdrawal exceeds overdraft limit." << endl;
        }
    }

    // Current accounts do not provide regular interest in this example.
    double calculateInterest() const override {
        return 0.0;                           // Returns zero interest.
    }

    // Overrides the display function.
    void displayAccount() const override {
        cout << "\n===== Current Account =====" << endl;

        Account::displayAccount();             // Displays common account information.

        cout << "Overdraft Limit: Rs. "
             << fixed << setprecision(2)
             << overdraftLimit << endl;

        cout << "Calculated Interest: Rs. "
             << fixed << setprecision(2)
             << calculateInterest() << endl;
    }
};


// Derived class representing a Fixed Deposit Account.
class FixedDepositAccount : public Account {
private:
    double interestRate;                      // Stores the fixed deposit interest rate.
    int durationYears;                        // Stores the FD duration in years.

public:
    // Constructor for FixedDepositAccount.
    FixedDepositAccount(string accNo, string name, double initialBalance,
                        double rate, int years)
        : Account(accNo, name, initialBalance), // Calls the base-class constructor.
          interestRate(rate),                   // Initializes interest rate.
          durationYears(years) {}               // Initializes duration.

    // Overrides withdrawal because fixed deposits generally have restrictions.
    void withdraw(double amount) override {
        cout << "Withdrawal is not allowed from Fixed Deposit before maturity."
             << endl;                           // Displays restriction message.
    }

    // Calculates interest according to FD rate and duration.
    double calculateInterest() const override {
        return balance * interestRate * durationYears / 100;
    }

    // Overrides the display function.
    void displayAccount() const override {
        cout << "\n===== Fixed Deposit Account =====" << endl;

        Account::displayAccount();             // Displays common account information.

        cout << "Interest Rate: "
             << interestRate << "%" << endl;

        cout << "Duration: "
             << durationYears << " years" << endl;

        cout << "Maturity Interest: Rs. "
             << fixed << setprecision(2)
             << calculateInterest() << endl;

        cout << "Maturity Amount: Rs. "
             << fixed << setprecision(2)
             << balance + calculateInterest() << endl;
    }
};


// Main function where program execution begins.
int main() {

    // Creates a vector that stores smart pointers to Account objects.
    vector<unique_ptr<Account>> accounts;

    // Creates a SavingsAccount object and stores it in the vector.
    accounts.push_back(
        make_unique<SavingsAccount>(
            "SA101",                    // Savings account number.
            "Rahul Patil",              // Account holder name.
            50000.0,                    // Initial balance.
            6.5                         // Annual interest rate.
        )
    );

    // Creates a CurrentAccount object and stores it in the vector.
    accounts.push_back(
        make_unique<CurrentAccount>(
            "CA202",                    // Current account number.
            "Priya Sharma",             // Account holder name.
            30000.0,                    // Initial balance.
            10000.0                     // Overdraft limit.
        )
    );

    // Creates a FixedDepositAccount object and stores it in the vector.
    accounts.push_back(
        make_unique<FixedDepositAccount>(
            "FD303",                    // Fixed deposit account number.
            "Amit Kulkarni",            // Account holder name.
            100000.0,                   // Initial deposit.
            7.5,                        // Annual interest rate.
            3                           // FD duration in years.
        )
    );

    // Displays a heading for account operations.
    cout << "========== BANKING SYSTEM ==========" << endl;

    // Deposits money into the first account.
    cout << "\n--- Deposit Operation ---" << endl;
    accounts[0]->deposit(5000.0);

    // Withdraws money from the first account.
    cout << "\n--- Withdrawal Operation ---" << endl;
    accounts[0]->withdraw(2000.0);

    // Attempts to withdraw money from the fixed deposit account.
    cout << "\n--- Fixed Deposit Withdrawal ---" << endl;
    accounts[2]->withdraw(5000.0);

    // Displays all account information.
    cout << "\n========== ACCOUNT DASHBOARD ==========" << endl;

    // Range-based for loop visits every account in the vector.
    for (const auto& account : accounts) {

        // Calls the appropriate overridden displayAccount()
        // function using runtime polymorphism.
        account->displayAccount();

        cout << "--------------------------------------" << endl;
    }

    // Displays a message before calculating interest.
    cout << "\n========== INTEREST SUMMARY ==========" << endl;

    // Loops through all accounts again.
    for (const auto& account : accounts) {

        // Displays the account number.
        cout << "Account: "
             << account->getAccountNumber();

        // Calls the correct calculateInterest() function
        // depending on the actual account type.
        cout << " | Interest: Rs. "
             << fixed << setprecision(2)
             << account->calculateInterest()
             << endl;
    }

    // unique_ptr automatically releases dynamically allocated memory.
    return 0;                               // Indicates successful completion of the program.
}