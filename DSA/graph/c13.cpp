// now i am doing the eventual safe state
// i think this question use indegree and outdegree concept
// i have to find the safe node safe node is that node which is terminal node or node which is connected with terminal node
// terminal node is that node which has not outoging
// i have to used topological sort we used dfs for making stack to check i have to use visited
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool dfs(int node, vector<vector<int>>& graph,vector<int>& visited){
        if(visited[node]==1){
            return true;
        }
        if(visited[node]==2){
            return false;
        }
        visited[node]=1;
        for(auto it:graph[node]){
            if(!dfs(it,graph,visited)){
                return false;
            }
        }
        visited[node]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,0);
        vector<int>safeNodes;
        for(int i=0;i<n;i++){
            if(dfs(i,graph,visited)){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};