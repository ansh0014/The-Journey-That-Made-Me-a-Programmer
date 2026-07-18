// now i am doing the invert binary tree
// approach: i will use recursion to invert the binary tree. i will swap the left and right child of each node and then recursively call the function on the left and right child. finally, i will return the root of the inverted binary tree.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    TreeNode* invertTree(TreeNode* root){
        if(root==NULL) return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};