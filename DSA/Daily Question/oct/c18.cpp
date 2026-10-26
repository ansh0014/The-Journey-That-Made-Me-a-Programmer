// now i am doing the largest number
// given a list of non-negative integers nums arrange them such that they form the largest number and return it
// sunce result may be very large so we have to return a string instead of integer
// use two pointer approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<string> ans;
        for (int x : nums)
        {
ans.push_back(to_string(x));
        }
        sort(ans.begin(), ans.end(), [](const string &a, const string &b)
             { return a + b > b + a; });
             if (ans[0] == "0") return "0";
             string res;
             for(const string &s : ans) res += s;
                return res;
    }
};
