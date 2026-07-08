#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequenceAfterOneReplacement(string s, string t) {
        int n = s.size();

        int a = 0;
        int b = -1;

        for (char c : t) {
            int x = a, y = b;

            if (x < n && s[x] == c)
                a = x + 1;

            if (y != -1 && y < n && s[y] == c)
                b = max(b, y + 1);

            if (x < n)
                b = max(b, x + 1);
        }

        return a == n || b == n;
    }
};