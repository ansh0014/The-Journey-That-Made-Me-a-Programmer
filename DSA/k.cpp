// i am doing the minimum operations to sort a string
// i one operation, i can select any substring of s that is not the entire string sort it in non-descending order and then replace the original substring with the sorted substring
// i have to return the minimum number of operations required to sort the string s in non-descending order
// other wise i have to return -1
// how i insurre the non-descending order of the string after sorting the substring
// this question is of greedy approach i have to find the longest non-descending substring in the string and then i have to sort the remaining substring and then i have to check if the sorted substring is in non-descending order or not if it is in non-descending order then i will return the number of operations required to sort the string otherwise i will return -1

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());
        if (s == t)
            return 0;
        if (n == 2 && s[0] > s[1])
            return -1;
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        if (s[0] == mn || s[n - 1] == mx)
            return 1;
        if (s[0] == mx && s[n - 1] == mn)
        {
            for (int i = 1; i < n - 1; i++)
            {
                if (s[i] == mn || s[i] == mx)
                {
                    return 2;
                }
            }
            return 3;
        }
        return 2;
    }
};