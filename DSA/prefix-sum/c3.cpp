// now i am doing the minimum cost to merge stones
// thsi is easy dp + prfix sum
// we use dp for storing the minimum cost to merge stones from i to j
// we use prefix sum for storing the sum of stones from i to j
// we sued the form 1 of dp[i][j]=min(dp[i][k]+dp[k+1][j]+sum[i][j]) for all k from i to j-1
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
int dp[31][31][31];
int K;
const int INF=1e9;
int rec(int i,int j,int piles,vector<int>&stones,vector<int>&prefix){
    if(i==j){
        if(piles==1)return 0;
        else return INF;
    }
    // cache the dp
    if(dp[i][j][piles]!=-1)return dp[i][j][piles];
int len=j-i+1;
if ((len - piles) % (K - 1) != 0) return dp[i][j][piles] = INF;
int ans=INF;
if(piles==1){
    ans=rec(i,j,K,stones,prefix)+prefix[j+1]-prefix[i];
}
else{
    for(int k=i;k<j;k+=K-1){
        ans=min(ans,rec(i,k,1,stones,prefix)+rec(k+1,j,piles-1,stones,prefix));
    }

}

return dp[i][j][piles]=ans;
}
int mergeStones(vector<int>& stones, int k) {
       int n = stones.size();

        if ((n - 1) % (k - 1) != 0)
            return -1;

        K = k;

        memset(dp, -1, sizeof(dp));

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        return rec(0, n - 1, 1, stones, prefix);

}

};