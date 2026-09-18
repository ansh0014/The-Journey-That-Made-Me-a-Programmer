// now i am doing the minimum insertion steps to make a string palindrome
// given a string s. in one step i can insert any charcter at any index of the string
// retrun the minimum number of steps to make s palindrome
// a palindrom string is ont hat reads the same backward as wel forward
// dp index is the state and we have choose take it and not take it transtion
#include <bits/stdc++.h>
using namespace std;
class Solution{
    int dp[501][501];
    public:
    int memo(int i,int j,string& s){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j]=memo(i+1,j-1,s);
        }
        else{
            return dp[i][j]=1+min(memo(i+1,j,s),memo(i,j-1,s));
        }
    }
    
    int minInsertions(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return memo(0,n-1,s);
    }
};