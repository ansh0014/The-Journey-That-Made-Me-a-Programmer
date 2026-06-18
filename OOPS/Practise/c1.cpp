// i have to create the class a student with the private data
#include<iostream>
using namespace std;
class Student{
    private:
    string name;
    int roll_number;
    string degree;
    string hostel;
    int CGPA;
  public:
    void setData(string name, int roll_number, string degree,string hostel,int CGPA){
        this->name=name;
        this->roll_number=roll_number;
        this->degree=degree;
        this->hostel=hostel;
        this->CGPA=CGPA;
    }
            void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<roll_number<<endl;
            cout<<"Degree: "<<degree<<endl;
            cout<<"Hostel: "<<hostel<<endl;
            cout<<"CGPA: "<<CGPA<<endl;
        }
        void updateCGPA(float new_CGPA){
            CGPA=new_CGPA;
        }
        void updateHostel(string new_hostel){
            hostel=new_hostel;
        }
        void updateDegree(string new_degree){
            degree=new_degree;
        }

    };

int main(){
    Student s1;
    s1.setData("Anshul", 1, "B.Tech", "Hostel A", 9);
    s1.display();
    s1.updateCGPA(9.5);
    s1.updateHostel("Hostel B");
    s1.updateDegree("M.Tech");
    s1.display();
    return 0;
}