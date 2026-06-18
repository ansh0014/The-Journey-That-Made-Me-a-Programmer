// Complex Number (object Return +Passing)
#include<iostream>
using namespace std;
class Complex{
private:
float real;
float imag;
public:
void setData(float real, float imag){
    this->real=real;
    this->imag=imag;
}
Complex add(Complex c){
    Complex temp;
    temp.real=real+c.real;
    temp.imag=imag+c.imag;
    return temp;
}
void display(){
    cout<<real<<" + "<<imag<<"i"<<endl;
}};
int main(){
Complex c1,c2,c3;
c1.setData(1,2);
c2.setData(3,4);
c3=c1.add(c2);
c3.display();

}