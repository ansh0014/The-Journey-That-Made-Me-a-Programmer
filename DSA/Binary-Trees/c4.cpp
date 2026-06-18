// now i am doing the find the bottom left tree value 
// approach i have to used the level order traversal vertical traversal concept using the queue data structure
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:

//     int findBottomLeftValue(TreeNode* root){
//         if(root==NULL) return -1;
//         queue<TreeNode*>q;
//         q.push(root);
//         int ans=-1;
//         while(!q.empty()){
//             int size=q.size();
//             for(int i=0;i<size;i++){
//                 TreeNode* node=q.front();
//                 q.pop();
//                 if(i==0) ans=node->val;
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//         }
//         return ans;
//     }
// };
// now i amd doing the binary tree right side view
// approach i have to used the level order traversal vertical traversal concept using the queue data structure
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     vector<int> rightSideView(TreeNode* root){
// if(root==NULL) return {};
// queue<TreeNode*>q;
// q.push(root);
// vector<int> ans;
// while(!q.empty()){
//     int size=q.size();
//     for(int i=0;i<size;i++){
//         TreeNode* node=q.front();
//         q.pop();
//         if(i==size-1) ans.push_back(node->val);
//         if(node->left) q.push(node->left);
//         if(node->right) q.push(node->right);
//     }
// }
// return ans;
// }};
// now i am doing the symmetric tree question 
// approach i have to check the level order traversal if they == then return tree else false
// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (!root) return true;

//         queue<TreeNode*> q;
//         q.push(root->left);
//         q.push(root->right);

//         while (!q.empty()) {
//             TreeNode* left = q.front(); q.pop();
//             TreeNode* right = q.front(); q.pop();

//             if (!left && !right) continue;
//             if (!left || !right) return false;

//             if (left->val != right->val) return false;

//             q.push(left->left);
//             q.push(right->right);

//             q.push(left->right);
//             q.push(right->left);
//         }

//         return true;
//     }
// };
