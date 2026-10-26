// now i am doing the product of array except self
#include<bits/stdc++.h>
using namespace std;
class Solution{
       vector<int> productExceptSelf(vector<int>& nums) {
     int n=nums.size();
    //  whye we create teh vector<int>ans(n,1) not vector<int>ans(n) because if we create vector<int>ans(n) then the value of ans[i] will be 0 and if we multiply any number with 0 then the value will be 0 so we create vector<int>ans(n,1) because if we multiply any number with 1 then the value will be that number only
     vector<int>ans(n,1);   
     for(int i=1;i<n;i++){
        ans[i]=ans[i-1]*nums[i-1];
     }
     int r=1;
     for(int i=n-1;i>=0;i--){
        ans[i]=ans[i]*r;
        r=r*nums[i];
     }
     return ans;
    }
};