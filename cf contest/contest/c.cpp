#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n + 1);

    if (n & 1) {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << "NO\n";
        return;
    }

    long long mnOdd = LLONG_MAX;
    long long mxEven = LLONG_MIN;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i & 1)
            mnOdd = min(mnOdd, a[i]);
        else
            mxEven = max(mxEven, a[i]);
    }

    if (mnOdd - mxEven >= 2)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}