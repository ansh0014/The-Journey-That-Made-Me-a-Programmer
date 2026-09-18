// now i am doing the partition to K equal sum subsets
// i have an given array nums and an integer k, return true if it s possible to divide this array into k non-empty subsets whose sums are all equal.
// appraoch i used backtracking
// think what are states then what value i have taken
// states are the elements of the array and then value is sum of subsets which is divide by k
// but with the backtrack i got tle
// so we used dp to store the sum of subsets and then check if it is possible to divide the array into k non-empty subsets whose sums are all equal
#include <bits/stdc++.h>
using namespace std;
class Solution{
   unordered_map<int,unordered_map<int,int>> dp;
   int encode(vector<int>& nums){
    int n=nums.size();
int mask=0;
    for(int i=0;i<n;i++){
        mask|=(1<<i);
    }
    return mask;

}
    public:
int memo(int mask, int k, int target, vector<int>& nums, int sum){
    if(k==0){
        return 1;
    }

if(dp.count(mask) && dp[mask].count(sum)){
    return dp[mask][sum];
}
    for(int i=0;i<nums.size();i++){
        if((mask&(1<<i))==0 && sum+nums[i]<=target){
            if(memo(mask|(1<<i), k-(sum+nums[i]==target), target, nums, (sum+nums[i])%target)){
                return dp[mask][sum]=1;
            }
        }
    }
    return dp[mask][sum]=0;
}
   bool canPartitionKSubsets(vector<int>& nums, int k) {
dp.clear();
    int n= nums.size();

    int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%k!=0){
            return false;
        }
        int target=sum/k;
        return memo(0, k, target, nums, 0);
     
}
     
    
};
