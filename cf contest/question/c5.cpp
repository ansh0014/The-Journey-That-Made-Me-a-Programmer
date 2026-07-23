// now i am doing the quesiton div 2 the cost of bracked squence
// let the cost of an arbitrary bracket string be the length of its longest subesequnce that is regular bracket sequence
// i have give a bracket string s and a  integer k. my stak is remove at most k characters form the string s so that the cost of the resulting strirng minimized
// A sequence a is subsequence of a sequence b if a can be obtained from b by deleting some (possibly zero) elements of b. A regular bracket sequence is defined as follows:
// †
// A bracket sequence is called regular if it is possible to obtain a correct arithmetic expression by inserting the characters +
//  and 1
//  into this sequence. For example, the sequences "(())()
// ", "()
// ", and "(()(()))
// " are regular, while ")(
// ", "(()
// ", and "(()))(
// " — are not.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        string s;

        cin >> n >> k;
        cin >> s;

        vector<int> prefOpen(n + 1, 0);
        vector<int> prefClose(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefOpen[i + 1] = prefOpen[i] + (s[i] == '(');
            prefClose[i + 1] = prefClose[i] + (s[i] == ')');
        }

        int totalClose = prefClose[n];

        int pos = n;

        for (int i = 0; i <= n; i++)
        {
            int cur =
                prefOpen[i] + totalClose - prefClose[i];

            int best =
                prefOpen[pos] + totalClose - prefClose[pos];

            if (cur < best)
            {
                pos = i;
            }
        }

        string ans(n, '0');

        for (int i = 0; i < pos && k > 0; i++)
        {
            if (s[i] == '(')
            {
                ans[i] = '1';
                k--;
            }
        }

        for (int i = pos; i < n && k > 0; i++)
        {
            if (s[i] == ')')
            {
                ans[i] = '1';
                k--;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}