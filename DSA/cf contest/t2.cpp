#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n, k, p, q;
        cin >> n >> k >> p >> q;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long sum0 = 0, sumP = 0, sumQ = 0, sumQP = 0, sumPQ = 0;

        for (int i = 0; i < n; i++) {
            sum0 += a[i];
            sumP += a[i] % p;
            sumQ += a[i] % q;
            sumQP += (a[i] % q) % p;
            sumPQ += (a[i] % p) % q;
        }

        if (k == 1) {
            cout << min({sum0, sumP, sumQ}) << "\n";
        } else {
            cout << min({sum0, sumP, sumQ, sumQP, sumPQ}) << "\n";
        }
    }

    return 0;
}