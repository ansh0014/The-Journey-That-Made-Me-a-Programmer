// now we are doing the shortest path visiting allnodes
// we can use the bitmask for this question and bfs
// approach is to use bfs and store the state of the node and the visited nodes in a queue
// but i have think for state then the trasition is to go to the next node and mark it as visited and then push it into the queue
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, pair<int, int>>> q; // node, mask, steps
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        
        for(int i = 0; i < n; i++) {
            q.push({i, {1 << i, 0}});
            visited[i][1 << i] = true;
        }
        
        while(!q.empty()) {
            auto [node, state] = q.front();
            auto [mask, steps] = state;
            q.pop();
            
            if(mask == (1 << n) - 1) return steps;
            
            for(int neighbor : graph[node]) {
                int newMask = mask | (1 << neighbor);
                if(!visited[neighbor][newMask]) {
                    visited[neighbor][newMask] = true;
                    q.push({neighbor, {newMask, steps + 1}});
                }
            }
        }
        
        return -1; 
    }
};