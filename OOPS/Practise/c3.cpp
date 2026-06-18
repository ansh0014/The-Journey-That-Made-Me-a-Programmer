
// Porblem
// a compnay manges two bank accounts. Due to system error the balances of two accounts nee to be swapped securely.
#include<bits/stdc++.h>
using namespace std;
class BankAccount{
    private:
    string name;
    double balance;
    public:
    BankAccount(string name, double b){
        this->name=name;
        this->balance=b;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
    friend void swapBalance(BankAccount &, BankAccount &);

};
void swapBalance(BankAccount &a, BankAccount &b){
    double temp=a.balance;
    a.balance=b.balance;
    b.balance=temp;
}
int main(){
    BankAccount A1("Anshul", 1000);
    BankAccount A2("Ashmit", 500);
    cout<<"Before swapping: "<<endl;
    A1.display();
    A2.display();
    swapBalance(A1, A2);
    cout<<"After swapping: "<<endl;
    A1.display();
    A2.display();
    return 0;
}
