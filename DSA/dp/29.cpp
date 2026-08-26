// now i am doing the Unique paths 11
// i have given an m*n integer array grid. there is robot initially located at the top-left corner. THe robot ties to move to the bottom-right corner(i.e. grid[m-1][n-1]. The robot can only move either down or right at any point in time)
// An obstacle and spce are markded as 1 or 0 repectively in grid, A path that the robot thakes conanot icnlude any square that is oblstacle
// Return the nubmer of psosible unique jpaths that the robot can take to reach the bottom-right corner. 
// Testcases are generated so the at the naswere will be less thatn or equal to 2*10^9
// approach we used simple dp in that 
// first we choice the state 
// then we choice the transition. basically this form 1 take or 0 take or not take
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int dp[101][101];
int memo(vector<vector<int>>&grid,int i, int j){
int n=grid.size();
if(i>=n || j>=grid[0].size() || grid[i][j]==1){
    return 0;
}
if(i==n-1 && j==grid[0].size()-1){
    return 1;
}
if(dp[i][j]!=-1){
    return dp[i][j];
}
if(i<n && j<grid[0].size()){
    return dp[i][j]=memo(grid,i+1,j)+memo(grid,i,j+1);
}
return 0;
}
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    memset(dp,-1,sizeof(dp));
    return memo(grid,0,0);
}
};
