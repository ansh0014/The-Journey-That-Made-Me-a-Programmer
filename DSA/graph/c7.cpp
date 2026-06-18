// now i am doing THE Rotting oragnes
// i have adjacent list ahnd contion is the adjacent oranges get the rotten every minutes 
// i have presend 2 which already rotten 1 for fresh 0 no oranges
// have travel in 4 direction and check the adjacent oranges and make them rotten and count the time
// return the minimum number of time that mus elatpese until not cesll have fresh orages 
// if not possible return -1
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int orangesRotting(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        // we have apply the bfs for that and one visited array for that
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        // we have to push the all rotten oranges in the queue and mark them as visited
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        int time=0;
        // we have to travel in 4 direction and check the adjacent oranges and make them rotten and count the time
        vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int size=q.size();
            bool flag=false;
            for(int i=0;i<size;i++){
                auto [x,y]=q.front();
                q.pop();
                for(auto dir:directions){
                    int newX=x+dir.first;
                    int newY=y+dir.second;
                    if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1 && !visited[newX][newY]){
                        visited[newX][newY]=true;
                        q.push({newX,newY});
                        flag=true;
                    }
                }
            }
            if(flag){
                time++;
            }
        }
        // we have to check if there is any fresh orange left or not if left return -1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    return -1;
                }
            }
        }
        return time;
    }
};