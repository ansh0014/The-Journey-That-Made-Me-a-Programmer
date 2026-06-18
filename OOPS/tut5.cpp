// now we learn about the static member
#include <iostream>
using namespace std;
// in c++ static member(variables and fuction) belongs to the class rather than the an instance object of the class 
// defination
// A static data member is shared among all objects of a class. There is only one copy of the variable, no matter how many objects you create
// now we learn about the static member fucntion
class Custmore
{
    string name;
    int account_number, balance;
    static int total_customre;   // this belong to the class 

public:
    Custmore(string name, int account_number, int balance)
    {
        this->name = name;
        this->account_number = account_number;
       this->balance = balance;
        total_customre++;
    }
    void display()
    {
        cout << name << endl;
        cout << account_number << endl;
        cout << balance << endl;
        cout<<"*****"<<endl;
    }
    void display_total(){
        cout<<total_customre<<endl;
    }
};
int Custmore::total_customre = 0;
int main()
{
    Custmore A1("Anshul", 1, 1000);
    Custmore A2("Ashmit", 2, 500);
    A1.display();
    A2.display();

    return 0;
}