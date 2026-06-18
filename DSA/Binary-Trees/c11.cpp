// now i am doing the sum of left leaves
// i have to used inorder traversal to find the left leaves and then i have to sum the left leaves and then return the sum
// #include<bits/stdc++.h>
// using namespace std;
// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x): val(x), left(NULL), right(NULL){}
// };
// class Solution{
// public:
// int sumOfLeftLeaves(TreeNode* root){
//     if(root==NULL) return 0;
//     int sum=0;
//     if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL){
//         sum+=root->left->val;
//     }
//     sum+=sumOfLeftLeaves(root->left);
//     sum+=sumOfLeftLeaves(root->right);
//     return sum;
// }
// };
// now i am doing hte subtree of another tree
// we have to traverse the tree s and for each node in s we have to check if the subtree rooted at that node is same as t or not
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class Solution{
    public:
    bool isSameTree(TreeNode* s, TreeNode* t){
        if(s==NULL && t==NULL) return true;
        if(s==NULL || t==NULL) return false;
        if(s->val!=t->val) return false;
        return isSameTree(s->left,t->left) && isSameTree(s->right,t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t){
        if(s==NULL) return false;
        if(isSameTree(s,t)) return true;
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};