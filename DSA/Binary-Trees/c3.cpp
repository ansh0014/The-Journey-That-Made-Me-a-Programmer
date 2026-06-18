// now i am doning the balanced binary tree
// i understand the logic i have to check the root left and right it they are balanced return true else false
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
//    int height(TreeNode* root){
//         if(root==NULL) return 0;
//         return 1+max(height(root->left),height(root->right));
//     }
// bool isBalanced(TreeNode* root){
 
//     if(root==NULL) return true;
//     int lh=height(root->left);
//     int rh=height(root->right);
//     if(abs(lh-rh)>1) return false;
//     else return isBalanced(root->left) && isBalanced(root->right);

// }


// };
// // now i am doing the binary tree maximum path sum
// // i understand the logic i have to tranverse the tree we use the recussion for that then find the maximum path sum for that we sum all path sum then compare then we get maximum path sum i return the it
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
// int maxPathSum(TreeNode* root){
//     int ans=INT_MIN;
//     if(root==NULL) return 0;
    
//     int l=max(0, maxPathSum(root->left));
//     int r=max(0, maxPathSum(root->right));
//     int sum=root->val+l+r;
    
//     ans=max(ans,sum);
//     return root->val+max(l,r);
// }
// };

// now i am doing the same tree
// i understand the logic i have to check the left and right subtree of the tree if they are same then return true else false
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
// bool isSameTree(TreeNode* p, TreeNode* q){
//     if(p==NULL && q==NULL) return true;
//     if(p==NULL || q==NULL) return false;
//     if(p->val!=q->val) return false;
//     return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

// }
// now i am doing the binary tree zizag level order tranversal
// i understand the i have to use the recursion for that and i have to use the queue for that and i have to check the level of the tree if it is even then i have to push the left to right else right to left
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
// vector<vector<int>> zigzagLevelOrder(TreeNode* root){
//     vector<vector<int>>ans;
// if(root==NULL)return ans;
// queue<TreeNode*> q;
// q.push(root);
// int l=0;
// while(!q.empty()){
//     int s=q.size();
// vector<int> v(s);
// for(int i=0;i<s;i++){
//     TreeNode* node=q.front();
//     q.pop();
//     int index=(l%2==0)?i:(s-1-i);
//     v[index]=node->val;
//     if(node->left) q.push(node->left);
//     if(node->right) q.push(node->right);
// }
// ans.push_back(v);
// l++; 
// }
// return ans;
// }
// };