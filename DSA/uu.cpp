// now i am doing the minimum edge weight Equilibrium queries in tree
// we use the find the path u to v
// count the frequency of each weight on pth
// answer=total_edges - max_frequency
#include <bits/stdc++.h>
using namespace std;
const int LOG=18;
int par[50005][LOG];
int dep[50005];
int freq[50005][27];
vector<pair<int,int>> adj[50005];
class Solution {
public:


void dfs(int node, int parent, int depth) {
    dep[node] = depth;
    par[node][0] = (parent == -1) ? node : parent;

    for (int k = 1; k < LOG; k++) {
        par[node][k] = par[par[node][k-1]][k-1];
    }

    for (auto& edge : adj[node]) {
        int child = edge.first;
        int w = edge.second;
        if (child != parent) {

            for (int i = 1; i <= 26; i++) {
                freq[child][i] = freq[node][i];
            }
            freq[child][w]++;
            dfs(child, node, depth + 1);
        }
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for (int k = 0; k < LOG; k++) {
        if ((diff >> k) & 1) {
            u = par[u][k];
        }
    }
    if (u == v) return u;
    for (int k = LOG - 1; k >= 0; k--) {
        if (par[u][k] != par[v][k]) {
            u = par[u][k];
            v = par[v][k];
        }
    }
    return par[u][0];
}  

   vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
for(int i=0;i<n;i++){
    adj[i+1].clear();
    for(int j=1;j<=26;j++){
        freq[i+1][j]=0;
    }
}
    for (auto& edge : edges) {
        int u = edge[0]+1;
        int v = edge[1]+1;
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    
    }
    dfs(1, -1, 0);
    vector<int>ans;
    for (auto& query : queries) {
    int u = query[0]+1;
    int v = query[1]+1;
    int l = lca(u, v);
    int path_length = dep[u] + dep[v] - 2 * dep[l];
    int max_freq = 0;
    for(int i = 1; i <= 26; i++) {
        int freq_count = freq[u][i] + freq[v][i] - 2 * freq[l][i];
        max_freq = max(max_freq, freq_count);
    }
    ans.push_back(path_length - max_freq);
}
return ans;
   
}
};