// now i amd doing the subrray product less than k
// given an array of integers nums and an integers k, return the number of contiguous subarray where the product of all elements in the subarray is striclty less than k.
// approach we used sliding window approach
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int n=nums.size();
       int l=0,r=0;
        long long product=1;
        long long ans=0;
        for(int i=0;i<n;i++){
            product*=nums[i];
            while(l<=i && product>=k){
                product/=nums[l];
                l++;
            }
            ans+=i-l+1;
        }
   
        return ans;

    }

};
