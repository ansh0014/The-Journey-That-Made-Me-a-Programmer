// swim in rising water
// i have given an n*n grid integer matrix grid where each value grid[i][j] represents the elevation at that point (i,j).
// it starts raining and water gradually rised over time. At time t, the water level is t, meaning any cell with elevation less that equal to t is submerged or reachable.
// i can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squeares individually are at most t. we can swim infinite distances in zero time. of course, you must stay within the boundaries of the grid during our swim
// return the least time until i can reach the bottom right square (n-1, n-1) if i start at the top left square (0, 0).
// we used the dijkstra's algorithm to solve this problem. we can use a priority queue to keep track of the minimum time to reach each cell. we start from the top left cell and explore its neighbors, updating their minimum time if we find a better path. we continue this process until we reach the bottom right cell, at which point we return the minimum time to reach it.
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int swimInWater(vector<vector<int>>& grid) {
int n = grid.size();
vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
distance[0][0] = grid[0][0];
pq.push({distance[0][0], {0, 0}});
int dr[]={-1, 1, 0, 0};
int dc[]={0, 0, -1, 1};
while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
    int time=it.first;
    int r=it.second.first;
    int c=it.second.second;
    if(time>distance[r][c]) continue;
    if(r==n-1 && c==n-1) return time;
    for(int i=0; i<4; i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr>=0 && nr<n && nc>=0 && nc<n){
            int newTime=max(time, grid[nr][nc]);
            if(newTime<distance[nr][nc]){
                distance[nr][nc]=newTime;
                pq.push({newTime, {nr, nc}});
            }
        }
    }
    
}
return -1;
}
};