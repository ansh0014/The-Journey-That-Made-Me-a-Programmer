// nwo i am doing the maximum level sum of binary tree
// given the root of a binary tree the lvel of its root 1, the lvel of it children in 2, and so on
// return the smallest level x such that sum of all values of nodes at level x is maximal 
// we have bfs level order travesal then write one condtion
// for level order we have used queue and push the root in it then while que is not empty we will take the size of que and then we will run a loop from 0 to size-1 and then we will pop the front of que and add its value to sum and then we will push its left child and right child in que if they are not null
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
    public:
    int maxLevelSum(TreeNode* root) {
     if(root==NULL) return 0;
     queue<TreeNode*>q;
     int sum=0;
     int maxsum=INT_MIN;
     int level=0;
     q.push(root);
     int ans=0;
     while(!q.empty()){
        int n =q.size();
        level++;
        sum=0;
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            sum+=node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(sum>maxsum){
            maxsum=sum;
            ans=level;
        }
     }   
     return ans;
    }
};