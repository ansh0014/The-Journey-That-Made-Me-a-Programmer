// now i am doing with path with Minimum effort
// i have given a 2D array heights where heights[i][j] is the height of cell (i,j) of a 2D grid
// return the minimum effort path from the top-left cell (0,0) to the bottom
// we used dijkstra algorithm for that and we have to find the minimum effort path from the top-left cell (0,0) to the bottom
#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     int minimumEffortPath(vector<vector<int>> &heights)
//     {
//         int n = heights.size();
//         int m = heights[0].size();
// // we make the adjacency list
// vector<vector<pair<int,int>>>adj(n*m);
//    int dr[]={-1, 1, 0, 0};
//     int dc[]={0, 0, -1, 1};
//     for(int row=0;row<n;row++){
//         for(int col=0;col<m;col++){
//             int node=row*m+col;
//             for(int i=0;i<4;i++){
//                 int newRow=row+dr[i];
//                 int newCol=col+dc[i];
//                    if (newRow >= 0 && newRow < n &&
//                         newCol >= 0 && newCol < m) {

//                         int next = newRow * m + newCol;

//                         int diff = abs(heights[row][col] - heights[newRow][newCol]);

//                         adj[node].push_back({next, diff});
//             }
//         }
//     }
    

//     }
//     vector<int>dist(n*m,INT_MAX);
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//     dist[0]=0;
//     pq.push({0,0});
//     while(!pq.empty()){
//         int effort=pq.top().first;
//         int node=pq.top().second;
//         if(effort>dist[node]){
//             continue;
//         }
//         for(auto it:adj[node]){
//             int next=it.first;
//             int diff=it.second;
//             int newEffort=max(effort,diff);
//             if(newEffort<dist[next]){
//                 dist[next]=newEffort;
//                 pq.push({newEffort,next});
//             }
//         }
//     }
//     return dist[n*m-1];
// }
// };
class Solution{
    public:
    int minimumEffortPath(vector<vector<int>> &heights){
        int n=heights.size();
        int m=heights[0].size();
        vector<int>dis(n*m,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        dis[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
int effort=pq.top().first;
int node=pq.top().second;
pq.pop();
if(effort>dis[node]){
    continue;
        }
        int row=node/m;
        int col=node%m;
        for (int i = 0; i < 4; i++)
        {
            int newrow=row+dr[i];
            int newcol=col+dc[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m){
                int next=newrow*m+newcol;
                int diff=abs(heights[row][col]-heights[newrow][newcol]);
                int newEffort=max(effort,diff);
                if(newEffort<dis[next]){
                    dis[next]=newEffort;
                    pq.push({newEffort,next});
                }
            }
        }
        
        
    }
    return dis[n*m-1];
}
};