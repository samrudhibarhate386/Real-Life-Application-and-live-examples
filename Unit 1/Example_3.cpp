//Real-Time Application 3: E-Commerce Product Catalog

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

 
class Product { 
// class → Defines a user-defined data type.
// Product → Name of the class.
// { → Starts the class body.

private: 
// private → Makes the following data members accessible only inside the class.

    int productId; 
    // int → Integer data type.
    // productId → Stores the unique ID of the product.
    // ; → Ends the declaration.

    string productName; 
    // string → Data type used to store text.
    // productName → Stores the name of the product.
    // ; → Ends the declaration.

    double price; 
    // double → Data type used to store decimal numbers.
    // price → Stores the price of the product.
    // ; → Ends the declaration.

    int stockQuantity; 
    // int → Integer data type.
    // stockQuantity → Stores the quantity of the product available in stock.
    // ; → Ends the declaration.

    static int totalProducts; 
    // static → Makes the data member shared by all Product objects.
    // int → Integer data type.
    // totalProducts → Stores the total number of Product objects.
    // ; → Ends the declaration.

 
public: 
// public → Makes the following members accessible from outside the class.

    Product(int id, string name, double p, int stock) 
    // Product → Constructor with the same name as the class.
    // int id → Parameter for receiving the product ID.
    // string name → Parameter for receiving the product name.
    // double p → Parameter for receiving the product price.
    // int stock → Parameter for receiving the stock quantity.
    // ( ) → Contains the constructor parameters.

        : productId(id), productName(name), price(p), stockQuantity(stock) { 
        // : → Starts the member initializer list.
        // productId(id) → Initializes productId using id.
        // productName(name) → Initializes productName using name.
        // price(p) → Initializes price using p.
        // stockQuantity(stock) → Initializes stockQuantity using stock.
        // { → Starts the constructor body.

        totalProducts++; 
        // totalProducts → Shared static variable.
        // ++ → Increment operator; increases the value by 1.
        // ; → Ends the statement.

    } 
    // } → Ends the constructor.

 
    inline int getId() const { return productId; } 
    // inline → Suggests that the compiler may replace the function call
    // with the function code for efficiency.
    // int → Function returns an integer.
    // getId → Name of the function.
    // ( ) → Function takes no parameters.
    // const → Function cannot modify the object.
    // { → Starts the function body.
    // return → Sends a value back from the function.
    // productId → Value returned by the function.
    // } → Ends the function.

    inline string getName() const { return productName; } 
    // inline → Suggests inline expansion of the function.
    // string → Function returns a string.
    // getName → Name of the function.
    // ( ) → Function takes no parameters.
    // const → Function cannot modify the object.
    // { → Starts the function body.
    // return → Sends a value back from the function.
    // productName → Value returned by the function.
    // } → Ends the function.

    inline double getPrice() const { return price; } 
    // inline → Suggests inline expansion of the function.
    // double → Function returns a decimal value.
    // getPrice → Name of the function.
    // ( ) → Function takes no parameters.
    // const → Function cannot modify the object.
    // { → Starts the function body.
    // return → Sends a value back from the function.
    // price → Value returned by the function.
    // } → Ends the function.

 
    void updateStock(int quantity) { 
    // void → Function does not return a value.
    // updateStock → Name of the function.
    // int quantity → Parameter containing the new stock quantity.
    // { → Starts the function body.

        stockQuantity = quantity; 
        // stockQuantity → Existing stock variable.
        // = → Assignment operator.
        // quantity → New stock quantity.
        // ; → Ends the statement.

    } 
    // } → Ends the updateStock function.

 
    static int getTotalProducts() { 
    // static → Function belongs to the class rather than a particular object.
    // int → Function returns an integer.
    // getTotalProducts → Name of the function.
    // ( ) → Function takes no parameters.
    // { → Starts the function body.

        return totalProducts; 
        // return → Sends a value back from the function.
        // totalProducts → Returns the current number of Product objects.
        // ; → Ends the statement.

    } 
    // } → Ends the getTotalProducts function.

 
    void display() const { 
    // void → Function does not return a value.
    // display → Name of the function.
    // ( ) → Function takes no parameters.
    // const → Function cannot modify the object.
    // { → Starts the function body.

        cout << "ID: " << productId 
        // cout → Displays output on the screen.
        // << → Output/insertion operator.
        // "ID: " → Displays the ID label.
        // productId → Displays the product ID.

             << " | Product: " << productName 
        // << → Sends the next value to cout.
        // " | Product: " → Displays the product label.
        // productName → Displays the product name.

             << " | Price: Rs. " << price 
        // " | Price: Rs. " → Displays the price label.
        // price → Displays the product price.

             << " | Stock: " << stockQuantity << endl; 
        // " | Stock: " → Displays the stock label.
        // stockQuantity → Displays the available stock.
        // endl → Moves the cursor to the next line.
        // ; → Ends the statement.

    } 
    // } → Ends the display function.

 
    ~Product() { 
    // ~ → Destructor symbol.
    // Product → Name of the class.
    // ~Product → Destructor of the Product class.
    // ( ) → Destructor takes no parameters.
    // { → Starts the destructor body.

        totalProducts--; 
        // totalProducts → Shared count of Product objects.
        // -- → Decrement operator; decreases the value by 1.
        // ; → Ends the statement.

    } 
    // } → Ends the destructor.

}; 
// } → Ends the Product class.
// ; → Ends the class definition.

 
int Product::totalProducts = 0; 
// int → Integer data type.
// Product → Class name.
// :: → Scope resolution operator.
// totalProducts → Static data member of the Product class.
// = → Assignment operator.
// 0 → Initial value of totalProducts.
// ; → Ends the statement.

 
int main() { 
// int → Specifies that main returns an integer.
// main → Starting point of the C++ program.
// ( ) → main function takes no parameters.
// { → Starts the main function.

    Product p1(1001, "Laptop", 55000, 15); 
    // Product → Class name.
    // p1 → Name of the first Product object.
    // ( ) → Contains constructor arguments.
    // 1001 → Product ID.
    // "Laptop" → Product name.
    // 55000 → Product price.
    // 15 → Stock quantity.
    // ; → Ends the statement.

    Product p2(1002, "Mouse", 450, 50); 
    // Product → Class name.
    // p2 → Name of the second Product object.
    // 1002 → Product ID.
    // "Mouse" → Product name.
    // 450 → Product price.
    // 50 → Stock quantity.
    // ; → Ends the statement.

    Product p3(1003, "Keyboard", 1200, 30); 
    // Product → Class name.
    // p3 → Name of the third Product object.
    // 1003 → Product ID.
    // "Keyboard" → Product name.
    // 1200 → Product price.
    // 30 → Stock quantity.
    // ; → Ends the statement.

    cout << "=== Product Catalog ===" << endl; 
    // cout → Displays output on the screen.
    // << → Output/insertion operator.
    // "=== Product Catalog ===" → Displays the catalog heading.
    // endl → Moves the cursor to the next line.
    // ; → Ends the statement.

    p1.display(); 
    // p1 → First Product object.
    // . → Member access operator.
    // display → Calls the display function.
    // ( ) → Calls the function without arguments.
    // ; → Ends the statement.

    p2.display(); 
    // p2 → Second Product object.
    // . → Member access operator.
    // display → Calls the display function.
    // ( ) → Calls the function without arguments.
    // ; → Ends the statement.

    p3.display(); 
    // p3 → Third Product object.
    // . → Member access operator.
    // display → Calls the display function.
    // ( ) → Calls the function without arguments.
    // ; → Ends the statement.

    cout << "\nTotal Products in Catalog: " 
    // cout → Displays output.
    // << → Output/insertion operator.
    // \n → Moves the output to a new line.
    // "Total Products in Catalog: " → Displays the total products label.

         << Product::getTotalProducts() << endl; 
    // Product → Class name.
    // :: → Scope resolution operator.
    // getTotalProducts → Static function of the Product class.
    // ( ) → Calls the static function without arguments.
    // << → Sends the returned value to cout.
    // endl → Moves the cursor to the next line.
    // ; → Ends the statement.

} 
// } → Ends the main function.