// now i am doing the edit distance
// given two strings word1 and word2, retrun the minimum number of operations required to converet word1 to word2
// you have the following 3 operations permitted on a word:
// 1. Insert a character
// 2. Delete a character
// 3. Replace a character
// we will use dynamic programming to solve this problem
// we used concept state machine to solve this problem

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minDistance(string word1, string word2){
        if(word1 == word2) return 0;
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = i;
        }
        for(int j=0; j<=m; j++){
            dp[0][j] = j;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[n][m];
    }
};