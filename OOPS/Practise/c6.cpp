#include<iostream>
using namespace std;
// Base class 
class Person{
    protected:
    string name;
    int age;
    public:
    Person(string name, int age){
        this->name=name;
        this->age=age;
        cout<<"Person constructor called"<<endl;
    }
};
class Employee{
    protected:
    int employee_id;
    double salary;
    public:
    Employee(int employee_id, double salary){
        this->employee_id=employee_id;
        this->salary=salary;
        cout<<"Employee constructor called"<<endl;
    }
};
class Manager: public Person, public Employee{
    private:
    string department;
    public:
    Manager(string name, int age, int employee_id, double salary, string department): Person(name, age), Employee(employee_id, salary){
        this->department=department;
        cout<<"Manager constructor called"<<endl;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Employee ID: "<<employee_id<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Department: "<<department<<endl;
    }
};
int main(){
    Manager m1("Anshul", 30, 101, 50000, "IT");
    m1.display();
    return 0;
}