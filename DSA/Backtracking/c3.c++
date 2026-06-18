// count the subsquences with the sume =k
#include <iostream>
using namespace std;

int f(int ind, int s, int sum, int arr[], int n)
{
    // base case
    if (ind == n)
    {
        if (s == sum) return 1;
        else return 0;
    }

    // take
    int l = f(ind + 1, s + arr[ind], sum, arr, n);

    // not take
    int r = f(ind + 1, s, sum, arr, n);

    return l + r;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;

    cout << f(0, 0, sum, arr, n);

    return 0;
}