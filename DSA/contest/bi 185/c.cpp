// now i am doing the create the 
// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     vector<string> createGrid(int m, int n) {

//         vector<string> grid(m, string(n, '#'));

//         // First row free
//         for (int j = 0; j < n; j++) {
//             grid[0][j] = '.';
//         }

//         // Last column free
//         for (int i = 0; i < m; i++) {
//             grid[i][n - 1] = '.';
//         }

//         return grid;
//     }
// };
// now i am doing the minimum lights to illuminate a road
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int minLights(vector<int>& lights) {

        int n = lights.size();

        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {

            int v = lights[i];

            if (v == 0) continue;

            int l = max(0, i - v);
            int r = min(n - 1, i + v);

            diff[l]++;

            if (r + 1 < n)
                diff[r + 1]--;
        }

        vector<int> visible(n);

        int cur = 0;

        for (int i = 0; i < n; i++) {
            cur += diff[i];
            visible[i] = (cur > 0);
        }

        int ans = 0;

        int i = 0;

        while (i < n) {

            if (visible[i]) {
                i++;
                continue;
            }

            int j = i;

            while (j < n && !visible[j])
                j++;

            int len = j - i;

            ans += (len + 2) / 3;

            i = j;
        }

        return ans;
    }
};
