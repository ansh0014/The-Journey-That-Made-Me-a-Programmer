// now i am doing hte kth smalles element in a bst
// i have do the inorder because it also the sorted manner and i have to check the count of the left subtree if it is equal to k-1 then i have to return the root value if it is less than k-1 then i have to go to right and if it is greater than k-1 then i have to go to left
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:


// int solve(TreeNode* root,int &k){
//     if(root==NULL) return -1;
//     int left=solve(root->left,k);
//     if(left!=-1) return left;
//     k--;
//     if(k==0) return root->val;
//     return solve(root->right,k);
// }
// int kthSmallest(TreeNode* root, int k){
//     return solve(root,k);
// }
// };

// now i am doing hte validate binary search tree
// i have to check the propery of BST that is L<N<R
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int solve(TreeNode* root,long min,long max){
        if(root==NULL) return true;
        if(root->val<=min || root->val>=max) return false;
        return solve(root->left,min,root->val) && solve(root->right,root->val,max);
    }

bool isValidBST(TreeNode* root){
    return solve(root,LONG_MIN,LONG_MAX);
}

};