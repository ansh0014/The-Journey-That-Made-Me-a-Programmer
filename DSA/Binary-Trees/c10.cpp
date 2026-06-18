// now i am doing the longes specail path
// i have to understand the question
// i have given the array of 3 ediges ui vi means 1 2 3 means one root is 1 and secodn is 2 distance between 1 and 2 is 3
// now i have give hte nums[i] means the value of the node i is nums[i]
// i have to understdn what is meaning of nums[i] means the value of the node i is nums[i] example if i is 1 and nums[1] is 5 then the value of node 1 is 5
// i have to find the longest specail path in the tree
// appraoch i have to used the dfs preorder traversal and i have to used the map to store the value of the node and the distance from the root to that node
// nums is used to prevent the duplicate because i need the unique path i have to check value of node then find the path
// i have to used the backtracking to find the longest specail path in the tree
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxdis = 0;
    int minNodes = INT_MAX;
    void dfs(int node, int parent, int currentdis, vector<vector<pair<int,int>>>&children,  int nodesCount, vector<int> &nums, unordered_set<int> &used_values)
    {
        if (used_values.count(nums[node]) > 0)
            return;
        used_values.insert(nums[node]);
        nodesCount++;
        if (currentdis > maxdis)
        {
            maxdis = currentdis;
            minNodes = nodesCount;
        }
        else if (currentdis == maxdis)
        {
            minNodes = min(minNodes, nodesCount);
        }
        // i have to go the downward(children) of the node and i have to check the distance and the value of the node
        for (auto &edge : children[node])
        {
            int nextNode = edge.first;
            int weight = edge.second;
            dfs(nextNode, node, currentdis + weight, children, nodesCount, nums, used_values);
        }
        used_values.erase(nums[node]);
    }
    vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
       vector<vector<pair<int,int>>> children(n); 

        function<void(int,int)> build = [&](int node, int parent){
            for(auto &edge : adj[node]){
                int next = edge.first;
                int wt = edge.second;
                if(next == parent) continue;
                children[node].push_back({next, wt});
                build(next, node);
            }
        };

        build(0, -1);

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> used_values;
   dfs(i, -1, 0, children, 0, nums, used_values);
        }
        return {maxdis, minNodes};
    }
};
// ooh i got the tle because i am doing the dfs for each node and i am checking the distance and the value of the node and i am using the backtracking to find the longest specail path in the tree
// i have to optimize the code by using the memoization to store the result of the dfs for each node and i have to check the distance and the value of the node and i have to return the result from the memoization if it is already calculated
