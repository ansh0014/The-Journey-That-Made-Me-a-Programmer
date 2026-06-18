#include<iostream>
using namespace std;
template<class T>
class Calculator{
    public:
    T divide( T a, T b){
        if(b==0){
            throw "Division by zero is not allowed";
        }
        return a/b;
    }
};
int main(){
    Calculator<int> c1;
    Calculator<float> c2;
    try
    {
        cout<<"Int division:"<<c1.divide(10,2)<<endl;
        cout<<"Float division:"<<c2.divide(10.5,2.5)<<endl;
    }
    catch(...)
    {
        std::cerr << "An error occurred" << '\n';
    }
 return 0;   
}