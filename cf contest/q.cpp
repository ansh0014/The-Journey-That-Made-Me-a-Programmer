#include <iostream>
using namespace std;

const long long MOD = 998244353;

long long power(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;

        long long dim = (r - 1) * m + (c - 1) * n - (r - 1) * (c - 1);

        cout << power(2, dim) << '\n';
    }

    return 0;
}