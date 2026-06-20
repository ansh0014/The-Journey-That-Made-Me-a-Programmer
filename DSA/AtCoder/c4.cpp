#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long W;

    cin >> n >> W;

    vector<long long> wt(n);
    vector<long long> val(n);

    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    vector<vector<long long>> dp(
        n + 1,
        vector<long long>(W + 1, 0)
    );

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {

            if (j > 0) {
                dp[i][j] = dp[i - 1][j];
            }

            if (wt[i - 1] <= j) {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i - 1][j - wt[i - 1]] + val[i - 1]
                );
            }
        }
    }

    cout << dp[n][W] << "\n";
}
