#include<iostream>
using namespace std;
class FreeAccount;
class AcademicAccount{
    private:
    string name;
    int marks;
    public:
    void setData(string name, int marks){
        this->name=name;
        this->marks=marks;
    }
    friend void checkEligibility(AcademicAccount, FreeAccount);

};
class FreeAccount{
    private:
    string name;
    int balance;
    public:
    void setData(string name, int balance){
        this->name=name;
        this->balance=balance;
    }
    friend void checkEligibility(AcademicAccount, FreeAccount);
};
void checkEligibility(AcademicAccount a, FreeAccount f){
    if(a.marks>=85 && f.balance>=1000){
        cout<<"Eligible for scholarship"<<endl;
    }
    else{
        cout<<"Not eligible for scholarship"<<endl;
    }
}
int main(){
    AcademicAccount a1;
    FreeAccount f1;
    a1.setData("Anshul", 90);
    f1.setData("Anshul", 1500);
    checkEligibility(a1, f1);
    return 0;
}