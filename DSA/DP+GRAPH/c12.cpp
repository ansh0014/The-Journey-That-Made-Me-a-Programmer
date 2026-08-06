// now i am doing the minimum cost to make at least one valid path in a grid
// i have given m*n grid. each cell of the grid has a sign pointing to next cell i should visit i i at currently in this cell the sign of grid[i][j]
// condition
/*
1 which measn go to the cell tof right grid[i][j] to grid[i][j+1]
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])

*/
// You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

// Return the minimum cost to make the grid have at least one valid path.

// approach i have make the dp with transation of the condition of the cell and then i will use the priority queue to find the minimum cost to make at least one valid path in a grid.
// we have implement the dijkstra algorithm to find the minimum cost to make at least one valid path in a grid. we will use a priority queue to store the cost and the cell coordinates and then we will use a visited array to mark the visited cells and then we will check if the current cost is less than the dp value of the current cell then we will push the adjacent cells into the priority queue with the updated cost.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minCost(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<pair<int,int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    while(!pq.empty()){
        auto [cost, cell]=pq.top();
        pq.pop();
        int row=cell.first;
        int col=cell.second;
        if(cost>dp[row][col]) continue;
        if(row==m-1 && col==n-1) return cost;
        for(int i=0;i<4;i++){
            int dr=directions[i].first;
            int dc=directions[i].second;
            int nr=row+dr;
            int nc=col+dc;
            if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
            int newCost=cost+(grid[row][col]!=i+1);
            if(newCost<dp[nr][nc]){
                dp[nr][nc]=newCost;
                pq.push({newCost,{nr,nc}});
            }
        }
    }
    return -1;
}
};
