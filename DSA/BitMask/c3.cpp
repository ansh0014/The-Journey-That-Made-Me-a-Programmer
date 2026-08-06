// now i am doing the longest Nice Subarray
// i have given an array nums consisting of psoitive integers.
// we call subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.
// return the length of the longest nice subarray.
// i using the bitmask to convert the array into a bitmask and then using the sliding window technique to find the longest nice subarray.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int longestNiceSubarray(vector<int>& nums){
        int n=nums.size();
        int ans=0;
        int left=0;
        int right=0;
        int bitmask=0;
        while(right<n){
            while((bitmask & nums[right])!=0){
                bitmask^=nums[left];
                left++;
            }
            bitmask|=nums[right];
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};