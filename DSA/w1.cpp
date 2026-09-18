#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    using ll = long long;

    // Construct palindrome of exactly len digits
    ll makePalindrome(ll prefix, int len) {

        string s = to_string(prefix);

        int h = (len + 1) / 2;

        // prefix must have exactly h digits
        if ((int)s.size() != h)
            return -1;

        string res = s;

        if (len % 2 == 1) {
            // Odd length
            for (int i = h - 2; i >= 0; i--) {
                res += s[i];
            }
        }
        else {
            // Even length
            for (int i = h - 1; i >= 0; i--) {
                res += s[i];
            }
        }

        return stoll(res);
    }


    ll greedy(ll x) {

        string s = to_string(x);

        int len = s.size();

        // Single digit numbers are already palindromes
        if (len == 1)
            return 0;

        int h = (len + 1) / 2;

        ll prefix = stoll(s.substr(0, h));

        int firstDigit = s[0] - '0';

        ll best = LLONG_MAX;


        // -----------------------------------
        // 1. Check nearby prefixes
        // -----------------------------------

        for (ll p = prefix - 1; p <= prefix + 1; p++) {

            if (p <= 0)
                continue;

            ll pal = makePalindrome(p, len);

            if (pal <= 0)
                continue;

            // Must be reachable using +/- 2
            if (pal % 2 != x % 2)
                continue;

            best = min(best, llabs(x - pal));
        }


        // -----------------------------------
        // 2. If first digit parity is wrong,
        //    move to nearest possible first digit
        // -----------------------------------

        int requiredParity = x % 2;

        ll power = 1;

        for (int i = 1; i < h; i++)
            power *= 10;


        // Try first digit - 1 and first digit + 1
        for (int d = firstDigit - 1;
             d <= firstDigit + 1;
             d++) {

            if (d < 1 || d > 9)
                continue;

            if (d % 2 != requiredParity)
                continue;


            ll p;

            if (d < firstDigit) {

                // Largest prefix beginning with d
                p = (d + 1) * power - 1;

            }
            else {

                // Smallest prefix beginning with d
                p = d * power;
            }


            ll pal = makePalindrome(p, len);

            if (pal <= 0)
                continue;

            if (pal % 2 != x % 2)
                continue;

            best = min(best, llabs(x - pal));
        }


        // -----------------------------------
        // 3. Check palindrome with one
        //    fewer digit
        // -----------------------------------

        if (firstDigit == 1 && requiredParity == 0) {

            int d = len - 1;

            string t;

            if (d == 1) {
                t = "8";
            }
            else {
                t = "8";

                for (int i = 0; i < d - 2; i++)
                    t += "9";

                t += "8";
            }

            ll pal = stoll(t);

            best = min(best, llabs(x - pal));
        }


        return best / 2;
    }


    long long minOperations(vector<int>& nums) {

        long long ans = 0;

        for (int x : nums) {
            ans += greedy(x);
        }

        return ans;
    }
};