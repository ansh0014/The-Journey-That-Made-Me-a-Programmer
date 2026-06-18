// now i am doing the largest Divisible subset
// i have given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
//  i have to return the answer in any order
// i have use the second form of dp which is ending form

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[1001];
    int parent[1001];
    int rec(vector<int> &nums, int i)
    {

        if (dp[i] != -1)
            return dp[i];
        dp[i] = 1;
        parent[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)
            {
                int len = 1 + rec(nums, j);
                if (len > dp[i])
                {
                    dp[i] = len;
                    parent[i] = j;
                }
            }
        }
        return dp[i];
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        memset(dp, -1, sizeof(dp));

        int maxlen = 0;
        int lastIndex = 0;
        for (int i = 0; i < n; i++)
        {
            int len = rec(nums, i);

            if (len > maxlen)
            {
                maxlen = len;
                lastIndex = i;
            }
        }
        vector<int>ans;

        while(parent[lastIndex] != lastIndex) {
            ans.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};