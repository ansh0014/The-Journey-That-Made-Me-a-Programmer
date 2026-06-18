// public member
// #include<iostream>
// using namespace std;
// class Base{
//     public :
//     int x=12;

// };
// class Derived: public Base{
//     public:
//     void show(){
//         cout<<x<<endl;
//     }
// };
// int main(){
//     Derived d;
//     // accessibel inside derived class 
  
//     d.show();
    
//     cout<<d.x<<endl; // we can access the public member of base class using derived class object
//     return 0;
// }
// protected member
#include<iostream>
// using namespace std;
// class Base{
//     protected:
//     int x=12;

// };
// class Derived: public Base{
//     public:
//     void show(){
// // accessible inside derived class
// cout<<x<<endl;
//     }
// };
// int main(){
//     Derived d;
//     // not aceesible outside
//     // cout<<d.x<<endl; // we cannot access the protected member of base class using derived class object
//     d.show();
//     return 0;
// }
// private member
#include<iostream>
using namespace std;
class Base{
    private:
    int x=12;
    public:
    void show(){
        cout<<x<<endl; // accessible inside base class
    }

};
class Derived: public Base{
    public:
    void display(){
        // cout<<x<<endl; // not accessible inside derived class
        show(); // we can access the private member of base class using public member function of base class
    }
};
int main(){
    Derived d;
    // cout<<d.x<<endl; // we cannot access the private member of base class using derived class object
    d.display();
    return 0;
}