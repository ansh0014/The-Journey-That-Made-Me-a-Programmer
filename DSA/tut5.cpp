// #include<iostream>
// #include<string.h>
// using namespace std;
// struct student
// {
//     char name[50];
//     int age;
// }a,b;

// int main(){
//     strcpy(a.name, "Anshul");
//     a.age=20;
//     cout<<"Name:"<<a.name<<endl;
//     cout<<"Age:"<<a.age<<endl;
//     return 0;
// }
// now we learn about the pointers
#include <iostream>
using namespace std;

//  int main()
// {
//     int a = 10;
//     int *p; // this is decareation of pointer
//     p = &a;  // derefrecring   // intilization of pointer // address of a &a
//     cout << a << endl;

//     cout << *p << endl;
//     cout << &a << endl; // print the addresss of a
//     cout << p << endl;  // print the addaress of a
//     cout << &p << endl;  // print the address of p
//     return 0;
// }
// int main(){
//     int a[5]={1,2,3,4,5};
//     int *p;
//     p=&a[0];
//     for (int i = 0; i < 5; i++)
//     {
//         cout<<p[i]<<endl;
//         cout<<" **************"<<endl;
//         cout<<&p[i]<<endl;
// //all things acess in stack
//     }

//     return 0;
// }
// array in created in heap
int main()
{
    // this allcoted the dynamic memmory alloacated /
    // dynamicl created aray inb heap
    int *p; 
    p= new int[2];
    p[0] = 10;
    p[1] = 14;
    // cout << p[0] << endl;
    // cout << p[1] << endl;
    for (int i = 0; i < 2; i++)
    {
        cout<<p[i]<<endl;
    }
    delete []p;
    
    return 0;
}