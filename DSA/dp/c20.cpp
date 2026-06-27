// now we are doing Partition array into two arrays to minimize sum difference
// i have given an integer arry of length n to minimize the absolute difference of the sume of the arras, to partition nums, puth each element of nums into one the two arrays, return the minimum absolute difference of the sums of the two arrays
// first i have state the problem in my own words then i will solve it using the iterative approach
// the state is the nums then transtion is 
// dp(nums, target)
// now we talking about the target, the target is the sum of the array divided by 2, we will try to find the subset of the array which is less than or equal to the target, then we will return the minimum absolute difference of the sums of the two arrays
// transition is dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]
// This question is done by the meet in middle solution which is form 6
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(n + 1), right(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sum = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[i];
                }
            }

            left[cnt].push_back(sum);
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sum = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[n + i];
                }
            }

            right[cnt].push_back(sum);
        }

        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {

            auto &L = left[k];
            auto &R = right[n - k];

            for (int leftSum : L) {

                double target = total / 2.0 - leftSum;

                auto it = lower_bound(
                    R.begin(),
                    R.end(),
                    target
                );

                if (it != R.end()) {
                    int chosen = leftSum + *it;
                    ans = min(ans,
                              abs(total - 2 * chosen));
                }

                if (it != R.begin()) {
                    --it;
                    int chosen = leftSum + *it;
                    ans = min(ans,
                              abs(total - 2 * chosen));
                }
            }
        }

        return ans;
    }
};