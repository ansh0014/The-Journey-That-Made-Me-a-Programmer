// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     long long maxPalindromicSubarraySum(vector<int>& nums) {
//         int n = nums.size();

//         vector<long long> pre(n + 1, 0);
//         for (int i = 0; i < n; i++)
//             pre[i + 1] = pre[i] + nums[i];

//         vector<vector<bool>> dp(n, vector<bool>(n, false));

//         long long ans = 0;

//         for (int len = 1; len <= n; len++) {
//             for (int i = 0; i + len - 1 < n; i++) {
//                 int j = i + len - 1;

//                 if (len == 1) {
//                     dp[i][j] = true;
//                 }
//                 else if (len == 2) {
//                     dp[i][j] = (nums[i] == nums[j]);
//                 }
//                 else {
//                     dp[i][j] = (nums[i] == nums[j] && dp[i + 1][j - 1]);
//                 }

//                 if (dp[i][j]) {
//                     ans = max(ans, pre[j + 1] - pre[i]);
//                 }
//             }
//         }

//         return ans;
//     }
// };
#include<bits/stdc++.h>
using namespace std;
// we are applying the manacher's algorithm to find the maximum sum of palindromic subarray
class Solution {
public:
    long long maxPalindromicSubarraySum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        auto get = [&](int l, int r) {
            return pre[r + 1] - pre[l];
        };

        long long ans = 0;

        // Odd length palindromes
        vector<int> d1(n);
        int l = 0, r = -1;

        for (int i = 0; i < n; i++) {
            int k;

            if (i > r) {
                k = 1;
            } else {
                k = min(d1[l + r - i], r - i + 1);
            }

            while (i - k >= 0 &&
                   i + k < n &&
                   nums[i - k] == nums[i + k]) {
                k++;
            }

            d1[i] = k;

            int L = i - k + 1;
            int R = i + k - 1;
            ans = max(ans, get(L, R));

            if (R > r) {
                l = L;
                r = R;
            }
        }

        // Even length palindromes
        vector<int> d2(n);
        l = 0;
        r = -1;

        for (int i = 0; i < n; i++) {
            int k;

            if (i > r) {
                k = 0;
            } else {
                k = min(d2[l + r - i + 1], r - i + 1);
            }

            while (i - k - 1 >= 0 &&
                   i + k < n &&
                   nums[i - k - 1] == nums[i + k]) {
                k++;
            }

            d2[i] = k;

            if (k > 0) {
                int L = i - k;
                int R = i + k - 1;
                ans = max(ans, get(L, R));

                if (R > r) {
                    l = L;
                    r = R;
                }
            }
        }

        return ans;
    }
};