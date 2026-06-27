// Shortest Path in Directed Acyclic Graph
// we are using the topological sort to find the shortest path in directed acyclic graph
#include<bits/stdc++.h>
using namespace std;
class Solution{
    void dfs(int node,vector<pair<int,int>> adj[],int visited[],stack<int> &st){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it.first]){
                dfs(it.first,adj,visited,st);
            }
        }
        st.push(node);
    }
public:
vector<int> shortestPath(int n,int m,vector<int> edges[]){
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }
    int visited[n]={0};
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }
vector<int> dist(n);
for(int i=0;i<n;i++){
    dist[i]=1e9;

}
dist[0]=0;
while(!st.empty()){
    int node=st.top();
    st.pop();
    for(auto it:adj[node]){
      int v=it.first;
      int wt=it.second;
        if(dist[node]+wt<dist[v]){
            dist[v]=dist[node]+wt;
        }
    }

}
return dist;
}
};
