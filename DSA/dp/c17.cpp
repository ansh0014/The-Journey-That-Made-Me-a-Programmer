// Partition Equal Subset Sum
// i am using the iterative approach to solve this problem
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool canPartition(vector<int>& nums){
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i];

        }
        if(ans%2!=0) return false;
        int target=ans/2;
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};