// now i am doing the maximum subarray sum after multiplier
// so i have give an integer array nums and a poistibe integer k
// i must have choose eactly one subarray of nums and perform eactly one fo the ollowing operations
// Multiply each number in the chosen subarry by k
// divide each number in the chosen subarray by k. 
// when dividing a poisitive number by k use the floor value of division result
// when dividing a negative number by k use the ceil value of division result
// return the maximum possible sum of the array after performing the operation
// approach is to use dp for storing the maximum sum of the array after performing the operation
// we use dp[i][0] for storing the maximum sum of the array after performing the operation on the subarray ending at index i
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long dp[100005][3];
    bool vis[100005][3];
    vector<int> nums;
    int n, k;
    bool multiplier;
    const long long NEG = -(1ll << 60);
    long long change(int x) {
        if (multiplier) {
            return 1ll * x * k;
        }
        if (x >= 0) {
            return x / k;
        }
        return -((-x)/k);
    }
    long long rec(int i, int state) {
        if (i == 0) {
            if (state == 0){
                return nums[0];
            }
            if (state == 1){
                return change(nums[0]);
            }
        return NEG;
        }
  
        // CACHE
        if (vis[i][state])
            return dp[i][state];
        vis[i][state] = true;

        // transition
        if (state == 0) {
            return dp[i][0] = max(1LL * nums[i], rec(i - 1, 0) + nums[i]);
        }

        if (state == 1) {
            long long cur = change(nums[i]);

            return dp[i][1] = max({cur, rec(i - 1, 0) + cur, rec(i - 1, 1) + cur});
        }

        return dp[i][2] = max({1LL * nums[i], rec(i - 1, 1) + 1LL * nums[i],rec(i - 1, 2) + 1LL * nums[i]});

    }

        long long solve(vector<int> & arr, int K, bool mul) {
            nums = arr;
            n = arr.size();
            k = K;
            multiplier = mul;
            memset(vis, 0, sizeof(vis));
            long long ans = NEG;
            for (int i = 0; i < n; i++) {
                for (int state = 0; state < 3; state++) {
                    ans = max(ans, rec(i, state));
                }
            }
            return ans;
        }

 long long maxSubarraySum(vector<int> & nums, int k) {  
 return max(solve(nums, k, true), solve(nums, k, false));
}
};

    
