// now we do the single Inheritance
// #include <iostream>
// using namespace std;
// class Parent{
//     public:
//     void show(){
//         cout<<"parent class "<<endl;
//     }
// };
// class child:public Parent{
//     public:
//     void showChild(){
//         cout<<"child class "<<endl;
//     }
// };
// int main(){
//     child c;
//     c.show(); // we can access the parent class function using child class object
//     c.showChild(); // we can access the child class function using child class object
//     return 0;
// }
// multilevel inheritance
// #include <iostream>
// using namespace std;
// class GrandParent{
//     public:
//     void grand(){
//         cout<<"Grand Parent class"<<endl;
//     }
// };
// class Parent:public GrandParent{
//     public:
//     void parent(){
//         cout<<"Parent class"<<endl;
//     }
// };
// class Child:public Parent{
//     public:
//     void child(){
//         cout<<"Child class"<<endl;
//     }
// };
// int main(){
//     Child c;
//     c.grand(); // we can access the grand parent class function using child class object
//     c.parent(); // we can access the parent class function using child class object
//     c.child(); // we can access the child class function using child class object
//     return 0;
// }
// multiple inheritance
// #include <iostream>
// using namespace std;
// class Father{
//     public:
//     void father(){
//         cout<<"Father class"<<endl;
//     }
// };
// class Mother{
//     public:
//     void mother(){
//         cout<<"Mother class"<<endl;
//     }
// };
// class Child:public Father, public Mother{
//     public:
//     void child(){
//         cout<<"Child class"<<endl;
//     }
// };
// int main(){
//     Child c;
//     c.father(); // we can access the father class function using child class object
//     c.mother(); // we can access the mother class function using child class object
//     c.child(); // we can access the child class function using child class object
//     return 0;
// }
// now we are doing the hierarchical inheritance
// #include<iostream>
// using namespace std;
// class Parent{
//     public:
//     void show(){
//         cout<<"Parent Fucntion"<<endl;
//     }
// };
// class Child1: public Parent{

// };
// class Child2: public Parent{

// };
// int main(){
//     Child1 c1;
//     Child2 c2;
//     c1.show();
//     c2.show();
// }
// now we do the Inheritance
// #include<iostream>
// using namespace std;
// class A{
//     public:
//     void showA(){
//         cout<<"Class A"<<endl;
//     }
// };
// class B: public A{
//     public:
//     void showB(){
//         cout<<"Class B"<<endl;
//     }
// };
// class C{
//     public:
//     void showC(){
//         cout<<"class C"<<endl;
//     }
// };
// class D: public B, public C{
//     public:
//     void showD(){
//         cout<<"Class D"<<endl;
//     }
// };
// int main(){
//     D d;
//     d.showA();
//     d.showB();
//     d.showC();
//     d.showD();
// }

// now we are doing he diamond problem
// #include <iostream>
// using namespace std;

// class A {
// public:
//     void show() {
//         cout << "Class A" << endl;
//     }
// };

// class B : public A {
// };

// class C : public A {
// };

// class D : public B, public C {
// };

// int main() {

//     D d;

//     // ERROR
//     // d.show();
// }

#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "Class A" << endl;
    }
};

class B : virtual public A {
};

class C : virtual public A {
};

class D : public B, public C {
};

int main() {

    D d;

    d.show();
}