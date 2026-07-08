// now i am doing the number of ways to arrive at destination
// I am in a city that consits of n intersection numbered from 0 to n-1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any ohter intersection and that there is at most one road between any two itnersections
// You are given an integer n and a 2D array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You are also given an integer destination. You want to know in how many different ways you can arrive at the destination intersection from the intersection 0 in the shortest amount of time. Return the number of ways you can arrive at the destination intersection from intersection 0 in the shortest amount of time. Since the answer may be large, return it modulo 10^9 + 7.
// Approach is to use dijkstra's algorithm for finding the shortest path from source to destination and
// approach we know we have to use dijkstra
// first we make the graph using adjacency list and then we use dijkstra's algorithm to find the shortest path from source to destination and we also keep track of the number of ways to reach each node in the shortest path
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int countPaths(int n,vector<vector<int>>&roads){
        vector<vector<pair<int,int>>>adj(n);
        for(auto &road:roads){
            int u=road[0];
            int v=road[1];
            int time=road[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
dist[0]=0;
ways[0]=1;
pq.push({0,0});
while(!pq.empty()){
    auto [d,u]=pq.top();
    pq.pop();
    if(d>dist[u])continue;
    for(auto &[v,time]:adj[u]){
        if(dist[u]+time<dist[v]){
            dist[v]=dist[u]+time;
            ways[v]=ways[u];
            pq.push({dist[v],v});
        }
        else if(dist[u]+time==dist[v]){
            ways[v]=(ways[v]+ways[u])%1000000007;
        }
    }
}
return ways[n-1];

    }
};
