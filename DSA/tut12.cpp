// // #include <iostream>
// // using namespace std;
// // int f(int n)
// // {
// //     if (n > 100)
// //     {
// //         return n - 10;
// //     }
// //     else
// //     {
// //         return f(f(n + 11));
// //     }
// // }
// // int main()

// // {
// //     int n = 95;
// //     int res = f(n);
// //     cout << res << endl;
// //     return 0;
// // }
// // sum of natural numbers using recursion
// // #include<iostream>
// // using namespace std;
// // int f(int n){
// //     if (n<0)
// //     {
// //         return 0;
// //     }
// //     else{
// //         return n+f(n-1);
// //     }

// // }
// // int main(){
// //     int n;
// //     n=9;
// //     int res=f(n);
// //     cout<<res<<endl;
// //     return 0;
// // }
// // now we right the program of taylor series using recursion
// #include <iostream>
// #include <math.h>
// using namespace std;

// int func(int n, int x)
// {
//     static int p = 1;
//     static int f = 1;
//     int r;
//     if (n == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         r = func(x, n - 1);
//         p = p * x;
//         f = f * n;

//         return r + (p / f);
//     }
// }
// int main()
// {
//     int res;
//     int n, x;
//     res = func(n, x);
//     cout << res << endl;
//     return 0;
// 