#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD = 1e9 + 7;
    

    
    long long dp[101][101][101]; // [ti][i1][i2]
    int n1, n2, nt;
    string w1, w2, t;
    
    // ways to form target[ti:] with next available index i1 in word1, i2 in word2
    long long rec(int ti, int i1, int i2) {
        if (ti == nt) return 1;
        if (i1 == n1 && i2 == n2) return 0;
        if (dp[ti][i1][i2] != -1) return dp[ti][i1][i2];
        
        long long ans = 0;
        char need = t[ti];
        
        // try all positions in word1 from i1 onwards
        for (int j = i1; j < n1; j++) {
            if (w1[j] == need) {
                ans = (ans + rec(ti + 1, j + 1, i2)) % MOD;
            }
        }
        // try all positions in word2 from i2 onwards
        for (int j = i2; j < n2; j++) {
            if (w2[j] == need) {
                ans = (ans + rec(ti + 1, i1, j + 1)) % MOD;
            }
        }
        
        return dp[ti][i1][i2] = ans;
    }
    
    // ways using ONLY word1 (ignore word2)
    long long dp1[101][101];
    long long recOnly1(int ti, int i1) {
        if (ti == nt) return 1;
        if (i1 == n1) return 0;
        if (dp1[ti][i1] != -1) return dp1[ti][i1];
        long long ans = 0;
        for (int j = i1; j < n1; j++) {
            if (w1[j] == t[ti])
                ans = (ans + recOnly1(ti + 1, j + 1)) % MOD;
        }
        return dp1[ti][i1] = ans;
    }
    
    // ways using ONLY word2
    long long dp2[101][101];
    long long recOnly2(int ti, int i2) {
        if (ti == nt) return 1;
        if (i2 == n2) return 0;
        if (dp2[ti][i2] != -1) return dp2[ti][i2];
        long long ans = 0;
        for (int j = i2; j < n2; j++) {
            if (w2[j] == t[ti])
                ans = (ans + recOnly2(ti + 1, j + 1)) % MOD;
        }
        return dp2[ti][i2] = ans;
    }
    
    int countWays(string word1, string word2, string target) {
        w1 = word1; w2 = word2; t = target;
        n1 = w1.size(); n2 = w2.size(); nt = t.size();
        
        memset(dp, -1, sizeof(dp));
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        
        long long total = rec(0, 0, 0);
        long long only1 = recOnly1(0, 0);
        long long only2 = recOnly2(0, 0);
        
        // inclusion-exclusion: at least one from each
        long long ans = ((total - only1 - only2) % MOD + MOD) % MOD;
        return (int)ans;
    }
};