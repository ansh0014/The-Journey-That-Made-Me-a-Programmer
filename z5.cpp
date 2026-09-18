// now i am doing the maximum width ramp
// a ramp in an integer nums is a pair (i, j) fow which i<j and nums[i]=<=nums[j]. Width of such a ramp is j-i.
// given an integer array nums, return the maximum width of ramp in nums. if theres i not ramp in nums return 0
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int maxWidthRamp(vector<int>&nums){
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int ans=0;
        int minIndex=n;
        for(int i=0;i<n;i++){
            minIndex=min(minIndex,v[i].second);
            ans=max(ans,v[i].second-minIndex);
        }
        return ans;
    }
};