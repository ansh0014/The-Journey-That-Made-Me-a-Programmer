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
        
        if (n == 1) {
            cout << 1 << "\n";
        } else if (n == 2) {
            cout << -1 << "\n";
        } else {
            vector<long long> a = {1, 2, 3};
            long long sum = 6;
            
            while ((int)a.size() < n) {
                a.push_back(sum);
                sum *= 2;
            }
            
            for (int i = 0; i < n; i++) {
                if (i) cout << " ";
                cout << a[i];
            }
            cout << "\n";
        }
    }
    
    return 0;
}