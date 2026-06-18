// now i am doing the split array largest sum
// if have k value i ahve split the array in k subarray
// then i have to find the how many ways i can split the array then i have to find the maximum sum

// we can also used the sliding window approach we have to find the sum of k subarray and then we have to compare the sum with the mid element if sum is less than mid element then i will move the high pointer to mid else i will move the low pointer to mid+1
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int splitArray(vector<int>& nums,int k){
    int n=nums.size();
    int low=0;
    int high=0;
    for(int i=0;i<n;i++){
        high+=nums[i];
        low=max(low,nums[i]);
        
    }
    while(low<high){
        int mid=(low+high)/2;
        int sum=0;
        int count=1;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                sum=nums[i];
                count++;
            }
        }
        if(count<=k){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

};