// now we do the prims algorithm
#include<bits/stdc++.h>
using namespace std;
class Solutio{
public:
int spanningtree(int v,vector<vector<int>> adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    vector<int> vis(v,0);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;
        if(vis[node] ==1){
            continue;
        }
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node]){
            int adjnode=it[0];
            int edw=it[1];
            if(vis[adjnode]==0){
                pq.push({edw,adjnode});
            }
        }
    
    }
    return sum;

}
};