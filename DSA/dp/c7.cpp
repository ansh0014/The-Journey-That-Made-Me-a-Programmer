// // now i am doing the form 3 which is used longest common subsquences 
// #include <bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     int longestCommonSubsequence(string text1, string text2) {
//     n=text1.length();
//     m=text2.length();
//     a=text1;
//     b=text2;
//     memset(dp,-1,sizeof(dp));
//     return rec(0,0);
// }

// int n, m;
// string a,b;
// int dp[1001][1001];
// int rec(int i, int j){
// // return the LCS fo a[i..] and b[j..]

// // pruing


// // basecase
// if(i>=n || j>=m){
//     return 0;
// }
// if(dp[i][j]!=-1){
//     return dp[i][j];
// }
// // save and compute
// int ans=0;
// ans=max(ans,rec(i+1,j));
// ans=max(ans,rec(i,j+1));
// if(a[i]==b[j]){
//     ans=max(ans,1+rec(i+1,j+1));
// }


// // save and return 
// dp[i][j]=ans;
// return ans;
// }

// };
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t=1;
//     // cin>>t;
//     while(t--){
//         Solution sol;
//         cout<<sol.longestCommonSubsequence("", "")<<endl;
//     }
// }

// now we are doing the longest Palindromic Subsequence

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

       int longestPalindromeSubseq(string s) {
    string t=s;
    reverse(t.begin(),t.end());
    return rec(s,0,s.length()-1);
    
    
}
  
    int rec(string &s, int i, int j){
        // return the longest palindromic subsequence in s[i..j]

        // base case
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }

        // save and compute
        int ans=0;
        if(s[i]==s[j]){
            ans=max(ans,2+rec(s,i+1,j-1));
        }
        else{
            ans=max(ans,rec(s,i+1,j));
            ans=max(ans,rec(s,i,j-1));
        }

        // save and return
        return ans;
    }
   public:
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t=1;
        // cin>>t;
        while(t--){
            Solution sol;
            cout<<sol.longestPalindromeSubseq("")<<endl;
        }
    }
};