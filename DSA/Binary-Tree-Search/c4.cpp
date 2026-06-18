// now i am doing the merge BSTs to create single BST
// i understand the question have give tree[0] and tree[1] and i have to merge them to create single BST
// 1. Store all trees in map
// 2. Find main root
// 3. DFS:
//     - check BST validity
//     - if leaf matches another tree → merge
// 4. In the end:
//     - all trees must be used
// for dfs i have to used the preorder
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// unordered_map<int,TreeNode*>mp;
// bool dfs(TreeNode* node,long minval,long maxval){
//     if(!node)return true;
//     if(node->val<=minval||node->val>=maxval)return false;
//     if(!node->left&&!node->right&&mp.count(node->val)){
//         TreeNode* mergeTree=mp[node->val];
//             if(mergeTree!=node){
//         node->left=mergeTree->left;
//         node->right=mergeTree->right;
//         mp.erase(node->val);
//     }
//     }
// return dfs(node->left,minval,node->val)&&dfs(node->right,node->val,maxval);
// }
// TreeNode* canMerge(vector<TreeNode*>& trees){
//     unordered_set<int>childs;
//     for(auto tree:trees)mp[tree->val]=tree;
//     for(auto tree:trees){
//         if(tree->left)childs.insert(tree->left->val);
//         if(tree->right)childs.insert(tree->right->val);
//     }
//     TreeNode* root=NULL;
//     for(auto tree:trees){
//         if(!childs.count(tree->val)){
//             root=tree;
//             break;
//         }
//     }
 
//     if(!root)return NULL;
//     mp.erase(root->val);
//     return dfs(root,LONG_MIN,LONG_MAX)&&mp.empty()?root:NULL;
// }
   
// };
// now i am doing maximum sum bst in binary tree
// i understadn the question i have to return the sum of the maximum subtree 
// for that i have to traverse the tree and using hte hashmap for storing hte value and check the sum also for that i have to check the left and right subtree sum and if they are bst then only i will add the sum of the left and right subtree with the current node value and update the maximum sum
// in bst follow l<n<r follow we insurre the value for that we don't serach whole tree 
// i have if l value is greater than current node value then it is not bst and if r value is less than current node value then it is not bst
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
   vector<int>dfs(TreeNode* root,int &maxSum){

        if(!root)return {0,INT_MAX,INT_MIN};
        auto left=dfs(root->left,maxSum);
        auto right=dfs(root->right,maxSum);
        if(left[2]<root->val&&root->val<right[1]){
            int sum=left[0]+right[0]+root->val;
            maxSum=max(maxSum,sum);
            
            return {sum,min(root->val,left[1]),max(root->val,right[2])};
        }
        return {0,INT_MIN,INT_MAX};
    }
    int maxSumBST(TreeNode* root){
        int maxSum=0;
        dfs(root,maxSum);
        return maxSum;
    }
};