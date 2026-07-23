// now i am doing the unique paths problem
// there is a robot an m*n grid. the robot initially located at the top-left corner(i.e grid[0][0]). the robot tries to move to the bottom-right corner. The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number o possible unique path that the robot can take reach the bottom-right corner.
// i will use dp  form 1 take or not take it form
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int uniquePath(int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up=0,left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }

        }
        return dp[m-1][n-1];
    }
};