// now i am doing the serilize and deserlize of binary tree
// i understand i have to convert the binary tree root to string and then convert the string the binary tree root
// i used bfs to do the serilize and deserlize of binary tree
// #include<bits/stdc++.h>
// using namespace std;
// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// class Codec{
// public:
// string serialize(TreeNode* root){
//     if(root==NULL) return "";
//     string s="";
//     queue<TreeNode*>q;
// q.push(root);
// while(!q.empty()){
//     TreeNode* node=q.front();
//     q.pop();
//     if(node==NULL) s.append("#,");
//     else s.append(to_string(node->val)+',');
//     if(node!=NULL){
//         q.push(node->left);
//         q.push(node->right);
//     }
// }
// return s;
// }
// TreeNode* deserialize(string data){
//     if(data.size()==0) return NULL;
//     stringstream s(data);
//     string str;
//     getline(s,str,',');
//     TreeNode* root=new TreeNode(stoi(str));
//     queue<TreeNode*>q;
//     q.push(root);
//     while(!q.empty()){
//         TreeNode* node=q.front();
//         q.pop();
//         getline(s,str,',');
//         if(str=="#") node->left=NULL;
//         else{
//             node->left=new TreeNode(stoi(str));
//             q.push(node->left);
//         }
//         getline(s,str,',');
//         if(str=="#") node->right=NULL;
//         else{
//             node->right=new TreeNode(stoi(str));
//             q.push(node->right);
//         }
//     }
//     return root;
// }};

// now i am doing the morris traversal of bianry tree
// #include<bits/stdc++.h>
// using namespace std;
// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {};
// };
// class Solution{
//     public:
// vector<int> morrisTraversal(TreeNode* root){
// vector<int>ans;
// TreeNode* curr=root;
// while(curr!=NULL){
//     if(curr->left==NULL){
//         ans.push_back(curr->val);
//         curr=curr->right;
//     }
//     else{
//         TreeNode* prev=curr->left;
//         while (prev->left!=NULL && prev->left!=curr){
//             prev=prev->right;

//         }
//         if(prev->right==NULL){
//             prev->right=curr;
//             curr=curr->left;
//         }
//         else{
//             prev->right=NULL;
//             ans.push_back(curr->val);
//             curr=curr->right;
        
//     }
// }

// } return ans;
// }};