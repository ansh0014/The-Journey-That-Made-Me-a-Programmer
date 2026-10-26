
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }
        bool alicewins = false;
        for (int x = 0; x <= n; x++) {
            if (freq[x] < 2 * k - 1) {
                break;
            }
            if (freq[x] == 2 * k - 1) {
                alicewins = true;
                break;
            }
        }
        cout << (alicewins ? "YES" : "NO") << '\n';
    }
    return 0;
}
