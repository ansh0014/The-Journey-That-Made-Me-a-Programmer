// now i am doing the construct uniform parity array 1
// i have given an array nums1 of n distinct integers. i want to construct another array nums2 of length n such that the elements in nums are either all odd or all even.
// for each index i i must choose exactly one of the following 
// nums2[i]=nums[i]
// nums2[i]=nums[i]-nums1[j] for index j1=i
// return true if it is possible to construct such an array otherwise return false.
// approach this is question counting and bits manipulation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int odd = 0;
        int even = 0;

        for (int x : nums1) {
            if (x & 1)
                odd++;
            else
                even++;
        }

        if (odd == n || even == n) {
            return true;
        }

        return true;
    }
};