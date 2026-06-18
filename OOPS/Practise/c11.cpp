// #include<iostream>
// using namespace std;
// template<typename T>
// T add(T a, T b){
//     return a+b;
// }
// int main(){
//     cout<<add(1,2)<<endl; // this will call the add function with int type
//     cout<<add(1.5,2.5)<<endl; // this will call the add function with double type
//     cout<<add(string("Hello "), string("World"))<<endl; // this will call the add function with string type
//     return 0;
// }
#include<iostream>
using namespace std;
template<class T>
class Box{
    private:
T value;
public:
void set(T v){
    value=v;
}
void display(){
    cout<<"Value: "<<value<<endl;
}
};
int main(){
Box<int> b1;
Box<string> b2;
b1.set(10);
b2.set("Hello, World!");
b1.display();
b2.display();
return 0;
}