// now we learn about the constructor
#include <iostream>
#include <string.h>
using namespace std;
class Custmore
{
    string name;
    int account_number;
    int balance;
    int *k;

public:
    // Default Constructor
    Custmore()
    {
        cout << "Hello constructor" << endl;
        k=new int[50];
    }
    // now we make the parameter counstucotr
    // Custmore(string a, int b, int c)
    // {
    //     name = a;
    //     account_number = b;
    //     balance = c;
    // }

    //     Custmore(string a, int b)
    // {
    //     name = a;
    //     account_number = b;

    // }
    // when i make the same constructor but the paramters are differen than it is called the overloading costructor
    Custmore(string name, int account_number, int balance)
    {
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
    }
    void display()
    {
        cout << name << endl<< account_number << endl<< balance << endl;
    }
    // this is inline constuctor
    // in coustructor i make the constructor of three parameter than i have to make the another constructor of two parameter
    //  now we learn copy constructor



};
int main()
{
    // if i remove the default contructor
    // then the coustore gie teh a
    Custmore a; // this call the default function
    Custmore A("Anshul", 23232, 50000000);
    Custmore A1("Mohit",34,1200);
    
    // Custmore A1("Ansh",454545);
    // this call the parameter fucntion
    A.display();
    A1.display();
    // A.display();
    Custmore A4(A1);
    A4.display();
    //  A1.display();
}
