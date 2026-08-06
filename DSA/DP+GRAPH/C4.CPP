// now i am doing the minimum cost Path with Alternating Directions 111
// i have given two interges ma and n representing the number of row and columns of a grid . My goal is reah cell (m-1,n-1) i
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    using ll= long long;
    const ll INF=1e18;
    long long minCost(int m , int n, vector<vector<int>>& penalty){
        vector<vector<vector<ll>>> d(m, vector<vector<ll>>(n, vector<ll>(2,INF)));
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
        d [0][0][0]=1;
        pq.push({1,0,0,0});
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        ll dis=cur[0];
        int x=cur[1];
        int y=cur[2];
        int t=cur[3];
        if(dis!=d[x][y][t]) continue;
        if(dis+penalty[x][y]<d[x][y][t^1]){
            d[x][y][t^1]=dis+penalty[x][y];
            pq.push({d[x][y][t^1],x,y,t^1});

        }
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            ll w=1LL*(nx+1)*(ny+1);
            bool ok=false;
            if(t==0){
                if((dx[k]==1 && dy[k]==0)|| (dx[k]==0 && dy[k]==1)){
                    ok=true;
                }
            }
                else{
                   if ((dx[k] == -1 && dy[k] == 0) ||
                        (dx[k] == 0 && dy[k] == -1))
                        ok = true;
                }
                if(!ok){
                    w+=penalty[x][y];
                }
                if(dis+w<d[nx][ny][t]){
                    d[nx][ny][t]=dis+w;
                    pq.push({d[nx][ny][t],nx,ny,t});
                }
            }
        }
        return min(d[m-1][n-1][0],d[m-1][n-1][1]);
    }
};