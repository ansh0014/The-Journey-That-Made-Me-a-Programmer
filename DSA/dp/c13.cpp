// now i am doing the Target Sum
// this is the form 4 
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int dp[21][1001];
    int n;

    int rec(int i,vector<int>nums,int target){
// puring 

if(i==n) return (target==0);
if(dp[i][target]!=-1){
    return dp[i][target];
}
int notTake=rec(i+1,nums,target);
int take=0;
if(nums[i]<=target){
    take=rec(i+1,nums,target-nums[i]);

}
return dp[i][target]=take+notTake;


}
int findTargetSumWays(vector <int> &nums,int target){

ios::sync_with_stdio(false);
     int sum = accumulate(nums.begin(), nums.end(), 0);
             if (sum + target < 0 || (sum + target) % 2)
            return 0;

        int req = (sum + target) / 2;

        n = nums.size();

        memset(dp, -1, sizeof(dp));

        return rec(0, nums,req);

    }
};