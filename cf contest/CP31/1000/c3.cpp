#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, p;
    cin >> n;
    cin >> p;
    vector<pair<long long, long long>> v(n);
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = {b[i], a[i]};
    }
    sort(v.begin(), v.end());
    long long mimcost = p;
    long long alreadyshared = 1;
    for (auto it : v)
    {
        long long can_be_shared = it.second;
        long long cost = it.first;
        if (cost >= p)
            break;
        if (alreadyshared + can_be_shared > n)
        {
            mimcost += (n - alreadyshared) * cost;
            alreadyshared = n;
            break;
        }
        else
        {
            mimcost += can_be_shared * cost;
            alreadyshared += can_be_shared;
        }
    }
    mimcost += (n - alreadyshared) * p;
    cout << mimcost << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}