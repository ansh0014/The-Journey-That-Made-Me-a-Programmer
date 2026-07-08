// now i am doing the Cost to Merge stones
// the approach we used we make the prefix sum 
// first we make the unordered map
// this is dp + prefix sum approach
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int n;
    vector<int>prefix;
    vector<vector<int>>dp;
    int solve(int i,int j,int k,vector<int>&stones){
        if((j-i+1-k)% (k-1) != 0) return 1e9;
     if(dp[i][j] != -1) return dp[i][j];
     if(i==j){
        return (k==1)?0:1e9;
     }

    }

};
