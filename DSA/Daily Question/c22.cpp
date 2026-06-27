// now i am doing the zigzag arrays 1
// i have given three integers n,land r
// A zig zag array of length n is defined as follows:
// each element lies in the range [l,r]
// No two adjacent elements are equal
// The first element is strictly less than the second element
// approach i have give range so i have to find the number of zig zag arrays of length n such that each element lies in the range [l,r] and no two adjacent elements are equal and the first element is strictly less than the second element
// we used dp for that and we have to find the number of zig zag arrays of length n such that each element lies in the range [l,r] and no two adjacent elements are equal and the first element is strictly less than the second element
// we used ending form 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long MOD = 1e9 + 7;

        int m = r - l + 1;

        if (n == 1) {
            return m;
        }

        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(m, vector<long long>(2, 0))
        );

        // Base case: arrays of length 2
        for (int x = l; x <= r; x++) {
            for (int y = l; y <= r; y++) {

                if (x < y) {
                    dp[2][y - l][1]++;
                }
                else if (x > y) {
                    dp[2][y - l][0]++;
                }
            }
        }

        for (int len = 2; len < n; len++) {

            for (int last = l; last <= r; last++) {

                long long up = dp[len][last - l][1];
                long long down = dp[len][last - l][0];

                // last move was UP
                // next must be smaller
                if (up) {
                    for (int nxt = l; nxt < last; nxt++) {
                        dp[len + 1][nxt - l][0] =
                            (dp[len + 1][nxt - l][0] + up) % MOD;
                    }
                }

                // last move was DOWN
                // next must be larger
                if (down) {
                    for (int nxt = last + 1; nxt <= r; nxt++) {
                        dp[len + 1][nxt - l][1] =
                            (dp[len + 1][nxt - l][1] + down) % MOD;
                    }
                }
            }
        }

        long long ans = 0;

        for (int val = l; val <= r; val++) {
            ans = (ans + dp[n][val - l][0]) % MOD;
            ans = (ans + dp[n][val - l][1]) % MOD;
        }

        return ans;
    }
};