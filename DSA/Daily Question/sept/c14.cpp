// now i am doing the reverse degree of a string
// the reverse degree is calculated as 
// for each character multiply its position in the reversed alphabet by its position in the string and sum them up
// we used the hash map to store the position of each character in the reversed alphabet
// then we iterate through the string and for each character we get its position in the reversed alphabet from the hash map and multiply it by its position in the string and sum them up
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:

    int reverseDegree(string s)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < 26; i++)
        {
            mp['a' + i] = 26 - i;
        }
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans += mp[s[i]] * (i + 1);
        }
        return ans;
    }
};
