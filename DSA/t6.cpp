// continuous subarray sum 
// i understand the question good array is atleast to and it multiple of given target sum 
// i have to used prefix sum and then i have to check if the prefix sum is divisible by k then i have to check if the prefix sum is already present in the map or not if it is present then i have to check if the index of the prefix sum is greater than 1 then i have to return true otherwise i have to return false
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool checkSubarraySum(vector<int>&nums,int k){
        int n=nums.size();
        unordered_map<int,int>mp;
        int prefixsum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            if(k!=0){
                prefixsum=prefixsum%k;
            }
            if(mp.find(prefixsum)!=mp.end()){
                if(i-mp[prefixsum]>1){
                    return true;
                }
            }
            else{
                mp[prefixsum]=i;
        }
        
    }
    return false;
    }
};