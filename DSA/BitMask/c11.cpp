// now i am doing hte beautiful arrangement of flowers
// suppose i have n integers labeled 1 through n. A permutation of those n integers perm(1-indexed) is considered a beautiful arrangement if for ever i (1<=i<=n) eigher of the followe is true;
// perm[i] is divisible by i
// i is divisible by perm[i]
// given an integer n , return thenjbmer of beautifull arrangements that i can construct
// approach we will use bitmask to represent the state of the arrangement and then we will use dp to store the number of beautiful arrangements for each state and then we will use backtracking to find the number of beautiful arrangements for the given n.
// bitmaks ----> we bitmask ith bit represents whether the ith number is used in the arrangement or not. if the ith bit is 1 then the ith number is used in the arrangement otherwise it is not used in the arrangement.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int memo(int n, int mask, unordered_map<int,int>&dp){
        if(mask==0) return 1;
        if(dp.count(mask)) return dp[mask];
        int ans=0;
        int pos=__builtin_popcount(mask);
        for(int i=1;i<=n;i++){
            if(mask&(1<<(i-1))){
                if(i%pos==0 || pos%i==0){
                    ans+=memo(n,mask^(1<<(i-1)),dp);
                }
            }
        }
        return dp[mask]=ans;
    }
int countArrangement(int n){   
    unordered_map<int,int> dp;
    return memo(n,(1<<n)-1,dp);


}


};