#include<iostream>
#include<stdlib.h>
#include<limits>

// Standard namespace declaration
using namespace std;

// A method to output the passed in string.
void output(std::string output);

// A method get the user's input of an integer and set it to the passed in pointer.
void getInput(int* number);

// A method to do a special output based on the passed in integer pointer.
void outputPointerInformation(int* pointer, std::string valueName);

int main(int argc, const char * argv[]) {
    // Declare the integer values.
    int firstNumber;
    int secondNumber;
    int thirdNumber;
    
    try {
        // Get the input from the user
        getInput(&firstNumber);
        getInput(&secondNumber);
        getInput(&thirdNumber);
        
        // Create integer pointers in dynamic memory
        int* ptr = new int;
        int* ptr2 = new int;
        int* ptr3 = new int;
        
        // Set the pointers to the values of the initial variables
        *ptr = firstNumber;
        *ptr2 = secondNumber;
        *ptr3 = thirdNumber;
        
        // Output to the user the values of the variables
        output("The first number's value is: " + std::to_string(firstNumber));
        output("The second number's value is: " + std::to_string(secondNumber));
        output("The third number's value is: " + std::to_string(thirdNumber));
        
        // Output to the user the pointer values and their memory addresses.
        outputPointerInformation(ptr, "first number");
        outputPointerInformation(ptr2, "second number");
        outputPointerInformation(ptr3, "third number");
        
        // Release the dynamic memory
        delete ptr;
        delete ptr2;
        delete ptr3;
        
    // Catch standard exceptions and output an error string and what the exception is
    } catch(std::exception& e) {
        cout<< "There was an exception thrown: "<< e.what() <<endl;
        
    // Catch unexpected non standard exceptions and output an error string
    } catch (...) {
        cout<< "There was an unknown exception thrown."<<endl;
    }
    
    return 0;
}

void output(std::string output) {
    std::cout<< output<<endl;
}

void outputPointerInformation(int* pointer, std::string valueName) {
    // Output the address of the pointer and the value.
    std::cout<<"The address of the " << valueName << ": " << &pointer <<endl;
    std::cout<<"The value of the " << valueName << ": " << *pointer <<endl;
}

void getInput(int* number) {
    // Declare methods parameters
    bool hasValidInput = false;
    string errorString = "Value entered is not a valid interger. Please try again.";
    
    // While the user has not entered a valid input, keep prompting them for one
    while (!hasValidInput) {
            std::cout<<"Please enter a whole number:"<<endl;
            std::cin >> *number;
        
            // Check if the input is considered a fail
            if (std::cin.fail()) {
                // Clear out the invalid input
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                // Let the user know the input is invalid
                output(errorString);
            } else {
                // Since the input is valid, set it to be valid so the loop exits
                hasValidInput = true;
            }
    }
}
