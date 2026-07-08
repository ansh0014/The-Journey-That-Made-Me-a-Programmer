// now i am doing the Brust Ballons
// we are given n ballons indexed from 0 to n-1.Each ballon is painted with a number on it represented by an array nums.
// You are asked to burst all the ballons.
// if you burst the ith ballon you will get nums[i-1]*nums[i]*nums[i+1] coins. if i-1 or i+1 goes out of bounds of the array, then treat it as if there is a ballon with a 1 painted on it.
// return the maximum coins you can collect by bursting the ballons wisely
// approach we used dp 
// we prefix the array with 1 at the start and end and then we use dp[i][j] for storing the maximum coins we can collect by bursting the ballons from i to j
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int dp[502][502];
    int rec(int i ,int j,vector<int>&nums){
        if(i>j)return 0;
        if(this->dp[i][j]!=-1)return this->dp[i][j];
        int ans=0;
        for(int k=i;k<=j;k++){
            ans=max(ans,rec(i,k-1,nums)+rec(k+1,j,nums)+nums[i-1]*nums[k]*nums[j+1]);
        }
        return this->dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums){
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return rec(1,n,nums);
        

    }
};