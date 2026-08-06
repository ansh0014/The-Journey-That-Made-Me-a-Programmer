// now i am doing the stone game 111
// stones are arrange in a row
// each stone has associated value which is an integer given in the array stonevalue
// alice and bob take turns with alice starting firs. On each player's turn that player can take 1,2 or 3 storne from the first reaming stones in the reow
// the score of each player is the sum of the value of the storne taken the score of each player is 0 initially
// the objective of the game is to end with the highest score, and winner is the player with the highes score and there could be tie the game continues until all the storne have been taken
// Assuem alice and bob play optimally
// Return "Alice" if alice will win the game or "Bob" if bob will win or "Tie" if they end the game with the same score
// state dp[i][j] represents the maximum score difference the current player can achieve over the other player from the subarray stonevalue[i] to stonevalue[j]
// transtion: dp[i][j] = max(stonevalue[i] - dp[i + 1][j], stonevalue[i] + stonevalue[i + 1] - dp[i + 2][j], stonevalue[i] + stonevalue[i + 1] + stonevalue[i + 2] - dp[i + 3][j])
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        string stoneGameIII(vector<int>& stoneValue) {
     int n = stoneValue.size();
     vector<int> dp(n + 1, INT_MIN);
     dp[n] = 0; 
     for(int i = n - 1; i >= 0; i--) {
         int take = 0;
         for (int j = 0; j < 3 && i + j < n; j++) {
             take += stoneValue[i + j];
             dp[i] = max(dp[i], take - dp[i + j + 1]);
         }
     }
        if (dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        else return "Tie";
    }
};