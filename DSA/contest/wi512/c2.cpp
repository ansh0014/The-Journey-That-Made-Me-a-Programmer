#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int M = 1e9 + 7;

    long long pw(long long a, long long b)
    {
        long long r = 1;

        while (b)
        {
            if (b & 1)
            {
                r = (r * a) % M;
            }

            a = (a * a) % M;
            b >>= 1;
        }

        return r;
    }

    int countValidSequences(int n, int k)
    {
        if (k > n)
        {
            return 0;
        }

        vector<long long> f(n + 1);
        vector<long long> inv(n + 1);

        f[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            f[i] = (f[i - 1] * i) % M;
        }

        inv[n] = pw(f[n], M - 2);

        for (int i = n - 1; i >= 0; i--)
        {
            inv[i] = (inv[i + 1] * (i + 1)) % M;
        }

        auto C = [&](int N, int R) -> long long
        {
            if (R < 0 || R > N)
            {
                return 0LL;
            }

            return (((f[N] * inv[R]) % M) * inv[N - R]) % M;
        };

        long long t = C(n - 1, k - 1);

        long long o = 0;

        if ((n - k) % 2 == 0)
        {
            o = C((n + k - 2) / 2, k - 1);
        }

        return (t - o + M) % M;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    Solution obj;

    cout << obj.countValidSequences(n, k) << '\n';

    return 0;
}