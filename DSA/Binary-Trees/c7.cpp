// now i am doing the construct binary tree from the preorder and inorder traversal
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// class Solution
// {
// public:
    
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
//     {
//         int n = preorder.size();
//         int m = inorder.size();
//         if (n == 0)
//             return NULL;
//         if (m == 0)
//             return NULL;
//         map<int, int> mp;
//         for (int i = 0; i < m; i++)
//         {
//             mp[inorder[i]] = i;
//         }
//         TreeNode *root = buildTree(preorder, inorder, 0, n - 1, 0, m - 1, mp);
//         return root;
//     }
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int prestart, int preend, int instart, int inend, map<int, int> &mp)
//     {
//         if (prestart > preend || instart > inend)
//             return NULL;
//         TreeNode *root = new TreeNode(preorder[prestart]);
//         int inroot = mp[preorder[prestart]];
//         int numsleft = inroot - instart;
//         root->left = buildTree(preorder, inorder, prestart + 1, prestart + numsleft, instart, inroot - 1, mp);
//         root->right = buildTree(preorder, inorder, prestart + numsleft + 1, preend, inroot + 1, inend, mp);
//         return root;
//     }
// };
// now i am doing the construct binary tree from the postorder and inorder traversal
class Solution{
public:
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    int n = postorder.size();
    int m = inorder.size();
    if(n == 0) return NULL;
    if(m == 0) return NULL;
    map<int,int> mp;
    for(int i = 0; i < m; i++){
        mp[inorder[i]] = i;
    }
    TreeNode* root = buildTree(inorder, postorder, 0, m - 1, 0, n - 1, mp);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int poststart, int postend, map<int,int> &mp){
    if(poststart > postend || instart > inend) return NULL;
    TreeNode* root = new TreeNode(postorder[postend]);
    int inroot = mp[postorder[postend]];
    int numsleft = inroot - instart;
    root->left = buildTree(inorder, postorder, instart, inroot - 1, poststart, poststart + numsleft - 1, mp);
    root->right = buildTree(inorder, postorder, inroot + 1, inend, poststart + numsleft, postend - 1, mp);
    return root;
}
};