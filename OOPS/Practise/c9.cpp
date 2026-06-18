#include<iostream>
using namespace std;
class Complex{
    private:
    int real, img;
    public:
    Complex(int real, int img){
        this->real=real;
        this->img=img;
    }
    // operator overloading
    Complex operator+(Complex c){
        return Complex(this->real + c.real, this->img + c.img);
    }
void display(){
    cout<<real<<" + "<<img<<"i"<<endl;
}
};
int main(){
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3=c1+c2;
    c3.display();
    return 0;
}