// now i am doing the subarrays distinct elemtns sum of squares1
// i have given an 0-indexed integer array nums
// the distinct count of a subarray of nums is defined as
// let nums[i...j] be a subarray of nums consisting of all the indics from i to j such that 0<=i<=j<nums.length. The distinct count of the subarray is the number of distinct elements in the subarray
// the distinct sum of a subarray of nums is defined as the sum of the squares of
// return the sum of squares of distinct counts of all subarrays of nums
// one approach we make set and then we will run two loops from 0 to n-1 and then we will run the inner loop from i to n-1 and then we will insert the elements in set and then we will calculate the size of set and then we will add the square of size in ans
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
       int sumCounts(vector<int>& nums) {
     int n=nums.size();
     long long ans=0;
     set<int>st;
   for(int i=0;i<n;i++){
    st.clear();
for(int j=i;j<n;j++){
    st.insert(nums[j]);
    int size=st.size();
    ans+=1LL*size*size;
   }
   return ans;
}
    }
};