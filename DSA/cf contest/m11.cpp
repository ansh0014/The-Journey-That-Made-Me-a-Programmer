#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        int64 m;
        cin >> n >> k >> m;

        if (k > m) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        vector<int64> pref(n + 1);
        for (int i = 0; i <= n; i++)
            pref[i] = i % k;

        for (int i = 1; i <= n; i++) {
            int64 delta = (pref[i] - pref[i - 1] + m) % m;
            if (delta == 0) delta = m;
            cout << delta << " ";
        }
        cout << "\n";
    }

    return 0;
}