// now we are doing the constructor 
#include<iostream>
using namespace std;
class Employee{
private:
string name;
double salary;
public:
// default constructor
Employee(){
    name="Unknown";
    salary=0;
cout<<"Default constructor called"<<endl;

}
Employee(string name, double salary){
    this->name=name;
    this->salary=salary;
    cout<<"Parameterized constructor called"<<endl;
}
void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Salary: "<<salary<<endl;
}
};
int main(){
    Employee e1; // default constructor called
    Employee e2("Anshul", 50000); // parameterized constructor called
    e1.display();
    e2.display();
    return 0;
}