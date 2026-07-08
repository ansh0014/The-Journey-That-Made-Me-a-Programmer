#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        const long long MOD = 1000000007;

        unordered_set<int> st;
        st.insert(2);

        for (int x : nums) {
            for (int d = 1; 1LL * d * d <= x; d++) {
                if (x % d) continue;
                if (d > 1) st.insert(d);
                int e = x / d;
                if (e > 1) st.insert(e);
            }
        }

        long long best = LLONG_MIN;
        int bk = 2;

        for (int k : st) {
            long long cur = LLONG_MIN;
            long long mx = LLONG_MIN;

            for (int x : nums) {
                long long v = (x % k == 0 ? x : -1LL * x);
                if (cur < 0) cur = v;
                else cur += v;
                mx = max(mx, cur);
            }

            if (mx > best || (mx == best && k < bk)) {
                best = mx;
                bk = k;
            }
        }

        long long ans = ((best % MOD + MOD) % MOD) * bk % MOD;
        return (int)ans;
    }
};