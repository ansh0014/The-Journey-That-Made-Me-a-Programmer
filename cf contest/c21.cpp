#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Hash {
    size_t operator()(const vector<ll>& v) const {
        size_t h = v.size();
        for (ll x : v)
            h = h * 1315423911u + hash<ll>{}(x);
        return h;
    }
};

unordered_map<vector<ll>, ll, Hash> dp;

ll brute(const vector<ll>& a, ll c) {
    if (a.empty())
        return 0;

    auto it = dp.find(a);
    if (it != dp.end())
        return it->second;

    ll ans = LLONG_MIN;
    int n = a.size();

    vector<ll> b;
    b.reserve(n);

    for (int i = 0; i < n; i++) {
        b.clear();
        for (int j = 0; j < n; j++)
            if (j != i)
                b.push_back(a[j]);

        ans = max(ans, a[i] - c + brute(b, c));
    }

    for (int i = 0; i + 1 < n; i++) {
        b.clear();
        for (int j = 0; j < n; j++)
            if (j != i && j != i + 1)
                b.push_back(a[j]);

        ans = max(ans, max(a[i], a[i + 1]) - c + brute(b, c));
    }

    return dp[a] = ans;
}

void solve() {
    int n;
    ll c;
    cin >> n >> c;

    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    dp.clear();

    cout << brute(a, c) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();
}