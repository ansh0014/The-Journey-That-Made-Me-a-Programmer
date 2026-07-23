// now i am doing the K-th largest perfect Subtree Size in binary tree
// i have given the root of binary tree and an integer k.
// Return an integer denoting the size of the kth largest perfect binary subtree, or -1 if it doesn't exist.
// A perfect binary tree is a binary tree in which all interior nodes have two children and all leaves have the same depth or same level.
// i have to use the dfs to find the size of the perfect binary subtree. i will check if the left and right child of the current node are perfect binary trees and if they are, then i will return the size of the current subtree. finally, i will sort the sizes of the perfect binary subtrees and return the kth largest size.
#include<bits/stdc++.h>
using namespace std;
class Solution{    
vector<int> sizes;
    int dfs(TreeNode* root){
      
        if(root==NULL) return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==-1 || right==-1) return -1;
        if(left==right) {
            sizes.push_back(left+right+1);
            return left+right+1;
        }
        return -1;
    }

public:
    int kthLargestPerfectSubtree(TreeNode* root, int k){
      
 
        dfs(root);
        sort(sizes.rbegin(),sizes.rend());
        if(k>sizes.size()) return -1;
        return sizes[k-1];
    }
};