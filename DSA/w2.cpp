class Solution {
public:
    long long countShadowPairs(vector<int>& nums) {

        vector<int> st;   // non-decreasing
        long long ans = 0;

        for (int x : nums) {

            // Remove values that are greater than x
            while (!st.empty() && st.back() > x) {
                st.pop_back();
            }

            // Count previous values strictly smaller than x
            int cnt = lower_bound(st.begin(), st.end(), x) - st.begin();

            ans += cnt;

            // Current element becomes active
            st.push_back(x);
        }

        return ans;
    }
};