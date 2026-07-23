// now i am doing the Print the Binary tree
// given the root fo a binary tree, construct a 0-indexed m*n string matrix res that represents a formatted layout of the tree. the formatted layout martix should be constructed using the following rules
// the height of the tree is height and the number of rows m should be equla to height+1.
// the number of columns n should be equal to 2^(height+1)-1.
// approach i will use the recursion to print the binary tree. i will find the height of the binary tree and then i will create a matrix of size m*n and then i will fill the matrix with the values of the binary tree. finally, i will return the matrix.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<string>> printTree(TreeNode* root){
        if(root==NULL) return {};
        int height=0;
        function<void(TreeNode*,int)> dfs=[&](TreeNode* node,int h){
            if(node==NULL) return;
            height=max(height,h);
            dfs(node->left,h+1);
            dfs(node->right,h+1);
        };
        dfs(root,0);
        int m=height+1;
        int n=(1<<(height+1))-1;
        vector<vector<string>> res(m,vector<string>(n,""));
        function<void(TreeNode*,int,int,int)> fill=[&](TreeNode* node,int r,int c,int w){
            if(node==NULL) return;
         res[r][c]=to_string(node->val);
         if(w==0) return;
         fill(node->left,r+1,c-w,w/2);
         fill(node->right,r+1,c+w,w/2);
        };
       int s=(height==0)?0:(1<<(height-1));
       fill(root,0,(n-1)/2,s);
         return res;
    }
};