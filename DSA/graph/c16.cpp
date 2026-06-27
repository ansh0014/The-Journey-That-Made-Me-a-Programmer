// now i am doing the Shortest path in Weighted Undirected graph
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> shortestPath(int n,int m,vector<vector<int>>& edges){
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,vector<pair<int,int>>>pq;

    vector<int>dist(n+1,1e9);
    vector<int>parent(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    dist[1]=0;
    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;
            if(dis+wt<dist[v]){
                dist[v]=dis+wt;
                parent[v]=node;
                pq.push({dist[v],v});
            }
        }
    

    }
    if(dist[n]==1e9){
        return {-1};
    }
    vector<int>path;
    int node=n;
    while(parent[node]!=node){
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    return path;

}
};