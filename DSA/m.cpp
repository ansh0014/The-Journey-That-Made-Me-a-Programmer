// maximum consistent columns in a grid
// i have given a 2d integer array grid of size m*n and an integer limit.
// i may remove zero or more columns form the grid , but atleast one column must reamin. The relative order of the reamining columns must be preserved.
// A grid is called consistent if for every row i, and for every pair of adjacent reaming columns a and b with the a<b the following hold gried[i][b]-grid[i][a]<=limit
// return the maximum number of columns that can be removed from the grid such that it remains consistent
// i have think how i remove zero or more columns from the grid , but at least one column must remain.  
// approach we used the dp over columns wehere each column is a state and trasition are allowed only if row satify the limint condition

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
int maxConsistentColumns(vector<vector<int>>& grid, int limit){
    int m=grid.size();
    int n=grid[0].size();
    vector<int> dp(n,1);
    int keep=1;
    for(int j=1;j<n;j++){
        for(int i=0;i<j;i++){
            bool valid=true;
            for(int row=0;row<m;row++){
                if(abs(grid[row][j]-grid[row][i])>limit){
                    valid=false;
                    break;
                }
            }
            if(valid){
                dp[j]=max(dp[j],dp[i]+1);
             
            }
        }
        keep=max(keep,dp[j]);

}
return keep;
}
};