// now i am doing the frog jum question 
// now i am doing the frog jump
// i have given a set of stones poistion in units in sorted ascending order, determine if the frog can corss the river by landing on the last stone. Initially the frog is on the first stone and assumes the first jump must be 1 unit.
// if the frog last was k units its next jump must be either k-1, k, or k+1 units. the frog can only jump in the forward direction.
// this is dp problem first form take or not take form
// we have to use tabulation method to solve this problem
#include<bits/stdc++.h>
using namespace std;
class Solution{
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dp[0][0] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int jump = stones[i] - stones[j];
                if (jump <= 0 || jump > n) continue;
                if (dp[j][jump - 1] || dp[j][jump] || dp[j][jump + 1]) {
                    dp[i][jump] = true;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (dp[n - 1][j]) return true;
        }
        return false;
    }
};