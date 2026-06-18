// now i am doing the coin change using the form 4
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<int> coins;
    int dp[15][10005];
    int rec(int coin, int amount) {
        if (amount == 0)
            return 0;
        if (coin >= n || amount < 0)
            return 1e9;
        if (dp[coin][amount] != -1)
            return dp[coin][amount];
        int take = 1 + rec(coin, amount - coins[coin]);
        int notTake = rec(coin + 1, amount);
        return dp[coin][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& c, int amount) {
        coins = c;
        n = coins.size();

        memset(dp, -1, sizeof(dp));

        int ans = rec(0, amount);

        return (ans >= 1e9) ? -1 : ans;
    }
};