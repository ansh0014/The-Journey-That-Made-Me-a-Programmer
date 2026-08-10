// now i am doing the max Area of island
// i have given an m*n binary matrix grid. An island is grp of 1's (representing land) connected 4-directionally (horizontal or vertical). I may assume all four edges of the grid are surrounded by water.
// the area of an island is the nubmer of cesll with the value 1 in the island
// return the maximum area of an island is grid. if there is not island, return 0.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int dfs(vector<vector<int>>&grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        int area=1;
        area+=dfs(grid,i+1,j);
        area+=dfs(grid,i-1,j);
        area+=dfs(grid,i,j+1);
        area+=dfs(grid,i,j-1);
        return area;
    }
    public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    maxArea=max(maxArea,dfs(grid,i,j));
                }
            }
        }
        return maxArea;
    }


};