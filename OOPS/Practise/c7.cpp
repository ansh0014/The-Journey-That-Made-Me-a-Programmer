#include<iostream>
using namespace std;
class Person{
    protected:
    string name;
    int age;
    public:
    void setPerson(string name, int age){
        this->name=name;
        this->age=age;
    }
};
// now we are doin the drived class
class Employee: public Person{
    private:
    int employee_id;
    double salary;
    public:
    void setEmployee(int employee_id, double salary){
        this->employee_id=employee_id;
        this->salary=salary;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Employee ID: "<<employee_id<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};
int main(){
    Employee *emp=new Employee();
    emp->setPerson("Anshul", 30);
    emp->setEmployee(101, 50000);
    emp->display();
    delete emp;
    return 0;
}