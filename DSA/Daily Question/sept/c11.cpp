// right now i am doing the maximum number of non-overlapping palindrome substrings
// i have given string s and positive integer k.
// select a set of non-overlapping substrings from the string s that satisfy the following conditions:
// the length of each substring is at least k.
// each substring is a palindrome.
// return the maximum number of substrings in an optimal selection.
// a substring is contiguous sequence of characters within a string.

#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i];
            for (int j = i - k + 1; j >= 0; --j) {
                if (isPalindrome(s, j, i)) {
                    dp[i + 1] = max(dp[i + 1], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
};