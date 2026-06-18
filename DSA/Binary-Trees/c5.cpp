// now i am doing the sum root to leaf numbers
// approach i have to do the level order traversal and then i have to sum the root to leaf node and then return the sum
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// int sumNumbers(TreeNode* root){
//     if (root==NULL) return 0;
//     int sum=0;
//     queue<pair<TreeNode*, int>>q;
//     q.push({root, root->val});
//     while(!q.empty()){
//         auto [node, num]=q.front();
//         q.pop();
//         if(!node->left && !node->right) sum+=num;
//         if(node->left) q.push({node->left, num*10+node->left->val});
//         if(node->right) q.push({node->right, num*10+node->right->val});
//     }
//     return sum;
// }

// };
// Now i am doing the maximum width of binary tree
// i understand the question i have to check the last node of tree then i have to check the every node left and right and i have do in left let take if 2 is at level 3 and i only have the left i have to conside the right null to last node i have to count this and give the width
// approach if have to used BFS for that count the size of queue and then i have to check the index of node and then i have to check the width of that level and then return the maximum width
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//    public:
//    int widthOfBinaryTree(TreeNode* root){
//   if(root==NULL)return 0;
//   int maxW=0;
//   queue<pair<TreeNode*,long long>>q;
//     q.push({root,0});
//      long long maxW=0;
//     while(!q.empty()){
//         int size=q.size();
       
//         long long start=q.front().second;
//         long long end=q.back().second;
//         maxW=max(maxW,end-start+1);
//         for(int i=0;i<size;i++){
//             auto [node,index]=q.front();
//             q.pop();
//             // this line code make the overflow of index because if we have the large tree then the index will be very large so we have to make the index start from 0 for every level so we have to do index-start
//              index=index-start; 
            
//             if(node->left) q.push({node->left,2*index+1});
//             if(node->right) q.push({node->right,2*index+2});
//         }
        
        
        
//    } 
//    return  maxW;

// }
// };
