// now i am doing the left and right sum differences
// i understand the problem i have to make leftSum[i] sum of elements to the left of the index i in the array nums if their is not element leftSum[i]=0
// and rightSum[i] sum of elements to the right of the index i in the array nums if their is not element rightSum[i]=0
// i have to return the answer[i]=abs(leftSum[i]-rightSum[i])
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> leftRightDifference(vector<int>& nums){
        int n=nums.size();
        vector<int> leftSum(n,0),rightSum(n,0),ans(n,0);
        for(int i=1;i<n;i++){
            leftSum[i]=leftSum[i-1]+nums[i-1];

        }
        for(int i=n-2;i>=0;i--){
            rightSum[i]=rightSum[i+1]+nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=abs(leftSum[i]-rightSum[i]);
        }
        return ans;
    }
};