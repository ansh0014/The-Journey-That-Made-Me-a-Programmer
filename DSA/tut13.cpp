// // now we print the ncr using the recurssion
// #include <iostream>
// using namespace std;

// int c(int n, int r)
// {
//     if (r == 0 || n == r)
//     {
//         return 1;
//     }
//     else
//     {
//         return c(n - 1, r - 1) + c(n - 1, r);
//     }
// }
// int main()
// {
//     int n, r;
//     n = 4, r = 8;
//     int res = c(n, r);
//     cout<<res<<endl;
//     return 0;
// }
// now we understand the concept of the tower of hanoi
#include<iostream>
using namespace std;
void TOH(int n, int a,int b, int c){
    if (n>0)
    {
      TOH(n-1,a,b,c);
      cout<<"from a to c"<<a,c;
      TOH(n-1,b,a,c);
    }
    
}
int main(){
    int n,a,b,c;
    n=3,a=1,b=2,c=3;
    TOH(n,a,b,c);
    
        return 0;
}

