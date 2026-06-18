// now i am doing hte flatten bianry tree to linked list
// i understand the question i have to flatten the binary tree to linked list in place and the linked list should be in the same order as the pre order traversal of the binary tree
// i used preoder recurssion `to do the flattening of the binary tree to linked list
// #include<bits/stdc++.h>
// using namespace std;
// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// class Solution{
//     public:
//     TreeNode* prev=NULL;
//     void flatten(TreeNode* root){
//         if(root==NULL) return;
        
//         flatten(root->right);
//         flatten(root->left);
//         root->right=prev;
//         root->left=NULL;
//         prev = root;
//     }
// };

// now i am doing the path sum 11
// i understand the question i have to find the path from root to leaf node and sum of the path should according ot give target
// i have to make find the subtree and then find the path from root to leaf node and then find the sum of the path and then check if the sum is equal to target or not if it is equal to target then return true else return false
// in output i have to find the subtree
// aaproach i have to used recurssion + backtracking to find the path from root to leaf node and then find the sum of the path and then check if the sum is equal to target or not if it is equal to target then return true else return false
// for traversal i have to used preoder traversal to find the path from root to leaf node and then find the sum of the path and then check if the sum is equal to target or not if it is equal to target then return true else return false
// #include<bits/stdc++.h>
// using namespace std;
// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// class Solution{
//     public:
//       vector<vector<int>> pathSum(TreeNode* root, int targetSum){
//         vector<vector<int>> ans;
//         vector<int> path;
//         findPath(root, targetSum, path, ans);
//         return ans;
//       }
//       void findPath(TreeNode* root, int targetSum, vector<int>&path,vector<vector<int>>& ans){
//         if(root==NULL) return;
//         path.push_back(root->val);
//         if(root->left==NULL && root->right==NULL && root->val==targetSum){
//             ans.push_back(path);
//         }
//         findPath(root->left, targetSum-root->val, path, ans);
//         findPath(root->right, targetSum-root->val, path, ans);
//         path.pop_back();
//       }
// };
// now i am doing the paths sum this is i have to return only true and false
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
    public:
    bool hasPathSum(TreeNode* root, int targetSum){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL && root->val==targetSum) return true;
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }

    

};
