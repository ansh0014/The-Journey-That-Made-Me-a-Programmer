// now i am doing the minimum number of visited cells in grid
// i have givne a 0 indexexd m*n interger martix grid. i at initial position is at the top-left cell(0,0)
// lets write the condition
/**
 starting from cell(i,j)
//  cells (i,j) with j<k<=grid[i][j]+j (right movement)or
cells (k,j)with i<k<=grid[i][j]+i (down movement) or
i have return hte minium number of cell i need to visit to reach the bootm-right (m-1,n-1)
*/
// lets write the approach
// we will used the bfs to find the minimum number of visisted 
// dp for transition of cell means condition that give me
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minimumVisitedCells(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            if(row==m-1 && col==n-1) return dp[row][col];
            for(int i=1;i<=grid[row][col];i++){
                if(col+i<n && dp[row][col+i]>dp[row][col]+1){
                    dp[row][col+i]=dp[row][col]+1;
                    q.push({row,col+i});
                }
                if(row+i<m && dp[row+i][col]>dp[row][col]+1){
                    dp[row+i][col]=dp[row][col]+1;
                    q.push({row+i,col});
                }
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid={{2,4,3},{3,2,1},{1,1,0}};
    cout<<s.minimumVisitedCells(grid)<<endl;
    return 0;
}