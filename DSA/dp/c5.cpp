// i am doing hte min cost climbing stairs
//  i have given cost where cost[i] is coste step on staricse
// choices i can ethert form step with index 0 or step with 1
// return minimum cost to reach the top of the floor
// constraints are high so we have to optimize our approach
// we can use dp to solve this problem
#include <bits/stdc++.h>
using namespace std;
class Solution{
    int rec(int level, int n, vector<int>&cost, vector<int>& dp){
        if(level>n) return 0;
        if(level==n) return 0;
        if(dp[level]!=-1) return dp[level];
        int ans=INT_MAX;
        for(int step=1;step<=2;step++){
            if(level+step<=n){
                ans=min(ans,cost[level]+rec(level+step,n,cost,dp));
            }
        }
        return dp[level]=ans;
    }

    public:
    int minCostClimbingStairs(vector<int>& cost){
        int n=cost.size();
      vector<int>dp(n+1,-1);
      return min(rec(0,n,cost,dp),rec(1,n,cost,dp));
    }
};