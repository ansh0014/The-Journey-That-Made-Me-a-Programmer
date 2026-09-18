// now i am doing the delete operation for two strings
// i have given strings word1 and word2, return the number steps reqired to amke word1 and word2 the same
// in one step i can delete exactly one character in either string
#include <bits/stdc++.h>
using namespace std;
class Solution{
    int dp[501][501];
    public:
   int memo(int index1 , int index2, string& word1, string& word2){
    int n=word1.size();
    int m=word2.size();
    if(index1==n){
        return m-index2;
    }
    if(index2==m){
        return n-index1;
    }
    // base case
    if(index1==n && index2==m){
        return 0;
    }
    // cache
    if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }
if(word1[index1]==word2[index2]){
    return memo(index1+1,index2+1,word1,word2);
}
    int ans=1+min(memo(index1+1,index2,word1,word2),memo(index1,index2+1,word1,word2));
    dp[index1][index2]=ans;
    return ans;
   }

        int minDistance(string word1, string word2) {
            memset(dp,-1,sizeof(dp));
            return memo(0,0,word1,word2);
        
    }

};