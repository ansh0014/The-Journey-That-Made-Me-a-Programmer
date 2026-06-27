// now i am doing the eventual safe state
// i think this question use indegree and outdegree concept
// i have to find the safe node safe node is that node which is terminal node or node which is connected with terminal node
// terminal node is that node which has not outoging
// i have to used topological sort using khan's algorithm
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n=graph.size();
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j:graph[i]){
                adj[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safeNodes.push_back(node);
            for(int neighbour:adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};