#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumStrength(vector<int>& monsters,
                              vector<vector<int>>& boosts) {

        int n = monsters.size();

        // Build bonus array
        vector<long long> diff(n + 1, 0);

        for (auto &b : boosts) {
            diff[b[0]] += b[2];
            if (b[1] + 1 < n)
                diff[b[1] + 1] -= b[2];
        }

        vector<long long> bonus(n);
        bonus[0] = diff[0];
        for (int i = 1; i < n; i++)
            bonus[i] = bonus[i - 1] + diff[i];

        auto check = [&](long long start) {

            long long strength = start;

            for (int i = 0; i < n; i++) {

                if (strength + bonus[i] < monsters[i])
                    return false;

                strength -= monsters[i];

                if (strength < 0)
                    strength = 0;
            }

            return true;
        };

        long long lo = 0;
        long long hi = 0;

        for (int x : monsters)
            hi += x;

        while (lo < hi) {

            long long mid = (lo + hi) / 2;

            if (check(mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};