// now i am doing the smallest stable index 1
//  i have given an integer array nums of lenght n and integer k.
// for each index i, define it instability score as max(nums[0...i]) - min(nums[0...i])
// in other words
// max (nums[0..i]) is the largest vlaue among the elements from index 0 to index i.
// min (nums[0..i]) is the smallest value among the elements from index 0 to index i.
// we used prefix sum technique to find the instability score of each index and then we will find the smallest stable index which is the index with the minimum instability score.
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int firstStableIndex(vector<int>& nums, int k) {
  int n=nums.size();
  vector<int>pre(n),suf(n);
  for(int i=0;i<n;i++){
      if(i==0) pre[i]=nums[i];
      else pre[i]=max(pre[i-1],nums[i]);
  }
  for(int i=n-1;i>=0;i--){
      if(i==n-1) suf[i]=nums[i];
      else suf[i]=min(suf[i+1],nums[i]);
  }
  int ans=-1;
    for(int i=0;i<n;i++){
        int instability=pre[i]-suf[i];
        if(instability<=k){
            ans=i;
            break;
        }
    

    }
    return ans;
}
};