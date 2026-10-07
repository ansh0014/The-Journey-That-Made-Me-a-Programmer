// now i am doing the contains duplicate 111
// i have given an integer array nums and two integers indexDiff and valueDiff
// find the pair of indices (i, j) such that
// i != j
// abs(i-j) <= indexDiff
// abs(nums[i]-nums[j]) <= valueDiff
// return true if such pair exists otherwise return false
// approach i think we can do using the sliding window+ hashmap
// we can also use easy thing which is window multiset
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
      bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
  int k=nums.size();
  multiset<long long> window;
  for(int i=0;i<k;i++){
      if(i>indexDiff){
          window.erase(window.find(nums[i-indexDiff-1]));
      }
      auto pos=window.lower_bound((long long)nums[i]-valueDiff);
      if(pos!=window.end() && *pos<=(long long)nums[i]+valueDiff){
          return true;
      }
      window.insert(nums[i]);
          
    }
    return false;
    }
};
