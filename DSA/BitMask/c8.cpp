// now i am doing the good subesquences
// i have given an integer array nums. A good subsequence is defined as a subsequence of nums where the absolute difference between any two consecutive elements in the subsequence is exactly 1.
// Return the sum of all possible good subsequences of nums.
// Since the answer may be very large, return it modulo 1e9 + 7.
// approach we will use bitmask to represent the state of the subsequence and then we will use dp to store the sum of all possible good subsequences for each state and then we will use backtracking to find the sum of all possible good subsequences for the given nums.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    unordered_map<int,int> dp;
 
    int memo(vector<int>& nums, int mask){
        int n=nums.size();
        if(mask==0) return 0;
   int state=mask;
        if(dp[state]!=-1) return dp[state];
        // above line show buffer overflow error because the state can be very large and it can exceed the size of the dp array. so we will use unordered_map to store the dp values.

        int ans=0;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                int newMask=mask^(1<<i);
                if(newMask==0){
                    ans+=nums[i];
                }else{
                    for(int j=0;j<n;j++){
                        if(newMask&(1<<j)){
                            if(abs(nums[i]-nums[j])==1){
                                ans+=nums[i]+memo(nums,newMask);
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[state]=ans;
}
int sumOfGoodSubsequences(vector<int>& nums) {
        int n=nums.size();
        dp.clear();
        return memo(nums,(1<<n)-1);
    }
};