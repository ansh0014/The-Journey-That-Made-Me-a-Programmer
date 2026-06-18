#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// void f(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
// {
//     if (ind == n)
//     {
//         for (auto it : ds)
//         {
//             cout << it << " ";
//         }
//         cout << endl;
//         return;
//     }
//     // take it
//     ds.push_back(arr[ind]);
//     s += arr[ind];

//     f(ind + 1, ds, s, sum, arr, n);
//     s -= arr[ind];
//     // not take
//     ds.pop_back();
//     f(ind + 1, ds, s, sum, arr, n);
// }

// int main()
// {
//     int arr[] = {1, 2, 1};
//     int n = 2;
//     int sum = 2;
//     vector<int> ds;
//     f(0, ds, 0, sum, arr, n);
//     return 0;
// }

bool f(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        // condition to satisified

        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        // condition not satisified

        return false;
    }
    // take it
    ds.push_back(arr[ind]);
    s += arr[ind];

    if (f(ind + 1, ds, s, sum, arr, n) == true)
    {
        return true;
    }
    s -= arr[ind];
    // not take
    ds.pop_back();
    if (f(ind + 1, ds, s, sum, arr, n) == true)
    {
        return true;
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    f(0, ds, 0, sum, arr, n);
    return 0;
}