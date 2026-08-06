// minimum time to visit a cell in a grid
// i have a m*n martiz grid consisting of non-negative integers where grid[row][col] represents the minimum time required to be able to visit the cell(row, col). which means i can visit hte cell(row, col) only when the time you visit iits greater than or equal to grid[row][col]
// we are standing in the top-left cell of the matrix in the oth second and i must move to any adjacent cell int hte four direction up down left and reight each move i make takes 1 second
// return the minimum time required in which i can visit the bottom-right cell of the matrix. if i cannot visit the bottom - right cell then return -1.
// apporach we used the dijstra for the finding the minimum time to visit the bottom right cell of the matrix. we will use a priority queue to store the time and the cell coordinates and then we will use a visited array to mark the visited cells and then we will check if the current time is greater than or equal to the grid value of the current cell then we will push the adjacent cells into the priority queue with the updated time.
// / in this question we have to used also dp for the transition of the time to visit the adjacent cells. we will use a dp array to store the minimum time required to visit each cell and then we will update the dp array with the minimum time required to visit the adjacent cells.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
int minimumTime(vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    if(m>1 && n>1 && grid[0][1]>1 && grid[1][0]>1) return -1;
    vector<vector<int>> dp(m ,vector<int>(n, INT_MAX));
    dp[0][0]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,0}});
    vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
    while(!pq.empty()){
        auto [time, cell]=pq.top();
        pq.pop();
        int row=cell.first;
        int col=cell.second;
        if(time>dp[row][col]) continue;
        if(row==m-1 && col==n-1) return time;
        for(auto [dr,dc]:directions){
            int nr=row+dr;
            int nc=col+dc;
            if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
            int arrive=max(time+1,grid[nr][nc]);
            if((arrive-(time+1))%2==1) arrive++;
            if(arrive<dp[nr][nc]){
                dp[nr][nc]=arrive;
                pq.push({arrive,{nr,nc}});
            }
   
        }
    }

return -1;
}
};
