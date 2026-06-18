// // fucntion
// #include <iostream>
// using namespace std;
// int f(int a, int b)
// {

//     return a + b;
// }
// int main()
// {
//     cout << "enter 1st no:" << endl;
//     int a;
//     cin >> a;
//     cout << "enter 2nd no:" << endl;
//     int b;
//     cin >> b;
//     int h;
//     h = f(a, b);
//     cout << h;
//     return 0;
// }
// now we learn about the pointer
// #include<iostream>
// using namespace std;
// int main(){
//     int x=3;
//     int *p=&x;
//     cout<<&x<<endl;
//     cout<<*p<<endl;
//     cout<<&p<<endl;

//     return 0;
// }
// now we learn array
#include <iostream>
#include<vector>
using namespace std;
// int main(){
//     int a[5]={1,2,3,4,5};
//     for (int i = 0; i < 5; i++)
//     {
//         cout<<a[i]<<endl;
//     }

//     return 0;
// }
// int main()
// {
//     int n;
//     cout << "enter a no." << endl;
//     cin >> n;
//     int a[n];
//     // now we enter a array
//     cout<<"enter a element of array"<<endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cout<<"array:"<<endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << endl;
//     }

//     return 0;
// }
// now we enter a 2d array
int main()
{
 
    int r, c;
    cout << "enter row:" << endl;
    cin >> r;
    cout << "enter column:" << endl;
    cin >> c;
    vector<vector<int>>a(r,vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j]<<" " << endl;
        }
        cout<<endl;
    }

    return 0;
}