//Real-Time Application 3: Binary File for Fixed-Size Records 

#include <cstring>   // Includes C-style string functions such as strcpy().
#include <fstream>   // Provides file handling classes such as ifstream and ofstream.
#include <iostream>  // Provides input/output functions such as cout, cerr, and endl.
using namespace std; // Allows us to use cout, cerr, etc. without writing std::.

// Structure used to store image metadata.
struct ImageMetadata {

    int width;       // Stores the width of the image in pixels.
    int height;      // Stores the height of the image in pixels.
    char format[10]; // Character array used to store the image format.
};


// Main function.
// Program execution starts from here.
int main() {

    // Creates the first ImageMetadata object.
    // width = 1920, height = 1080, format = "PNG".
    ImageMetadata image1{1920, 1080, "PNG"};

    // Creates the second ImageMetadata object.
    // width = 1280, height = 720, format = "JPEG".
    ImageMetadata image2{1280, 720, "JPEG"};

    // Creates the third ImageMetadata object.
    // width = 3840, height = 2160, format = "PNG".
    ImageMetadata image3{3840, 2160, "PNG"};


    // Creates an output file stream named output.
    // "images.bin" is the binary file.
    // ios::binary opens the file in binary mode.
    ofstream output("images.bin", ios::binary);

    // Checks whether the binary file was successfully opened.
    if (!output) {

        // Displays an error message if the file could not be opened.
        cerr << "Unable to open binary file for writing." << endl;

        // Returns 1 to indicate that an error occurred.
        return 1;
    }


    // Writes image1 directly into the binary file.
    //
    // reinterpret_cast<const char*>(&image1)
    // converts the address of image1 into a pointer to characters.
    //
    // &image1 means the memory address of image1.
    //
    // sizeof(ImageMetadata) returns the number of bytes occupied
    // by one ImageMetadata object.
    output.write(
        reinterpret_cast<const char*>(&image1),
        sizeof(ImageMetadata)
    );

    // Writes image2 into the binary file.
    output.write(
        reinterpret_cast<const char*>(&image2),
        sizeof(ImageMetadata)
    );

    // Writes image3 into the binary file.
    output.write(
        reinterpret_cast<const char*>(&image3),
        sizeof(ImageMetadata)
    );

    // Closes the binary file after writing all three records.
    output.close();


    // Creates an input file stream named input.
    // Opens images.bin in binary reading mode.
    ifstream input("images.bin", ios::binary);

    // Checks whether the binary file was successfully opened.
    if (!input) {

        // Displays an error message if the file could not be opened.
        cerr << "Unable to open binary file for reading." << endl;

        // Returns 1 to indicate that an error occurred.
        return 1;
    }


    // Creates an ImageMetadata object named item.
    // {} value-initializes the object.
    ImageMetadata item{};

    // Stores the record number.
    // The first record starts at 1.
    int recordNo = 1;

    // Prints the heading of the output.
    cout << "=== Image Metadata ===" << endl;


    // Reads one ImageMetadata record from the binary file at a time.
    //
    // input.read() reads raw binary data from the file.
    //
    // reinterpret_cast<char*>(&item)
    // converts the address of item into a character pointer
    // so that binary data can be written directly into its memory.
    //
    // sizeof(ImageMetadata) specifies how many bytes to read.
    //
    // The while loop continues as long as reading succeeds.
    while (
        input.read(
            reinterpret_cast<char*>(&item),
            sizeof(ImageMetadata)
        )
    ) {

        // Prints the current record number.
        cout << "Record "

             // Prints the value of recordNo and then increases it by 1.
             // recordNo++ is the post-increment operator.
             << recordNo++

             // Prints a colon and space.
             << ": "

             // Prints the image width.
             << item.width

             // Prints the multiplication-style separator.
             << " x "

             // Prints the image height.
             << item.height

             // Prints a separator before the image format.
             << " | "

             // Prints the image format stored in the character array.
             << item.format

             // Moves the cursor to the next line.
             << endl;
    }

    // Closes the binary input file.
    input.close();

    // Returns 0 to indicate successful program execution.
    return 0;
}