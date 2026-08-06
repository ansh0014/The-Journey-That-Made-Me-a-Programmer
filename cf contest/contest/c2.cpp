#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> l(n+1), r(n+1), u(n+1), v(n+1);
        for (int i = 1; i <= n; i++)
            cin >> l[i] >> r[i] >> u[i] >> v[i];
        
        int ans = 0;
        for (int m = 1; m <= n; m++) {
            int cnt = 0, pos = 1;
            for (int i = 1; i <= n && cnt < m; i++) {
                bool leftOk = (pos < l[i] || pos > r[i]);
                int rrank = m - pos + 1;
                bool rightOk = (rrank < u[i] || rrank > v[i]);
                if (leftOk && rightOk) {
                    cnt++;
                    pos++;
                }
            }
            if (cnt == m) ans = m;
        }
        cout << ans << "\n";
    }
    return 0;
}