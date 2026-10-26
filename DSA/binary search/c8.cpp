// now i am doing the given the root of a binary search tree BST convert it to greater tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST
// as a reminder a binary search tree that satifies these constraints:
// the left substree of node contains only nodes with key less than the node's key
// the right subtree of node contains only nodes with key greater than nodes key
// both the left and right subtrees must also be binary search trees
// we used recurssive appraoch and mention some condtion
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
      TreeNode* solve(TreeNode* root,int &sum){
        if(root==NULL) return NULL;
        solve(root->right,sum);
        sum+=root->val;
        root->val=sum;
        solve(root->left,sum);
        return root;
    }
 TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        return solve(root,sum);
    }
  
}; 
