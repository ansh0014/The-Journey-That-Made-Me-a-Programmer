// now i am doing the maximum number of non-overlapping substrings
// i have given s of lowercase letters , i need to find the maximum number of non-empty substrings of s that meet the following conditions:
// the substring do not overlap, that is for any two substrings s[i...j] and s[x..y], either j<x and i>y is true.
// a substring that contains a certain character c must also contain all occurrences of c.
// find the maximum number of substrings that meet the above conditions. if there are multiple solutions, with the same number of substrings, reutrn the one with minimum total length. it can be shown that there exists a unique soltuion of minimum total lenght.
// notice that you can return the substrings in any order.
// approach first we have to make the possible substrings.
// then we have to check the condtions for the substrings and then we have to find the maximum number of substrings that meet the above conditions. if there are multiple solutions, with the same number of substrings, return the one with minimum total length. it can be shown that there exists a unique solution of minimum total length. notice that you can return the substrings in any order.
// we used dp for this problem. we have to find the maximum number of substrings that meet the above conditions. if there are multiple solutions, with the same number of substrings, return the one with minimum total length. it can be shown that there exists a unique solution of minimum total length. notice that you can return the substrings in any order.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct State {
        int count;
        int length;
        vector<pair<int, int>> intervals;
    };


    bool better(const State& a, const State& b) {

    
        if (a.count != b.count) {
            return a.count > b.count;
        }

     
        return a.length < b.length;
    }
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }
        vector<pair<int, int>> intervals;

        for (int c = 0; c < 26; c++) {

            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;
            for (int i = l; i <= r; i++) {

                int x = s[i] - 'a';
                if (first[x] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[x]);
            }
            if (valid) {
                intervals.push_back({l, r});
            }
        }
        vector<vector<pair<int, int>>> endingAt(n);
        for (auto [l, r] : intervals) {
            endingAt[r].push_back({l, r});

        }
        vector<State> dp(n + 1);
        dp[0] = {0, 0, {}};

        for (int i = 0; i < n; i++) {

            State skip = dp[i];

            if (better(skip, dp[i + 1])) {
                dp[i + 1] = skip;
            }

            for (auto [l, r] : endingAt[i]) {

                State take = dp[l];

                take.count++;
                take.length += (r - l + 1);

                take.intervals.push_back({l, r});

                if (better(take, dp[i + 1])) {
                    dp[i + 1] = take;
                }
            }
        }
        vector<string> ans;

        for (auto [l, r] : dp[n].intervals) {

            ans.push_back(
                s.substr(l, r - l + 1)
            );
        }

        return ans;
    }
};