// now i am doing the maximum valid pair sum
// i have given an integer array nums of length n and an integerk
// A pair of indices(i,j ) is called valid if
// 0<=i<j<n
// j-i>=k
// return maximum value nums[i]+nums[j] among all valid pairs.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        int best = nums[0];
        int ans = INT_MIN;

        for (int j = k; j < n; j++) {
            best = max(best, nums[j - k]);
            ans = max(ans, best + nums[j]);
        }

        return ans;
    }
};