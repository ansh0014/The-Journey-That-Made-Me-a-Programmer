// now i am doing the Jagged Swaps
// i have given a permutation of a of size n. i can do the following operation
#include <bits/stdc++.h>
using namespace std;
void solve()
{

    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (a[0] == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}