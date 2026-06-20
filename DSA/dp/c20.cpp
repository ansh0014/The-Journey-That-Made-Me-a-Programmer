// now we are doing Partition array into two arrays to minimize sum difference
// i have given an integer arry of length n to minimize the absolute difference of the sume of the arras, to partition nums, puth each element of nums into one the two arrays, return the minimum absolute difference of the sums of the two arrays
// first i have state the problem in my own words then i will solve it using the iterative approach
// the state is the nums then transtion is 
// dp(nums, target)
// now we talking about the target, the target is the sum of the array divided by 2, we will try to find the subset of the array which is less than or equal to the target, then we will return the minimum absolute difference of the sums of the two arrays
// transition is dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minimumDifference(vector<int>& nums){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target=sum/2;
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
        int ans=0;
        for(int j=target;j>=0;j--){
            if(dp[n][j]){
                ans=j;
                break;
            }
        }
        return sum-2*ans;
    }
};