// now i am doing the wides possible fence
// i have given an integer array planks where planks[i] represents the height of the ith wooden plank. each plan has width of 1 unit 
// i want to build a fence consisting of planks that all have the same height.
// i may eigher use a plank as is or combine exatly two distinct original planks into singel plan whose height equals tohe sum of theri heights. Each orgitnal can be used at most onec not all orginal planks need to be used.
// return the maximum possible height of the fence that can be built. if it is impossible to build a fence, return 0.
// approach i am using greedy for the maximum possible height of the fence that can be built. we will use the bitmask for the mask of the planks and then we will use the dp for the transition of the mask and then we will use the backtracking to find the maximum possible height of the fence that can be built.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int widestFence(vector<int>& planks) {

        int mx = *max_element(planks.begin(), planks.end());

        vector<int> freq(mx + 1, 0);

        for (int x : planks)
            freq[x]++;

        int ans = 0;

        for (int h = 1; h <= 2 * mx; h++) {

            int width = 0;

            for (int x = 1; x <= h / 2; x++) {

                int y = h - x;

                if (y > mx) continue;

                if (x == y)
                    width += freq[x] / 2;
                else
                    width += min(freq[x], freq[y]);
            }

            if (h <= mx)
                width += freq[h];

            ans = max(ans, width);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> planks(n);

    for (int i = 0; i < n; i++)
        cin >> planks[i];

    Solution s;
    cout << s.widestFence(planks);
}