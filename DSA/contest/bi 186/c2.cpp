#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int INF = 1e9;
    int memo[100005][2];
    string s1, s2;
    int n;
    
    int rec(int i, int cur) {
        if (i == n) return 0;
        if (memo[i][cur] != -1) return memo[i][cur];
        
        int target = s2[i] - '0';
        int nxtOrig = (i+1 < n) ? (s1[i+1]-'0') : 0;
        int ans = INF;
        
        if (cur == target) {
            // no op needed, move forward
            ans = min(ans, rec(i+1, nxtOrig));
        }
        
        if (cur == 0 && target == 1) {
            // op1 at i: cost 1, s1[i] becomes 1, move forward
            ans = min(ans, 1 + rec(i+1, nxtOrig));
            
            // op1+op2+op1 at i: cost 3 (or 4), s1[i+1] becomes 0
            // only consider if i+1 < n
            if (i+1 < n) {
                if (nxtOrig == 1) {
                    // op1(i) + op2(i,i+1) + op1(i): cost 3, next cur = 0
                    int sub = rec(i+1, 0);
                    if (sub < INF) ans = min(ans, 3 + sub);
                } else {
                    // s1[i+1]=0: op1(i) + op1(i+1) + op2(i,i+1) + op1(i): cost 4, next cur = 0
                    int sub = rec(i+1, 0);
                    if (sub < INF) ans = min(ans, 4 + sub);
                }
            }
        }
        
        if (cur == 1 && target == 0) {
            if (i+1 < n) {
                if (nxtOrig == 1) {
                    // op2 directly: cost 1, s1[i+1] becomes 0
                    int sub = rec(i+1, 0);
                    if (sub < INF) ans = min(ans, 1 + sub);
                } else {
                    // op1(i+1) + op2: cost 2, s1[i+1] becomes 0
                    int sub = rec(i+1, 0);
                    if (sub < INF) ans = min(ans, 2 + sub);
                }
            }
            // i+1 >= n: stays INF (impossible)
        }
        
        return memo[i][cur] = ans;
    }
    
    int minOperations(string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        n = s1.size();
        memset(memo, -1, sizeof(memo));
        int ans = rec(0, s1[0]-'0');
        return ans >= INF ? -1 : ans;
    }
};