// #include <iostream>
// using namespace std;
// int main(){
//     int a=10;
//     int b=0;
//     try{
//         if(b==0){
//             throw "Division by zero is not allowed";
//         }
//         cout<<"Result: "<<a/b<<endl;
//     }
//     catch(const char* msg){
//         cerr<<msg<<endl;
//     }
//     return 0;
// }
#include <iostream>
#include<exception>
using namespace std;
class myexception: public exception{
    private:
    string msg;
    public:
    myexception(string msg){
        this->msg=msg;
    }
    const char* what() const noexcept{
        return msg.c_str();
    }
};
int main()
{
    try
    {
        int *p = new int [1000000000000];
        cout << "memory allocated successfully" << endl;
        delete[] p;
    }
    catch (const myexception &e)
    {
        cerr << "Memory allocation failed" <<e.what()<< endl;
    }
}