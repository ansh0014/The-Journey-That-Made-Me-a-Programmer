#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<vector<int>> children(n + 1);
        vector<int> parent(n + 1, 0);
        
        for(int i = 2; i <= n; i++){
            int p; cin >> p;
            parent[i] = p;
            children[p].push_back(i);
        }
        
        vector<int> height(n + 1, 0);
        for(int v = n; v >= 1; v--)
            for(int c : children[v])
                height[v] = max(height[v], height[c] + 1);

        vector<int> max_sib(n + 1, -1);
        
        for(int p = 1; p <= n; p++){
            if(children[p].size() <= 1) continue;
            int first = -1, second = -1;
            for(int c : children[p]){
                if(height[c] > first){ second = first; first = height[c]; }
                else if(height[c] > second){ second = height[c]; }
            }
            for(int c : children[p]){
        
                max_sib[c] = (height[c] == first && second < first) ? second : first;
            }
        }
        
        long long ans = height[1] + 1; 
        
        for(int v = 2; v <= n; v++){
            if(max_sib[v] == -1) continue; 
            ans += min(max_sib[v], height[v]) + 1;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}