// now i am doing the longest subarray of 1's after deleting one element
// approach we used sliding window approach
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int longestSubarray(vector<int>&nums){
        int n=nums.size();
        int left=0,right=0;
        int count=0;
        int ans=0;
        for(auto right=0;right<n;right++){
            if(nums[right]==0){
                count++;
            }
            while(count>1){
                if(nums[left]==0){
                    count--;
                }
                left++;
            }
            ans=max(ans,right-left);
        }
        return ans;
    }
};