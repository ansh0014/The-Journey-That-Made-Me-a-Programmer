// now i am doing the ALL nodes distance k in binary trees
// i understand the question  i have given the target i have to reach the target first then i have to move the distance which i have given

// apporach i have to think like the graph problem because in this their is the parent then i have to apply bfs then solve it

// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// unordered_map<TreeNode*,TreeNode*> parent;
// void findParent(TreeNode* root,TreeNode* par){
//     if(root==NULL) return;
//     parent[root]=par;
//     findParent(root->left,root);
//     findParent(root->right,root);
// }
// vector<int> distanceK(TreeNode* root,TreeNode* target,int k){
//     findParent(root,NULL);
//     unordered_map<TreeNode*,bool> visited;
//     queue<TreeNode*> q;
//     q.push(target);
//     visited[target]=true;
//     int dist=0;
//     while(!q.empty()){
//         int size=q.size();
//         if(dist==k) break;
//         dist++;
//         for(int i=0;i<size;i++){
//             TreeNode* node=q.front();
//             q.pop();
//             if(node->left && !visited[node->left]){
//                 visited[node->left]=true;
//                 q.push(node->left);
//             }
//             if(node->right && !visited[node->right]){
//                 visited[node->right]=true;
//                 q.push(node->right);
//             }
//             if(parent[node] && !visited[parent[node]]){
//                 visited[parent[node]]=true;
//                 q.push(parent[node]);
//             }
//         }
//     }
//     vector<int> ans;
//     while(!q.empty()){
//         ans.push_back(q.front()->val);
//         q.pop();
//     }
//     return ans;
// }

// };

// now i am doing the count complete tree nodes
// i understand i have to count the number of nodes in the complete tree
// approach i have to find the height of the left and right subtree if they are same then i can calculate the number of nodes by using the formula 2^h-1 else i have to move to the left or right subtree and then i have to count the nodes
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     int countNode(TreeNode* root){
//         if(root==NULL) return 0;
//         int left=0;
//         int right=0;
//         TreeNode* leftNode=root;
//         TreeNode* rightNode=root;
//         while(leftNode){
//             left++;
//             leftNode=leftNode->left;
//         }
//         while(rightNode){
//             right++;
//             rightNode=rightNode->right;
//         }
//         if(left==right) return pow(2,left)-1;
//         return 1+countNode(root->left)+countNode(root->right);

//     }
// };
