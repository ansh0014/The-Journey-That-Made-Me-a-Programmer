// now i am doing the minimum number of operations to sort a binary tree by level.
// i have given the root of a binary tree with unique values.
// in one operation, i can choose any two noeds at the same level ans swap their value
// return the minimum number of oerpations needed to make the value at each level sorted in strictly increasing order.
// the level of a node is the number of edges along the path between it and the root node.
// we can you greedy approach to solve this problem. we will traverse the binary tree level by level and for each level, we will sort the values and count the number of swaps needed to sort them. we can use a map to keep track of the original indices of the values and then use a visited array to mark the nodes that have already been placed in their correct position. we will then iterate through the values and for each value that is not in its correct position, we will swap it with the value that is currently in its correct position and mark both values as visited. we will continue this process until all values are in their correct positions and return the total number of swaps needed.
// for traverse i want to use depth first search (dfs) to traverse the binary tree level by level. we will use a queue to keep track of the nodes at each level and for each node, we will add its left and right children to the queue. we will also keep track of the current level and when we reach a new level, we will sort the values and count the number of swaps needed to sort them. we will continue this process until we have traversed all levels of the binary tree and return the total number of swaps needed.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOperations(TreeNode* root){
  if(root==NULL) return 0;
  int ops=0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        vector<int>sortedLevel=level;
        sort(sortedLevel.begin(),sortedLevel.end());
        unordered_map<int,int>indexMap;
        for(int i=0;i<sortedLevel.size();i++){
            indexMap[sortedLevel[i]]=i;
        }
        vector<bool>visited(level.size(),false);
        for(int i=0;i<level.size();i++){
            if(visited[i] || indexMap[level[i]]==i) continue;
            int cycleSize=0;
            int j=i;
            while(!visited[j]){
                visited[j]=true;
                j=indexMap[level[j]];
                cycleSize++;
            }
            if(cycleSize>0) ops+=cycleSize-1;
        }
    }
    return ops;
}
};