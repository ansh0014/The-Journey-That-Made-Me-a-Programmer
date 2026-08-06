#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> aggregateSeries(vector<vector<int>>& series1,
                                        vector<vector<int>>& series2) {

        int n = series1.size();
        int m = series2.size();

        int i = 0, j = 0;
        vector<vector<int>> ans;

        while (i < n || j < m) {

            if (j == m || (i < n && series1[i][0] < series2[j][0])) {

                int timestamp = series1[i][0];
                int val1 = series1[i][1];
                int val2 = (j < m ? series2[j][1] : 0);

                ans.push_back({timestamp, val1 + val2});
                i++;
            }
            else if (i == n || series2[j][0] < series1[i][0]) {

                int timestamp = series2[j][0];
                int val1 = (i < n ? series1[i][1] : 0);
                int val2 = series2[j][1];

                ans.push_back({timestamp, val1 + val2});
                j++;
            }
            else {

                int timestamp = series1[i][0];
                int val1 = series1[i][1];
                int val2 = series2[j][1];

                ans.push_back({timestamp, val1 + val2});
                i++;
                j++;
            }
        }

        return ans;
    }
};