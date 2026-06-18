// now i am doing the House Robber
// lets talk about the constraints and the problem statement
// adjacent houses cannot be roobed
// i have to return the maximum amount of money you can rob tonight without alerting the police
// we can use the dp to solve this problem
// first we have think aobut the choices we have to make at each step
// we can either rob the current house or not rob the current house
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// int rob(vector<int>& nums){
//     int houses=nums.size();
//     if(houses==0) return 0;
//     if(houses==1) return nums[0];
//     vector<int>dp(houses,-1);
//     dp[0]=nums[0];
//     dp[1]=max(nums[0],nums[1]);
//     for(int i=2;i<houses;i++){
//         dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
//     }
//     return dp[houses-1];
// }
// };

// now i am doing he house robber 2
// form a circle so the first and last house are adjacent
// we can not rob both the first and last house
// dp(house )=max(dp(house-1),nums[house]+dp(house-2))
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int rec(vector<int>& nums,int start, int end){
    int n=end-start+1;
    if(n==1) return nums[start];
    vector<int>dp(n);
    dp[0]=nums[start];
    dp[1]=max(nums[start],nums[start+1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],nums[start+i]+dp[i-2]);

    }
    return dp[n-1];
}
int rob(vector<int>&nums){
int n=nums.size();
if(n==1) return nums[0];
int excludelast=rec(nums,0,n-2);
int excludefirst=rec(nums,1,n-1);
return max(excludelast,excludefirst);
}
};
