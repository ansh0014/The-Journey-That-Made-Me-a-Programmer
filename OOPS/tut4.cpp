// #include <iostream>
// using namespace std;

// class students {
// public:
//     int marks;
//     int age;
//     string name;
//     // default constructor
//     students(){
//         marks=0;
//         age=0;
//         name="unamed";
//     }

//     // Custom copy constructor
//     students(const students &b) {
//         marks = b.marks;
//         age = b.age;     // ✅ correct assignment
//         name = b.name;
//         cout << "[Custom Copy Constructor Called]" << endl;
//     }

//     void printdetails() {
//         cout << "Name: " << name << endl;
//         cout << "Age: " << age << endl;
//         cout << "Marks: " << marks << endl;
//     }
// };

// int main() {
//     students s1;
//     s1.name = "Anshul";
//     s1.marks = 89;
//     s1.age = 14;

//     // Custom copy constructor is called here
//     students s2 = s1;

//     // Print to verify copied values
//     s2.printdetails();

//     return 0;
// }
// now we learn about the destrcutor
#include <iostream>
using namespace std;
class Custmore
{
    string name;
    int *data;

public:
    Custmore(string name)
    {
        // name="Anshul";
        this->name=name;
        // data=new int;
        // *data==10;
        // cout << "construstor is called"<<endl;;
        cout<<"constructor "<<name<<endl;
    }
    // Destructor
    ~Custmore()
    {
        // delete data;

        cout<<"Destructor "<<name<<endl;

    }
};
int main()
{
    Custmore S1("1");
    Custmore S2("2");
    Custmore S3("3");
}