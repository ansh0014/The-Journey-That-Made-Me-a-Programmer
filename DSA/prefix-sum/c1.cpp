// now i am doing the contiguous array
// i have given the binary array nums, return the maximum lenght of a contiguous subarray with equal number of 0 and 1
// approach i have understood is we will make the prefix sum and then we will check if the prefix sum is already present in the map or not if it is present then we will check the length of the subarray and update the answer
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int findMaxLenght(vector<int>&nums){
    int n=nums.size();
    int sum=0;
    unordered_map<int,int>mp;
    int ans=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0) sum+=-1;
        else sum+=1;
        if(sum==0) ans=max(ans,i+1);
        if(mp.find(sum)!=mp.end()){
            ans=max(ans,i-mp[sum]);
        }
        else{
            mp[sum]=i;
        }
    }
    return ans;
}
};