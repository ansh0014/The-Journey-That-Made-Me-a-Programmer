// Fair Distribution of cookies
// we used bitmasking to represent the distribution of cookies among children
// approach : i will use bitmask dp to find the minimum unfairness that can be achieved by distributing cookies among children. i will use a dp array to store the minimum unfairness that can be achieved by distributing cookies among children. i will iterate through all the possible combinations of cookies and children and for each combination, i will calculate the total unfairness and update the dp array accordingly. finally, i will return the minimum value in the dp array.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,all;
    vector<int> sum;
    int dp[9][1 << 8];

    int dfs(vector<int>& cookies, int child, int mask, int k) {
        if (child==k - 1)
            return sum[all ^mask];
        if (dp[child][mask] != -1)
            return dp[child][mask];
        int ans = INT_MAX;
        for (int sub = 1; sub <= all; sub++) {
            if (sub & mask) continue;        
            int newMask = mask | sub;
            int remain = all ^ newMask;
            if (__builtin_popcount(remain) < (k - child - 1))
                continue;
            ans = min(ans, max(sum[sub],dfs(cookies, child + 1, newMask, k)));
        }
        return dp[child][mask] = ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {

        n = cookies.size();
        all = (1 << n) - 1;
        sum.assign(1 << n, 0);
        for (int mask = 1; mask <= all; mask++) {
            int bit = __builtin_ctz(mask);
            sum[mask] = sum[mask ^ (1 << bit)] + cookies[bit];
        }

        memset(dp, -1, sizeof(dp));

        return dfs(cookies, 0, 0, k);
    }
};