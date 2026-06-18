// // now we learn refrence 
// #include<iostream>
// using namespace std;
// int main(){
//     int a=10;
//     int &r=a;
// cout<<a<<endl;
// r++;
// cout<<r<<endl;
// cout<<a<<endl;
// }
// this is value of pass by value swapping is not work 
// #include <stdio.h>

// void swap(int a, int b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// int main() {
//     int x = 5, y = 10;
//     swap(x, y);  // Pass by value
//     printf("x = %d, y = %d\n", x, y);  // Output: x = 5, y = 10
//     return 0;
// }
// so in c we use pass by pointers in swapping 
// #include <stdio.h>

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main() {
//     int x = 5, y = 10;
//     swap(&x, &y);  // Pass address
//     printf("x = %d, y = %d\n", x, y);  // Output: x = 10, y = 5
//     return 0;
// }
// in c++ we use the pass by refrences for the swapping
#include<iostream>
using namespace std;
void swap (int &x,int &y){
    int temp;
temp=x;
x=y;
y=temp;
}
int main(){
    int a=10;
    int b=15;
    swap(a,b);
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}