// now i am doing the shortest path to get all key
// dp+graph question
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int shortestPathAllKeys(vector<string>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int allkeys=0;
        int startx,starty;
        // first we find the starting point and the keys
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    startx=i;
                    starty=j;
                }
                else if(grid[i][j]>='a' && grid[i][j]<='f'){
                allkeys++;
                }
            }
        }
        int targetmask=(1<<allkeys)-1;
        // now we make bfs
        vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(1<<allkeys,false)));
        queue<tuple<int,int,int,int>> q;
        q.push({startx,starty,0,0});
        visited[startx][starty][0]=true;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty()){
            auto[x,y,mask,dist]=q.front();
            q.pop();
            if(mask==targetmask) return dist;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
                char c=grid[nx][ny];
                if(c=='#') continue;
                int newmask=mask;
                if(c>='a' && c<='f'){
                    newmask|=(1<<(c-'a'));
                }
                if(c>='A' && c<='F'){
                    if(!(mask&(1<<(c-'A')))) continue;
                }
                if(!visited[nx][ny][newmask]){
                    visited[nx][ny][newmask]=true;
                    q.push({nx,ny,newmask,dist+1});
                }
            }
        }
        return -1;
    }

};