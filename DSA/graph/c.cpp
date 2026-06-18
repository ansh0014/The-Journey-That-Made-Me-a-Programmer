// now we are doing how i represent the graph
// two ways to represent the graph one is matrix way one is the vector way
#include<bits/stdc++.h>
using namespace std;
int main(){
    // int n,m;
    // // graph stored
    // cin>>n>>m;
    // int adj[n+1][m+1];
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u][v]=1;
    //     adj[v][u]=1;
    // }
    int n,m;
    cin>>n,m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // u and v are neighbours
        // directed graph
        // u--->v
        
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    return 0;
}