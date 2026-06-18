// #include<iostream>
// using namespace std;
// class Base{
//     public:
//     virtual void display(){
//         cout<<"Base class display function"<<endl;
//     }
// };
// class Derived: public Base{
//     public:
//     void display(){
//         cout<<"Derived class display function"<<endl;
//     }
// };
// int main(){
//     Base *bptr;
//     Derived d;
//     bptr=&d;
//     bptr->display(); // this will call the derived class display function because of virtual function
//     return 0;
// }
#include<iostream>
using namespace std;
class Payment{
    public:
    virtual void pay(){
        cout<<"Payment method: "<<endl;
    }
};
class CreditCardPayment: public Payment{
    public:
    void pay(){
        cout<<"Payment method: creadit card"<<endl;
    }
};
class NetBankingPayment: public Payment{
    public:
    void pay(){
        cout<<"payment method: net banking"<<endl;
    }
};
class Upi:public Payment{
    public:
    void pay(){
        cout<<"Payment method: UPI"<<endl;
    }
};
int main(){
    Payment *ptr;
    CreditCardPayment ccp;
    NetBankingPayment nbp;
    Upi upi;
    ptr=&ccp;
    ptr->pay();
    ptr=&nbp;
    ptr->pay();
    ptr=&upi;
    ptr->pay();
    return 0;
}