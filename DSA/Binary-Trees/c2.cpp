// now i am doing the vertical order traversal of the binary tree
// i understand the logic i have to use the map for counting the column and row but i have to chekc major column emsn start with the min column and then grup the same column in one has table 
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     vector<vector<int>> verticalTraversal(TreeNode* root){
//         vector<vector<int>>ans;
//          map<int, map<int, multiset<int>>> mp;
// // i have to apply level order traversal for that i have to use the queue for that question
// queue<pair<TreeNode*,pair<int,int>>>q;
//   q.push({root,{0,0}});
//     while(!q.empty()){
//         auto it=q.front();
//         q.pop();
//         TreeNode* node=it.first;
//         int col=it.second.first;
//         int row=it.second.second;
//         mp[col][row].insert(node->val);
//         if(node->left){
//             q.push({node->left,{col-1,row+1}});
//         }
//         if(node->right){
//             q.push({node->right,{col+1,row+1}});
//         }
        
//     }  
// for (auto &colPair : mp) {
//     vector<int> v;

//     for (auto &rowPair : colPair.second) {
//         v.insert(v.end(), rowPair.second.begin(), rowPair.second.end());
//     }

//     ans.push_back(v);
// }
//     return ans;
// }
// };