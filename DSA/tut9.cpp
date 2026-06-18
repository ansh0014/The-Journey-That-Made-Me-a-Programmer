#include<iostream>

using namespace std;
// struct Rectangle
// {
//     int length;
//     int breadth;

// }r;
// void f(struct Rectangle r1){
//     r1.length=5;
//     r1.breadth=15;
//     cout<<"length "<<r1.length<<endl<<"breadth "<<r1.breadth<<endl;


// }
// void f(struct Rectangle *p){  // now we learn about the call by addresss
//     p->length=15;     // now we change the value of length and breadth and by the call by address
//      p->breadth=25;
//     cout<<"length "<<p->length<<endl<<"breadth "<<p->breadth<<endl;


// }
// void f(struct Rectangle &r1){  // this is call by refresence in which the r1 and r is same if i change the value of r1 r is also change
//     r1.length=5;
//     r1.breadth=15;
//     cout<<"length "<<r1.length<<endl<<"breadth "<<r1.breadth<<endl;


// }
// int main(){
//     r.length=10;
//     r.breadth=20;
//     f(r);
//     cout<<"length "<<r.length<<endl<<"breadth "<<r.breadth<<endl;
// }
// int main(){
//     r.length=10;
//     r.breadth=20;
//     f(&r);
//     cout<<"length "<<r.length<<endl<<"breadth "<<r.breadth<<endl;
// }
struct Rectangle{
int length;
int breadth;
};
struct Rectangle *func(){   // this is fucniton that return a pointer to reactangle struct

    struct Rectangle *p;  // a pointer p is decalred which can point to a rectangel
    p=new Rectangle;   // dynamcially allocates memory on the heap for one recatnangle object
    p->length=15;
    p->breadth=50;
    return p;   // the pointer p is retrunet to the calling fucntion
}
int main(){
    struct Rectangle *ptr=func();
    cout<<"Length "<<ptr->length<<endl<<"Breadth "<<ptr->breadth<<endl;
    
    return 0;
}