// right now i am doing the path with Maximum probability
// i have given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i]=[a,b] is an undirected edge connecting the nodes a and b with probability of success of traversing that edge succProb[i].
// given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
// If there is no path from start to end, return 0. the answer will be accepted if it differs from the correct answer by at most 1e-5.
// i have i implement the dijkstra's algorithm to solve this problem
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int m=edges.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }

priority_queue<pair<double,int>>pq;
vector<double>dist(n,0);
dist[start_node]=1;
pq.push({1,start_node});
while(!pq.empty()){
    
    double prob=pq.top().first;
    int node=pq.top().second;
    pq.pop();
    if(node==end_node){
        return prob;
    }
    for(auto it:adj[node]){
        int adjNode=it.first;
        double edgeProb=it.second;
        if(prob*edgeProb>dist[adjNode]){
            dist[adjNode]=prob*edgeProb;
            pq.push({dist[adjNode],adjNode});
        }
    }

}
return 0;
    }

};