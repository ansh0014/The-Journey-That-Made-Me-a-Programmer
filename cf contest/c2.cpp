#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = INF;
    for (int total = 0; total <= n; total++) {
        vector<vector<int>> dp(n + 1, vector<int>(total + 2, INF));
        dp[0][0] = 0;
        for (int pos = 0; pos < n; pos++) {
            for (int l = 0; l <= min(pos, total); l++) {
                if (dp[pos][l] == INF) continue;
                if (l < total) {
                    int rleft = pos - l;
                    if (rleft >= k) {
                        dp[pos + 1][l + 1] = min(dp[pos + 1][l + 1], dp[pos][l] + (s[pos] != 'L'));
                    }
                }
                int lright = total - l;
                if (lright >= k) {
                    dp[pos + 1][l] = min(dp[pos + 1][l],dp[pos][l] + (s[pos] != 'R'));
                }
            }
        }
        ans = min(ans, dp[n][total]);
    }

    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}