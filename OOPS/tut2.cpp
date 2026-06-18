// in this we learn about the padding the size of the classes and object
#include <iostream>
using namespace std;
// class t{

// }a;
// int main(){
//     cout<<sizeof(a)<<"* "<<endl;
//     return 0;
// }
class t
{
    // c b p p a a a a x x x x x x x x p 
    char c;
    char b;
    int a;
    double x;
} a;
int main()
{
    cout << sizeof(a) << endl;
    return 0;
}