#include <iostream>
using namespace std;
class Complex{
    int real,img;
    public:
    Complex(int real,int img){
        this->real=real;
        this->img=img;
    }
    void display(){
        cout<<real<<" + "<<img<<"i"<<endl;
    }
    Complex operator+(Complex c){
        return Complex(this->real + c.real, this->img + c.img);
    }

};
int main(){
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3=c1+c2; // this will give an error because we have not defined the operator+ for the Complex class
    c3.display();

    return 0;
}