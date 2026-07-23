// now i am doing the maximum value of an alternationg sequence
// i have given three integers n, s and m.
// A sequence seq of integers of length n is considerd valid if:
/*
seq[0]=s
The sequence is alternating, meaning that either:
seq[0] > seq[1] < seq[2] > ..., or
seq[0] < seq[1] > seq[2] < ....
for every adjacent pari, |seq[i] - seq[i-1]| <= m
A sequence of length 1 is considered alternating.
Return the maximum possible element that can appear in any valid sequence.
// we used greedy approach to find the maximum value of an alternating sequence. we will start from the first element s and then we will keep adding m to the previous element until we reach the end of the sequence. we will keep track of the maximum value that we have seen so far and return it at the end.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maximumValue(int n, int s, int m)
    {
        if (n == 1)
            return s;
        long long ans = s;
        long long k1 = n / 2;
        if (k1 > 0)
        {
            ans = max(ans, 1LL * s + 1LL * k1 * m - (k1 - 1));
        }
        long long k2 = (n - 1) / 2;
        if (k2 > 0)
        {
            ans = max(ans, 1LL * s + 1LL * k2 * m - (k2 - 1));
        }
        return ans;
    }
};
