// now we learn loops
// pattern printing
#include <iostream>
using namespace std;
void f(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void f1(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void f2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void f3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void f4(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
void f5(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void f6(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // star
        for (int k = 0; k < (2 * i + 1); k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void f7(int n)

{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < (2 * (n - i) - 1); k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void f8(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
        {
            stars = 2 * n - i;
        }
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void f9(int n)
{

    int start;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            start = 1;
        }
        else
            start = 0;
        for (int j = 1; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}
void f10(int n)
{
    int spaces = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        // no.
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // no.
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        spaces -= 2;
    }
}
void f11(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num = num + 1;
        }
        cout << endl;
    }
}
void f12(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (char j = 'A'; j <= 'A' + i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void f13(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char j = 'A'; j < 'A' + (n - i - 1); j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void f14(int n)
{
    for (char i = 0; i < n; i++)
    {
        char k='A'+i;
        for ( char j = 0; j <=i; j++)
        {
            cout << k << " ";
        }
        cout<<endl;
    }
}
void f15(int n){
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < i-1; j++)
        {
            cout<<" ";
        }
        // star
        for (int j = 0; j < 2*i+1; j++)
        {
            cout<<"*";
        }
        // spaces
        for (int j = 0; j < i-1; j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
    
}
int main()
{
    cout << "enter a no." << endl;
    int n;
    cin >> n;
    f14(n);

    return 0;
}
