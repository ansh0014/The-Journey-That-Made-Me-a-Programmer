// now i am doing the maximum subarray min-product
// the min-product of any array is equal to minimum value int he array miltiplied by the array sum
// function ans=min-product(nums) return the maximum min-product of any non-empty subarray of nums
// since the answer may be large return it modulo 10^9+7
// approach frist we have create the subraay and then we will find the minimum value in the subarray and then we will find the sum of the subarray and then we will multiply the minimum value with the sum of the subarray and then we will return the maximum min-product of any non-empty subarray of nums
// we used the prefix sum technique to find the sum of the subarray and then we will use the stack to find the minimum value in the subarray

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int maxSumMinProduct(vector<int>& nums) {
  int n = nums.size();
  vector<long long> prefix(n+1,0);
  for(int i=0;i<n;i++){
      prefix[i+1]=prefix[i]+nums[i];
    if(nums[i]==0) prefix[i+1]=prefix[i];

    }
    stack<int> st;
    long long ans=0;
    for(int i=0;i<=n;i++){
        while(!st.empty() && (i==n || nums[st.top()]>=nums[i])){
            int j=st.top();
            st.pop();
            long long sum=prefix[i]-prefix[st.empty()?0:st.top()+1];
            ans=max(ans,sum*nums[j]);
        }
        st.push(i);

    }
    return ans%1000000007;



    }
};