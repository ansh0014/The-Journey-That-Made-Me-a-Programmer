// now i am doing the maximum product of the length of two plandromic subsequences
// i have given a string s find two disjoint plaindromic subsequences of s such that the product of their lenghts is maximized. The two subsequence are disjoint if they do not both pick a character at the same index
// return the maximum possible product of the lengths of the two plandromix subesquences
// a subsequences is the string that can be derived from another string by deleting some or no charactes without changing the order of the reamining characters. A string is plindromic if it reads the smae forward and backward
// approach we will use bitmask to represent the state of the then we will use dp to store the maximum product of the lenghts of the two plandromic subsequences for each state and then we will use backtracking to find the maximum product of the lengths of the two plandromic subsequences for the given string s.
// first question arise which i will use the bitmask to represent the state of the subsequence or the bitmask to represent the state of the string. i will use the bitmask to represent the state of the string because it will be easier to implement and it will be more efficient.
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int maxProduct(string s) {
    int n=s.size();
    vector<int> dp(1<<n,0);
    for(int mask=1;mask<(1<<n);mask++){
        string t="";
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                t+=s[i];
            }
        }
        string r=t;
        reverse(r.begin(),r.end());
        if(t==r){
            dp[mask]=t.size();
        }

    }

    int ans=0;
    for(int mask1=1;mask1<(1<<n);mask1++){
        for(int mask2=1;mask2<(1<<n);mask2++){
            if(mask1 & mask2!=0) continue; 
            ans=max(ans,dp[mask1]*dp[mask2]);
        }
    }
    return ans;
    
}
};
