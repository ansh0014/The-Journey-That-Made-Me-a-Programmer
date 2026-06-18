#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int target) {

 
        unordered_map<int, int> freq;

        unordered_map<int, int> indexMap;

  
        unordered_map<int, int> prefixMap;

     
        unordered_set<int> st;

    
        prefixMap[0] = 1;

        int sum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {

            int val = nums[i];


            freq[val]++;

          
            if(st.find(val) != st.end()) {
                
            }
            st.insert(val);

            // 🔹 3. Two Sum Logic
            int rem = target - val;
            if(indexMap.find(rem) != indexMap.end()) {
                // pair found: (indexMap[rem], i)
            }

            // store index AFTER check
            indexMap[val] = i;

            // 🔹 4. Prefix Sum Logic
            sum += val;

            // Case: subarray sum == target
            if(prefixMap.find(sum - target) != prefixMap.end()) {
                count += prefixMap[sum - target];
            }

            // store prefix sum
            prefixMap[sum]++;

            // 🔹 5. Longest Subarray Logic
            // (store only first occurrence)
            if(prefixMap.find(sum) == prefixMap.end()) {
                prefixMap[sum] = i;
            }
        }

        // OUTPUT (depends on problem)
        cout << "Subarray count: " << count << endl;
    }
};