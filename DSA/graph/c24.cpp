// now i am doing the most stonres removed with same row or column
// on a 2d plane we plance n stones at some integer corrdiante points. each coordiane point have at most one stone 
// a stone can be removed if it shares either the same row or the same column as another stone that has not been removed
// given an array stones of length n where stones[i] = [xi, yi] represents
// approach  we can remove a stone if it shares either the same row or the same column as another stone that has not been removed
// we can use dfs to solve this problem
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited);
            }
        }
        return 1;
    }
    public:
    int removStones(vector<vector<int>>& stones){
        int n = stones.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i, adj, visited);
            }
        }
        return n - count;
    }
};