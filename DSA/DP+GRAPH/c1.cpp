// now i am doing the largest colr value in a directed graph
// there is a directed graph of n colored nodes and m edges. the nodes are numbered from 0 to n-1.
// i have given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). i have given a 2D array edges where edges[j]=[aj,bj] indicates that there is a directed edge from node aj to node bj.
// A valid path in the graph is a sequence of nodes 
// approach i will use topological sort to find the largest color in dag  (dfs) and if there is a cycle in the graph then i will return -1
// for valid path i will use dp to find the largest color value in a directed graph
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& onPath, bool& hasCycle, vector<int>& topoSort){
    if(onPath[node]){
        hasCycle=true;
        return;
    }
    if(visited[node] || hasCycle) return;
    visited[node]=true;
    onPath[node]=true;
    for(int neighbor: graph[node]){
        dfs(neighbor, graph, visited, onPath, hasCycle, topoSort);
    }
    onPath[node]=false;
    topoSort.push_back(node);
}
int largestPathValue(string colors, vector<vector<int>>& edges){
    int n=colors.size();
    vector<vector<int>> graph(n);
    for(auto &edge: edges){
        graph[edge[0]].push_back(edge[1]);
    }
    vector<bool> visited(n, false);
    vector<bool> onPath(n, false);
    bool hasCycle=false;
    vector<int> topoSort;
for(int i=0; i<n; i++){
    if(!visited[i]){
        dfs(i, graph, visited, onPath, hasCycle, topoSort);
    }

}
if(hasCycle) return -1;
reverse(topoSort.begin(), topoSort.end());
vector<vector<int>> dp(n, vector<int>(26, 0));
int ans=0;
for(int node:topoSort){
    dp[node][colors[node]-'a']++;
    ans=max(ans, dp[node][colors[node]-'a']);
    for(int neighbor: graph[node]){
        for(int c=0; c<26; c++){
            dp[neighbor][c]=max(dp[neighbor][c], dp[node][c]);
        }
    }
}
return ans;

}
};