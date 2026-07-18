// longest cycle in a graph
// i have given a directed graph of n nodes numbered from 0 to n-1, where each node has at most one outgoing edge.
// the graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. if there is no outgoing edges.
// return the length of the longest cycle in the graph. if no cycle exists, return -1.
// a cycle is a path that starts and ends at the same node.
// approach  khan's algorithm
// in this approach, we will use Kahn's algorithm to find the longest cycle in a directed graph. The idea is to perform a topological sort and keep track of the nodes that are part of cycles. We will use an array to keep track of the in-degrees of each node and a queue to process nodes with zero in-degrees. After processing all nodes, we will check for cycles and calculate their lengths.
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> inDegree(n, 0);
        
        // Calculate in-degrees
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                inDegree[edges[i]]++;
            }
        }
        
        queue<int> q;
        // Add nodes with zero in-degree to the queue
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Perform Kahn's algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            if (edges[node] != -1) {
                inDegree[edges[node]]--;
                if (inDegree[edges[node]] == 0) {
                    q.push(edges[node]);
                }
            }
        }
        
        // Check for cycles and calculate their lengths
        int longestCycleLength = -1;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (inDegree[i] > 0 && !visited[i]) {
                int currentNode = i;
                int cycleLength = 0;
                
                while (!visited[currentNode]) {
                    visited[currentNode] = true;
                    cycleLength++;
                    currentNode = edges[currentNode];
                }
                
                longestCycleLength = max(longestCycleLength, cycleLength);
            }
        }
        
        return longestCycleLength;
    }
};
