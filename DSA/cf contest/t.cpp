#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k+2, INT_MAX), b(n+1);
        for(int i = 1; i <= k; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        vector<int> ops;
        for(int iter = 0; iter < 1000; iter++) {
            bool done = true;
            for(int i = 1; i <= n; i++) if(b[i] != k+1) { done = false; break; }
            if(done) break;
            
            for(int i = 1; i <= n; i++) {
                if(b[i] == k+1) continue;
                int nxt = b[i] + 1;
                int cnt = 0;
                for(int j = 1; j <= n; j++) if(b[j] == nxt) cnt++;
                if(nxt == k+1 || cnt < a[nxt]) {
                    b[i]++;
                    ops.push_back(i);
                }
            }
        }
        
        bool ok = true;
        for(int i = 1; i <= n; i++) if(b[i] != k+1) { ok = false; break; }
        
        if(!ok) cout << -1 << "\n";
        else {
            cout << ops.size() << "\n";
            for(int x : ops) cout << x << " ";
            cout << "\n";
        }
    }
}