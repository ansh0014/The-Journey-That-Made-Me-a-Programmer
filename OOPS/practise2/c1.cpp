// now we do the inheritance modes
// class Derived: public base
// class Derived: protected base
// class Derived: private base
// #include<iostream>
// using namespace std;
// class Base{
//     public:
//     int a=10;
//     protected:
//     int b=20;
// };
// class Derived:public Base{
//     public:
//     void show(){
//         cout<<"Public member: "<<a<<endl; // accessible public remain public
//         cout<<"Protected member: "<<b<<endl; // accessible protected remain protected
//     }
// };
// int main(){
//     Derived d;
//     d.show();
//     cout<<"Accessing public member from main: "<<d.a<<endl; // accessible
//     // cout<<"Accessing protected member from main: "<<d.b<<endl; // not accessible
//     return 0;
// }

// Protected inheritance
