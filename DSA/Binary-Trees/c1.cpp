// #include<iostream>
// using namespace std;
// class Node{
// public:
// int data;
// struct Node* left;
// struct Node* right;
// Node(int val){
//     data=val;
//     left=NULL;
//     right=NULL;
// }
// };
// int main(){
//     struct Node* root=new Node(1);
//     root->left=new Node(2);    
//     root->right=new Node(3);    
//     root->left->right=new Node(5);
//     cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<" "<<root->left->right->data;    

//     return 0;
// }
// now i am doing the binary tree preorder traversal
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// vector<int> preorderTraversal(TreeNode* root){
//     vector<int> ans;
//     if(root=NULL){
//         return ans;
//     }
//     // i am doing this using the recursive approach
//     ans.push_back(root->val);
//     vector<int> left=preorderTraversal(root->left);
//     vector<int> right=preorderTraversal(root->right);
//     ans.insert(ans.end(),left.begin(),left.end());
//     ans.insert(ans.end(),right.begin(),right.end());
//     return ans;
// }
// };
// now i amd doing the binary tree inorder traversal
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// vector<int> inorderTraversal(TreeNode* root){
//     vector<int> ans;
//     if(root==NULL){
//       return ans;
//     }
//     vector<int> left=inorderTraversal(root->left);
//     ans.insert(ans.end(),left.begin(),left.end());
//     ans.push_back(root->val);
//     vector<int> right=inorderTraversal(root->right);
//     ans.insert(ans.end(),right.begin(),right.end());
//     return ans;
// }
// };
// now i am doing the binar tree postorder traversal
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     vector<int> postorderTraversal(TreeNode* root){
//         vector<int> ans;
//         if(root==NULL) return ans;
//         vector<int> left=postorderTraversal(root->left);
//         ans.insert(ans.end(),left.begin(),left.end());
//         vector<int> right=postorderTraversal(root->right);
//         ans.insert(ans.end(),right.begin(),right.end());
//         ans.push_back(root->val);
//         return ans;
//     }
// };
// now i am doing the binary tree level order traversal
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// vector<vector<int>> levelOrder(TreeNode* root){
//     vector<vector<int>>ans;
//     if(root==NULL){
//         return ans;
//     }
//     queue<TreeNode*>q;
//     q.push(root);
//     while (!q.empty()){
// int size=q.size();
// vector<int> level;
// for(int i=0;i<size;i++){
//     TreeNode*node=q.front();
//     q.pop();
//     level.push_back(node->val);
//     if(node->left){
//         q.push(node->left);
//     }
//     if(node->right){
//         q.push(node->right);
//     }
// }
// ans.push_back(level);
//     }
//     return ans;
    
    

// }
// };
// // now i amd doing the iterative preorder traversal of binary tree using the stack
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//   vector<int> preorderTraversal(TreeNode* root){
//     vector<int> ans;
//     if(root==NULL){
//         return ans;
//     }
//     stack<TreeNode*>st;
//     st.push(root);
//     while (!st.empty())
//     {
//     root=st.top();
// ans.push_back(root->val);
// if(root->right!=NULL){
//     st.push(root->right);

//     }
//     if(root->left!=NULL){
//         st.push(root->left);
//     }
   
//   return ans;  
//   }
// }
// };