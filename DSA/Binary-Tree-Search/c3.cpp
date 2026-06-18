// now i am doing the construct binary tree from preorder traversal
// approach preorder traversal =root left right
// so in bst i have to follow the bst rule which l<N<R
//  when i got prorder first i got the root value means i got the root then i have to go the left subtree and i have to check the value of the left subtree if it is less than root value then i have to go to left and if it is greater than root value then i have to go to right
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:

// TreeNode* solve(vector<int>&preorder,int &i,int bound){
//     if(i==preorder.size() || preorder[i]>bound){
//         return NULL;
//     }
//     TreeNode* root=new TreeNode(preorder[i++]);
//     root->left=solve(preorder,i,root->val);
//     root->right=solve(preorder,i,bound);
//     return root;
// }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int i=0;
//         return solve(preorder,i,INT_MAX);
//     }

// };
// now i am doing the inorder successor predecessor in bst
// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     pair<TreeNode *, TreeNode *> inorder(TreeNode *root, TreeNode *p)
//     {
//         TreeNode *successor = NULL;
//         TreeNode *predecessor = NULL;
//         while (root)
//         {
//             if (p->val < root->val)
//             {
//                 successor = root;
//                 root = root->left;
//             }
//             else if (p->val > root->val)
//             {
//                 predecessor = root;
//                 root = root->right;
//             }
//             else
//             {
//                 if (root->left)
//                 {
//                     TreeNode *temp = root->left;
//                     while (temp->right)
//                     {
//                         temp = temp->right;
//                         predecessor = temp;
//                     }
//                     if (root->right)
//                     {
//                         TreeNode *temp = root->right;
//                         while (temp->left)
//                         {
//                             temp = temp->left;
//                             successor = temp;
//                         }
//                     }
//                     break;
//                 }
//             }
//             return {successor, predecessor};
//         }
//     }
// };

// now i am doing the binary search tree iterator
// #include<bits/stdc++.h>
// using namespace std;
// class BSTIterator{
//     private:
//     stack<TreeNode*> st;
//     void pushAll(TreeNode* node){
//         while(node){
//             st.push(node);
//             node=node->left;
//         }
//     }
//     public:
//     BSTIterator(TreeNode* root){
//         pushAll(root);
//     }
//     int next(){
//     TreeNode* temp=st.top();
//     st.pop();
//     if(temp->right){
//         pushAll(temp->right);
//     }
//     return temp->val;
//     }
//     bool hasNext(){
//         return !st.empty();
//     }

// };