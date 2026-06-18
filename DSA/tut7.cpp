// #include <iostream>
// using namespace std;
// void func(int *A, int n)
// { // we can also write the A[] instead of *A
//     // cout<<sizeof(A)/sizeof(int)<<endl;
//     for (int i = 0; i < 4; i++)
//     {
//         cout << A[i] << endl;
//     }
//     // A[0]=67;
// }
// int main()
// {
//     int A[4] = {2, 3, 4, 5};
//     int n = 4;
//     for (int i = 0; i < 4; i++)
//     {
//         cout << A[i] << " ";
//     }
//     cout << endl;
//     cout<<"*********"<<endl;
//     func(A, n);

//     return 0;
// }
// now we learn how to return a array
#include <iostream>
using namespace std;
int *f(int size)
{
    int *p;
    p = new int[size];
    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1;
   
    }
         return p;    
}
int main()
{
    int *ptr, size = 6;
    ptr = f(size);
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << endl;
    }

    return 0;
}