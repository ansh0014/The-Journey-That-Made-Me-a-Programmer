#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[1001];

    int longestStrChain(vector<string>& words)
    {
        sort(words.begin(), words.end(),
             [](string &a, string &b)
             {
                 return a.size() < b.size();
             });

        memset(dp, -1, sizeof(dp));

        int n = words.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, rec(words, i));
        }

        return ans;
    }

    int rec(vector<string> &words, int i)
    {
        if (dp[i] != -1)
            return dp[i];

        int ans = 1;

        for (int prev = 0; prev < i; prev++)
        {
            if (isPredecessor(words[prev], words[i]))
            {
                ans = max(ans, 1 + rec(words, prev));
            }
        }

        return dp[i] = ans;
    }

    bool isPredecessor(string &a, string &b)
    {
        if (a.length() + 1 != b.length())
            return false;

        int i = 0, j = 0;

        while (i < a.length() && j < b.length())
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

        return i == a.length();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        Solution sol;
        vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
        cout << sol.longestStrChain(words) << endl;
    }
}