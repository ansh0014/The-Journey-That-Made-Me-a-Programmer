// now i am doing the populating next right pointers in each node
// i have given a perfect binary tree where all leaves are on the same level, and every paretn has two children. 
// populate each next pointer to point to its next right node. if there is no next right node, the next pointer should be set to next
// i have used the recursive approach and mention some condition
// we have implement the bfs level order traversal and then we will take the size of que and then we will run a loop from 0 to size-1 and then we will pop the front of que and then we will check if i<size-1 then we will set the next pointer of node to que.front() else we will set it to NULL and then we will push its left child and right child in que if they are not null
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
     Node* connect(Node* root) {
if(root==NULL) return NULL;
queue<Node*>q;
q.push(root);
while(!q.empty()){
    int n=q.size();
    for(int i=0;i<n;i++){
        Node* node=q.front();
        q.pop();
        if(i<n-1) node->next=q.front();
        else node->next=NULL;
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);

    }

}
return root;        
    }

};