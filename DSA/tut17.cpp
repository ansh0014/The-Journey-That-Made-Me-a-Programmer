#include <iostream>
using namespace std;

int reversearray(int a[], int n)
{
    n;
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;

    int res = reversearray(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}