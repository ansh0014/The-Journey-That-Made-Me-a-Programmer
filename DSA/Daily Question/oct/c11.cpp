// now i am doing the check knight tour configuration
// there is a knight on n*n chessboard. in a valid configuration, the knight starts at top-left cell of board and visits every cell on the board exactly once.
// i have given an n*n integer matrix grid consisitnng of distinct integer from the range [0, n*n - 1]. where grid [row][col] indicates that the knight is at that position in the tour.
//
//  return true if grid represents a valid configuration of knight's tour, or false otherwise.
// this question is simple bfs question we have to check the knight tour configuration is valid or not
// return the true if grid represents a valid configuration of knight's tour, or false otherwise.

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool checkValidGrid(vector<vector<int>>& grid) {
int n=grid.size();
if(grid[0][0]!=0) return false;
vector<vector<int>> vis(n,vector<int>(n,0));
queue<pair<int,int>> q;
q.push({0,0});
vis[0][0]=1;
while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    int val=grid[x][y];
    if(val==n*n-1) return true;
    vector<pair<int,int>> moves={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    for(auto move:moves){
        int newX=x+move.first;
        int newY=y+move.second;
        if(newX>=0 && newX<n && newY>=0 && newY<n && !vis[newX][newY] && grid[newX][newY]==val+1){
            vis[newX][newY]=1;
            q.push({newX,newY});
        }
    }

}
return false;
    }
};