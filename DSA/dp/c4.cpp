// now i am doing the climbing stairs problem of leetcode using the dp
// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
// int rec(int level,int n,int dp[]){
//     if(level>n) return 0;
//     if(level==n) return 1;
//     if(dp[level]!=-1) return dp[level];
//     int ans=0;
//     for(int step=1;step<=2;step++){
//         if(level+step<=n){
//             int ways=rec(level+step,n,dp);
//             ans+=ways;
//         }
//     }
//     return dp[level]=ans;
// }


//     int climbStairs(int n)
//     {
//         int dp[n + 1];
//         memset(dp, -1, sizeof(dp));
//         return rec(0, n, dp);


        
//     }

// };
// now i am doing the climbing staris 11
// ok first i have to understand the problem 
// i have level n and i have taken the n+1 steps 
// i have given 1-indexed integer array costs of length n cost[i] is cost of each step
// constraints jump i+1, i+2, i+3 cost 
// cost[j]+(j-i)^2
// i havve to return total cost
// i have to use form one of dp  dp()=take/not take
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int rec(int level,int n,vector<int>& cost,int dp[]){
        if(level>n) return 0;
        if(level==n) return 0;
        if(dp[level]!=-1) return dp[level];
        int ans=INT_MAX;
        for(int step=1;step<=3;step++){
            if(level+step<=n){
                int ways=rec(level+step,n,cost,dp);
                ans=min(ans,ways+cost[level+step-1]+(step*step));
        
            }
        }
        return dp[level]=ans;
    }
    int climbStairs(int n,vector<int>& cost){
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return rec(0,n,cost,dp);
    }

};