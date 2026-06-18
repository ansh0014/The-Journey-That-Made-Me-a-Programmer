#include <iostream>  // This header file is used for input and output (cin and cout)
using namespace std;

// Creating a class named Arithametic
class Arithametic
{
private:
    int a; // This variable will store the first number
    int b; // This variable will store the second number

public:
    // Constructor: This function runs automatically when an object of the class is created
    Arithametic(int a, int b)
    {
        // 'this->a' means the class's variable 'a'
        // The right side 'a' is the value we pass when we create the object
        this->a = a;  // Assign value to member variable 'a'
        this->b = b;  // Assign value to member variable 'b'
    }

    // This function adds the two numbers and returns the result
    int add()
    {
        int c;
        c = a + b;  // Add a and b
        return c;   // Return the result
    }

    // This function subtracts the second number from the first and returns the result
    int sub()
    {
        int c;
        c = a - b;  // Subtract b from a
        return c;   // Return the result
    }
};

int main() {
    // Create an object 'ar' of class Arithametic and pass 10 and 5 to it
    // This will call the constructor and set a = 10, b = 5
    Arithametic ar(10, 5);

    // Call the add() function using the object 'ar' and print the result
    cout << "Add " << ar.add() << endl;

    // Create another object 'r' of class Arithametic and pass 14 and 6
    Arithametic r(14, 6);

    // Call the sub() function using the object 'r' and print the result
    cout << "Sub " << r.sub() << endl;

    return 0;  // End of the program
}
