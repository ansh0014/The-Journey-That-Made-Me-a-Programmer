#include <iostream>
using namespace std;
class Animal{
    public:
    virtual void bark(){
        cout<<"Animal is eating"<<endl;
    }
};
class Dog: public Animal{
    public:
    void bark(){
        cout<<"Dog is barking"<<endl;
    }
};
int main(){
    Animal *a=new Dog();
    a->bark(); // this will call the bark function of the Dog class because of the virtual function in the base class
    delete a;
    return 0;
}