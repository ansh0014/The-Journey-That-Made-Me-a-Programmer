// now i am doing hte unique binary search tree
#include <bits/stdc++.h>
using namespace std;
// i have maintain the property of the binary search tree that is left node is less than the root and right node is greater than the root
// i have to use the recursion to solve this problem
class Solution{
    public:
    int numTrees(int n){
        if(n==0 || n==1){
            return 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }

};