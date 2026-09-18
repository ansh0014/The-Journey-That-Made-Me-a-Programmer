// now i am doing the distinct subesquences
// i have given two strings s and t, return the number of distinct subsequences of s which equals t.
// the test cases are generated so that the answer fits on 32-bit signed integer.
// apporach we can apply dp state machine to solve this problem
// with two loops i got tle lets do memoization
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
class Solution{
    public:
    int memo(int index1, int index2, string &s, string &t) {
        if (index2 == 0) return 1;
        if (index1 == 0) return 0;
        if (dp[index1][index2] != -1) return dp[index1][index2];
   if(s[index1 - 1] == t[index2 - 1]) {
            return dp[index1][index2] = memo(index1 - 1, index2 - 1, s, t) + memo(index1 - 1, index2, s, t);
        } else {
            return dp[index1][index2] = memo(index1 - 1, index2, s, t);
        }
    }
    public:
    int numDistinct(string s, string t) {
        int n=s.size();

        int m=t.size();
      memset(dp,-1,sizeof(dp));
     return memo(n,m,s,t);
    }
};