// now we are doing the logest palindromic
// we use form 2 ending form with the ittrative approach to solve this problem
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int longestPalindromeSubseq(string s){
    int n=s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=1;
        if(i<n-1 && s[i]==s[i+1]){
            dp[i][i+1]=2;
        }else if(i<n-1){
            dp[i][i+1]=1;
        }

    }
    for(int len=3;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            if(s[i]==s[j]){
                dp[i][j]=2+dp[i+1][j-1];
            }else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}
};