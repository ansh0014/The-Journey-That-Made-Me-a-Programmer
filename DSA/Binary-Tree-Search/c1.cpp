// now i am doing the search in binary tree
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     TreeNode* searchBST(TreeNode* root,int val){
//     while(root!=NULL){
//         if(root->val==val){
//             return root;
//         }
//         else if(val<root->val){
//             root=root->left; // go to left
//         }
//         else{
//             root=root->right; // go the right
//         }
//     }
//     return NULL;
//     }
// };
// now i am doing the insert into a binary search 
// i have to flow the property of BST that L<N<R
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// TreeNode* insertIntoBST(TreeNode* root, int val){
//     if(root==NULL){
//         return new TreeNode (val);
//     }
//     if(val<root->val){
//         root->left=insertIntoBST(root->left,val);
//     }else{
// root->right=insertIntoBST(root->right,val);
//     }
//     return root;
//     }
// };
// now i am doing the delete in binary serach delete node
// approach is that i find the node using L<N<R rule if key val<key then go to left else go to right
// i have to make if i delete the node i have reaarange acording to the property of BST
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
TreeNode* deleteNode(TreeNode* root, int key){
    if(root==NULL) return NULL;
    if(key<root->val){
        root->left=deleteNode(root->left,key);
        
    }else if(key>root->val){
        root->right=deleteNode(root->right,key);

    }else{

        if(root->left==NULL){
            TreeNode* temp=root->right;
            delete root;
            return temp;

        }
        if(root->right==NULL){
            TreeNode* temp=root->left;
            delete root;
            return temp;

        }
    
        
            TreeNode* temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
             return root;
      
        
    }
    return root;
}
};

