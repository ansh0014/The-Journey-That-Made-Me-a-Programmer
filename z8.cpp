// now i am doing the shortest bridge
// i have givnen an n*n bianry martix gridp presentes aland and 0 represents water
// an island is 4-directionlayy connected grpup connec4ed to any other 1's is not connexted to any other 1's theres are exactly tow islands in grid
// i can change 0's to 1's toc onnect the two islands to form one island 
// return the smalles number of 0's i must flip toc onnec thte two islands
// i understand the question i have to flip the 0's to 1's to connect the two islands.
// approach we used bfs and then flip the no where 
// we used bfs to find the first island and then we used bfs to find the shortest path to the second island
// used bfs using some condition we have to flip the 0's to 1's to connect the two islands
#include <bits/stdc++.h>
using namespace std;
class Solution{
    // first we find the first island
    void find(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&vis, queue<pair<int,int>>&q, vector<int>&dir){
    bool found=false;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1 && !vis[i][j]){
                q.push({i,j});
                vis[i][j]=1;
                found=true;
                break;
            }
        }
        if(found){
            break;
        }
    }
}

    public:
    int shortestBridge(vector<vector<int>>& grid) {
     int n=grid.size();
vector<int>dir={0,1,0,-1,0};

vector<vector<int>>vis(n,vector<int>(n,0));
     queue<pair<int,int>>q;
     find(grid,0,0,vis,q,dir);
   while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nx = x + dir[k];
                int ny = y + dir[k + 1];

                if(nx >= 0 && nx < n &&
                   ny >= 0 && ny < n &&
                   grid[nx][ny] == 1 &&
                   !vis[nx][ny]) {

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]){
                q.push({i,j});
            }
        }
     }
     int distance=0;
     while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dir[k];
                int ny=y+dir[k+1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny]){
                    if(grid[nx][ny]==1){
                        return distance;
                    }
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        distance++;
     }

    return 0;
    
}

};
