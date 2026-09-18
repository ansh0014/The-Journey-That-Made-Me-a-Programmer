// now i am doing hte maximum number of jumps to reach the last index
// this is greedy approach
// first i have to understand the what is target means
// target means the last index of the array and i have to reach there
// target help to allow the jumb 
// -target<=nums[j]-nums[i]<=target
// approach i think we have to use dp 
// now we have think for state and trasition
// state: dp[i] = maximum number of jumps to reach index i
// transition: dp[j] = max(dp[j], dp[i] + 1) if |nums[j] - nums[i]| <= target


#include<bits/stdc++.h>
using namespace std;
class Solution{

    public:
   
    int maximumJumps(vector<int>&nums,int target){
     vector<int>dp(nums.size(),-1);
     dp[0]=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==-1) continue;
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[j]-nums[i])<=target){
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
        }
        return dp[nums.size()-1];
    }
};