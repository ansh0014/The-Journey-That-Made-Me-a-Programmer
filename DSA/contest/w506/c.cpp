// toaday i am giving the weekly contest 509
// now i am doing the sum fo integer with the maximmum digit Range
// i have given an integer num and an integer k
// return the minimum possible sum of the digits of num after performing at most k operations
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfIntegers(vector<int>& nums) {
        vector<int> range(nums.size());
        int mxRange = -1;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int mn = 9, mx = 0;

            while (x > 0) {
                int d = x % 10;
                mn = min(mn, d);
                mx = max(mx, d);
                x /= 10;
            }

            range[i] = mx - mn;
            mxRange = max(mxRange, range[i]);
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (range[i] == mxRange)
                ans += nums[i];
        }

        return ans;
    }
};