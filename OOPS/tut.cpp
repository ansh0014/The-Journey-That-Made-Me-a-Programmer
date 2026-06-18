#include <iostream>
#include <string>
using namespace std;
// class student{
//     public:
//     string name;
//     int age;
// }a;
// int main(){
//     a.name="Anshul";
//     a.age=20;
//     cout<<"Studnet Details:"<<endl;
//     cout<<a.name<<endl;
//     cout<<a.age<<endl;
//     return 0;
// }
class student
{
    // by default it is private
    string name;
    int age;
    char grade;
    // now we use fucntion to call this attrubutes
public:
    void setname(string n)
    {
        if (n.size() == 0)
        {
            cout << "Error" << endl;
        }

        name = n;
    }
    void setage(int a)
    {
        if (age <= 5 || age >= 100)
        {
            cout << "Error" << endl;
        }

        age = a;
    }
    void setgrade(char c)
    {
        grade = c;
    }
    void getname()
    {
        cout << name << endl;
    }
    void getage()
    {
        cout << age << endl;
    }
    void getgrade()
    {
        cout << grade << endl;
    }
} a1;
int main()
{
    a1.setname("Anshul");
    a1.setage(20);
    a1.setgrade('A');
    cout << "Student Details" << endl;
    a1.getname();
    a1.getage();
    a1.getgrade();
    return 0;
}