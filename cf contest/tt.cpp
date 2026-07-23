#include<bits/stdc++.h>
using namespace std;

long long countCompatiblePairs(int warehouse_nodes, vector<int> warehouse_from, vector<int> warehouse_to, vector<int> warehouse_weight, vector<int> val) {
    
    int n = warehouse_nodes;
    vector<vector<pair<int,int>>> adj(n + 1);
    
    for (int i = 0; i < (int)warehouse_from.size(); i++) {
        int u = warehouse_from[i];
        int v = warehouse_to[i];
        int w = warehouse_weight[i];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    // we used  vector  for storing rootDist, nodeNumber of current ancestors
    vector<pair<long long, int>> ancestors;
    long long ans = 0;
    
    function<void(int, int, long long)> dfs = [&](int node, int par, long long dist) {
        

        long long threshold = dist - (long long)val[node - 1];
        
        for (auto& p : ancestors) {
            // p.first = ancestor's root distance
            // dist - p.first = distance from ancestor to current node
            if (p.first >= threshold) {
                ans++;
            }
        }
        
        // add current node to ancestors before going to children
        ancestors.push_back({dist, node});
        
        for (auto& edge : adj[node]) {
            int child = edge.first;
            int w = edge.second;
            if (child != par) {
                dfs(child, node, dist + w);
            }
        }
        
        // backtrack - remove current node
        ancestors.pop_back();
    };
    
    dfs(1, -1, 0LL);
    
    return ans;
}