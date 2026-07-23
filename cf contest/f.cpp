#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, s;
        cin >> n >> x >> s;
        string u;
        cin >> u;


        vector<long long> dp(x + 2, -1e18);
        dp[x] = 0;

        for (char c : u) {
            vector<long long> ndp(x + 2, -1e18);
            for (long long e = 0; e <= x; e++) {
                if (dp[e] < -1e17) continue;
                long long cap = (x - e) * s; // total capacity of opened tables
                long long partial = cap - dp[e]; // remaining partial seats

                if (c == 'I') {
                    // kick
                    ndp[e] = max(ndp[e], dp[e]);
                    // seat: open new table
                    if (e > 0) ndp[e-1] = max(ndp[e-1], dp[e] + 1);
                }
                else if (c == 'E') {
                    // kick
                    ndp[e] = max(ndp[e], dp[e]);
                    // seat: fill partial
                    if (partial > 0) ndp[e] = max(ndp[e], dp[e] + 1);
                }
                else { // A
                    // kick
                    ndp[e] = max(ndp[e], dp[e]);
                    // fill partial
                    if (partial > 0) ndp[e] = max(ndp[e], dp[e] + 1);
                    // open new table
                    if (e > 0) ndp[e-1] = max(ndp[e-1], dp[e] + 1);
                }
            }
            dp = ndp;
        }

        long long ans = 0;
        for (long long e = 0; e <= x; e++)
            ans = max(ans, dp[e]);
        cout << ans << "\n";
    }
}
