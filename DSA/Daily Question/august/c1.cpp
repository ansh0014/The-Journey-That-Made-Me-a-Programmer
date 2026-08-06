// now i am doing the stone game
// Alice and bob play a game with piles of stones. THERE are an even number of piles arranged in a row, and each pile has positive integer number of stones piles[i].
// The objective of the game is end with the most stoens. the total number of stones across all the piles is odd so there are no ties.
// Alice and bob take turns, with alice starting first. Each turn, player takes the entire pile of stoen either from beginning or form the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.
// Assuming alice and Bob play optimally return true if alice wins the game or false if bob wins.
// we used game theory to solve this problem. we can use dp to solve this problem. we can use dp[i][j] to represent the maximum number of stones that the current player can get from piles[i] to piles[j]. we can use the following formula to calculate dp[i][j]:
// dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool stoneGame(vector<int>& piles){
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = piles[i];
        }
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};