// now i am doing the count Good integers in a Range
// i have given three integers l,r and k 
// A number is considered good if the absolute difference between every pair of adjacent digits is at most k.
// return the number of good integers in the range [l, r] inclusive.
// the absolute difference between two digits a and b is defined as |a - b|
// constraints 10<= l <= r <= 10^15
// Q4. Count Good Integers in a Range
// Approach: Digit DP. f(n) = count of "good" integers in [0, n].
// Answer = f(r) - f(l-1).
//
// State: (pos, prev_digit, started, tight)
//   - started handles leading zeros so "01" isn't treated as adjacent digits 0,1
//   - memoized only when !tight (tight path is unique per call, no reuse)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGoodIntegers(long long l, long long r, int k) {
        return f(r, k) - f(l - 1, k);
    }

private:
    long long f(long long n, int k) {
        if (n < 0) return 0;
        string s = to_string(n);
        int L = s.size();

        // memo[pos][prev+1][started], prev in [-1..9] -> offset by 1 (size 11)
        vector<vector<array<long long, 2>>> memo(
            L + 1, vector<array<long long, 2>>(11, {-1, -1}));

        function<long long(int, int, bool, bool)> dp =
            [&](int pos, int prev, bool started, bool tight) -> long long {
            if (pos == L) return 1;

            if (!tight && memo[pos][prev + 1][started] != -1)
                return memo[pos][prev + 1][started];

            int limit = tight ? (s[pos] - '0') : 9;
            long long total = 0;

            for (int d = 0; d <= limit; d++) {
                bool ntight = tight && (d == limit);
                if (!started && d == 0) {
                    // still in leading-zero region
                    total += dp(pos + 1, prev, false, ntight);
                } else {
                    if (started && abs(d - prev) > k) continue;
                    total += dp(pos + 1, d, true, ntight);
                }
            }

            if (!tight) memo[pos][prev + 1][started] = total;
            return total;
        };

        return dp(0, -1, false, true);
    }
};

// quick local test harness
int main() {
    Solution sol;
    cout << sol.countGoodIntegers(10, 15, 1) << endl;   // expect 3
    cout << sol.countGoodIntegers(201, 204, 2) << endl; // expect 2
    return 0;
}