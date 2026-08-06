// now i am doing the delete and concantenate
// i have an array a of n integers . i have intial score is 0.
// i can perform until the array becomes empty
// choose a single element. Add its value to your socre, and remove it from the array.
// choose two adjacent elements. Add the maximum of their value to your score, and remove both the lelemtns from the array

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] -= c;
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n / 2; i++) {
            a[i] = max(0LL, a[i]);
        }

        int ans = 0;
        for (int x : a)
            ans += x;

        cout << ans << '\n';
    }

    return 0;
}