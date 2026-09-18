// now i am doing the distinct subesquences 11
// given a string s , return the number of distinct non-empty subesquences of s. since the answer may be very large, return it modulo 10^9 + 7.
// a subequnce of string is new string that is formed from the orginal string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. 
// approach we use greedy approach to solve this problem. we will use dp to store the number of distinct subsequences of s[0...i] and we will use a hashmap to store the last index of each character in s.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        unordered_map<char,int>mp;
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1])%1000000007;
            if(mp.find(s[i-1])!=mp.end()){
                dp[i]=(dp[i]-dp[mp[s[i-1]]-1]+1000000007)%1000000007;
            }
            mp[s[i-1]]=i;
        }
        return (dp[n]-1+1000000007)%1000000007;
    }
};