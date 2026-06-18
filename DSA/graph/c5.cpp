// now we are doing the disjkstra
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int> dist(V,1e9);
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int dis=it.first;
            for(auto it:adj[node]){
                int adjweight=it[0];
                int adjnode=it[1];
                if(dis+adjweight<dist[adjnode]){
                    dist[adjnode]=dis+adjweight;
                    pq.push({dis+adjweight,adjnode});
                }
            }
        }
        return dist;
    }
};