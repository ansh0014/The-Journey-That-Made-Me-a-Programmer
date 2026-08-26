// right now i am doing the scramble string problem
// we can scramble a string s to get a string t using hte following algorithm:
// 1. if the length of the string is 1, stop
// 2. if the length of the string is >1 do the following :
// .. Split the string into two non-empty substrings at a random index i.e. if the string si s, divide it to x and y where s=x+y
// .. Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step , s may become s=x+y or s=y+x.
// .. Apply step 1 recursively on each of the two substrings x and y.
// Given two strings s1 and s2 of the same length, return true if s2
// approach we used the dp in that
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int dp[31][31][31];
    int memo(vector<int>&s1, vector<int>s2, int i, int j,int len){
        int n=s1.size();
        int m=s2.size();
if(i>=n || j>=m){
            return 0;
        }
        if(len==1){
            return s1[i]==s2[j];
        }
        if(dp[i][j][len]!=-1){
            return dp[i][j][len];
        }
        int ans=0;
        for(int k=1;k<len;k++){
            if((memo(s1,s2,i,j,k) && memo(s1,s2,i+k,j+k,len-k)) || (memo(s1,s2,i,j+len-k,k) && memo(s1,s2,i+k,j,len-k))){
                ans=1;
                break;
            }
        }
        return dp[i][j][len]=ans;

    }
bool isScramble(string s1, string s2){
    
        int n=s1.size();
        int m=s2.size();
        if(n!=m){
            return false;
        }
        memset(dp,-1,sizeof(dp));
        vector<int>v1,v2;
        for(int i=0;i<n;i++){
            v1.push_back(s1[i]-'a');
            v2.push_back(s2[i]-'a');
        }
        return memo(v1,v2,0,0,n);
}
};