// now i am doing the count nodes equal to average of subtree
// i have given root of a binary tree , return the number of nodes where the value of the node is equal to the average of the values in its subtree.
// note:
// the average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
// a subtree of root is a tree consisting of root and all of its descendants.
// approach we will do a post order traversal of the tree and for each node we will calculate the sum and count of the subtree and then we will check if the value of the node is equal to the average of the subtree and if it is then we will increment the count.
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        pair<int, int> postorder(TreeNode* node, int& count) {
            if (node == nullptr) {
                return {0, 0};
            }
            auto left = postorder(node->left, count);
            auto right = postorder(node->right, count);
            int sum = left.first + right.first + node->val;
            int numNodes = left.second + right.second + 1;
            if (sum / numNodes == node->val) {
                count++;
            }
            return {sum, numNodes};
        }
        int averageOfSubtree(TreeNode* root) {
        // for post order traversal we used recursion and for each node we will calculate the sum and count of the subtree and then we will check if the value of the node is equal to the average of the subtree and if it is then we will increment the count. 
        int count = 0;
        postorder(root, count);
        return count;
    }
};