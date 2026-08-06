// now i am doing the Largest Integer with digit sum
// i have given two non-negative integers n and s. 
// return the largest integer that has at most n digits and whose sum of digits is s. if no such integer exists, return -1
#include <bits/stdc++.h>
    using namespace std;
class Solution{
    public:

    int largestNumber(int n, int s) {

        if (s == 0) {
            if (n == 1)
                return 0;
            return -1;
        }

        if (s > 9 * n)
            return -1;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int digit = min(9, s);
            ans = ans * 10 + digit;
            s -= digit;
        }

        return (int)ans;
    }
};

int main() {
    int n, s;
     cout << "n: " << n << ", s: " << s << endl; // Debugging line
    cin >> n >> s;
       

    Solution sol;
    cout << sol.largestNumber(n, s) << endl;
    return 0;
}