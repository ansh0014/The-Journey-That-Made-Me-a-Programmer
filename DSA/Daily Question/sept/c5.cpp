// i have to smallest stable index 2
// i have given an integer array nums of length n and an integer k.
// for each index i, define its instability score as max(nums[0...i])-min(nums[0...i])
// we used hashmap to find the instability score of each index and then we will find the smallest stable index which is the index with the minimum instability score.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int firstStableIndex(vector<int>& nums, int k) {
            int n=nums.size();
            unordered_map<int,int>mp;
        int ans=-1;
        for(int i=0;i<n;i++){
            int h=nums[i];
            mp[h]++;
            int instability=0;
            int max=INT_MIN;
            int min=INT_MAX;
            for(auto it:mp){
                if(it.first>max) max=it.first;
                if(it.first<min) min=it.first;
            }
            instability=max-min;
            if(instability<=k){
                ans=i;
                break;
            }

        }
        return ans;
        }
};