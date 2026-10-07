// now i am doing the map of hieghtest peak
// i have given an integer martix isWater of size m*n that represents a map of land and cells
// if isWater[i][j]==0 means cell (i,j) is a land cell
// if isWater[i][j]==1 means cell (i,j) is a water cell
// you have to assign each cell a height in a way that follows the given rules:
// The height of each cell must be non-negative.
// If the cell is a water cell, its height must be 0.
// Any two adjacent cells must have an absolute height difference of at most 1. A cell
// approaches its adjacent cells if they share a side.
// we have use the bfs to find the height of each cell and we can use the queue to store the water cells and then we can iterate through the queue and for each water cell we can check its adjacent cells and if it is a land cell we can assign it a height of 1 and push it to the queue and continue this process until we have assigned height to all the land cells
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
       vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
 int m =isWater.size();
 int n = isWater[0].size();
 vector<vector<int>> ans(m,vector<int>(n,-1));
 queue<pair<int,int>> q;
 for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
         if(isWater[i][j]==1){
             ans[i][j]=0;
             q.push({i,j});
         }
        }
    }
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        int height=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto cell=q.front();
                q.pop();
                int x=cell.first;
                int y=cell.second;
                for(int j=0;j<4;j++){
                    int newX=x+dir[j][0];
                    int newY=y+dir[j][1];
                    if(newX>=0 && newX<m && newY>=0 && newY<n && ans[newX][newY]==-1){
                        ans[newX][newY]=height;
                        q.push({newX,newY});
                    }
               


                }
            }
            height++;
     }
         return ans;;
    }


    };
    
    
